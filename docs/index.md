# 🎮 Welcome to the Gesture Game Controller Documentation

Ever dreamed of controlling a video game with just your hand — no keyboard, no mouse, no controller?

The **Gesture Game Controller** is a project built during **Arduino Days 2026 at Semè City**. It uses embedded artificial intelligence to recognize hand movements in real time and transmit them wirelessly to a PC, which converts them into keyboard inputs for any game.

---

## How it works at a glance

```
Your hand moves
      ↓
Arduino Nano 33 BLE Sense   ← IMU sensor captures movement
  (powered by powerbank)    ← Edge Impulse AI classifies the gesture
      ↓  (Bluetooth BLE)
PC (built-in Bluetooth)     ← Python receives the gesture wirelessly
      ↓
Video Game                  ← Receives ⬆ ⬇ ⬅ ➡ like a real keyboard
```

---

## The 4 recognized gestures

| Hand movement | Simulated key |
|--------------|---------------|
| Tilt forward | ⬆ Arrow Up |
| Tilt backward | ⬇ Arrow Down |
| Tilt left | ⬅ Arrow Left |
| Tilt right | ➡ Arrow Right |

---

## System components

!!! info "Arduino Nano 33 BLE Sense"
    The brain of the project. It holds a built-in IMU sensor (accelerometer + gyroscope) and runs an AI model trained with Edge Impulse that classifies gestures in real time. It is powered by a **powerbank**, making it completely wireless. Detected gestures are sent to the PC via **Bluetooth Low Energy (BLE)**.

!!! success "Python Script on the PC"
    The action engine. It connects to the Arduino via the PC's built-in Bluetooth, receives the gesture labels wirelessly, and simulates the matching arrow key press using the `pynput` library. The game receives these inputs exactly as if they came from a real keyboard.

---

## Hardware summary

- **Arduino Nano 33 BLE Sense** + powerbank
- **PC** with Bluetooth, Python 3, and Arduino IDE installed

---

---

## See it in action

![Gesture Game Controller controlling Beach Buggy Racing in real time](images/demo-1.jpg)

*The Python script (left) logs every gesture detected. Beach Buggy Racing (right) reacts instantly — no keyboard touched.*

---

**Ready to get started? Head to the [Introduction](introduction.md)!** 🚀
