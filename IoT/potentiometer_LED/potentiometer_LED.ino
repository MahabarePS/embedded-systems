/*
Adjusting LED brightness using a POTmeter
*/

#define LED 2
#define POT 4

uint8_t brightness = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(LED, OUTPUT);
  // declare the potPin as an INPUT:
  pinMode(POT, INPUT);
  //start the serial monitor:
  Serial.begin(9600);
}

void loop() {
    // read the most recent byte (which will be from 0 to 255):
    brightness = analogRead(POT);
    Serial.println(brightness);
    // set the brightness of the LED:
    analogWrite(LED, brightness);
    delay(1);
}