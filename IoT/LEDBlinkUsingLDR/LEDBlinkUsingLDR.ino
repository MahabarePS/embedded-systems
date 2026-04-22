#define LED 2
#define LDR A0
int threshold = 9;
void setup(){
pinMode(LED, OUTPUT);
pinMode(LDR, INPUT);
Serial.begin(9600);
}
void loop(){
int LDR_read = analogRead(LDR);
Serial.println(LDR_read);

if(LDR_read < threshold){
  digitalWrite(LED, HIGH);
}else{
  digitalWrite(LED, LOW);
}
delay(100);
}