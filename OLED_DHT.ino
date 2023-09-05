#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Wire.setSDA(12);
  Wire.setSCL(13);

  Wire.begin();

  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10); // setCursor 없으면 값이 계속 오른쪽으로 이동해서 입력됨
  display.println("Hello, world!");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  float F = dht.readTemperature(true);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10); // setCursor 없으면 값이 계속 오른쪽으로 이동해서 입력됨
  display.print("Humidity: ");
  display.print(hum);
  display.println("%");
  display.print("Temperature: ");
  display.println(temp);
  display.display();
  delay(1000);
}