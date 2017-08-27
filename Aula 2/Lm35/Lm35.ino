int lm35 = 1;
int temperatura;

void setup() {
  pinMode(lm35,INPUT);
  Serial.begin(9600);
}
void loop() {
  temperatura = (analogRead(lm35)*500)/1023;
  Serial.println(temperatura);
}
