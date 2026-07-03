#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16 ,2);
const int trigPin =12;
const int echoPin=11;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" RADAR SYSTEM ");
  delay(1500);
  lcd.clear();
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration * 0.034/2;
  lcd.setCursor(0, 0);
  lcd.print("Distance:    ");
  lcd.setCursor(10, 0);
  if(distance>=400 || distance<=0){lcd.print("---  ");}
  else{lcd.print(distance);
  lcd.print(" cm ");
  }
  delay(200);
  // put your main code here, to run repeatedly:

}
