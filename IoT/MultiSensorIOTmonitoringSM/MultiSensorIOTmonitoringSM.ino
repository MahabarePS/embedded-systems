/*
ESP32-Based Multi-Sensor IoT Monitoring System with Blynk Cloud Integration

Sensors used:
1. DHT11
2. PIR motion sensor

Author: Prasad Mahabare
*/
//Firmware config
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3CM09bnpO"
#define BLYNK_TEMPLATE_NAME "MultiSensor"
#define BLYNK_AUTH_TOKEN "qlRBXBQkcTabbLdTsAvGP9nKalIFjFv6"
//Header configuration
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
//MACROS DEFINED
#define DHT_read 4
#define MOTION_read 18       //PIR sensor read pin
#define ROOM_LED  21    
#define LOW 0
#define HIGH 1
//WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "iPhone (2)";
char pass[] = "12345sorry123";
//----------------------------------------------------------------
//Global read for DHT
float temperature, humidity;
//Binding DHT Pin with DHT_TYPE
DHT dht(DHT_read, DHT11);
void DHT_reading(){
  Serial.println("Processing Temperature and Humidity!");
  temperature  = dht.readTemperature();           // Read Temperature
  humidity     = dht.readHumidity();              // Read Humidity
  //
  Blynk.virtualWrite(V0, temperature);            // Send Temp to Blynk
  Blynk.virtualWrite(V1, humidity);               // Send Humidity to Blynk
}
//----------------------------------------------------------------
//Global read for Motion Sensor
int val=0, state=LOW;
void motion_reading(){
  val = digitalRead(MOTION_read);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(ROOM_LED, HIGH);   // turn LED ON
    delay(1000);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Blynk.virtualWrite(V3, "Motion detected!");    // Send it to Blynk
      Serial.println("Motion detected!");
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      
      digitalWrite(ROOM_LED, LOW); // turn LED OFF
      delay(1000);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Blynk.virtualWrite(V3, "Motion stopped!");    // Send it to Blynk
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
//----------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  BLYNK_PRINT.begin(9600);
  BLYNK_PRINT.println("Starting ESP32!");
  //Connect to the WiFi
  Blynk.begin(auth, ssid, pass);
  Serial.println("ESP32 Connected to wireless network!");
  //Starting motion sensor
  Serial.println("Activating Motion Sensor");
  pinMode(ROOM_LED,OUTPUT);
  pinMode(MOTION_read,INPUT);
  //start the DHT sensor
  dht.begin();
  Serial.println("Activating DHT sensor!");
  //Processing Temp and Humidity
  DHT_reading();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  motion_reading();
}
