const int RED_LED = 7;
const int GREEN_LED = 10;
const int BLUE_LED = 11;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(RED_LED, 1);
  digitalWrite(GREEN_LED, 1);
  digitalWrite(BLUE_LED, 1);-
  delay(1000);

  digitalWrite(RED_LED, 0);
  digitalWrite(GREEN_LED, 1);
  digitalWrite(BLUE_LED, 1);
  delay(1000);

  digitalWrite(RED_LED, 1);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(BLUE_LED, 1);
  delay(1000);

  digitalWrite(RED_LED, 1);
  digitalWrite(GREEN_LED, 1);
  digitalWrite(BLUE_LED, 0);
  delay(1000);

  digitalWrite(RED_LED, 0);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(BLUE_LED, 1);
  delay(1000);

  digitalWrite(RED_LED, 1);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(BLUE_LED, 0);
  delay(1000);

  digitalWrite(RED_LED, 0);
  digitalWrite(GREEN_LED, 1);
  digitalWrite(BLUE_LED, 0);
  delay(1000);

  digitalWrite(RED_LED, 0);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(BLUE_LED, 0);
  delay(1000);
  // put your main code here, to run repeatedly:
}
