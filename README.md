# 🎮 Gesture Game Controller

> Control any video game with hand gestures — no keyboard required.

Built during **Arduino Days 2026 @ Semè City** 🇧🇯

## 📖 Documentation website

👉 **[View the full documentation](https://TON_USERNAME.github.io/gesture-game-controller/)**

## Architecture

```
Hand movement → Arduino (IMU + AI) → BLE → Python (PC) → Game
```

## Hardware

| Component | Role |
|-----------|------|
| Arduino Nano 33 BLE Sense | IMU + Edge Impulse AI + BLE |
| Powerbank | Wireless power |
| PC with Bluetooth | Python script + game |

## Quick start

```bash
pip install bleak pynput
python python/gesture_controller.py
```

## License

MIT License — Arduino Days 2026 @ Semè City
