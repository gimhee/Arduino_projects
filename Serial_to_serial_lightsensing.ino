#define PIN_CDS 26

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_CDS, INPUT);

/*
  Serial2.setTX(8);
  Serial2.setRX(9);*/
  Serial2.begin(115200);
  delay(2000); // Give the module time to initialize
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if(Serial.available())
  {
    char c = Serial.read();
    Serial2.write(c);
    Serial.print(c);
  }
  if(Serial2.available())
  {
    char c2 = Serial2.read();
    Serial.write(c2);
  
  }*/

  int CDS_sensor = analogRead(26);

  Serial.print("CDS Value: ");
  Serial.println(CDS_sensor);

  if (CDS_sensor > 600){
  sendSMS("01080607223", "too dark!");}
  delay(5000); // Replace with recipient's phone number
}


void sendSMS(const char* phoneNumber, const char* message) {
  // AT command to set the GSM module in SMS mode
  Serial2.println("AT+CMGF=1");
  delay(1000);

  // AT command to specify the recipient's phone number
  Serial2.print("AT+CMGS=\"");
  Serial2.print(phoneNumber);
  Serial2.println("\"");
  delay(1000);

  // Message content
  Serial2.print(message);

  // ASCII code of the Ctrl+Z
  Serial2.write(26);
  delay(1000);
}
