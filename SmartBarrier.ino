#include <Servo.h>

// Настройки пинов
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;


const int openDistance = 15;


const int servoStop = 91;   
const int servoUp = 71;      
const int servoDown = 111;   


const int moveTime = 600; 

Servo barrierServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  barrierServo.attach(servoPin);
  barrierServo.write(servoStop); 
  
  Serial.begin(9600);
}

void loop() {
  int distance = getDistance();
  
  Serial.print("Дистанция: ");
  Serial.print(distance);
  Serial.println(" см");


  if (distance > 0 && distance <= openDistance) {
    Serial.println("Машина тут! Поднимаю стрелу...");
    
    barrierServo.write(servoUp);  
    delay(moveTime);               
    barrierServo.write(servoStop); 
    
    
    delay(5000); 
    
    Serial.println("Опускаю стрелу...");
    barrierServo.write(servoDown); 
    delay(moveTime);              
    barrierServo.write(servoStop); 
   
    delay(2000); 
  }
  
  delay(200); 
}


int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return 999;
  
  return duration * 0.034 / 2;
}