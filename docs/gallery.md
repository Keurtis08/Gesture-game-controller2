# Project Gallery

The photos below show the **Gesture Game Controller** in action during **Arduino Days 2026 at Semè City**.

On the left side of each screenshot you can see the Python script running in the terminal, displaying every key press in real time. On the right side, the game **Beach Buggy Racing** reacts instantly to each hand gesture.

---

## Demo — Python script + Beach Buggy Racing

### The Python script sending commands to the game

![Python script sending UP, DOWN, LEFT, RIGHT commands while Beach Buggy Racing responds](images/demo-1.jpg)

*The terminal shows every gesture detected: UP (Acceleration), DOWN (Braking), LEFT (Turn left), RIGHT (Turn right). The game reacts in real time.*

---

![Close-up view of the Python script output alongside the racing game](images/demo-2.jpg)

*Each line in the terminal corresponds to a key press sent to the game. The timestamps confirm the real-time responsiveness of the system.*

---

![The car turning in Beach Buggy Racing while the Python script logs the gesture](images/demo-3.jpg)

*When a LEFT or RIGHT gesture is detected, the buggy steers accordingly — no keyboard involved.*

---

![Python script running a detailed test sequence with the game active](images/demo-4.jpg)

*The script runs a full test sequence: acceleration, braking, left turn, right turn — all triggered by hand movements.*

---

![Final test run showing the complete gesture-to-game pipeline working](images/demo-5.jpg)

*The complete pipeline working end-to-end: gesture detected → Python receives it → Beach Buggy Racing responds.*

---

## What the terminal output means

| Terminal message | Meaning |
|-----------------|---------|
| `Enfoncé : HAUT (Accélération) pendant 3.0s` | UP gesture → Arrow Up pressed 3s |
| `Enfoncé : BAS (Freinage) pendant 4.0s` | DOWN gesture → Arrow Down pressed 4s |
| `Enfoncé : GAUCHE (Virage) pendant 2.0s` | LEFT gesture → Arrow Left pressed 2s |
| `Enfoncé : DROITE (Virage) pendant 2.0s` | RIGHT gesture → Arrow Right pressed 2s |
| `Relâché. Attente de 1.0s...` | Key released, waiting 1s before next gesture |
