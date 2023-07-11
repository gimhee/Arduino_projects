//rain sensing with beep sound and RED LED

const int RED_LED = 7;
const int Buzzer = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(27, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rain_sensor = analogRead(27);

  if( rain_sensor > 900 ) {
    Serial.println("Not Raining");
    digitalWrite(RED_LED, 1);
  }

  else if( rain_sensor < 800 ) {
    Serial.println("Heavy Raining");
    digitalWrite(RED_LED, 0);
    tone(Buzzer, 523);
    delay(100);
    noTone(Buzzer);
    delay(30);
  }

  else {
    Serial.println("Light Raining");
    digitalWrite(RED_LED, 0);
    tone(Buzzer, 262);
    delay(100);
    noTone(Buzzer);
    delay(30);
  }

  Serial.print("Rain Sensor Value: ");
  Serial.print(rain_sensor);
  Serial.print(" ");

  delay(1000);
}
