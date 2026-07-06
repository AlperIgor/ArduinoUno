#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TM1637Display.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);
#define Pin_X A0
#define Pin_Y A1
int playerX=0;
int playerY=0;
int bulletX=15;
int bulletY=0;
bool bulletActive=true;
int score=0;
unsigned long lastMoveTime=0;
int gameSpeed=50;
void setup() {
 lcd.init();
  lcd.backlight(); // put your setup code here, to run once:
display.setBrightness(0x0f);
display.showNumberDec(score);
lcd.setCursor(3,0);
lcd.print("Space Game");
delay(1500);
lcd.clear();


}

void loop() {
  int joyX= analogRead(Pin_X);
  int joyY= analogRead(Pin_Y);
  lcd.setCursor(playerX, playerY);
  lcd.print(" ");
  if(joyY < 300) playerY=0;
  if(joyY > 700) playerY=1;
  if(joyX<300 && playerX>0) playerX--;
   if(joyX>700 && playerX<15) playerX++;
   if(millis()-lastMoveTime>gameSpeed){
    lastMoveTime=millis();

    lcd.setCursor(bulletX, bulletY);
    lcd.print(" ");
    if(bulletActive){
      bulletX--;
      if(bulletX<0){
        score++;
        display.showNumberDec(score);
        bulletX=15;
        bulletY=random(0,2);
        if(gameSpeed>100) gameSpeed -=15;
      }
    }
   }
   if(playerX == bulletX && playerY == bulletY){
    lcd.clear();
    lcd.setCursor(3, 1);
    lcd.print("GAME OVER!");
    for(int i=0;i<3;i++){
      display.clear();
      delay(300);
      display.showNumberDec(score);
      delay(300);
    }
    score=0;
    gameSpeed=50;
    playerX=0;
    playerY=0;
    bulletX=15;
    bulletY=random(0,2);
    display.showNumberDec(score);
    lcd.clear();

   }
   lcd.setCursor(bulletX, bulletY);
   lcd.print("-");
   lcd.setCursor(playerX, playerY);
   lcd.print(">");
   delay(50);
  // put your main code here, to run repeatedly:

}
