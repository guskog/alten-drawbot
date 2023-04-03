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

void setup()
{
  Serial.begin(9600);
  pinMode(xStep, OUTPUT);
  pinMode(xDir, OUTPUT);
  pinMode(yStep, OUTPUT);
  pinMode(yDir, OUTPUT);
  // Mega / ramps enable pins
  // pinMode(38, OUTPUT);
  // digitalWrite(38, LOW);
  // pinMode(A2, OUTPUT);
  // digitalWrite(A2, LOW);
}

void loop()
{
  rotateToAngle('x', 70);
  delay(1000);
  rotateToAngle('x', 10);
  delay(1000);
  rotateToAngle('y', 130);
  delay(1000);
  rotateToAngle('y', 40);
  delay(1000);
}

void rotateToAngle(char motor, int targetAngle)
{
  int dirPin;
  int stepPin;
  int currentAngle;
  switch (motor)
  {
    case 'x':
      Serial.println("Case X");
      dirPin = xDir;
      stepPin = xStep;
      currentAngle = xAngle;
      break;
    case 'y':
      Serial.println("Case Y");
      dirPin = yDir;
      stepPin = yStep;
      currentAngle = yAngle;
      break;
  }
  if (currentAngle < targetAngle)
  {
    digitalWrite(dirPin, HIGH);
    for (int step = currentAngle; step < targetAngle; step++)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
  }
  else if (currentAngle > targetAngle)
  {
    digitalWrite(dirPin, LOW);
    for (int step = currentAngle; step > targetAngle; step--)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
  }
  if (motor == 'x') {
    xAngle = targetAngle;
  }
  else if (motor == 'y') {
    yAngle = targetAngle;
  }
}