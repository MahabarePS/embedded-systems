/*
Adjusting LED brightness using a POTmeter
*/

#define LED 2
#define POT 4

//PWM settings
const int freq = 5000;
const int resolution = 12;
const int channel=0;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 // configure PWM
 ledcSetup(channel, freq, resolution);
 ledcAttachPin(LED, channel);
}

void loop() {
  // put your main code here, to run repeatedly:
}
