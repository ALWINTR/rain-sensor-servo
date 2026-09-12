# 🌧️ Arduino Rain Sensor Automated Servo Protection Cover

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/rain-sensor-servo)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![Platform](https://img.shields.io/badge/Platform-Arduino_Uno_%26_Servo-38bdf8?style=for-the-badge&logo=arduino&logoColor=white)](https://github.com/ALWINTR)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

An automated weather protection system that detects precipitation in real time, executes a software hysteresis debounce state machine, and deploys a servo-actuated protective shutter to shield outdoor electronic equipment from moisture and water ingress.

---

## 📌 System Architecture

The rain-responsive mechanism operates with zero-lag response:
1. **Precipitation Sensing**: The **FC-37 nickel sensor plate** detects raindrops bridging the conductive traces, lowering electrical resistance.
2. **Comparator Signal Conditioning**: The onboard **LM393 dual comparator** produces both an analog intensity voltage (A0) and a digital trip signal (D0).
3. **Anti-Oscillation Hysteresis**: Firmware prevents mechanical fluttering caused by solitary raindrops or drying moisture.
4. **Precision Servo Actuation**: Deploys the protective shutter to 180° upon rain confirmation, retracting to 0° after a verified dry period.

---

## ⚙️ Hardware Components & Bill of Materials

| Component | Technical Specification | Function |
| :--- | :--- | :--- |
| **Microcontroller** | Arduino Uno / Nano (ATmega328P) | Sensor polling & PWM pulse timing |
| **Rain Sensor Plate** | FC-37 Nickel-Coated PCB Grid | High-sensitivity moisture conductivity |
| **Comparator Module** | LM393 Dual Differential Comparator | Onboard sensitivity trimmer & threshold |
| **Actuator** | TowerPro SG90 9g Micro Servo Motor | Mechanical protective cover deployment |
| **Status LEDs** | Blue (Rain Active) / Green (Standby) | Visual operational status feedback |

---

## 🔌 Circuit Pinout Table

| Module Pin | Arduino Pin | Signal Type | Description |
| :--- | :--- | :--- | :--- |
| **FC-37 Analog (A0)** | Analog Pin A0 | Analog In (0-5V) | Moisture intensity (1023=Dry, <400=Heavy Rain) |
| **FC-37 Digital (D0)** | Digital Pin D2 | Digital In | Instant hardware threshold interrupt |
| **SG90 Servo Signal** | Digital Pin D9 | PWM Output (50Hz) | 0° (Retracted) to 180° (Protected) |
| **Blue Rain LED** | Digital Pin D7 | Digital Output | Active when precipitation is present |
| **Green Standby LED** | Digital Pin D8 | Digital Output | Active in dry resting state |

---

## 🧠 Firmware State Machine & Timing

The Arduino firmware (`rain_sensor_servo.ino`) implements a software debounce timer to protect the servo gear train:
```cpp
// Calibration Threshold Constants
const int RAIN_THRESHOLD = 500;       // Analog trigger threshold
const unsigned long DRY_DELAY = 5000; // 5-second post-dry verification delay
```

---

## 🚀 Getting Started

1. Clone repository:
   ```bash
   git clone https://github.com/ALWINTR/rain-sensor-servo.git
   ```
2. Open `rain_sensor_servo.ino` in Arduino IDE.
3. Select board **Arduino Uno** / **Nano**.
4. Compile and upload firmware.
5. Open Serial Monitor at **9600 baud** to view real-time moisture readings.

---

## 👨‍💻 Author

**Alwin T R** — Robotics & Automation Engineer  
- 💼 LinkedIn: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- 🌌 Portfolio: [alwintr.github.io](https://alwintr.github.io)  
- 💻 GitHub: [github.com/ALWINTR](https://github.com/ALWINTR)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
