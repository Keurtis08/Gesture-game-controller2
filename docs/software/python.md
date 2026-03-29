# Python Script

## What this script does

This script runs on the PC and is the final piece of the system:

1. **Scans** for the Arduino over Bluetooth BLE
2. **Connects** automatically when it finds it
3. **Receives** gesture labels wirelessly in real time
4. **Simulates** the matching arrow key press using `pynput`

---

## Full script

```python
"""
Gesture Game Controller — Python Script
Arduino Days 2026 @ Semè City

Connects to the Arduino via Bluetooth BLE, receives gesture labels,
and simulates the corresponding arrow key presses on the PC.
"""

import asyncio
from bleak import BleakScanner, BleakClient
from pynput.keyboard import Key, Controller

# ======================================================
# CONFIGURATION — must match the Arduino code
# ======================================================
BLE_DEVICE_NAME = "GestureController"   # Arduino BLE name
GESTURE_CHAR_UUID = "00002a56-0000-1000-8000-00805f9b34fb"
# ======================================================

# Map each gesture label to an arrow key
GESTURE_MAP = {
    "UP":    Key.up,
    "DOWN":  Key.down,
    "LEFT":  Key.left,
    "RIGHT": Key.right,
}

keyboard = Controller()

def simulate_key(gesture: str):
    """Press and release the arrow key matching the gesture."""
    key = GESTURE_MAP.get(gesture.strip())
    if key:
        keyboard.press(key)
        asyncio.get_event_loop().call_later(0.05, keyboard.release, key)
        print(f"Key pressed: {gesture} → {key}")

def on_gesture_received(sender, data: bytearray):
    """Called automatically every time the Arduino sends a gesture."""
    gesture = data.decode("utf-8").strip()
    if gesture in GESTURE_MAP:
        simulate_key(gesture)

async def main():
    print(f"Scanning for Arduino '{BLE_DEVICE_NAME}' via Bluetooth...")

    # Scan for the Arduino
    device = await BleakScanner.find_device_by_name(BLE_DEVICE_NAME)
    if device is None:
        print(f"ERROR: Could not find '{BLE_DEVICE_NAME}'.")
        print("Make sure the Arduino is powered on and Bluetooth is enabled on your PC.")
        return

    print(f"Found: {device.name} ({device.address})")
    print("Connecting...")

    async with BleakClient(device) as client:
        print("Connected! Waiting for gestures...\n")

        # Subscribe to gesture notifications
        await client.start_notify(GESTURE_CHAR_UUID, on_gesture_received)

        # Keep the script running
        while client.is_connected:
            await asyncio.sleep(0.1)

    print("Disconnected.")

if __name__ == "__main__":
    asyncio.run(main())
```

---

## How to run the script

### Step 1 — Install dependencies
```bash
pip install bleak pynput
```

### Step 2 — Enable Bluetooth on your PC
Make sure Bluetooth is turned **on** in your PC's settings before running the script.

### Step 3 — Power on the Arduino
Plug the Arduino into the **powerbank**. The built-in LED will light up when the PC connects.

### Step 4 — Run the script
```bash
python gesture_controller.py
```

You should see:
```
Scanning for Arduino 'GestureController' via Bluetooth...
Found: GestureController (AA:BB:CC:DD:EE:FF)
Connecting...
Connected! Waiting for gestures...

Key pressed: UP → Key.up
Key pressed: RIGHT → Key.right
```

### Step 5 — Play!
Open any arrow-key game and move your hand. 🎮

---

## Gesture-to-key mapping

| BLE message received | Simulated key |
|---------------------|---------------|
| `UP` | Arrow Up ⬆ |
| `DOWN` | Arrow Down ⬇ |
| `LEFT` | Arrow Left ⬅ |
| `RIGHT` | Arrow Right ➡ |
