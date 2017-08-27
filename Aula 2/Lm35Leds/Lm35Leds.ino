int ledVermelho = 2;
int ledAzul = 3;
int sensor_temp = 1;

void setup() {
  pinMode(ledVermelho,OUTPUT);
  pinMode(ledAzul,OUTPUT);
  pinMode(sensor_temp,INPUT);
  Serial.begin(9600);
}

void loop() {
  int temperatura = (analogRead(sensor_temp)*500)/1023;

  if (temperatura < 25){
    digitalWrite(ledAzul,HIGH);
    digitalWrite(ledVermelho,LOW);
  }else{
    digitalWrite(ledAzul,LOW);
    digitalWrite(ledVermelho,HIGH);
  }
}
