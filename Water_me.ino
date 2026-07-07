#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int sensorPin = A0; 

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED дисплей не найден!"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(15, 20);
  display.print("Flower Monitor");
  display.display();
  delay(2000);
}

void loop() {
  int rawValue = analogRead(sensorPin);
  
  int moisturePercent = map(rawValue, 1023, 200, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  display.clearDisplay();


  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("MOISTURE:");


  display.setTextSize(3);
  display.setCursor(0, 16);
  display.print(moisturePercent);
  display.print("%");

 
  display.setTextSize(1);
  display.setCursor(0, 52);
  
  if (moisturePercent < 30) {
    display.print("STATUS: NEED WATER! :("); 
  } else if (moisturePercent >= 30 && moisturePercent < 70) {
    display.print("STATUS: GOOD :)");        
  } else {
    display.print("STATUS: VERY WET :O");    
  }

  display.display();

  delay(1000);
}
