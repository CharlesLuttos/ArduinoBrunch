int led = 3;
int botao = 4;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(botao,INPUT);
}

void loop() {
int Status_Botao = digitalRead(botao);
  if (Status_Botao == HIGH){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}
