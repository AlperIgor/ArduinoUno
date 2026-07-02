#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FluxGarage_RoboEyes.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

// Создаем объекты для дисплея и глаз
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RoboEyes<Adafruit_SSD1306> eyes(display);

unsigned long lastEmotionChange = 0;
int currentEmotion = 0;

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;); 
  }
  
  display.clearDisplay();
  display.display();

  eyes.begin(128, 64, 30);
  
 
  eyes.setAutoblinker(true, 2000, 4000);
  
 
  eyes.setMood(DEFAULT);
}

void loop() {
  display.clearDisplay();
  
 
  if (millis() - lastEmotionChange >= 4000) {
    lastEmotionChange = millis();
    
    currentEmotion++;
    if (currentEmotion > 3) currentEmotion = 0; 
    
    switch (currentEmotion) {
      case 0:
        eyes.setMood(DEFAULT);
        break;
      case 1:
        eyes.setMood(TIRED);
        break;
      case 2:
        eyes.setMood(ANGRY);
        break;
      case 3:
        eyes.setMood(HAPPY);
        break;
    }
  }

  eyes.update(); 
  display.display(); 
}