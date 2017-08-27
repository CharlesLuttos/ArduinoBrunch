int Reed = 2;
int Push = 5;
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int key;

void setup() {
  pinMode(Reed,INPUT);
  pinMode(Push,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(Reed) == HIGH){
    if(digitalRead(Push) == HIGH)
    {
      key++;
      if(key>4){
        key=0;
      }
      switch(key){
        case 0:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
        break;
        case 1:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
        break;
        case 2:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
        break;
        case 3:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
        break;
        case 4:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
        break;
      }
      while(digitalRead(Push)==HIGH){}
    }
  }else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  Serial.print("Push = ");
  Serial.print(digitalRead(Push));
  Serial.print(" - ");
  Serial.print("Reed = ");
  Serial.println(digitalRead(Reed));
}



