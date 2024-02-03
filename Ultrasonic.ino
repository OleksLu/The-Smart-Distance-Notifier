#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NewTone.h>

// Підключення пінів для ультразвукового датчика HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// Адреса OLED дисплею через I2C
#define OLED_RESET    -1  // Якщо ви не використовуєте ресет-пін, встановіть -1
Adafruit_SSD1306 display(OLED_RESET);

// Пін для підключення динаміка
const int speakerPin = 11;

void setup() {
  Serial.begin(9600);  // Ініціалізація монітору порту
  while (!Serial);     // Чекаємо, доки монітор порту буде готовий
  
  // Ініціалізація OLED дисплею через I2C
if(!display.begin(0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Встановлення розміру шрифту для тексту на OLED дисплеї
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Ініціалізація пінів для ультразвукового датчика
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Ініціалізація піну для динаміка
  pinMode(speakerPin, OUTPUT);
}

float measureDistance() {
  // Відправлення звукового імпульсу
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Зчитування часу зворотнього ехо-імпульсу
  float duration = pulseIn(echoPin, HIGH);

  // Перетворення часу на відстань (см)
  float distance = duration * 0.034 / 2;

  // Виведення значень в монітор порту
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Виведення інформації на OLED дисплей
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(F("Distance: "));
  display.print(distance);
  display.print(F(" cm"));
  display.display();

  return distance;
}

void loop() {
  // Вимірювання відстані за допомогою ультразвукового датчика
  float distance = measureDistance();

  // Генерація звуку на динаміку
  if (distance < 10.0) {
    playTone(1000, 200);
  }

  // Затримка перед новим вимірюванням
  delay(500);
}

void playTone(int frequency, int duration) {
  NewTone(speakerPin, frequency, duration);
  delay(duration + 50); // Затримка для уникнення зсуву часових інтервалів
  noNewTone(speakerPin);
}
