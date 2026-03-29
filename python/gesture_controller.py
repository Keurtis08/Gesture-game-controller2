"""
Gesture Game Controller — Python Script
Arduino Days 2026 @ Semè City

TODO: Remplace ce fichier par votre vrai script Python
Colle ici le code complet que votre équipe a développé
"""

import asyncio
from bleak import BleakScanner, BleakClient
from pynput.keyboard import Key, Controller

BLE_DEVICE_NAME   = "GestureController"
GESTURE_CHAR_UUID = "00002a56-0000-1000-8000-00805f9b34fb"

GESTURE_MAP = {
    "UP":    Key.up,
    "DOWN":  Key.down,
    "LEFT":  Key.left,
    "RIGHT": Key.right,
}

keyboard = Controller()

def simulate_key(gesture: str):
    key = GESTURE_MAP.get(gesture.strip())
    if key:
        keyboard.press(key)
        asyncio.get_event_loop().call_later(0.05, keyboard.release, key)
        print(f"Key pressed: {gesture} → {key}")

def on_gesture_received(sender, data: bytearray):
    gesture = data.decode("utf-8").strip()
    if gesture in GESTURE_MAP:
        simulate_key(gesture)

async def main():
    print(f"Scanning for '{BLE_DEVICE_NAME}'...")
    device = await BleakScanner.find_device_by_name(BLE_DEVICE_NAME)
    if device is None:
        print("ERROR: Arduino not found. Check Bluetooth is ON.")
        return
    print(f"Found! Connecting to {device.address}...")
    async with BleakClient(device) as client:
        print("Connected! Waiting for gestures...\n")
        await client.start_notify(GESTURE_CHAR_UUID, on_gesture_received)
        while client.is_connected:
            await asyncio.sleep(0.1)

if __name__ == "__main__":
    asyncio.run(main())
