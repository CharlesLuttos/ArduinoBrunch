#include <IRremote.h>  
  
int RECV_PIN = 11;  
float armazenavalor;  

IRrecv irrecv(RECV_PIN);  
decode_results results;  

void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
}

void loop()
{  
  if (irrecv.decode(&results))  
    {  
      Serial.print("Valor lido : ");  
      Serial.println(results.value, HEX);  
      armazenavalor = (results.value);  
    irrecv.resume(); //Le o próximo valor  
    }  
}
