const int irPin = 2;    
const int relayPin = 3; 

bool lightState = false; 
bool lastIrState = HIGH; 

void setup() {
  pinMode(irPin, INPUT);     
  pinMode(relayPin, OUTPUT);  
  digitalWrite(relayPin, LOW); 
}

void loop() {

  bool currentIrState = digitalRead(irPin);

  
  if (currentIrState == LOW && lastIrState == HIGH) {
    
    lightState = !lightState; 
    
    if (lightState == true) {
      digitalWrite(relayPin, HIGH); 
    } else {
      digitalWrite(relayPin, LOW);  
    }
    
   
    delay(1500); 
  }

  // Запоминаем состояние датчика для следующего шага цикла
  lastIrState = currentIrState;
  
  delay(10); // Микро-пауза для стабильности процессора
}
