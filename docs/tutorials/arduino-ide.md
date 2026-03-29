# Install Arduino IDE

## Step 1 — Download Arduino IDE 2

Go to [arduino.cc/en/software](https://www.arduino.cc/en/software) and download version **2.x** for your OS.

---

## Step 2 — Add support for the Nano 33 BLE Sense

1. Open Arduino IDE
2. Go to **Tools → Board → Boards Manager**
3. Search for `Arduino Mbed OS Nano Boards`
4. Click **Install**

---

## Step 3 — Install the required libraries

Go to **Tools → Manage Libraries** and install:

- `ArduinoBLE` — handles Bluetooth BLE communication
- `Arduino_LSM9DS1` — reads the built-in IMU sensor

Then install your Edge Impulse model:

1. Go to **Sketch → Include Library → Add .ZIP Library**
2. Select the `.zip` file you exported from Edge Impulse

**Next step: [Train the AI model](edge-impulse.md)**
