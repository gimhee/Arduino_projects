const int LED_RED = 7;
const int LED_GREEN = 10;
const int LED_BLUE = 11;
const int SW1 = 3;
const int SW2 = 4;
const int SW3 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);

  digitalWrite(LED_RED, 1);
  digitalWrite(LED_GREEN, 1);
  digitalWrite(LED_BLUE, 1);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(SW1)==0)
  {
    digitalWrite(LED_RED, 0);
    if (digitalRead(SW2)==0)
    {
      digitalWrite(LED_GREEN, 0);
      if (digitalRead(SW3)==0)
      {
        digitalWrite(LED_BLUE, 0);
      }
      else if (digitalRead(SW3)==1)
      {
        digitalWrite(LED_BLUE, 1);
      }
    }
    else if (digitalRead(SW2)==1)
    {
      digitalWrite(LED_GREEN, 1);
      if (digitalRead(SW3)==0)
      {
        digitalWrite(LED_BLUE, 0);
      }
      else if (digitalRead(SW3)==1)
      {
        digitalWrite(LED_BLUE, 1);
      }
    }
  }
  else if (digitalRead(SW1)==1)
  {
    digitalWrite(LED_RED, 1);
    if (digitalRead(SW2)==0)
    {
      digitalWrite(LED_GREEN, 0);
      if (digitalRead(SW3)==0)
      {
        digitalWrite(LED_BLUE, 0);
      }
      else if (digitalRead(SW3)==1)
      {
        digitalWrite(LED_BLUE, 1);
      }
    }

    else if (digitalRead(SW2)==1)
    {
      digitalWrite(LED_GREEN, 1);
      if (digitalRead(SW3)==0)
      {
        digitalWrite(LED_BLUE, 0);
      }
      else if (digitalRead(SW3)==1)
      {
        digitalWrite(LED_BLUE, 1);
      }
    }
  }
}

