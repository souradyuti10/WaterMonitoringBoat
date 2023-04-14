#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4  //D3 connected
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius;

void setup() {
  Serial.begin(9600);
  sensors.begin();
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  Celcius = sensors.getTempCByIndex();
  Serial.println(Celcius);
  delay(10);
}