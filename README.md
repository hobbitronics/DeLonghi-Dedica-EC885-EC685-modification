# Espresso Machine Display – Arduino Nano Project

With this project, you can monitor and visualize the coffee brewing and extraction process by installing a pressure sensor and a temperature sensor. No modifications are made to the machine’s electronics — it is purely a non-invasive monitoring and display system shown on a small screen. This helps in determining the optimal grind size and coffee dose.

For installation, you only need to disconnect the silicone hose between the thermoblock and the outlet. This hose is available as a spare part, so the machine can be fully restored to its original condition at any time. The display is designed in a way that no drilling is required — it uses the original mounting holes of the logo badge.

The system is based on an Arduino Nano with its own power supply. It can be connected without any soldering or modifications to the original circuit board.


---

## ✨ Features

- **Non-invasive monitoring**: The machine remains unmodified — no soldering, no drilling, and 100% reversible installation.
- **Real-time shot timer**: Accurately displays extraction duration from the moment the pump starts.
- **Pressure measurement**: Displays current and maximum brewing pressure during extraction.
- **Temperature display** *(optional)*: Shows current and maximum water temperature while brewing.
- **Post-shot analysis**: After extraction, the display shows average pressure and temperature values.
- **OLED display**: Compact 128x64 I2C screen for clear and minimalistic visualization.
- **One-button operation**: Single push button for reset/start — intuitive and simple.
- **Standalone system**: Powered by USB, does not interfere with the machine’s electronics.
- **3D-printed mounting**: Reuses existing logo mounting holes — no drilling required.

---



## 📦 Bill of Materials (BOM)

| **Component**                                   | **Quantity** | **Specification**                                             | **Notes**                                                            |
|-------------------------------------------------|--------------|---------------------------------------------------------------|----------------------------------------------------------------------|
| **Arduino (e.g., Uno, Nano)**                   | 1            | -                                                             | Microcontroller                                                      |
| **OLED Display**                                | 1            | 0.96" I2C OLED Display, 128x64                                | I2C compatible                                                       |
| **Resistor (100kΩ)**                            | 1            | 100kΩ, 1/4W                                                   | For voltage divider with the thermistor                              |
| **Thermistor (ATC Semitec 104GT-2)**            | 1            | 10kΩ @ 25°C (NTC)                                             | Temperature sensor                                                   |
| **G1/4" Pressure Sensor (DC 5V)**               | 1            | Stainless steel, 0-300 PSI, analog output                     | Pressure sensor for water, air, gas, or heating oil                  |
| **T-Steckanschluss, Innengew. G 1/4"-4mm, IQS-MSV** | 1         | G 1/4" internal thread, 4mm hose connector                    | Pneumatic T-fitting for sensor integration                          |
| **Hailege 5pcs NANO IO Shield DIY Kit**         | 1            | DIY Kit for Arduino Nano (5 pieces)                           | IO expansion board for Arduino Nano                                  |
| **Wires**                                       | -            | Various lengths                                               | For connecting components                                            |
| **WAGO 2-pin Connector**                        | 2            | -                                                             | For quick and secure wire connections                                |
| **Screws M2.5x12mm**                            | 2            | M2.5, Length: 12mm                                            | For securing components                                              |
| **Solder Nuts M2.5**                            | 2            | M2.5, suitable for the screws                                 | For a permanent and secure connection of the screws                  |
| **Power Supply Option 1 (EPLZON 12V)**          | 1            | EPLZON 12V/DC 6W Mini LED Transformer                         | Provides 12V DC power                                                |
| **Power Supply Option 2 (Meanwell IRM-03-12S)** | 1            | Meanwell IRM-03-12S, 12V DC, 3W                               | Provides 12V DC power, alternative to EPLZON                         |
| **Piggyback Flat Connectors**                   | 2            | Flat push-on type with additional tab (e.g., 6.3 mm)          | For daisy-chaining power connections                                 |

---

## 🔧 Wiring Diagram
Basic wiring instructions:
- **OLED SDA → Arduino A4**
- **OLED SCL → Arduino A5**
- **OLED GND → Arduino GND**
- **OLED VCC → Arduino 5V**
- **100kΩ resistor → between Arduino GND & Arduino A1** (used for thermistor divider)
- **Thermistor ATC Semitec 104GT-2 → between Arduino 5V & Arduino A1** (used in conjunction with the resistor for temperature sensing)
- **Pressure Sensor VCC → Arduino 5V**
- **Pressure Sensor GND → Arduino GND**
- **Pressure Sensor SIGNAL → Arduino A0**

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
## 💖 Support

If you find this project helpful and would like to support its development, consider buying me a coffee:

[![Buy Me a Coffee](https://img.shields.io/badge/Buy%20Me%20a%20Coffee-FFDD00?logo=buymeacoffee&logoColor=black&style=for-the-badge)](https://www.buymeacoffee.com/caijonas404)

Thank you for your support! ☕😊

##⚠️ **Warning / Disclaimer**

- This project involves working with high voltage and mechanical components. Improper handling may lead to electric shock, injury, or damage to the equipment.
- Modifying your machine will likely void any manufacturer warranty.
- You are responsible for any risks or consequences. Proceed only if you have experience with electronics and high-voltage systems.
