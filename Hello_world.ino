#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(2, 0);
  lcd.print("Hello, world");
  delay(1000);
  lcd.setCursor(6, 1);
  lcd.print("I'm");
  delay(2000);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Igor Alper");
  delay(1000);
  lcd.setCursor(6, 1);
  lcd.print("and");
  delay(2000);
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("I");
  delay(1000);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("started");
  delay(1000);
  lcd.clear();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
