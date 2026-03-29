# About

## The project

**Gesture Game Controller** was built during **Arduino Days 2026** at **Semè City**, Bénin.

The challenge was to create an innovative interface between the human body and a video game, using embedded artificial intelligence running directly on a microcontroller.

---

## System architecture

```
Arduino Nano 33 BLE Sense   →   Bluetooth BLE   →   PC (Python + Game)
   (powered by powerbank)            ↑
                            No extra hardware needed
```

---

## Technologies used

| Technology | Role |
|------------|------|
| Arduino Nano 33 BLE Sense | Microcontroller with built-in IMU + BLE |
| Edge Impulse | TinyML model training and deployment |
| Bluetooth Low Energy (BLE) | Wireless gesture transmission |
| Python — bleak | BLE reception on the PC |
| Python — pynput | Keyboard simulation |

---

## About Semè City

[Semè City](https://semecity.bj) is an innovation and creativity hub in Bénin, dedicated to developing African talent in digital technology, design, and entrepreneurship.

---

## License

This project is released under the **MIT License** — free to use, modify, and share.

```
MIT License — Copyright 2026 — Arduino Days @ Semè City
```
