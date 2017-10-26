#include <IRremote.h>
int r=2;
int g=3;
int b=4;
int menu;
int RECV_PIN = 7;
float armazenavalor;
int x = 255,y=255,z=255;

IRrecv irrecv(RECV_PIN);  
decode_results results;  

void setup() {
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  digitalWrite(r,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(b,HIGH);
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results))  
  {  
    Serial.print("Valor lido : ");  
    Serial.println(results.value, HEX);  
    armazenavalor = (results.value);
    if(armazenavalor==0xFF6897){//1
      menu = 1;
    }
    if(armazenavalor==0xFF9867){//2
      menu = 2;
    }
    if(armazenavalor==0xFFB04F){//3
      menu = 3;
    }
    if(armazenavalor==0xFF30CF){//4

    }
    if(armazenavalor==0xFF18E7){//5

    }
    if(armazenavalor==0xFF7A85){//6

    }

    if(armazenavalor==0xFF629D){//up
      incr();
    }
    if(armazenavalor==0xFFA857){//down
      decr();
    }
    if(armazenavalor==0xFF02FD){//Botão ok
      digitalWrite(r,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(b,HIGH);
    }
    irrecv.resume();
    }
}
void incr(){
  int led = menu+1;
  if(led==2){
    x-=10;
  if(x<0){
    x=0;
  }
    analogWrite(led,x);
    Serial.println(x);
  }else if(led==3){
    y-=10;
  if(y<0){
    y=0;
  }
    analogWrite(led,y);
    Serial.println(y);
  }else{
    z-=10;
  if(z<0){
    z=0;
  }
    analogWrite(led,z);
    Serial.println(z);
  } 
}
void decr(){
  int led = menu+1;
  if(led==2){
    x+=10;
  if(x>255){
    x=255;
  }
    analogWrite(led,x);
    Serial.println(x);
  }else if(led==3){
    y+=10;
  if(y>255){
    y=255;
  }
    analogWrite(led,y);
    Serial.println(y);
  }else{
    z+=10;
  if(z>255){
    z=255;
  }
    analogWrite(led,z);
    Serial.println(z);
  }
}
