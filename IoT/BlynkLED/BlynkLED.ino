/*
LED Blynk using vitual switch with periodic switch pressed count
*/
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL36njn2bQQ"
#define BLYNK_TEMPLATE_NAME "BlynkLED"
#define BLYNK_AUTH_TOKEN "f3qHuSIkYsfae1iprdAjjq9Bt0Kogrkn"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "iPhone (2)";
char pass[] = "12345sorry123";

int count = 0;

BlynkTimer timer; // Create a timer object

#define LED 2

BLYNK_WRITE(V0){
  int state = param.asInt();
  if(state==1){
    count++;
  }
  digitalWrite(LED, state);
  BLYNK_PRINT.println(state ? "LED ON" : "LED OFF");
  }

void periodic_press_count(){
  Blynk.virtualWrite(V0,count); //send count to a virtual pin
  BLYNK_PRINT.println("Switch pressed: ");
  BLYNK_PRINT.println(count);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);

  Blynk.begin(auth, ssid, pass);
  // Schedule the functtion to run every 5000ms (5sec)
  timer.setInterval(5000L,periodic_press_count);
}
void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  // initiate timer
  timer.run();
}
