#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10
#define PIN_CDS 26

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int trig_pin = 15;
const int echo_pin = 14;
const int Buzzer = 6;
const int RED_LED = 7;
const int GREEN_LED = 10;
const int SW1 = 3;
const int SW2 = 4;
const int RELAY = 22;

long ultrason_duration;
float distance_cm;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(PIN_CDS, INPUT);

  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);

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
  display.println("Welcome Driver!");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
}

void loop() {
  if (digitalRead(SW1)==0){
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(TRIG_PULSE_DURATION_US);
    digitalWrite(trig_pin, LOW);

    ultrason_duration=pulseIn(echo_pin, HIGH);

    distance_cm=ultrason_duration*SOUND_SPEED/2*0.0001;

    delay(500);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0, 10); // setCursor 없으면 값이 계속 오른쪽으로 이동해서 입력됨
    display.println(distance_cm);
    display.display();

    if (distance_cm <=3){
      tone(Buzzer, 200);
      digitalWrite(RELAY, 0);
      digitalWrite(RED_LED, 0);
      delay(3000);
    }
    else {
      noTone(Buzzer);
      delay(300);
      digitalWrite(RED_LED, 1);
      digitalWrite(RELAY, 1);
    }
  }
  else if(digitalRead(SW2)==0){
    int CDS_sensor = analogRead(26);
    if (CDS_sensor > 600) {
      digitalWrite(RED_LED, 0);
      digitalWrite(GREEN_LED, 0);
    }
    else {
      digitalWrite(RED_LED, 1);
      digitalWrite(GREEN_LED, 1);
    }
  }
}
