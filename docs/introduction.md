# Introduction

## The problem

Video games have always relied on keyboards or controllers for input. It works, but it is not natural for the human body.

**What if you could play just by moving your hand?**

That was the challenge presented at **Arduino Days 2026 at Semè City**: build an interface between the human body and a video game using embedded artificial intelligence.

---

## Our solution

We designed a two-part system that works together in real time:

### 1. Movement capture & wireless transmission — Arduino Nano 33 BLE Sense

The Arduino Nano 33 BLE Sense carries a built-in **IMU** (Inertial Measurement Unit) that continuously measures:

- **Accelerometer**: detects orientation and changes in speed across 3 axes
- **Gyroscope**: measures the rotation of the hand across 3 axes

These raw sensor values are fed into an **AI model trained on Edge Impulse**, which classifies the hand position into one of 4 gestures with a high confidence score. When a gesture is detected, the Arduino immediately broadcasts its label (`UP`, `DOWN`, `LEFT`, or `RIGHT`) over **Bluetooth Low Energy (BLE)**.

The Arduino is powered by a **powerbank**, so it is completely wireless and can be held freely in the hand during gameplay.

### 2. Keyboard simulation — Python Script

A Python script runs in the background on the PC. It:

- Connects to the Arduino via the **PC's built-in Bluetooth**
- Receives gesture labels wirelessly in real time
- Simulates the matching **arrow key press** using the `pynput` library

The game receives those key presses exactly as if they came from a real keyboard — **no modification to the game required**.

---

## Why is this interesting?

!!! tip "What is embedded AI (TinyML)?"
    Unlike AI running on a remote server (like ChatGPT), embedded AI runs **directly on the Arduino chip** with no internet connection. This is called **TinyML** (Machine Learning on microcontrollers).

    Gesture recognition happens in a few milliseconds, with no network latency, and using very little power — the whole device runs on a small powerbank.

!!! note "What is Edge Impulse?"
    [Edge Impulse](https://edgeimpulse.com) is the free platform we used to train our model. It lets you collect IMU sensor data, train a neural network, and export it directly as an Arduino library ready to deploy.

!!! info "What is Bluetooth Low Energy (BLE)?"
    BLE is a wireless communication protocol designed for low power consumption. The Arduino Nano 33 BLE Sense has a BLE chip built in, and most modern PCs and laptops also have a BLE-compatible Bluetooth adapter. No extra hardware is needed on the PC side.

---

## What you will learn in this documentation

- How each component of the system works
- How to set up and connect everything
- How the AI model was trained on Edge Impulse
- How to install and run the project yourself

**Next step: [Components list](hardware/list.md)**
