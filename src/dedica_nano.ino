#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <math.h>

// ---------- CONFIG ----------
const uint8_t PRESS_PIN = A0;
const uint8_t THERM_PIN = A1;
const float vcc = 4.98; // 5V assumed; for 3.3V boards, change to 3.3

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/SCL, /* data=*/SDA,
                                         /* reset=*/U8X8_PIN_NONE);

// Sensor mapping (0.5V -> 0 bar ; 4.5V -> 16 bar)
const float SENSOR_V_MIN = 0.5;
const float SENSOR_V_MAX = 4.5;
const float SENSOR_BAR_MAX = 16.0;

// Thermistor
const float R_PULL = 100000.0;
const float R0 = 100000.0;
const float T0_K = 298.15;
const float BETA = 3950.0;

// Averaging / smoothing
const float TEMP_IIR_ALPHA = 0.12;

// Shot detection
const float SHOT_START_BAR = 4.5;
const float SHOT_END_BAR = 3.5;
const unsigned long SHOT_END_HYST_MS = 200;
const unsigned long MIN_SHOT_TIME_MS = 7000;

// Sparkline: a graph of the pressure over time, showing the general trend of
// the shot.
#define SPARK_SAMPLES 64
uint8_t spark[SPARK_SAMPLES]; // 0..160
uint8_t spark_idx = 0;

// ---------- runtime ----------
float temp_filtered = NAN;
bool in_shot = false;
unsigned long shot_start_ms = 0;
unsigned long last_below_ms = 0;
uint8_t peak_bar = 0;      // 0..160
unsigned long sum_bar = 0; // sum in 0.1 bar units
unsigned int shot_samples = 0;

float readVoltage(uint8_t pin) {
  int samples = 8;
  long sum = 0;
  for (int i = 0; i < samples; i++)
    sum += analogRead(pin);
  float avg = sum / (float)samples;
  return avg / 1023.0 * vcc;
}

float pressureFromVoltage(float vin) {
  if (vin <= SENSOR_V_MIN)
    return 0.0;
  if (vin >= SENSOR_V_MAX)
    return SENSOR_BAR_MAX;
  float bar =
      (vin - SENSOR_V_MIN) / (SENSOR_V_MAX - SENSOR_V_MIN) * SENSOR_BAR_MAX;
  return bar;
}

float readThermC() {
  float v = readVoltage(THERM_PIN); // or convert analogRead manually
  if (v <= 0.0001)
    return NAN;

  float Rth = (vcc * R_PULL / v) - R_PULL;
  if (Rth <= 0)
    return NAN;

  float tK = 1.0 / ((1.0 / T0_K) + (1.0 / BETA) * log(Rth / R0));
  return tK - 273.15;
}

void addSpark(uint8_t val) {
  spark[spark_idx] = val;
  spark_idx++;
  if (spark_idx >= SPARK_SAMPLES)
    spark_idx = 0;
}

void drawLiveScreen(float pressure, float tempC, unsigned long shotTimeMs) {
  u8g2.clearBuffer();

  // Serial.print("big bar ");
  // Serial.println(pressure);
  // Big pressure
  char buf[8];
  dtostrf(pressure, 4, 1, buf);
  u8g2.setFont(u8g2_font_fub20_tr);
  int pw = u8g2.getUTF8Width(buf);
  u8g2.drawUTF8((128 - pw) / 2, 38, buf);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr((128 - pw) / 2 + pw + 2, 34, "bar");

  // ---- Temperature (right-aligned) ----
  char tbuf[8];
  dtostrf(tempC, 4, 1, tbuf);

  int w_temp = u8g2.getStrWidth(tbuf);
  int total_w = w_temp + 1 + u8g2.getStrWidth("C");
  int x = 128 - total_w - 2; // 2px right margin

  u8g2.drawStr(x, 10, tbuf);
  u8g2.drawStr(x + w_temp + 1, 10, "C");

  // Shot timer
  unsigned long s = shotTimeMs / 1000;
  unsigned long ds = (shotTimeMs % 1000) / 100; // deciseconds (0–9)
  char timebuf[12];
  snprintf(timebuf, sizeof(timebuf), "%lu.%lus", s, ds);
  u8g2.drawStr(2, 10, timebuf);

  // Sparkline
  float minv = 9999, maxv = -9999;
  for (int i = 0; i < SPARK_SAMPLES; i++) {
    if (spark[i] < minv)
      minv = spark[i];
    if (spark[i] > maxv)
      maxv = spark[i];
  }
  if (minv == 9999) {
    minv = 0;
    maxv = 160;
  }
  if (maxv - minv < 1)
    maxv = minv + 1;

  int gx = 2, gy = 62, gw = 124, step = gw / SPARK_SAMPLES;
  if (step < 1)
    step = 1;
  for (int i = 0; i < SPARK_SAMPLES; i++) {
    int idx = (spark_idx + i) % SPARK_SAMPLES;
    float v = spark[idx];
    int x = gx + i * step;
    float heightFraction = (v - minv) / (maxv - minv);
    int h = (int)(heightFraction * 10);
    for (int y = 0; y < h; y++)
      u8g2.drawPixel(x, gy - y);
  }
  u8g2.sendBuffer();
}

void drawPostShotScreen(uint8_t peak, uint16_t sum, unsigned int samples,
                        float tempC, unsigned long shotMs) {
  u8g2.clearBuffer();
  char buf[17];

  // --- Peak pressure ---
  float peakF = peak;
  dtostrf(peakF, 4, 1, buf); // float → string
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(4, 18, "Peak: ");
  u8g2.drawStr(4 + u8g2.getStrWidth("Peak: "), 18, buf);

  // --- Average pressure ---
  float avgF = (sum / (float)samples);
  dtostrf(avgF, 4, 1, buf);
  u8g2.drawStr(4, 36, "Avg: ");
  u8g2.drawStr(4 + u8g2.getStrWidth("Avg: "), 36, buf);

  // --- Temperature ---
  dtostrf(tempC, 4, 1, buf);
  u8g2.drawStr(4, 54, "Temp: ");
  u8g2.drawStr(4 + u8g2.getStrWidth("Temp: "), 54, buf);

  // --- Shot time ---
  unsigned long s = shotMs / 1000;
  unsigned long ms = (shotMs % 1000) / 10;
  snprintf(buf, sizeof(buf), "T: %lu.%02lus", s, ms); // safe, no floats
  u8g2.drawStr(76, 36, buf);

  u8g2.sendBuffer();
}

void setup() {
  Serial.begin(9600);
  u8g2.begin();
  for (int i = 0; i < SPARK_SAMPLES; i++)
    spark[i] = 0;
  temp_filtered = readThermC();
  if (isnan(temp_filtered))
    temp_filtered = 25.0;
}

void loop() {

  float vpress = readVoltage(PRESS_PIN);
  // Serial.print("vpress ");
  // Serial.println(vpress);

  float bar = pressureFromVoltage(vpress);

  float tC = readThermC();
  if (!isnan(tC)) {
    if (isnan(temp_filtered))
      temp_filtered = tC;
    else
      temp_filtered =
          temp_filtered * (1.0 - TEMP_IIR_ALPHA) + tC * TEMP_IIR_ALPHA;
  }

  addSpark((uint8_t)(bar * 10.0)); // if spark expects 0–160

  unsigned long now = millis();

  if (!in_shot) {
    if (bar >= SHOT_START_BAR) {
      in_shot = true;
      shot_start_ms = now;
      peak_bar = bar;
      sum_bar = bar;
      shot_samples = 1;
      last_below_ms = 0;
    }
  } else {
    if (bar > peak_bar)
      peak_bar = bar;
    sum_bar += bar;
    shot_samples++;

    const bool meetsMinShotTime = (now - shot_start_ms) >= MIN_SHOT_TIME_MS;
    const bool belowEndThreshold = (bar < SHOT_END_BAR);

    if (belowEndThreshold && meetsMinShotTime) {
      // Start hysteresis timer if first time dipping below
      if (last_below_ms == 0) {
        last_below_ms = now;
      }
      // If hyst period elapsed → end shot
      else if ((now - last_below_ms) >= SHOT_END_HYST_MS) {
        unsigned long shot_len = now - shot_start_ms;
        in_shot = false;
        last_below_ms = 0;
        drawPostShotScreen(peak_bar, sum_bar, shot_samples, temp_filtered,
                           shot_len);
        // Reset accumulators
        peak_bar = 0;
        sum_bar = 0;
        shot_samples = 0;
        delay(15000);
      }
    } else {
      // Not continuously under threshold → reset hysteresis timer
      last_below_ms = 0;
    }
  }

  drawLiveScreen(bar, temp_filtered, in_shot ? (now - shot_start_ms) : 0);
  delay(100);
}
