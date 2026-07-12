#include <Servo.h>
#include <TM1637Display.h> // Подключаем библиотеку дисплея

// Настройки дисплея
#define CLK 4 // Пин CLK к D4
#define DIO 3 // Пин DIO к D3
TM1637Display display(CLK, DIO);

Servo sorterServo; // Создаем объект сервопривода

const int irSensorPin = 2; // Пин ИК-датчика
int itemScale = 0;        // Счетчик деталей
bool itemDetected = false; // Флаг обнаружения

void setup() {
  pinMode(irSensorPin, INPUT);
  sorterServo.attach(11); // Серво на 11 пин
  sorterServo.write(91);   // Стоп мотор
  
  display.setBrightness(0x0f); // Ставим максимальную яркость экрана
  display.showNumberDec(0);    // Выводим стартовый ноль: 0000
  
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(irSensorPin); 

  if (sensorState == LOW && !itemDetected) {
    itemScale++;
    itemDetected = true; 
    
    // Мгновенно выводим новое число деталей на ваш дисплей!
    display.showNumberDec(itemScale); 
    
    Serial.print("Деталь №");
    Serial.println(itemScale);

    // Логика сортировки
    if (itemScale % 2 != 0) {
      sorterServo.write(51);   // Налево
      delay(400);            
      sorterServo.write(91);  // Стоп
    } 
    else {
      sorterServo.write(131); // Направо
      delay(400);             
      sorterServo.write(91);  // Стоп
    }
  }

  if (sensorState == HIGH && itemDetected) {
    itemDetected = false; 
    delay(200); 
  }
}