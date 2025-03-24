
---

```markdown
# 🚗 HB100 Radar Speed Detection using STM32F301RB

This project measures the speed of moving objects using the **HB100 Doppler radar module**, an **STM32F301RB microcontroller**, and an **SSD1306 OLED display**. Instead of traditional pulse counting, the system uses **FFT (Fast Fourier Transform)** on analog IF output to extract frequency information and compute speed accurately.

---

## 🔧 Features

- ⚡️ **FFT-based speed detection**
- 📈 Real-time analog signal sampling using **ADC**
- 📊 Dominant frequency extraction using **CMSIS DSP FFT**
- 🎯 Speed displayed in **km/h** on OLED
- 🧠 Pre-processing using **Sallen-Key filter**
- 🧪 Sampling rate: ~4 kHz for Doppler frequency capture

---

## 📦 Hardware Required

| Component              | Description                                    |
|------------------------|------------------------------------------------|
| STM32F301RB            | Nucleo board or similar STM32 board            |
| HB100 Doppler Radar    | 24.125 GHz motion detection radar              |
| Sallen-Key Filter      | 2nd-order low-pass filter (for signal cleanup) |
| SSD1306 OLED Display   | 128x64 I2C OLED display                        |
| Power Supply           | 5V/3.3V as required                            |
| Jumper wires, Breadboard | For prototyping                              |

---

## 🛠️ Circuit Connection

### ⚙️ HB100 to STM32

| HB100 Pin   | STM32 Pin         |
|------------|-------------------|
| VCC        | 5V or 3.3V        |
| GND        | GND               |
| IF         | PA0 (ADC input) via Sallen-Key filter |

### 🖥️ OLED (I2C) to STM32

| OLED Pin | STM32 Pin | Note            |
|----------|-----------|-----------------|
| VCC      | 3.3V      | or 5V           |
| GND      | GND       |                 |
| SDA      | PB7       | I2C1 SDA        |
| SCL      | PB6       | I2C1 SCL        |

---

## 📐 Doppler Speed Calculation

The Doppler shift frequency is proportional to the target's speed:

```
speed (m/s) = (f_d * λ) / 2
```

Where:
- `f_d`: Doppler frequency from FFT
- `λ` = 0.0124 m (wavelength of 24.125 GHz HB100)

Converted to **km/h**:

```
speed_kmh = speed_mps * 3.6
```

---

## 📁 File Structure

```bash
├── Core
│   ├── Inc
│   │   ├── main.h
│   │   ├── ssd1306.h
│   │   └── fonts.h
│   └── Src
│       ├── main.c
│       ├── ssd1306.c
│       └── fonts.c
├── Drivers
│   └── CMSIS
│       └── DSP (CMSIS DSP FFT library)
├── README.md
```

---

## 📊 Performance Tips

- Use **larger FFT sizes** (e.g., 512 or 1024) for finer resolution.
- Ensure **Sallen-Key LPF** cuts off above expected max Doppler (~200 Hz).
- Sample rate ≥ 2× max Doppler frequency (Nyquist rule).

---

## 📦 Dependencies

- STM32 HAL Library
- CMSIS DSP Library (for FFT)
- SSD1306 OLED library (HAL-compatible)
- STM32CubeMX (for initial configuration)

---

## 🧠 Future Improvements

- DMA-based ADC sampling
- Graphical spectrum on OLED
- Target direction detection using dual radar

---

## 👨‍💻 Author

**Thomas Jefferson**  
Electronics & Robotics Engineer | Embedded Systems Enthusiast

---

## 📜 License

This project is open source under the MIT License.
```

---

