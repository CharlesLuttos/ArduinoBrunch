int ldr = 1;
float luz;

void setup() {
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop() {
  luz = analogRead(ldr);
  Serial.println(luz);
}
