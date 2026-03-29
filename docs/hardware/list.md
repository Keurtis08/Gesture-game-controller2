# Components List

Everything you need to reproduce this project.

---

## Hardware components

| Component | Quantity | Role |
|-----------|----------|------|
| Arduino Nano 33 BLE Sense | 1 | IMU sensor + AI model + BLE transmitter |
| USB cable (for Arduino) | 1 | Programming only (before the demo) |
| Powerbank | 1 | Wireless power supply during gameplay |
| PC with Bluetooth | 1 | Runs the Python script and the game |

!!! success "No extra bridge needed"
    The Arduino Nano 33 BLE Sense has a **built-in BLE chip**, and most modern PCs have a **built-in Bluetooth adapter**. They communicate directly — no additional hardware required between them.

---

## The Arduino Nano 33 BLE Sense in detail

!!! info "Why this board?"
    The Arduino Nano 33 BLE Sense is the perfect board for this project because it natively includes:

    - A built-in **LSM9DS1 IMU** (3-axis accelerometer + 3-axis gyroscope)
    - A built-in **Bluetooth Low Energy (BLE) 5.0** chip
    - Enough memory to run a TinyML model from Edge Impulse

| Specification | Value |
|--------------|-------|
| Processor | ARM Cortex-M4 @ 64 MHz |
| RAM | 256 KB |
| Flash | 1 MB |
| Bluetooth | BLE 5.0 (built-in) |
| Accelerometer | ±2g / ±4g / ±8g / ±16g |
| Gyroscope | ±245 / ±500 / ±2000 dps |
| Power | 5V via USB or powerbank |

---

## PC requirements

| Requirement | Details |
|-------------|---------|
| Bluetooth | BLE-compatible adapter (built-in on most laptops) |
| Python | Version 3.8 or higher |
| Arduino IDE | Version 2.x (for uploading the sketch) |

### Python libraries to install

```bash
pip install bleak pynput
```

> `bleak` is the Python library used to receive BLE data from the Arduino.
> `pynput` is used to simulate keyboard key presses.

### Arduino libraries to install (via Arduino IDE Library Manager)

- `ArduinoBLE` — handles BLE communication
- `Arduino_LSM9DS1` — reads the IMU sensor
- Your exported Edge Impulse model (`.zip` file)

**Next step: [Wiring diagram](diagram.md)**
