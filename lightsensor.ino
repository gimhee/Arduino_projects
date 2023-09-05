#define PIN_CDS 26
const int RED_LED = 7;
const int GREEN_LED = 10;
const int BLUE_LED = 11;
//const int RELAY = 22;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_CDS, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
//  pinMode(RELAY, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int CDS_sensor = analogRead(26);

  Serial.print("CDS Value: ");
  Serial.println(CDS_sensor);

/*  if (CDS_sensor > 600) {
    digitalWrite(RED_LED, 0);
    digitalWrite(GREEN_LED, 0);
    digitalWrite(BLUE_LED, 0);
    digitalWrite(RELAY, 1);
//    delay(1000);
  }

  else {
    digitalWrite(RED_LED, 1);
    digitalWrite(GREEN_LED, 1);
    digitalWrite(BLUE_LED, 1);
    digitalWrite(RELAY, 0);
//    delay(1000);
  }
*/
  delay(5000);
}
