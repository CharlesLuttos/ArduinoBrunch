#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);//Definindo os pinos do Lcd

void setup() {
  lcd.begin(16,2);//Define o tipo de lcd, neste caso 16x2
  lcd.clear();//Limpa qualquer dado que estiver escrito no Lcd
}

void loop()
{  
   lcd.setCursor(0,0);//coloca o cursor na coluna 0 linha 0
   lcd.print("Arduino 16x2");//Imprime Arduino 16x2 no Lcd
   lcd.setCursor(1,1);//posiciona o cursor na coluna 1 linha 1
   lcd.print("Seu nome");//Imprime "Seu nome" no Lcd
}
