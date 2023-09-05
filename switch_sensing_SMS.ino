const int SW1 = 3;
//const int SW3 = 5;

const int BLUE_LED = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200);

  pinMode(SW1, INPUT);
  pinMode(BLUE_LED, OUTPUT);
/*
  Serial2.setTX(8);
  Serial2.setRX(9);*/
  delay(2000); // Give the module time to initialize
  digitalWrite(BLUE_LED, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int SWITCH = digitalRead(SW1);
  if(SWITCH ==0){
    digitalWrite(BLUE_LED, 0);
    Serial.print("Engine");
    Serial.println(SWITCH);
    sendSMS("01063889819", "engine on");
  }
//  receiveSMS();
//  if (SWITCH == 0){
//  delay(2000); // Replace with recipient's phone number
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


/*void receiveSMS() {
  // AT command to set the GSM module in SMS mode
  Serial2.println("AT+CMGR=1");
  delay(1000);

  // AT command to specify the recipient's phone number
  //Serial2.println("AT+CNMI=2,2,0,0,0");

  //if (Serial2.available()) {
  String receivedData = Serial2.readStringUntil('\n');
    const char* received = receivedData.c_str();
    Serial.print(received);
    if(strstr(received, "NEWMT")!=NULL)
  //if (receivedData.startsWith("+CMT:")) {
      // Incoming SMS detected
  //String phoneNumber = Serial2.readStringUntil('\n');
  //String smsContent = Serial2.readStringUntil('\n');
      
      // Print received SMS details to Serial Monitor
  Serial.println(receivedData);
}*/
