# Wiring Diagram

## Overview

The setup is entirely wireless during gameplay. The only physical connection is between the **Arduino and the powerbank**.

```
┌──────────────────────────────┐
│   Arduino Nano 33 BLE Sense  │
│                              │
│   [Built-in IMU sensor]      │
│   [Edge Impulse AI model]    │
│   [Built-in BLE 5.0 chip]   │
│                              │
│              │               │
│        USB cable             │
│              │               │
│          Powerbank           │
│       (power supply)         │
└──────────────────────────────┘
            ↕ Bluetooth BLE (wireless)
┌──────────────────────────────┐
│            PC                │
│   [Built-in Bluetooth]       │
│   Python script running      │
│   Game running               │
└──────────────────────────────┘
```

---

## Connection table

| From | To | Connection type | Purpose |
|------|----|----------------|---------|
| Arduino Nano 33 BLE Sense | Powerbank | USB cable | Power supply |
| Arduino Nano 33 BLE Sense | PC | Bluetooth BLE (wireless) | Gesture data |

---

## Setup steps before playing

**Before the demo** (done once):
1. Connect the Arduino to your PC via USB cable
2. Upload the Arduino sketch using Arduino IDE
3. Disconnect the USB cable from the PC

**During the demo**:
1. Plug the Arduino into the **powerbank** via USB cable
2. Run the Python script on the PC — it will scan for the Arduino via Bluetooth and connect automatically
3. Open the game and start playing 🎮

!!! warning "Make sure Bluetooth is enabled on your PC"
    Before running the Python script, check that Bluetooth is turned on in your PC's settings. The script will fail to find the Arduino if Bluetooth is off.

**Next step: [Arduino Code](../software/arduino.md)**
