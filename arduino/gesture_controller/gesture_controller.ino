/*
 * Gesture Game Controller — Arduino Nano 33 BLE Sense
 * Arduino Days 2026 @ Semè City
 *
 * TODO: Remplace ce fichier par votre vrai code Arduino
 * Colle ici le code complet que votre équipe a développé
 */

#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>
// #include <your_ei_model_inferencing.h>  ← décommente avec ton vrai modèle

#define BLE_DEVICE_NAME      "GestureController"
#define CONFIDENCE_THRESHOLD  0.70

BLEService gestureService("180C");
BLEStringCharacteristic gestureChar("2A56", BLERead | BLENotify, 10);

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  if (!IMU.begin()) { while (1); }
  if (!BLE.begin())  { while (1); }

  BLE.setLocalName(BLE_DEVICE_NAME);
  BLE.setAdvertisedService(gestureService);
  gestureService.addCharacteristic(gestureChar);
  BLE.addService(gestureService);
  BLE.advertise();
}

void loop() {
  BLEDevice central = BLE.central();
  if (central) {
    digitalWrite(LED_BUILTIN, HIGH);
    while (central.connected()) {
      float ax, ay, az;
      if (IMU.accelerationAvailable()) {
        IMU.readAcceleration(ax, ay, az);
        String gesture = classifyGesture(ax, ay, az);
        if (gesture != "") {
          gestureChar.writeValue(gesture);
        }
      }
      delay(50);
    }
    digitalWrite(LED_BUILTIN, LOW);
  }
}

String classifyGesture(float ax, float ay, float az) {
  if (ay > 0.6)  return "UP";
  if (ay < -0.6) return "DOWN";
  if (ax < -0.6) return "LEFT";
  if (ax > 0.6)  return "RIGHT";
  return "";
}
