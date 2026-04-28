/*
Simple LED blink using ESP32-WROOM module
*/
#define LED 2  //Pin Connected to the IR sensor OUT
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  delay(100);
  digitalWrite(LED,LOW);
  delay(100);
}
