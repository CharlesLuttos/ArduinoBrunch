int trigger = 7;
int echo = 6;
int buzzer = 10;
long duration,cm;

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Distancia();
  if (cm < 30){
    digitalWrite(buzzer,HIGH);
    delay(cm*3.40);
    digitalWrite(buzzer,LOW);
    delay(cm*3.40);
  }
}

void Distancia(){
  pinMode(trigger,OUTPUT);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  pinMode(echo,INPUT);
  duration = pulseIn(echo,HIGH);
  cm = duration / 58.8;
  Serial.println(cm);
}
