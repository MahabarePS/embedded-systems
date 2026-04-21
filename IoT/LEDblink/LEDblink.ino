#define LED 2
void setup() {
  // put your setup code here, to run once:
  pinmode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalwrite(LED,HIGH);
  delay(100);
  digitalwrite(LED,LOW);
  delay(100);
}
