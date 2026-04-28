/*
Using IR sensor with an ESP32
*/
#define IRsenIn 15  //Pin Connected to the IR sensor OUT
void setup() {
  //Initialize the IR sensor pin as an input
  pinMode(IRsenIn, INPUT);

  //Start serial communication for debugging
  Serial.begin(9600);
}
void loop() {
  //Read the state of the IR sensor 
  int IRvalue = digitalRead(IRsenIn);
  //If the IR sensor detects something LOW
  if(IRvalue==LOW){
    Serial.println("Object Detected!");
  }else{
    Serial.println("----------------");
  }
  delay(100);
}
