/*
Adjusting LED brightness using a POTmeter
*/

#define LED 2
#define POT 4

uint8_t brightness = 0;
uint16_t potValue = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(LED, OUTPUT);
  // declare the potPin as an INPUT:
  pinMode(POT, INPUT);
  //start the serial monitor:
  Serial.begin(9600);
}

void loop() {
    // ADC read (0->4095)
    potValue = analogRead(POT);
    //Scale ADC range to PWM range
    brightness = potValue/16;
    // set the brightness of the LED:
    analogWrite(LED, brightness);
    Serial.println(brightness);
    delay(1);
}