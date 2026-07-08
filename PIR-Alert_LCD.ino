
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int pirPin = 2;    
const int ledPin = 13;   

void setup() {
  pinMode(pirPin, INPUT);     
  pinMode(ledPin, OUTPUT);    
 
  lcd.init();                      
  lcd.backlight(); 
  
  lcd.setCursor(0, 0);
  lcd.print("Calibrating...");
  lcd.setCursor(0, 1);
  lcd.print("Please wait...");
  
  delay(15000); 
  lcd.clear();
}

void loop() {
  int motionStatus = digitalRead(pirPin); 

  if (motionStatus == HIGH) {            
    digitalWrite(ledPin, HIGH);          
    
    lcd.setCursor(0, 0);
    lcd.print("STATUS: ALERT!  "); 
    lcd.setCursor(0, 1);
    lcd.print("Motion Detected ");
    
    delay(200); 
  } else {
    digitalWrite(ledPin, LOW);           
    
    lcd.setCursor(0, 0);
    lcd.print("STATUS: QUIET  ");
    lcd.setCursor(0, 1);
    lcd.print("No motion      ");
    
    delay(200);
  }
}