# FAQ — Frequently Asked Questions

## The Python script cannot find the Arduino

**Likely cause:** Bluetooth is off on your PC, or the device name does not match.

**Solutions:**
1. Make sure Bluetooth is **enabled** on your PC
2. Make sure the Arduino is powered on (plugged into the powerbank)
3. Check that `BLE_DEVICE_NAME` in the Arduino code and `BLE_DEVICE_NAME` in the Python script are **exactly the same**, including capitalization

---

## The script finds the Arduino but disconnects immediately

**Likely cause:** The BLE characteristic UUID does not match.

**Solution:** Confirm that `GESTURE_CHAR_UUID` in the Python script matches the UUID defined in the Arduino code (`2A56` → full UUID: `00002a56-0000-1000-8000-00805f9b34fb`).

---

## Gestures are not recognized correctly

**Likely cause:** The AI model needs more training data.

**Solution:** Go back to Edge Impulse, add more examples for the gestures that are not working — especially in varied positions and speeds — then retrain and re-export the model.

---

## The Arduino LED does not light up

The LED stays on while the PC is connected via BLE. If it does not light up:

1. Check that the powerbank is turned on
2. Run the Python script on the PC — the LED lights up only when the PC is actively connected
3. Open the Arduino IDE Serial Monitor (while connected via USB) to see debug messages

---

## `pip install bleak` fails on Windows

Try running the command in an **Administrator** terminal, or use:

```bash
pip install --upgrade pip
pip install bleak pynput
```
