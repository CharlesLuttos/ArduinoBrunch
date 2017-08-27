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
  acender led Azul - O comando é LOW por que o tipo do led
  RGB é anodo comum, caso fosse catodo comum o comando seria HIGH
   */
  digitalWrite(red,LOW);
  delay(1000);
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  delay(1000);
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
  delay(1000);
  digitalWrite(blue,HIGH);
}
