#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const int RELAY = 22;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  float F = dht.readTemperature(true);

  if (isnan(hum) || isnan(temp) || isnan(F)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  Temperature: ");
  Serial.print(temp);
  Serial.println("°C ");


  if(hum > 80){
  digitalWrite(RELAY, 0);
  delay(1000);
  }
//  
//  delay(1000);

//  digitalWrite(RELAY, 1);
//  delay(1000);
}




