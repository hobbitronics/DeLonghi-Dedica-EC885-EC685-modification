# Espresso Machine Display – Arduino Nano Project


With this project, you can monitor and visualize the coffee brewing and extraction process by installing a pressure sensor and a temperature sensor. No modifications are made to the machine’s electronics — it is purely a non-invasive monitoring and display system shown on a small screen. This helps in determining the optimal grind size and coffee dose.

For installation, you only need to disconnect the silicone hose between the thermoblock and the outlet. This hose is available as a spare part, so the machine can be fully restored to its original condition at any time. The display is designed in a way that no drilling is required — it uses the original mounting holes of the logo badge.

The system is based on an Arduino Nano with its own power supply. It can be connected without any soldering or modifications to the original circuit board.


---

## ✨ Features
- **Shot Timer:** Displays the duration of espresso extraction
- **Temperature Display:** Shows water temperature (optional)
- **Minimal Interface:** Single-button control

---

## 📦 Required Hardware (Bill of Materials)
| Qty | Component                   | Notes                                      |
|:---:|:----------------------------|:-------------------------------------------|
| 1   | Arduino Nano                | ATmega328P-based, original or clone        |
| 1   | OLED Display 128x64 I2C     | Based on SSD1306                           |
| 1   | Push Button                 | Start/Stop control                         |
| 1   | 10kΩ Resistor               | For pull-down on button                    |
| 1   | Jumper Wires                | Arduino to components                      |
| 1   | (optional) DS18B20 Sensor   | For temperature reading                    |

---

## 🔧 Wiring Diagram
Basic wiring instructions:
- **OLED SDA → Arduino A4**
- **OLED SCL → Arduino A5**
- **OLED GND → Arduino GND**
- **OLED VCC → Arduino 5V**
- **Button → Arduino D2** (with 10kΩ pull-down resistor)
- **(Optional) DS18B20 → Arduino D3** (with 4.7kΩ pull-up)

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
YouTube: _Add link here_

---

## ⚖️ License
This project is licensed for **private, non-commercial use only**.  
See `LICENSE` for details or contact the author for other use cases.

---

## 🤝 Contributing
Feel free to open issues or submit pull requests!

---

## 📝 Disclaimer
Use at your own risk. The system is designed as a non-invasive add-on and makes no changes to the machine’s internals.
