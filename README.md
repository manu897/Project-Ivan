# 🛠️ Ivan AR Helmet HUD

**Project-Ivan** is a hobbyist AR/VR project inspired by Ivan Sutherland's vision of augmented computing. It aims to embed a **minimal head-up display (HUD)** inside a motorcycle helmet using an **ESP32-S3 board**, a **prism cube**, and a **compact LCD**. The goal is to display useful data — like time, navigation, or sensor readings — within a rider's field of view.

---

## 🚀 Project Goals

- Display digital overlays in a motorcycle helmet using a transparent optical path.
- Integrate with helmet's **Universal Communication System (UCS)** slot for power and audio.
- Add motion awareness using built-in IMU for future gesture/head tracking.
- Enable audio features (e.g., alerts or Bluetooth connectivity).

---

## 🧹 Hardware Components

| Component          | Details                                                |
| ------------------ | ------------------------------------------------------ |
| ESP32-S3 Dev Board | Waveshare 1.3" LCD, ST7789V2 driver, 240×240, SPI, IMU |
| Display            | 1.3" IPS LCD w/ ST7789V2 + EYESPI connector            |
| Prism Cube         | H-K9 optical glass, 10×10×10mm, partially reflective   |
| Helmet             | MT Stringer 2 with Universal Comms Slot (UCS)          |
| Battery Management | PL4054 onboard Li-ion charge controller (with LED indicator) |
| Power Regulator    | ME6217C33M5G LDO, 3.3V @ 800mA max                        |
| Battery Input       | MX1.25 connector for 3.7V LiPo cells                     |
| Audio (planned)    | Bone conduction or flat helmet speakers + Class D amp  |

---

## 🧠 Software Stack

- **ESP-IDF**: Main development framework
- **LVGL**: Lightweight graphics library for drawing UI
- **ST7789V2 SPI Driver**: Used to control the onboard LCD
- **VS Code**: IDE with GitHub Copilot for assisted development
- **QMI8658 IMU**: Six-axis gyro + accelerometer for motion and orientation sensing.

---

## 💻 Project Structure

```bash
├── main/ # Core application (app_main.c)
├── components/ # LVGL, display, IMU drivers
├── docs/ # Design notes, planning logs
├── CMakeLists.txt
├── sdkconfig
└── README.md
```

---

## ✅ Current Features

- [x] Digital clock rendered through prism
- [x] SPI display driver integrated
- [x] Simple LVGL layout
- [ ] IMU-based movement tracking (planned)
- [ ] Bluetooth audio & alerts (planned)
- [ ] UCS-mounted battery system (planned)

---

## 🧪 Quick Start (ESP-IDF)

```bash
$HOME/esp/esp-idf/export.sh

idf.py set-target esp32s3

idf.py build

idf.py flash monitor
```

## 📚 Docs & Resources
- [**Waveshare ESP32-S3 LCD 1.3" Wiki**](https://www.waveshare.com/wiki/ESP32-S3-LCD-1.3)
- [**LVGL for ESP32 (GitHub)**](https://github.com/lvgl/lv_port_esp32)
- [**ESP-IDF Documentation**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)

## 📌 License

MIT License. Built for personal experimentation and learning.

## 📄 About the Author

Project by [**Manideep**](https://github.com/manu897). Inspired by Ivan Sutherland’s vision of head-mounted computing.

Want to contribute? Fork the repo or open an issue!
