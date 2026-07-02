#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
const int sensorPin =2;
int sensorState = LOW;
int lastSensorState = LOW;
bool isOpen=false;
int green=13;
int red=12;
void setup() {
  myservo.attach(9);
  myservo.write(91);
  pinMode(sensorPin, INPUT);
    lcd.init();
  lcd.backlight();
  pinMode(green,OUTPUT);
 pinMode(red,OUTPUT);
 digitalWrite(red, HIGH);
 digitalWrite(green, LOW);
 lcd.setCursor(0,0);
 lcd.print("LOCKED");
 
  // put your setup code here, to run once:

}

void loop() {
  sensorState=digitalRead(sensorPin);
  if(sensorState !=lastSensorState){
    if(sensorState==HIGH){
      if(isOpen){
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
        lcd.setCursor(0,0);
        lcd.print("LOCKED");
        myservo.write(47);
        delay(220);
        myservo.write(91);
        isOpen=false;
      }
      else{
        digitalWrite(red, LOW);
        digitalWrite(green,HIGH);
        lcd.setCursor(0,0);
        lcd.print("OPENED");
        myservo.write(135);
        delay(220);
        myservo.write(91);
        isOpen=true;
      }
    }
    delay(50);
  }
 lastSensorState=sensorState;
  // put your main code here, to run repeatedly:

}
