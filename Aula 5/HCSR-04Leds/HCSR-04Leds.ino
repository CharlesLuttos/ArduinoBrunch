#define led_verde 9
#define led_amarelo 10
#define led_vermelho 11
int trigger = 7;
int echo = 6;
long duration,cm;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  Distancia();//Puxa o método que mede a distância
  
  //Se a distância for menor que 6
  if (cm<=5){
    digitalWrite(led_amarelo,LOW);
    digitalWrite(led_verde,LOW);
  digitalWrite(led_vermelho,HIGH);//Led vermelho acende  
  }else if((cm>5)&&(cm<=10)){//Senao se a distancia estiver entre 6 e 10
    digitalWrite(led_amarelo,HIGH);//Led amarelo acende
    digitalWrite(led_verde,LOW);
    digitalWrite(led_vermelho,LOW);  
  }else{//Se todas as condiÁıes anteriores forem falsas
    digitalWrite(led_amarelo,LOW);
    digitalWrite(led_verde,HIGH);//Led verde acende
    digitalWrite(led_vermelho,LOW);  
  }
}

//Método para medir a distância
void Distancia(){
  pinMode(trigger,OUTPUT);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  pinMode(echo,INPUT);
  duration = pulseIn(echo,HIGH);
  cm = duration / 58.8;
  Serial.println(cm); 
}
