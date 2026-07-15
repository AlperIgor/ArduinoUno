#include<Arduino.h>
#include<TM1637Display.h>
#include<Servo.h>


#define CLK 4
#define DIO 3
TM1637Display display(CLK, DIO);

Servo lockServo;
const int servoPin=11;

const int pinX=A0;
const int pinY=A1;
const int pinBtn=2;

const int ledGreen=13;
const int ledRed=12;

int correctCode[4]={1,2,3,4};
int userCode[4]={0,0,0,0};
int activeDigit=0;

bool isLocked=true;
unsigned long lastMoveTime=0;
const int debounceDelay=300;

void updateDisplay(){
  display.showNumberDec(userCode[0]*1000+userCode[1]*100+userCode[2]*10+userCode[3], 0, true);
}
void setup() {
  Serial.begin(9600);
  lockServo.attach(servoPin);
  lockServo.write(91);

  pinMode(pinBtn,INPUT_PULLUP);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed,OUTPUT);

  display.setBrightness(0x0f);
  updateDisplay();

  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  // put your setup code here, to run once:

}

void loop() {
  int xVal=analogRead(pinX);
  int yVal=analogRead(pinY);
  bool bthPressed=!digitalRead(pinBtn);

  if(millis()-lastMoveTime>debounceDelay){
    if(yVal>800){
      userCode[activeDigit]++;
      if(userCode[activeDigit]>9) userCode[activeDigit]=0;
      updateDisplay();
      lastMoveTime=millis();
    }
    else if (yVal<200){
      userCode[activeDigit]--;
      if (userCode[activeDigit]<0) userCode[activeDigit]=9;
      updateDisplay();
      lastMoveTime=millis();
    }
    if(xVal>800){
      activeDigit++;
      if(activeDigit<0) activeDigit=3;
      lastMoveTime=millis();
    }
    else if (xVal<200){
      activeDigit--;
      if(activeDigit<0) activeDigit=3;
      lastMoveTime=millis();
    }
  }
  if(bthPressed && (millis()-lastMoveTime>500)){
    lastMoveTime=millis();
    if(isLocked){
      bool codeMatch=true;
      for(int i=0;i<4;i++){
        if(userCode[i] !=correctCode[i]){
          codeMatch=false;
        }
      }
      if (codeMatch){
        digitalWrite(ledRed,LOW);
        digitalWrite(ledGreen,HIGH);
        lockServo.write(120);
        delay(2000);
        lockServo.write(91);
        isLocked=false;
      }
      else{
        for(int i=0;i<3;i++){
          digitalWrite(ledRed,LOW);
          delay(150);
          digitalWrite(ledRed,HIGH);
          delay(150);
        }
        for(int i=0;i<4;i++) userCode[i]=0;
        activeDigit=0;
        updateDisplay();
      }
    }
    else{
      digitalWrite(ledGreen,LOW);
      digitalWrite(ledRed,HIGH);
      lockServo.write(50);
      delay(200);
      lockServo.write(91);
      for(int i=0;i<4;i++) userCode[i]=0;
      activeDigit=0;
      updateDisplay();
      isLocked=true;
    }
  }

  // put your main code here, to run repeatedly:

}
