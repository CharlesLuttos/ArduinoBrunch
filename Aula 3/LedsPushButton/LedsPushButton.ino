int pushButton = 8;
int led = 7;

void setup() {
  pinMode(pushButton,OUTPUT);
  pinMode(led,OUTPUT);
}
void loop() {
  digitalWrite(pushButton,HIGH);
  digitalWrite(led,LOW);
  delay(1000);
  digitalWrite(pushButton,LOW);
  digitalWrite(led,HIGH);
  delay(1000);
}


