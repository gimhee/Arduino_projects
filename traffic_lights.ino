const int RED_LED = 0;
const int YELLOW_LED = 2;
const int GREEN_LED = 1;
const int WHITE_LED = 6; //LEFT GREEN

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED, 1);
  digitalWrite(YELLOW_LED, 0);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(WHITE_LED, 0);
  delay(2000);

  digitalWrite(RED_LED, 0);
  digitalWrite(YELLOW_LED, 0);
  digitalWrite(GREEN_LED, 1);
  digitalWrite(WHITE_LED, 1);
  delay(2000);

  digitalWrite(RED_LED, 0);
  digitalWrite(YELLOW_LED, 0);
  digitalWrite(GREEN_LED, 1);
  digitalWrite(WHITE_LED, 0);
  delay(2000);

  digitalWrite(RED_LED, 0);
  digitalWrite(YELLOW_LED, 1);
  digitalWrite(GREEN_LED, 0);
  digitalWrite(WHITE_LED, 0);
  delay(1000);
}
