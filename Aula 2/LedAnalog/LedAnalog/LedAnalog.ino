int led = 3;

void setup(){
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  analogWrite(led,255);
}
