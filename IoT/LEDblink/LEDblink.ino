#define WHITE 12
#define GREEN 14
#define YELLOW 27
void setup() {
  // put your setup code here, to run once:
  pinMode(WHITE,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(WHITE,HIGH);
  delay(500);
  digitalWrite(WHITE,LOW);
  delay(500);
  digitalWrite(GREEN,HIGH);
  delay(500);
  digitalWrite(GREEN,LOW);
  delay(500);
  digitalWrite(YELLOW,HIGH);
  delay(500);
  digitalWrite(YELLOW,LOW);
  delay(500);
}
