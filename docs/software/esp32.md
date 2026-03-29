# Code ESP32 — Le pont BLE vers USB

## Rôle de ce code

L'ESP32 fait le lien entre l'Arduino et le PC. Il :

1. **Scanne** automatiquement le Bluetooth au démarrage
2. **Se connecte** à l'Arduino dès qu'il le trouve
3. **Retransmet** chaque geste reçu au PC via le câble USB

---

## Le code complet

```cpp
/*
 * Gesture Game Controller — ESP32 BLE to Serial Bridge
 * Arduino Days 2026 @ Semè City
 *
 * Ce code reçoit les gestes depuis l'Arduino via BLE
 * et les retransmet au PC via le port série USB.
 */

#include <BLEDevice.h>
#include <BLEClient.h>
#include <BLEScan.h>

// Doit correspondre EXACTEMENT au nom dans le code Arduino
#define TARGET_DEVICE_NAME "BLE_Data Riders"

// UUIDs du service et de la caractéristique (mêmes que dans Arduino)
#define SERVICE_UUID     "180C"
#define CHAR_UUID        "2A56"

BLEClient* pClient = nullptr;
BLERemoteCharacteristic* pChar = nullptr;
bool connected = false;

// Callback appelé à chaque nouveau geste reçu via BLE
void onGestureReceived(BLERemoteCharacteristic* pChar,
                       uint8_t* pData, size_t length, bool isNotify) {
  String gesture = String((char*)pData).substring(0, length);
  Serial.println(gesture); // Envoie au PC via USB
}

void setup() {
  Serial.begin(115200);
  BLEDevice::init("ESP32_Bridge");
  Serial.println("ESP32 prêt, recherche de l'Arduino...");
}

void loop() {
  if (!connected) {
    connectToArduino();
  }
  delay(100);
}

void connectToArduino() {
  BLEScan* pScan = BLEDevice::getScan();
  BLEScanResults results = pScan->start(5); // Scan pendant 5 secondes

  for (int i = 0; i < results.getCount(); i++) {
    BLEAdvertisedDevice device = results.getDevice(i);
    if (device.getName() == TARGET_DEVICE_NAME) {
      Serial.println("Arduino trouvé ! Connexion...");

      pClient = BLEDevice::createClient();
      pClient->connect(&device);

      BLERemoteService* pService = pClient->getService(SERVICE_UUID);
      if (pService) {
        pChar = pService->getCharacteristic(CHAR_UUID);
        if (pChar && pChar->canNotify()) {
          pChar->registerForNotify(onGestureReceived);
          connected = true;
          Serial.println("Connecté et en écoute !");
        }
      }
      break;
    }
  }
}
```

---

## Points clés du code

### La connexion automatique
Au démarrage, l'ESP32 scanne pendant 5 secondes. S'il trouve l'Arduino, il se connecte automatiquement. **Pas besoin d'appuyer sur un bouton.**

### Le callback `onGestureReceived`
C'est la fonction la plus importante. Elle est appelée **automatiquement** chaque fois que l'Arduino envoie un geste. Elle l'affiche immédiatement sur le port série.

### `Serial.println(gesture)`
Cette ligne envoie le geste vers le PC via USB. Le script Python de l'autre côté écoute exactement ce port et lit ces messages.

**Prochaine étape : [Script Python](python.md)**
