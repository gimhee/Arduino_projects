const int Buzzer = 6;

int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0; 
  
  for(i = 0; i < 8; i++)
  {
    tone(Buzzer, melody[i]);
    delay(100);
    noTone(Buzzer);
    delay(100);
  }

  for(i = 7; i >= 0; i--)
  {
    tone(Buzzer, melody[i]);
    delay(100);
    noTone(Buzzer);
    delay(100);
  }
}