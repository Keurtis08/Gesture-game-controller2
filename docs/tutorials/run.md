# Run the Project

## Prerequisites

- Arduino IDE installed with all required libraries
- Edge Impulse model exported and installed as an Arduino library
- Python installed with `bleak` and `pynput`
- Bluetooth enabled on your PC

---

## Step 1 — Upload the sketch to the Arduino

1. Open `arduino/gesture_controller/gesture_controller.ino` in Arduino IDE
2. Select **Tools → Board → Arduino Nano 33 BLE Sense**
3. Select the correct **COM port** under Tools → Port
4. Click **Upload** (the → arrow)
5. Wait for "Upload complete"
6. **Disconnect the Arduino from the PC** — plug it into the **powerbank** instead

## Step 2 — Install Python dependencies

```bash
pip install bleak pynput
```

## Step 3 — Run the Python script

```bash
python python/gesture_controller.py
```

The script will scan for the Arduino automatically and connect when it finds it.

## Step 4 — Play!

Open any arrow-key-based game and move your hand. 🎮

---

!!! success "Working correctly?"
    In the terminal you should see gestures appearing as you move your hand:
    ```
    Connected! Waiting for gestures...

    Key pressed: UP → Key.up
    Key pressed: LEFT → Key.left
    ```

!!! warning "Issues?"
    Check the [FAQ](../faq.md) for common problems and solutions.
