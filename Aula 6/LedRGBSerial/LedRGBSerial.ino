#define red 9
#define green 10
#define blue 11
char ltr;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  digitalWrite(red,HIGH);
  digitalWrite(green,HIGH);
  digitalWrite(blue,HIGH);
  Serial.begin(9600);
}

void loop() {
  ltr = Serial.read();
  if(ltr == 'r'){
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(blue,HIGH);
    Serial.println("Cor vermelha acesa");
    }
  else if(ltr == 'g'){
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    Serial.println("Cor verde acesa");
    }
  else if(ltr == 'b'){
    digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(red,HIGH);
    Serial.println("Cor azul acesa");
    }
}



