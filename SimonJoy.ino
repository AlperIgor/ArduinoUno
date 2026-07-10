
const int ledPins[] = {4, 5, 6, 7}; // 0-Влево, 1-Вправо, 2-Вверх, 3-Вниз
const int numLeds = 4;

// Пины джойстика
const int pinX = A0;
const int pinY = A1;

// Переменные игры
int sequence[100]; // Массив для хранения шагов Саймона
int gameRound = 0;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH); // Из-за подключения к плюсу АКБ, 
                                    // выключаем светодиоды подачей HIGH
  }
  
  randomSeed(analogRead(A2)); // Инициализация случайных чисел
  Serial.begin(9600);
  
  // Стартовая анимация
  flashAll(3);
  delay(1000);
}

void loop() {
  // 1. Шаг Саймона: добавляем новый цвет в цепочку
  sequence[gameRound] = random(0, numLeds);
  gameRound++;

  // 2. Саймон показывает цепочку
  for (int i = 0; i < gameRound; i++) {
    lightUp(sequence[i], 500);
    delay(200);
  }

  // 3. Ход игрока
  for (int i = 0; i < gameRound; i++) {
    int playerInput = waitForJoystick();
    
    // Проверка на ошибку
    if (playerInput != sequence[i]) {
      // Игрок ошибся! Игра окончена.
      gameOver();
      return;
    }
    // Если угадал, подсветим диод
    lightUp(playerInput, 300);
  }
  
  delay(1000); // Пауза перед следующим раундом
}

// Функция включения конкретного светодиода (LOW зажигает его)
void lightUp(int ledIndex, int duration) {
  digitalWrite(ledPins[ledIndex], LOW);
  delay(duration);
  digitalWrite(ledPins[ledIndex], HIGH);
}

// Мигание всеми диодами сразу
void flashAll(int times) {
  for (int t = 0; t < times; t++) {
    for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], LOW);
    delay(200);
    for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], HIGH);
    delay(200);
  }
}

// Считывание джойстика и определение направления
int waitForJoystick() {
  while (true) {
    int xVal = analogRead(pinX);
    int yVal = analogRead(pinY);

    if (xVal < 200) return 0; // Влево
    if (xVal > 800) return 1; // Вправо
    if (yVal < 200) return 2; // Вверх
    if (yVal > 800) return 3; // Вниз
    
    delay(50); 
  }
}

// Конец игры
void gameOver() {
  Serial.println("Game Over!");
  flashAll(5); // Быстро мигаем в знак проигрыша
  gameRound = 0; // Сброс игры
  delay(2000);
}



