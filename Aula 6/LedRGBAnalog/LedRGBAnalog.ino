#define red 11
#define green 10
#define blue 9

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  //Iniciar com todos os leds apagados
  digitalWrite(red,HIGH);
  digitalWrite(green,HIGH);
  digitalWrite(blue,HIGH);
}

void loop() {
  /*
  Acender leds com analog Read
  --> 0 para acender com intensidade total
  -->255 para apagar
  intervalo entre 0 e 255 muda intensidade da cor
  veja o código abaixo:
   */
  analogWrite(blue,255);//terminal azul apagado
  delay(1000);
  analogWrite(blue,200);
  delay(1000);
  analogWrite(blue,150);
  delay(1000);
  analogWrite(blue,100);
  delay(1000);
  analogWrite(blue,0);//terminal azul aceso com intensidade total
  delay(1000);
}
