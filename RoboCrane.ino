#include <Servo.h>

Servo myServo;

const int joystickX = A0; 
int joystickValue = 0;    
int servoSpeed = 91;      

void setup() {
  myServo.attach(11);     
  myServo.write(servoSpeed); 
  Serial.begin(9600);     
}

void loop() {
  
  joystickValue = analogRead(joystickX);
servoSpeed = map(joystickValue, 0, 1023, 0, 180);
if (servoSpeed >= 88 && servoSpeed <= 94) {
    servoSpeed = 91; 
  }
myServo.write(servoSpeed);
Serial.print("Joystick: ");
  Serial.print(joystickValue);
  Serial.print(" -> Servo Command: ");
  Serial.println(servoSpeed);

  delay(20);
}
