int reed = 3;
int led = 4;
int push = 5;

void setup() {
  pinMode(reed,INPUT);
  pinMode(led,OUTPUT);
  pinMode(push,INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(reed) == HIGH){
   if(digitalRead(push) == HIGH)
   {
      digitalWrite(led,HIGH);
    }else{
     digitalWrite(led,LOW);
   }
  }else{
    digitalWrite(led,LOW);
  }
  Serial.print("Push = ");
  Serial.print(digitalRead(push));
  Serial.print(" - ");
  Serial.print("Reed = ");
  Serial.println(digitalRead(reed));
}
