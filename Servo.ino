#include <Servo.h>
Servo myservo;
const int buttonPin=2;
int buttonState=0;
int lastButtonState=0;
bool isOpen=false;
void setup() {
 myservo.attach(9);
 myservo.write(91);
 pinMode(buttonPin, INPUT_PULLUP);
  // put your setup code here, to run once:

}

void loop() {
  buttonState=digitalRead(buttonPin);
  if(buttonState != lastButtonState){
    if(buttonState == HIGH){
      if(isOpen){
        myservo.write(45);
        delay(1000);
        myservo.write(91);
        isOpen=false;
      }
      else{
        myservo.write(135);
        delay(1000);
        myservo.write(91);
        isOpen=true;
      }
    }
    delay(50);
  }
  // put your main code here, to run repeatedly:
 lastButtonState = buttonState;
}
