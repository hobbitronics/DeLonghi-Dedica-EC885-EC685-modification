# Espresso Machine Display – Arduino Nano Project

With this project, you can monitor and visualize the coffee brewing and extraction process by installing a pressure sensor and a temperature sensor. No modifications are made to the machine’s electronics — it is purely a non-invasive monitoring and display system shown on a small screen. This helps in determining the optimal grind size and coffee dose.

For installation, you only need to disconnect the silicone hose between the thermoblock and the outlet. This hose is available as a spare part, so the machine can be fully restored to its original condition at any time. The display is designed in a way that no drilling is required — it uses the original mounting holes of the logo badge.

The system is based on an Arduino Nano with its own power supply. It can be connected without any soldering or modifications to the original circuit board.


---

## ✨ Features

- **Non-invasive monitoring**: The machine remains unmodified — no soldering, no drilling, and 100% reversible installation.
- **Real-time shot timer**: Accurately displays extraction duration from the moment the pressure is high enough and the extraction starts.
- **Pressure measurement**: Displays current and maximum brewing pressure during extraction.
- **Temperature display** *(optional)*: Shows current and maximum water temperature while brewing.
- **Post-shot analysis**: After extraction, the display shows average pressure and temperature values.
- **OLED display**: Compact 128x64 I2C screen for clear and minimalistic visualization.
- **Standalone system**: Powered by USB, does not interfere with the machine’s electronics.
- **3D-printed mounting**: Reuses existing logo mounting holes — no drilling required.

---



## 📦 Bill of Materials (BOM)

| **Komponente**                                  | **Menge** | **Spezifikation**                                             | **Hinweise**                                                            | **Link**                    |
|-------------------------------------------------|-----------|---------------------------------------------------------------|--------------------------------------------------------------------------|-----------------------------|
| **Arduino Nano**                                | 1         | Mikrocontroller                                               | Kompatibel mit ATmega328P                                                | [Arduino Nano – Arduino Store](https://store.arduino.cc/products/arduino-nano) |
| **OLED Display**                                | 1         | 0.96" I2C OLED Display, 128x64                                | I2C-kompatibel                                                           |[DIYmall 0.96" OLED Display – Amazon](https://www.amazon.com/DIYmall-Serial-128x64-Display-Arduino/dp/B00O2KDQBE) |
| **Widerstand (100kΩ)**                          | 1         | 100kΩ, 1/4W                                                   | Für Spannungsteiler mit dem Thermistor                                   | [100kΩ Widerstand 20er-Pack – LED-Shop](https://www.led-shop.com/Widerstand-1-4W-100k-Ohm-20er-Pack) |
| **Thermistor (ATC Semitec 104GT-2)**            | 1         | 100kΩ @ 25°C (NTC)                                             | Temperatursensor                                                        | [JINXIUS 104GT-2 Thermistor – Amazon](https://www.amazon.com/JINXIUS-Temperature-104NT-4-R025H42G-Thermistor-Compatible/dp/B097PBSQYZ) |
| **Drucksensor G1/4" (DC 5V)**                   | 1         | Edelstahl, 0–300 PSI, analoger Ausgang                        | Für Wasser, Luft, Gas oder Heizöl                                        | [Drucktransmitter G1/4" – Amazon](https://www.amazon.de/Drucktransmitter-Analogsensor-Wasser-Luftkompressor-0-300/dp/B0DPQTX1JR) |
| **T-Steckanschluss G1/4"-4mm, IQS-MSV**         | 1         | G1/4" Innengewinde, 4mm Schlauchanschluss                     | Pneumatischer T-Anschluss für Sensorintegration                          | [T-Steckanschluss IQS-MSV – Landefeld](https://www.landefeld.de/artikel/de/t-steckanschluss-g-14-4mm-iqs-msv-standard-/IQST%20144%20G%20MSV) |
| **Hailege 5pcs NANO IO Shield DIY Kit**         | 1         | DIY-Kit für Arduino Nano (5 Stück)                            | IO-Erweiterungsboard für Arduino Nano                                    | [Hailege Nano IO Shield – Amazon](https://www.amazon.com/Hailege-Shield-Expansion-Board-Arduino/dp/B08D7D8NPL) |
| **Kabel**                                       | -         | Verschiedene Längen                                           | Für den Anschluss der Komponenten                                        | |
| **WAGO 2-poliger Steckverbinder**               | 2         | -                                                             | Für schnelle und sichere Drahtverbindungen                               | [https://www.wago.com/de/installationsklemmen/verbindungsklemme-mit-hebeln/p/221-412 ](https://www.wago.com/de/installationsklemmen/verbindungsklemme-mit-hebeln/p/221-412) |
| **Schrauben M2.5x12mm**                         | 2         | M2.5, Länge: 12mm                                             | Zur Befestigung von Komponenten                                          | [M2.5x12mm Schrauben – Amazon](https://www.amazon.de/Innensechskant-Au%C3%9Fengewinde-Edelstahl-Anti-Lose-Maschinenbefestigungen-M2-5x12mm/dp/B0BJPLYXK1) |
| **M2,5 Gewindeeinsätze/ Einschlagmuttern        | 2         | M2.5                                                          | Für eine dauerhafte und sichere Verbindung der Schrauben                 | [M2,5 Gewindeeinsätze/ Einschlagmuttern](https://www.ahltec.de/shop/de/M2-5-Gewindeeinsaetze--Einschlagmuttern-438.html) |
| **Stromversorgung Option 1 (EPLZON 12V)**       | 1         | EPLZON 12V/DC 6W Mini LED Transformator                       | Liefert 12V DC Strom                                                     | [EPLZON 12V Trafo – Amazon](https://www.amazon.de/EPLZON-Transformator-Leuchten-Stripes-Mindestlastanforderungen/dp/B0DQNP4Z2S) |
| **Stromversorgung Option 2 (Meanwell IRM-03-12S)** | 1       | Meanwell IRM-03-12S, 12V DC, 3W                               | Alternative zu EPLZON, kompakte Bauform                                 | [Meanwell IRM-03-12S – Mouser](https://www.mouser.de/ProductDetail/MEAN-WELL/IRM-03-12S?qs=NKmfXavxMaxrQLjk4RvqlA%3D%3D) |
| **Piggyback Flachstecker**                      | 2         | Flachsteckverbinder mit zusätzlichem Abzweig (z. B. 6,3 mm)   | Für das Durchschleifen von Stromverbindungen                             | [Piggyback Flachstecker 6,3 mm – Amazon](https://www.amazon.de/-/en/10-Piggy-Backs-5mm%C2%B2-6-red/dp/B005J4QMLI) |



## 🔧 Wiring Diagram & Setup Instructions

### 🖥️ OLED Display (I2C)
- **SDA** → Arduino **A4**
- **SCL** → Arduino **A5**
- **GND** → Arduino **GND**
- **VCC** → Arduino **5V**

### 🌡️ Thermistor (ATC Semitec 104GT-2) & Voltage Divider
- **Thermistor**:
  - One end → Arduino **5V**
  - Other end → Arduino **A1**
- **100kΩ Resistor**:
  - One end → Arduino **A1**
  - Other end → Arduino **GND**

### 📈 Pressure Sensor
- **VCC** → Arduino **5V**
- **GND** → Arduino **GND**
- **SIGNAL** → Arduino **A0**

### ⚡ Power Supply via Piggyback Connector
- **The power supply is connected to the board via a piggyback connector**
- **Positive lead (+)** from power supply → Arduino **VIN**
- **Ground (−)** from power supply → Arduino **GND**

> ⚠️ **Note**: When powering the Arduino externally, use the **VIN pin**, not the 5V pin. Ensure **GND is shared** across all components for proper reference voltage.

  
---

## 🧑‍💻 Installation
1. Install the Arduino IDE
2. Install libraries:
   - Adafruit SSD1306
   - Adafruit GFX
   - DallasTemperature (optional)
   - OneWire (optional)
3. Upload `display_controller.ino` to your Arduino Nano
4. Wire components as described above
5. Power up and enjoy!

---

## 📸 Photos
_Images of the mounted system go here_

---

## 📺 Demo Video
YouTube: https://youtu.be/2GCKHqg131g?feature=shared
         https://youtube.com/shorts/OjNCzPk4PEM?feature=shared
         https://youtube.com/shorts/8p8zOG2kiDQ?feature=shared

---

## ⚖️ License
This project is licensed for **private, non-commercial use only**.  
See `LICENSE` for details or contact the author for other use cases.

---

## 🤝 Contributing
Feel free to open issues or submit pull requests!

---
## 💖 Support

If you find this project helpful and would like to support its development, consider buying me a coffee:

[![Buy Me a Coffee](https://img.shields.io/badge/Buy%20Me%20a%20Coffee-FFDD00?logo=buymeacoffee&logoColor=black&style=for-the-badge)](https://www.buymeacoffee.com/caijonas404)

Thank you for your support! ☕😊

##⚠️ **Warning / Disclaimer**

- This project involves working with high voltage and mechanical components. Improper handling may lead to electric shock, injury, or damage to the equipment.
- Modifying your machine will likely void any manufacturer warranty.
- You are responsible for any risks or consequences. Proceed only if you have experience with electronics and high-voltage systems.
