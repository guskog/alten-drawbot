// Constants
const int stepsPerRevolution = 200;

// https://wokwi.com/projects/361017183449588737

// Pin definitions
// for RAMPS board from https://reprap.org/wiki/File:Arduinomegapololushieldschematic.png
int xStep = A0;
int xDir = A1;
int yStep = A6;
int yDir = A7;

// Global variables
int xAngle = 0;
int yAngle = 0;

unsigned long previousMotorTimeX = micros();
unsigned long previousMotorTimeY = micros();
long stepTimeX = 100;
long stepTimeY = 10;

int delayMicro = 20;
void setup() {
  Serial.begin(9600);
  pinMode(xStep, OUTPUT);
  pinMode(xDir, OUTPUT);
  pinMode(yStep, OUTPUT);
  pinMode(yDir, OUTPUT);
  // Mega / ramps enable pins
  pinMode(38, OUTPUT);
  digitalWrite(38, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
}

void loop() {
  unsigned long currentMotorTimeX = micros();
  unsigned long currentMotorTimeY = micros();
  rotateToAngle('x', 1000);
  // delay(1000);
  rotateToAngle('y', 1000);
  delay(100);
  // delay(1000);
  // rotateToAngle('y', 1300);
  // delay(1000);
  // rotateToAngle('y', 40);
  // delay(1000);
}

void rotateToAngle(char motor, int targetAngle) {
  int dirPin;
  int stepPin;
  int currentAngle;
  unsigned long currentMotorTime;
  unsigned long previousMotorTime;
  long stepTime;
  switch (motor) {
    case 'x':
      Serial.println("Case X");
      dirPin = xDir;
      stepPin = xStep;
      currentAngle = xAngle;
      currentMotorTime = micros();
      stepTime = stepTimeX;
      previousMotorTime = previousMotorTimeX;
      break;
    case 'y':
      Serial.println("Case Y");
      dirPin = yDir;
      stepPin = yStep;
      currentAngle = yAngle;
      currentMotorTime = micros();
      stepTime = stepTimeY;
      previousMotorTime = previousMotorTimeY;
      break;
  }
  // Choose direction
  if (currentAngle < targetAngle) {
    digitalWrite(dirPin, HIGH);
    currentAngle++;
  }
  if (currentAngle > targetAngle) {
    digitalWrite(dirPin, LOW);
    currentAngle--;
  }

  // Take Step if enough time has elapsed
  if (currentMotorTime - previousMotorTime > stepTime) {
    for (int i = 0; i < 1; i++) { // take 10 steps
      digitalWrite(stepPin, HIGH);
digitalWrite(stepPin, LOW);      
    }
    //digitalWrite(stepPin, HIGH);
    previousMotorTime = currentMotorTime;
    Serial.print("PreviousMotorTime: ");
    Serial.println(previousMotorTime);
  }
  digitalWrite(stepPin, LOW);

  // else if (currentAngle > targetAngle) {
  //   digitalWrite(dirPin, LOW);
  //   for (int step = currentAngle; step > targetAngle; step--) {
  //     // Serial.println("Ner");
  //     digitalWrite(stepPin, HIGH);
  //     delayMicroseconds(delayMicro);
  //     digitalWrite(stepPin, LOW);
  //     delayMicroseconds(delayMicro);
  //   }

  if (motor == 'x') {
    xAngle = currentAngle;
    Serial.print("xAngle: ");
    Serial.println(xAngle);        
    previousMotorTimeX = previousMotorTime;
  } else if (motor == 'y') {
    yAngle = currentAngle;
    previousMotorTimeY = previousMotorTime;
  }
}

void rotateMotor(char motor, int targetAngle) {
  int dirPin;
  int stepPin;
  int currentAngle;
  unsigned long currentMotorTime;
  unsigned long previousMotorTime;
  long stepTime;
  switch (motor) {
    case 'x':
      Serial.println("Case X");
      dirPin = xDir;
      stepPin = xStep;
      currentAngle = xAngle;
      currentMotorTime = micros();
      stepTime = stepTimeX;
      previousMotorTime = previousMotorTimeX;
      break;
    case 'y':
      Serial.println("Case Y");
      dirPin = yDir;
      stepPin = yStep;
      currentAngle = yAngle;
      currentMotorTime = micros();
      stepTime = stepTimeY;
      previousMotorTime = previousMotorTimeY;
      break;
  }
  // Choose direction
  if (currentAngle < targetAngle) {
    digitalWrite(dirPin, HIGH);
    currentAngle++;
  }
  if (currentAngle > targetAngle) {
    digitalWrite(dirPin, LOW);
    currentAngle--;
  }

  // Take Step if enough time has elapsed
  if (currentMotorTime - previousMotorTime > stepTime) {
    digitalWrite(stepPin, HIGH);
    previousMotorTime = currentMotorTime;
  }
  digitalWrite(stepPin, LOW);

  // else if (currentAngle > targetAngle) {
  //   digitalWrite(dirPin, LOW);
  //   for (int step = currentAngle; step > targetAngle; step--) {
  //     // Serial.println("Ner");
  //     digitalWrite(stepPin, HIGH);
  //     delayMicroseconds(delayMicro);
  //     digitalWrite(stepPin, LOW);
  //     delayMicroseconds(delayMicro);
  //   }

  if (motor == 'x') {
    xAngle = currentAngle;
    previousMotorTimeX = previousMotorTime;
  } else if (motor == 'y') {
    yAngle = currentAngle;
    previousMotorTimeY = previousMotorTime;
  }
}

/**
takeStepX()

takeStepY()

if (xAngle < xTargetAngle)
  if xTimeElapsed > timeBetweenSteps
    takeStepX(clockwise)

if (yAngle < xTargetAngle)
  if (yTimeElapsed > timeBetweenSteps)
      takeStepY(clockwise)



**/