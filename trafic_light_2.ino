#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int green=13;
int yellow=12;
int red=11;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
}

void loop() {
digitalWrite(green,LOW);
digitalWrite(yellow,LOW);
digitalWrite(red,HIGH);
lcd.setCursor(5,0);
lcd.print("STOP!");
delay(2000);
digitalWrite(green,LOW);
digitalWrite(yellow,HIGH);
digitalWrite(red,LOW);
lcd.clear();
lcd.setCursor(5,0);
lcd.print("WAIT");
delay(1000);
digitalWrite(green,HIGH);
digitalWrite(yellow,LOW);
digitalWrite(red,LOW);
lcd.clear();
lcd.setCursor(6,0);
lcd.print("GO!");
delay(2000);
lcd.clear();


  // put your main code here, to run repeatedly:

}
