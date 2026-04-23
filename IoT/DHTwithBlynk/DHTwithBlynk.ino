/*
IoT-Based Temperature & Humidity Monitoring System using ESP32 and Blynk Cloud
*/
#define BLYNK_PRINT Serial
//Firmware config
#define BLYNK_TEMPLATE_ID "TMPL3x6cTI_tN"
#define BLYNK_TEMPLATE_NAME "DHTupdate"
#define BLYNK_AUTH_TOKEN "mUgmwuiu4g3_ubLM-lsbXhpP0QHjys01"
//Sensor Pin Config
#define DHT_read 34
//Header Configuration
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<DHT.h>
//WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "iPhone (2)";
char pass[] = "12345sorry123";
//Creating Timer Object
BlynkTimer timer;
//Binding DHT Pin with DHT_TYPE
DHT dht(DHT_read, DHT11);
//Global variables to hold readings
float temperature;
float humidity;
//Function to read the Humidity and sending it to Blynk
void DHT_sensor_read(){
  temperature  = dht.readTemperature();
  humidity     = dht.readHumidity();
  //
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
}
void setup() {
  // put your setup code here, to run once:
  BLYNK_PRINT.begin(9600);
  BLYNK_PRINT.println("Starting ESP32!");
  //Connect to the WiFi
  Blynk.begin(auth, ssid, pass);
  Serial.println("ESP32 Connected to wireless network!");
  //start the DHT sensor
  dht.begin();
  Serial.println("Activating DHT sensor!");
  // update the Temperature and Humidity after every second
  timer.setInterval(1000L, DHT_sensor_read);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
  Blynk.run();
  timer.run();
}