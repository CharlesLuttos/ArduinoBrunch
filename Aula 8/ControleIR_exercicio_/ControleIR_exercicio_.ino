#include <IRremote.h>  
#define led 3
int turno = 0;
boolean ativa_frequencia = false;

int RECV_PIN = 11;  
float armazenavalor;  

IRrecv irrecv(RECV_PIN);  
decode_results results;  

void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
  pinMode(led, OUTPUT);
}

void loop()
{  
  if (ativa_frequencia == true){
    for(int x = 200; x > 0; x-=10){
          digitalWrite(led,HIGH);
          delay(x);
          digitalWrite(led,LOW);
          delay(x);  
        }
    for(int x = 0; x < 200; x+=10){
      digitalWrite(led,HIGH);
      delay(x);
      digitalWrite(led,LOW);
      delay(x);  
    }
  }
  
  if (irrecv.decode(&results))  
    {  
      Serial.print("Valor lido : ");  
      Serial.println(results.value, HEX);  
      armazenavalor = (results.value);

      //Botao 1
      if (armazenavalor == 0xFF6897){
        for(int i = 0; i<256; i++){
          analogWrite(led,i);
          delay(12); 
        }
        for(int i = 255; i>=0; i--){
          analogWrite(led,i);
          delay(12); 
        }
      }

      //Botao 2
      if (armazenavalor == 0xFF9867){
        for(int i = 0; i<256; i++){
          analogWrite(led,i);
          delay(12); 
        }
        for(int i = 255; i>=0; i--){
          analogWrite(led,i);
          delay(12); 
        }
        for(int x = 0; x < 3; x++){
          digitalWrite(led,HIGH);
          delay(500);
          digitalWrite(led,LOW);
          delay(500);  
        }
      }

      //Botao 3
      if (armazenavalor == 0xFFB04F){
        turno+=1;
        if (turno > 1) {turno = 0;}
        if (turno == 0){
          ativa_frequencia = true;
        }else{
          ativa_frequencia = false;
        }
      }
    irrecv.resume(); //Le o próximo valor  
    }  
}
