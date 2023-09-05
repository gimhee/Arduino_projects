const int trig_pin = 15;
const int echo_pin = 14;

#define SOUND_SPEED 340
#define TRIG_PULSE_DURATION_US 10

long ultrason_duration;
float distance_cm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig_pin, 0);
  delayMicroseconds(2);

  digitalWrite(trig_pin, 1);
  delayMicroseconds(TRIG_PULSE_DURATION_US);
  digitalWrite(trig_pin, 0);

  ultrason_duration = pulseIn(echo_pin, 1);

  distance_cm = ultrason_duration * SOUND_SPEED/2 * 0.0001;

  Serial.print("Distance (cm): ");
  Serial.println(distance_cm);

  delay(250);
}
