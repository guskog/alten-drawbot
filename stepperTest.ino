// Constants
const int stepsPerRevolution = 200;

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
  pinMode(xStep, OUTPUT);
  pinMode(xDir, OUTPUT);
  pinMode(yStep, OUTPUT);
  pinMode(yDir, OUTPUT);
}

void loop()
{
  rotateToAngle(70);
  delay(1000);
  rotateToAngle(10);
  delay(1000);
}

void rotateToAngle(int targetAngle)
{
  if (xAngle < targetAngle)
  {
    digitalWrite(xDir, HIGH);
    for (int step = xAngle; step < targetAngle; step++)
    {
      digitalWrite(xStep, HIGH);
      delayMicroseconds(2000);
      digitalWrite(xStep, LOW);
      delayMicroseconds(2000);
    }
    xAngle = targetAngle;
    return;
  }
  else if (xAngle > targetAngle)
  {
    digitalWrite(xDir, LOW);
    for (int step = xAngle; step > targetAngle; step--)
    {
      digitalWrite(xStep, HIGH);
      delayMicroseconds(2000);
      digitalWrite(xStep, LOW);
      delayMicroseconds(2000);
    }
    xAngle = targetAngle;
    return;
  }
}

