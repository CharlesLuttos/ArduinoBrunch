int trigger = 7;
int echo = 6;
long duration,cm;

void setup() {
  Serial.begin(9600);
}

void loop() {
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
