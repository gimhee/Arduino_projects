const int RELAY = 22;

void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY, 0);
  delay(1000);

  digitalWrite(RELAY, 1);
  delay(1000);
}
