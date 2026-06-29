#include <Wire.h>
#include <GyverOLED.h>
#include <DHT.h>
GyverOLED<SSD1306_128x64, OLED_NO_BUFFER>oled;
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  oled.init();
  oled.clear();
  // put your setup code here, to run once:

}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  if(isnan(h)||isnan(t)){
    oled.clear();
    oled.setCursor(10, 3);
    oled.print("Sensor Error");
    return;
  }
  oled.clear();
  oled.rect(0, 0, 127, 63, OLED_STROKE);
  oled.line(0, 31, 127, 31);

oled.setScale(1);
oled.setCursor(8, 1);
oled.print("TEMP:");

oled.setScale(2);
oled.setCursor(45, 1);
oled.print(t,1);
oled.print("C");

oled.setScale(1);
oled.setCursor(8, 5);
oled.print("HUMI:");

oled.setScale(2);
oled.setCursor(45, 5);
oled.print(h,0);
oled.print("%");

delay(2000);
  // put your main code here, to run repeatedly:

}
