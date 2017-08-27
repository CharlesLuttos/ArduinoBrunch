int led = 3;
int botao = 4;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(botao,INPUT);
  Serial.begin(9600);
}

void loop() {
int Status_Botao = digitalRead(botao);
  if (Status_Botao == HIGH){
     digitalWrite(led,HIGH);
     delay(100);
     digitalWrite(led,LOW);
     delay(100);
  }else{
     digitalWrite(led,LOW);
  }
Serial.println(Status_Botao);
}
