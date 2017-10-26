int reed = 3;
int led = 4;

void setup() {
  pinMode(reed,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(reed));
  if (digitalRead(reed) == HIGH){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}
