// This project implements the simulation of the reading a DHT sensor using an ESP32 
// The source code is available on my git repo at : https://github.com/Bamamou/DHT11_ESP32.git
// the only difference is the sensor, Here; we use a DHT11 while in Platform io we use a DHT22
#include <DHT.h>  
// Set up the DHT sensor 
DHT dht(4, DHT11);
float temperature ;
float  humidity;
int counter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // put your main code here, to run repeatedly:
  temperature  = dht.readTemperature();
  humidity     = dht.readHumidity();
  Serial.println("Data: "+ String(counter));
  // Print the values of temperature in Celsus
  Serial.print("Temperatue:\t");
  Serial.print(dht.readTemperature(false));
  Serial.println("C");
   // Print the values of temperature in Fahrenheit
  Serial.print("Temperatue:\t");
  Serial.print(dht.readTemperature(true));
  Serial.println("F");
  // print Humidity in perscent 
  Serial.println("Humidity: \t"+String(humidity)+ "%");
  // Print the values of the heat Index for both Units
  Serial.print("Heat Index In Celsus: ");
  Serial.println(dht.computeHeatIndex(temperature, humidity, false));
  
  Serial.print("Heat Index In Fahrenheit: ");
  Serial.println(dht.computeHeatIndex(temperature, humidity, true));
  Serial.println(" ");
  delay(1000); // this speeds up the simulation
  counter++;
}