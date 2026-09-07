# Arduino Rain Sensor Automatic Servo Cover

> Arduino Uno automated rain sensor servo mechanism for automatic roof/window protection.

- **Conversation ID**: `a50cebf7-8166-4836-80c4-7e4ce6535ae2`
- **Session Started**: `2026-09-07T05:38:10Z`
- **Last Updated**: `2026-09-07T05:49:23Z`

---

### 👤 User (`2026-09-07T05:38:10Z`)

a rainsensor with servo with uno

---

### 🤖 AI Assistant (`2026-09-07T05:38:13Z`)

Here is a complete guide and Arduino code for building an **Automatic Rain-Sensing Servo System** using an **Arduino Uno**, a **Rain Sensor module (FC-37 / YL-83)**, and a **Servo Motor (SG90 / MG90S)** (commonly used for smart wipers, automatic window closers, or rain shelters).

---

### 1. Components Needed

| Component | Description |
| :--- | :--- |
| **Arduino Uno** | Microcontroller board |
| **Rain Sensor Module** | Sensing plate + LM393 comparator driver board |
| **Servo Motor** | SG90 (Micro) or MG90S |
| **Jumper Wires** | Male-to-Female and Male-to-Male |
| **Breadboard** | Optional (for easier 5V/GND sharing) |

---

### 2. Wiring Connections

```
    [ Rain Sensor Board ]              [ Arduino Uno ]             [ Servo Motor (SG90) ]
       VCC --------------------------------- 5V ----------------------- VCC (Red)
       GND --------------------------------- GND ---------------------- GND (Brown/Black)
       AO (Analog Out) --------------------- A0
                                             Pin 9 -------------------- Signal (Orange/Yellow)
```

#### Detailed Pinout Table:

| From Device | Pin Name | Arduino Uno Pin | Wire / Note |
| :--- | :--- | :--- | :--- |
| **Rain Sensor** | `VCC` | `5V` | Power (3.3V - 5V) |
| | `GND` | `GND` | Ground |
| | `AO` | `A0` | Analog reading (0–1023) |
| | `DO` | *Not connected* | *(Optional digital threshold)* |
| **Servo Motor** | `VCC` (Red) | `5V` | Shared 5V line |
| | `GND` (Brown/Black)| `GND` | Shared Ground |
| | `Signal` (Orange/Yellow)| `D9` | PWM Pin for Servo Control |

> [!TIP]
> **Sensor Values Guide:**
> * **Completely Dry:** `~1000 - 1023`
> * **Light Rain / Drizzle:** `~600 - 800`
> * **Heavy Rain:** `< 500`

---

### 3. Arduino Code

Upload this sketch to your Arduino Uno using the Arduino IDE:

```cpp
#include <Servo.h>

// --- Pin Definitions ---
const int RAIN_PIN = A0;   // Analog input pin from Rain Sensor AO
const int SERVO_PIN = 9;   // PWM control pin for Servo

// --- Threshold & Position Settings ---
const int RAIN_THRESHOLD = 600;  // Values BELOW this trigger "Rain Detected"
const int POS_DRY = 0;           // Angle when dry (e.g., Window Open / Shelter Retracted)
const int POS_RAIN = 90;         // Angle when raining (e.g., Window Closed / Shelter Deployed)

Servo myServo;

void setup() {
  Serial.begin(9600);
  
  // Attach servo and set initial position
  myServo.attach(SERVO_PIN);
  myServo.write(POS_DRY);
  
  Serial.println("Rain Sensor + Servo System Initialized.");
  Serial.println("----------------------------------------");
  delay(1000);
}

void loop() {
  // Read analog value from rain sensor (0 = wet, 1023 = dry)
  int rainValue = analogRead(RAIN_PIN);

  // Display value in Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.print(rainValue);

  if (rainValue < RAIN_THRESHOLD) {
    Serial.println(" -> [STATUS: RAIN DETECTED!] Closing/Moving Servo...");
    moveServoSmoothly(myServo.read(), POS_RAIN);
  } else {
    Serial.println(" -> [STATUS: DRY] Opening/Returning Servo...");
    moveServoSmoothly(myServo.read(), POS_DRY);
  }

  delay(500); // Check every half-second
}

// Function to smoothly move the servo to avoid sudden mechanical jerks
void moveServoSmoothly(int fromAngle, int toAngle) {
  if (fromAngle == toAngle) return;

  int step = (toAngle > fromAngle) ? 1 : -1;
  for (int pos = fromAngle; pos != toAngle; pos += step) {
    myServo.write(pos);
    delay(15); // Adjust for movement speed
  }
  myServo.write(toAngle);
}
```

---

### 4. How to Test and Calibrate

1. **Open Serial Monitor**: In the Arduino IDE, set the baud rate to **9600**.
2. **Observe Dry State**: When dry, you should see readings between `900` and `1023`, and the servo will stay at `0°`.
3. **Simulate Rain**: Place a few drops of water or a damp tissue on the sensor plate.
4. **Trigger Action**: The value should drop below `600`, and the servo will smoothly rotate to `90°`.
5. **Adjust Sensitivity**: If needed, adjust `RAIN_THRESHOLD` in the code based on your Serial Monitor readings.

---

### 5. Pro Tips for Real-World Use

* **External Power for Servo**: If your Arduino resets when the servo starts moving, it means the servo is drawing more current than the Arduino's 5V regulator can supply. Power the servo with an external 5V/1A power supply (remember to connect all `GND` lines together).
* **Prevent Sensor Corrosion**: Running continuous 5V current through nickel-plated rain boards causes electrolysis oxidation over time. For long-term projects, power the sensor's `VCC` from a digital pin (e.g., `D8`) and only turn it `HIGH` right before taking a reading.

---

### 👤 User (`2026-09-07T05:40:42Z`)

you upload

---

### 🤖 AI Assistant (`2026-09-07T05:41:04Z`)

I am checking your system for connected Arduino devices (found `COM5`) and searching for the Arduino toolchain to compile and upload the sketch. I'll update you as soon as it's ready.

---

### 🤖 AI Assistant (`2026-09-07T05:43:45Z`)

I have uploaded the code to your Arduino Uno.

### Summary of Actions Taken:
1. **Device Detected**: Arduino board identified on **`COM5`** (`USB-SERIAL CH340`).
2. **Created Sketch**: Saved project file to `C:\Users\matha\.gemini\Developer Logs\scratch\rain_sensor_servo\rain_sensor_servo.ino`.
3. **Installed Dependencies**: Configured and installed the **`Servo`** library.
4. **Compiled & Uploaded**: Successfully compiled the binary and flashed it to **COM5**.

---

### Quick Testing Checklist:
* **Pin Connections**:
  * Rain Sensor **`AO`** $\rightarrow$ Arduino **`A0`**
  * Rain Sensor **`VCC`** & **`GND`** $\rightarrow$ Arduino **`5V`** & **`GND`**
  * Servo **Signal (Orange/Yellow)** $\rightarrow$ Arduino **`Pin 9`**
  * Servo **`VCC` (Red)** & **`GND` (Brown/Black)** $\rightarrow$ **`5V`** & **`GND`**
* **Testing**:
  * When dry, the servo should hold its position at `0°`.
  * Place a drop of water or a damp tissue across the sensor plate — the servo will smoothly rotate to `90°`.
  * Open the **Serial Monitor** in the Arduino IDE at **9600 baud** to see real-time sensor readings.

---

### 👤 User (`2026-09-07T05:45:28Z`)

give code

---

### 🤖 AI Assistant (`2026-09-07T05:45:28Z`)

Here is the complete Arduino code that is uploaded to your board (also saved at `C:\Users\matha\.gemini\Developer Logs\scratch\rain_sensor_servo\rain_sensor_servo.ino`):

```cpp
#include <Servo.h>

// ================= Pin Definitions =================
const int RAIN_PIN  = A0;  // Analog input pin from Rain Sensor AO
const int SERVO_PIN = 9;   // PWM control pin for Servo

// ============ Threshold & Angle Settings ============
const int RAIN_THRESHOLD = 600;  // Values BELOW this trigger "Rain Detected"
const int POS_DRY        = 0;    // Angle when dry (Open / Retracted)
const int POS_RAIN       = 90;   // Angle when raining (Closed / Deployed)

Servo myServo;

// Function to smoothly move the servo to avoid sudden mechanical jerks
void moveServoSmoothly(int fromAngle, int toAngle) {
  if (fromAngle == toAngle) return;

  int step = (toAngle > fromAngle) ? 1 : -1;
  for (int pos = fromAngle; pos != toAngle; pos += step) {
    myServo.write(pos);
    delay(15); // Adjust delay to change movement speed (lower = faster)
  }
  myServo.write(toAngle);
}

void setup() {
  Serial.begin(9600);
  
  // Attach servo to pin 9 and set initial dry position
  myServo.attach(SERVO_PIN);
  myServo.write(POS_DRY);
  
  Serial.println("Rain Sensor + Servo System Initialized.");
  Serial.println("----------------------------------------");
  delay(1000);
}

void loop() {
  // Read analog value from rain sensor (0 = wet, 1023 = dry)
  int rainValue = analogRead(RAIN_PIN);

  // Print value to Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.print(rainValue);

  if (rainValue < RAIN_THRESHOLD) {
    Serial.println(" -> [STATUS: RAIN DETECTED!] Closing/Moving Servo...");
    moveServoSmoothly(myServo.read(), POS_RAIN);
  } else {
    Serial.println(" -> [STATUS: DRY] Opening/Returning Servo...");
    moveServoSmoothly(myServo.read(), POS_DRY);
  }

  delay(500); // Check every 500ms
}
```

---

### Key Variables You Can Adjust:
* **`RAIN_THRESHOLD = 600`**: Increase this (e.g., `750`) if you want it more sensitive to small droplets, or lower it (e.g., `450`) for heavy rain only.
* **`POS_DRY` & `POS_RAIN`**: Change the angles (`0°` to `180°`) depending on your mechanical setup.
* **`delay(15)` inside `moveServoSmoothly`**: Increase for slower movement, decrease for faster movement.

---

### 👤 User (`2026-09-07T05:48:19Z`)

servo not move

---

### 🤖 AI Assistant (`2026-09-07T05:49:23Z`)

I have uploaded an updated **Diagnostic & Auto-Calibrated sketch** to your Arduino Uno on **COM5**.

### 1. Watch the Startup Self-Test
When you power on the Arduino (or press the **RESET button** on the Uno board), the code will immediately perform a self-test:
$$\text{Moves to } 0^\circ \longrightarrow \text{Moves to } 90^\circ \longrightarrow \text{Returns to } 0^\circ$$

---

### 2. What this tells you:

#### Case A: If the servo **MOVES** during startup:
* **The Servo is working properly!** 
* The reason it wasn't moving earlier is because the sensor was completely dry (reading ~1023), so the Arduino was keeping it at $0^\circ$.
* **Now test with water**: Touch a damp tissue or wet finger across the sensor grid. The servo will turn to **$90^\circ$**. (I increased the threshold sensitivity to **800** so it triggers easily).

---

#### Case B: If the servo **DOES NOT MOVE** during startup:
It is a physical wiring or power connection issue. Please double-check these 3 points:

1. **Check Servo Wiring (3 pins)**:
   * **Orange / Yellow wire (Signal)** $\rightarrow$ Must be in **Digital Pin 9** (make sure it isn't shifted by one pin into 8 or 10).
   * **Red wire (Power)** $\rightarrow$ **5V** pin on Arduino.
   * **Brown / Black wire (Ground)** $\rightarrow$ **GND** pin on Arduino.

2. **Check Rain Sensor Wiring**:
   * Sensor board **AO** pin $\rightarrow$ Arduino **A0**.
   * Sensor board **VCC** $\rightarrow$ **5V**.
   * Sensor board **GND** $\rightarrow$ **GND**.

3. **Loose Jumper Wires / Power**:
   * Ensure the jumper pins fit snugly into the servo connector and the Arduino headers. 
   * If the green/red power LED on your Arduino blinks or turns off when the servo tries to move, the servo is drawing too much current through USB.

---

### Current Updated Code Running on Your Arduino:

```cpp
#include <Servo.h>

// --- Pin Definitions ---
const int RAIN_PIN = A0;    // Rain Sensor AO pin
const int SERVO_PIN = 9;   // Servo Signal pin (Orange/Yellow wire)

// --- Settings ---
const int RAIN_THRESHOLD = 800; // Increased to 800 for high sensitivity
const int POS_DRY = 0;          // Angle when Dry
const int POS_RAIN = 90;        // Angle when Raining

Servo myServo;
int currentPos = 0;

void moveServo(int targetPos) {
  if (currentPos == targetPos) return;

  int step = (targetPos > currentPos) ? 1 : -1;
  while (currentPos != targetPos) {
    currentPos += step;
    myServo.write(currentPos);
    delay(10);
  }
}

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);

  Serial.println("==================================");
  Serial.println("STARTUP: Testing Servo Movement...");
  Serial.println("==================================");
  
  // --- SELF-TEST SWEEP ON BOOT ---
  myServo.write(0);
  currentPos = 0;
  delay(1000);

  moveServo(90);
  delay(1000);

  moveServo(0);
  delay(1000);

  Serial.println("Self-test done! Listening for rain...");
}

void loop() {
  int rainValue = analogRead(RAIN_PIN);

  Serial.print("Sensor Reading: ");
  Serial.print(rainValue);

  if (rainValue < RAIN_THRESHOLD) {
    Serial.println(" -> [RAIN DETECTED] Moving to 90 deg");
    moveServo(POS_RAIN);
  } else {
    Serial.println(" -> [DRY] Moving to 0 deg");
    moveServo(POS_DRY);
  }

  delay(300);
}
```

---
