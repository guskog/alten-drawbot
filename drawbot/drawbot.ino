// Libraries
//#include <math>

// Constants
const float armAlength = 100;
const float armBlength = 200;

// Global variables
float angleAlfa = 0;  // elbow angle
float angleBeta = 0;  // shoulder angle

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Program start");

  anglesFromCoordinates(100, 110);
  Serial.println("100, 110");
  Serial.print("Angle Alfa: ");
  Serial.println(angleAlfa);
  Serial.print("Angle Beta: ");
  Serial.println(angleBeta);
  delay(3000);

  anglesFromCoordinates(70, 50);
  Serial.println("70, 50");
  Serial.print("Angle Alfa: ");
  Serial.println(angleAlfa);
  Serial.print("Angle Beta: ");
  Serial.println(angleBeta);
  delay(3000);

  anglesFromCoordinates(10, 210);
  Serial.println("10, 210");
  Serial.print("Angle Alfa: ");
  Serial.println(angleAlfa);
  Serial.print("Angle Beta: ");
  Serial.println(angleBeta);
  delay(3000);
}

void anglesFromCoordinates(float x, float y) {
  // Based on https://appliedgo.net/roboticarm/
  float hypotenuseLength = sqrt(x * x + y * y);
  float angleD1 = atan(y / x);  // angle of
  float angleD2 = acos((armBlength * armBlength + hypotenuseLength * hypotenuseLength - armAlength * armAlength) / (2 * armBlength * hypotenuseLength));
  angleAlfa = ((armAlength * armAlength + armBlength * armBlength) / (2 * armAlength * armBlength));
  angleBeta = angleD1 + angleD2;
}


/*
Milestones / codeparts 
1. Rotate motors
2. Rotate motors to specific angle (and keep track of the angle)
3. Calculate angles from coordinates
4. Rotate motors to correct angles based on coordinates
5. Interpolate between coordinates (segments) to get straight lines
*/