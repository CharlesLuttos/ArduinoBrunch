int reed = 3;

void setup() {
  pinMode(reed,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(reed));
}
