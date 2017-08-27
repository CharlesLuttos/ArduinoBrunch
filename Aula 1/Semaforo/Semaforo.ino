int sinalVerde = 7;
int sinalAmarelo = 8;
int sinalVermelho = 9;

void setup() {
  pinMode(sinalVerde,OUTPUT);
  pinMode(sinalAmarelo,OUTPUT);
  pinMode(sinalVermelho,OUTPUT);
}

void loop() {
  digitalWrite(sinalVerde,HIGH);
  delay(3000);
  digitalWrite(sinalVerde,LOW);
  digitalWrite(sinalAmarelo,HIGH);
  delay(1000);
  digitalWrite(sinalAmarelo,LOW);
  digitalWrite(sinalVermelho,HIGH);
  delay(2000);
  digitalWrite(sinalVermelho,LOW);
}


