const int LED = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);
  pinMode(LED, OUTPUT);
  Serial.println("Serial Open!");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    char i = (char)Serial.read();
    if(i == '1')
    {
      digitalWrite(LED, 1);
      Serial.println("LED ON!");
    }

    else if(i == '0')
    {
      digitalWrite(LED, 0);
      Serial.println("LED OFF!");
    }
  }
}
