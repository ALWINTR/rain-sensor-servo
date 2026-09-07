#include <Servo.h>

// --- Pin Definitions ---
const int RAIN_PIN = A0;    // Rain Sensor AO pin
const int SERVO_PIN = 9;    // Servo Signal pin (Orange/Yellow wire)

// --- Settings ---
const int RAIN_THRESHOLD = 800; // Rain trigger (increased to 800 for easier triggering)
const int POS_DRY = 0;             // Angle when Dry
const int POS_RAIN = 90;          // Angle when Raining

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

  Serial.println("====================================");
  Serial.println("STARTUN: Testing Servo Movement...");
  Serial.println("====================================");
  
  // --- SELN TEST MOVEMENT ---
  // This will spin the servo on startup so you know it works!
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
    Serial.println(" -> [RAIN DE TECTED] Moving to 90 °");
    moveServo(POS_RAIN);
  } else {
    Serial.println(" -> [DRY] Moving to 0 °");
    moveServo(POS_DRY);
  }

  delay(300);
}
