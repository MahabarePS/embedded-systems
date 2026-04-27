/*
Reading distance on Blynk using Ultrasonic sensor with ESP32
*/
//Firmware config
#define BLYNK_TEMPLATE_ID "TMPL3uaMf7mQ2"
#define BLYNK_TEMPLATE_NAME "ultrasonic"
#define BLYNK_AUTH_TOKEN "M5Ax6HakRJbNHbdtX8s5lJ9MfDILZnWF"
#define BLYNK_PRINT Serial
//Header Configuration
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
//WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "iPhone (2)";
char pass[] = "12345sorry123";

#define TRG_PIN 18
#define ECHO_PIN 5
#define SPEED 0.034

float duration_us, distance_cm;

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  BLYNK_PRINT.begin(9600);
  BLYNK_PRINT.println("Starting ESP32!");
  //Connect to the WiFi
  Blynk.begin(auth, ssid, pass);
  Serial.println("ESP32 Connected to wireless network!");
  // configure the trigger pin to output mode
  pinMode(TRG_PIN, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRG_PIN, HIGH);
  //delayMicroseconds(10);
  digitalWrite(TRG_PIN, LOW);
  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = SPEED * duration_us/2;
  // send the distance in CM
  Blynk.virtualWrite(V0, distance_cm);  
  // print the value to Serial Monitor
  Serial.println("distanceA: ");
  Serial.print(distance_cm);
  Blynk.run();
}
