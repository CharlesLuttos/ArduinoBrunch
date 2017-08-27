#include <LiquidCrystal.h>

LiquidCrystal lcd(22,23,24,25,26,27);
void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  
  lcd.begin(16,2);
  Serial.begin(9600);
  Serial.println("Aguardando...");
  Serial.println();
}
void loop()
{  
for (int ti = 3; ti<7; ti++)
    {
    //Alterna o estado dos pinos das linhas
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(ti, HIGH);
    //Verifica se alguma tecla da coluna 1 foi pressionada
    if (digitalRead(8) == HIGH)
    {
      imprime_linha_coluna(ti-2, 1);
      while(digitalRead(8) == HIGH){}
    } 
    //Verifica se alguma tecla da coluna 2 foi pressionada    
    else if (digitalRead(9) == HIGH)
    {
      imprime_linha_coluna(ti-2, 2);
      while(digitalRead(9) == HIGH){}
    }
     
    //Verifica se alguma tecla da coluna 3 foi pressionada
    else if (digitalRead(10) == HIGH)
    {
      imprime_linha_coluna(ti-2, 3);
      while(digitalRead(10) == HIGH){}
    }
     
    //Verifica se alguma tecla da coluna 4 foi pressionada
    else if (digitalRead(11) == HIGH)
    {
      imprime_linha_coluna(ti-2, 4);
      while(digitalRead(11) == HIGH){} 
    }
   }
   delay(10);
}

void imprime_linha_coluna(int x, int y)
{
  if ((x==1)&&(y==1)){
       Serial.println("1");
  }else if((x==1)&&(y==2)){
       Serial.println("2");
  }else if((x==1)&&(y==3)){
       Serial.println("3");  
  }else if((x==1)&&(y==4)){
       Serial.println("A");
  }else if((x==2)&&(y==1)){
       Serial.println("4");  
  }else if((x==2)&&(y==2)){
       Serial.println("5");
  }else if((x==2)&&(y==3)){
       Serial.println("6");
  }else if((x==2)&&(y==4)){
       Serial.println("B");
  }else if((x==3)&&(y==1)){
       Serial.println("7");
  }else if((x==3)&&(y==2)){
       Serial.println("8");
  }else if((x==3)&&(y==3)){
       Serial.println("9");
  }else if((x==3)&&(y==4)){
       Serial.println("C");
  }else if((x==4)&&(y==1)){
       Serial.println("*");
  }else if((x==4)&&(y==2)){
       Serial.println("0");
  }else if((x==4)&&(y==3)){
       Serial.println("#");
  }else if((x==4)&&(y==4)){
       Serial.println("D");   
  }
  delay(10);
}
