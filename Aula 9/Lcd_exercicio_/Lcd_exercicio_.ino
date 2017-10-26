#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);//Definindo os pinos do Lcd

void setup() {
  lcd.begin(16,2);//Define o tipo de lcd, neste caso 16x2
  lcd.clear();//Limpa qualquer dado que estiver escrito no Lcd
}

void loop()
{  
  for(int i = 0; i < 2; i++){
    lcd.clear();
    delay(500);
    lcd.setCursor(2,0);  
    lcd.print("Smartphone LG");
    delay(500);
  }
  lcd.setCursor(0,1);
  lcd.print("Compre ja o seu!!");
  delay(2000);
  lcd.clear();
  lcd.print("Lojao do eletronico");
  delay(3000);     
}
