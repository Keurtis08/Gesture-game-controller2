# Train the AI Model on Edge Impulse

## What is Edge Impulse?

[Edge Impulse](https://edgeimpulse.com) is a free platform for building AI models that run on microcontrollers. It handles all the complexity of machine learning for you.

---

## Steps

### 1. Create an account
Go to [studio.edgeimpulse.com](https://studio.edgeimpulse.com) and sign up for free.

### 2. Create a new project
Click **Create new project** → choose **Accelerometer data** as the project type.

### 3. Collect gesture data
Connect your Arduino and use Edge Impulse's data collection tool to record examples of each gesture:

- **UP** — 30+ examples of tilting forward
- **DOWN** — 30+ examples of tilting backward
- **LEFT** — 30+ examples of tilting left
- **RIGHT** — 30+ examples of tilting right
- **IDLE** — 30+ examples of the hand still

!!! tip "More data = better accuracy"
    Record gestures in different positions and at different speeds. The more varied your examples, the more robust the model will be.

### 4. Design and train the model
Go to **Impulse Design** → configure the signal processing and learning blocks → click **Train**.

### 5. Export as Arduino library
Go to **Deployment** → select **Arduino library** → click **Build** → download the `.zip` file.

### 6. Install in Arduino IDE
**Sketch → Include Library → Add .ZIP Library** → select the downloaded file.

**Next step: [Run the project](run.md)**
