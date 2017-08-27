int potenciometro = 1;
void setup() {
  pinMode(potenciometro,INPUT);
Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(potenciometro));
}

