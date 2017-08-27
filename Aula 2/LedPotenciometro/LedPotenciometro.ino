int led = 3;
int potenciometro = 1;

void setup() {
pinMode(led,OUTPUT);
pinMode(potenciometro,INPUT);
}

void loop() {
  int valorpotenciometro = analogRead(potenciometro);
  int x = valorpotenciometro/4.01176471;
  analogWrite(led,x);
}
