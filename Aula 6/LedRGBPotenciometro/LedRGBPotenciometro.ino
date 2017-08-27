#define red 11
#define green 10
#define blue 9
//Variáveis dos Potenciometros
int p1 = 1;
int p2 = 2;
int p3 = 3;

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);
  //Iniciar com todos os leds apagados
  digitalWrite(red,HIGH);
  digitalWrite(green,HIGH);
  digitalWrite(blue,HIGH);
  Serial.begin(9600);
}

void loop() {
  /*Variáveis responsáveis por guardar 
    o valor convertido dos potenciômetros*/
  int r = (analogRead(p1)/4.01176471);
  int g = (analogRead(p2)/4.01176471);
  int b = (analogRead(p3)/4.01176471);
  //Escrevendo nos leds
  analogWrite(red,r);
  analogWrite(green,g);
  analogWrite(blue,b);
  /*Escrevendo no monitor serial 
    as informações sobre os valores colhidos*/
  Serial.print("Red: ");
  Serial.print(r);
  Serial.print("*");
  Serial.print("Green: ");
  Serial.print(g);
  Serial.print("*");
  Serial.print("Blue: ");
  Serial.println(b);
}
