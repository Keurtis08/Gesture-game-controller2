# Arduino Code

## What this code does

This code runs on the Arduino Nano 33 BLE Sense. It does 3 things:

1. **Reads** the IMU sensor data continuously (accelerometer + gyroscope)
2. **Classifies** the data using the Edge Impulse AI model to recognize a gesture
3. **Broadcasts** the detected gesture label wirelessly via Bluetooth BLE

The Arduino is powered by a powerbank and requires no USB connection to the PC during gameplay.

---

## Full code

```cpp
/*
 * Gesture Game Controller — Arduino Nano 33 BLE Sense
 * Arduino Days 2026 @ Semè City
 *
 * Reads IMU data, classifies hand gestures using an Edge Impulse
 * AI model, and sends the gesture label to the PC via BLE.
 */

#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>

// =====================================================
// REPLACE WITH YOUR EDGE IMPULSE MODEL HEADER
// Example: #include <gesture_model_inferencing.h>
// =====================================================

// BLE device name — must match the name in the Python script
#define BLE_DEVICE_NAME     "GestureController"

// Confidence threshold: only send if the model is at least 70% sure
#define CONFIDENCE_THRESHOLD 0.70

// BLE Service and Characteristic UUIDs
BLEService gestureService("180C");
BLEStringCharacteristic gestureChar("2A56", BLERead | BLENotify, 10);

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize IMU sensor
  if (!IMU.begin()) {
    Serial.println("ERROR: IMU sensor not found!");
    while (1);
  }

  // Initialize Bluetooth
  if (!BLE.begin()) {
    Serial.println("ERROR: Bluetooth initialization failed!");
    while (1);
  }

  BLE.setLocalName(BLE_DEVICE_NAME);
  BLE.setAdvertisedService(gestureService);
  gestureService.addCharacteristic(gestureChar);
  BLE.addService(gestureService);
  BLE.advertise();

  Serial.println("Arduino ready — advertising as: " BLE_DEVICE_NAME);
}

void loop() {
  BLEDevice central = BLE.central();

  // Wait for the PC to connect via Bluetooth
  if (central) {
    Serial.print("PC connected: ");
    Serial.println(central.address());
    digitalWrite(LED_BUILTIN, HIGH);  // LED on = connected

    while (central.connected()) {
      float ax, ay, az;

      if (IMU.accelerationAvailable()) {
        IMU.readAcceleration(ax, ay, az);

        // =====================================================
        // REPLACE this with your Edge Impulse inference call
        // The model should return the gesture label as a String
        // =====================================================
        String gesture = classifyGesture(ax, ay, az);

        if (gesture != "") {
          gestureChar.writeValue(gesture);  // Send via BLE
          Serial.print("Gesture sent: ");
          Serial.println(gesture);

          // Flash LED to confirm gesture was sent
          digitalWrite(LED_BUILTIN, LOW);
          delay(80);
          digitalWrite(LED_BUILTIN, HIGH);
        }
      }

      delay(50);  // ~20 readings per second
    }

    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("PC disconnected.");
  }
}

// Simplified tilt-based detection (replace with Edge Impulse model)
String classifyGesture(float ax, float ay, float az) {
  if (ay > 0.6)  return "UP";
  if (ay < -0.6) return "DOWN";
  if (ax < -0.6) return "LEFT";
  if (ax > 0.6)  return "RIGHT";
  return "";
}
```

---

## Key parts explained

### The BLE device name
```cpp
#define BLE_DEVICE_NAME "GestureController"
```
This is the name the Arduino broadcasts over Bluetooth. The Python script on the PC will search for exactly this name. **Both must match.**

### The BLE characteristic
```cpp
BLEStringCharacteristic gestureChar("2A56", BLERead | BLENotify, 10);
```
This is the "channel" through which the gesture label is sent. `BLENotify` means the PC is automatically notified every time a new gesture is written — no need to constantly ask for updates.

### The LED
The built-in LED stays **on** while the PC is connected, and **flashes** briefly each time a gesture is detected. This makes it easy to confirm everything is working during a demo.

### The confidence threshold
```cpp
#define CONFIDENCE_THRESHOLD 0.70
```
The Edge Impulse model outputs a confidence score between 0 and 1. Only gestures detected with at least 70% confidence are sent, which prevents accidental inputs.

**Next step: [Python Script](python.md)**
