//Safe House final 3.2
#include <LiquidCrystal.h>

/*Variáveis responsaveis por definir 
a atividade no teclado e o estado do alarme*/
bool atividade,alarme_ativo=false;
String stat,letra,senha,pass;

/*Variavel que será usada como chave
que será alternada entre os modos
Stand by e modo ativo através da 
estrutura de seleção Switch case*/
int portal=0;

int reed = 30;
int buzzer = 31;

LiquidCrystal lcd(22,23,24,25,26,27);

/*Pino 15 do lcd(luz de fundo) funciona como um led
pode ser ligado e desligado*/
#define luzFundo 40

void setup() {
  //Teclado
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  //Teclado
  pinMode(buzzer,OUTPUT);
  pinMode(reed,INPUT);
  //Tela Lcd
  lcd.begin(16,2);
  pinMode(luzFundo,OUTPUT);
  //Tela Lcd
  Serial.begin(9600);
  Serial.println("Aguardando...");
  Serial.println();
}

void loop()
{  
    teclado(); 
    /*Estrutura switch que usaremos para escolher entre os algoritmos*/
    switch(portal){ 
      case 0://Caso 0 a tela apaga e fica em stand by
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("*Stand By*");
      digitalWrite(luzFundo,LOW);
      while(portal ==0){teclado();}
      break;
      case 1://Caso 1 a tela acende e entra o menu de alarme
    
      /*Luz fundo corresponde ao pino 40 no Arduino(pino 15 no lcd)*/
      digitalWrite(luzFundo,HIGH);
      
      /*Deixa a letra em branco a cada volta
      pois so e possivel pegar uma letra de cada vez no Arduino*/
      letra="";
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Digite sua senha");
      lcd.setCursor(0,1);
      
      /*Enquanto a variável letra não tiver 4 caracteres
       o programa irá monitorar o teclado e esperar 
       o usuário digitar a senha completa*/
      while(senha.length() < 4){
        teclado();              
        while(atividade == true){}
        senha +=letra;
        if(letra!=""){
          pass="*";
        }else{
          pass="";
        }
        letra="";
        lcd.print(pass);
      }
      if (senha == "3673"){
      letra="";
      delay(200);
      lcd.clear();
      lcd.setCursor(0,0);//posiciona cursor na linha 0 coluna 0
      lcd.print("1. Ativar");
      lcd.setCursor(0,1);//posiciona cursor na linha 1 coluna 0
      lcd.print("2. Desativar");
       delay(100);
      while(atividade == false){teclado();
      if(letra =="1"){//Caso a escolha seja 1
        lcd.clear();//limpa tela lcd
        lcd.setCursor(0,0);
        lcd.print("Alarme ativado");
        alarme_ativo = true;//variável responsável por ativar alarme
        delay(3000);
        portal = 0;
        senha="";
        break;//Quebra o laço
      }else if(letra =="2"){//Caso a escolha seja 2
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Alarme desativado");
        alarme_ativo = false;
        delay(3000);
        portal = 0;
        senha="";
        break;//Quebra o laço
      }
      }//Laço while
      }else{
        delay(500);
        lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Senha incorreta");
      delay(2000);
      portal = 0;
      senha = "";
      break;//Quebra o laço
      }
      break;
    }//Switch
}
void Alarme(){//Método do alarme
  if(alarme_ativo == true){//Se variável alarme for verdadeira
    if(digitalRead(reed)==LOW){//Se Reed Switch estiver aberto
      delay(10);
      digitalWrite(buzzer,LOW);
      delay(10);
      digitalWrite(buzzer,HIGH);//Apita buzzer
    }else{//Senao (Reed Switch estiver fechado) - Buzzer não apita
      digitalWrite(buzzer,LOW);
    }
  }else{
    /*Buzzer não irá apitar se Reed switch 
    estiver aberto e variável alarme for falsa*/
      digitalWrite(buzzer,LOW);
  }
}
//Método do teclado
void teclado(){
  for (int ti = 3; ti<7; ti++)
    {
      Alarme();//Chamando método do alarme
      /*****
      Chamamos os métodos do alarme e controle
      dentro do teclado por que neste algorimo
      estamos usando o teclado como base 
      para nosso código visto que é a partir dele
      que iremos manipular o alarme da casa
      *****/
    //Alterna o estado dos pinos das linhas
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(ti, HIGH);
    
    //Verifica se alguma tecla da coluna 1 foi pressionada
    if (digitalRead(7) == HIGH)
    {
      imprime_linha_coluna(ti-2, 1);
      atividade = true;
      /*
      Atribuindo um valor a variável portal que fará a função de menu
      neste caso portal será de 0 a 1 onde usaremos a estrutura 
      de seleção Switch case para determinar o que o código irá fazer
      de acordo com a opção escolhida.
      */
      portal = +1;
      while(digitalRead(7) == HIGH){}
    } 
    //Verifica se alguma tecla da coluna 2 foi pressionada    
    else if (digitalRead(8) == HIGH)
    {
      imprime_linha_coluna(ti-2, 2);
      //define atividade do teclado como verdadeira
      atividade = true;
      portal += 1;
      while(digitalRead(8) == HIGH){}
    }
    //Verifica se alguma tecla da coluna 3 foi pressionada
    else if (digitalRead(9) == HIGH)
    {
      imprime_linha_coluna(ti-2, 3);
      atividade = true;
      portal += 1;
      while(digitalRead(9) == HIGH){}
    }
    //Verifica se alguma tecla da coluna 4 foi pressionada
    else if (digitalRead(10) == HIGH)
    {
      imprime_linha_coluna(ti-2, 4);
      atividade = true;
      portal += 1;
      while(digitalRead(10) == HIGH){} 
    }else{
      atividade = false;//define atividade do teclado como falsa
    }
   }
   delay(10);
}

/*Metodo que irá obter os digitos 
do teclado a partir das linhas e colunas*/
void imprime_linha_coluna(int x, int y) 
{                                       
/* Compara as linhas e colunas pressionadas
 * e retorna o digito correspondente*/
  if ((x==1)&&(y==1)){
       letra = "1";
       Serial.println("1");
  }else if((x==1)&&(y==2)){
       letra = "2";
       Serial.println("2");
  }else if((x==1)&&(y==3)){
       letra = "3";
       Serial.println("3");
  }else if((x==1)&&(y==4)){
       letra = "A";
       Serial.println("A");
  }else if((x==2)&&(y==1)){
       letra = "4";
       Serial.println("4");
  }else if((x==2)&&(y==2)){
       letra = "5";
       Serial.println("5");
  }else if((x==2)&&(y==3)){
       letra = "6";
       Serial.println("6");
  }else if((x==2)&&(y==4)){
       letra = "B";
       Serial.println("B");
  }else if((x==3)&&(y==1)){
       letra = "7";
       Serial.println("7");
  }else if((x==3)&&(y==2)){
       letra = "8";
       Serial.println("8");
  }else if((x==3)&&(y==3)){
       letra = "9";
       Serial.println("9");
  }else if((x==3)&&(y==4)){
       letra = "C";
       Serial.println("C");
  }else if((x==4)&&(y==1)){
       letra = "*";
       Serial.println("*");
  }else if((x==4)&&(y==2)){
       letra = "0";
       Serial.println("0");
  }else if((x==4)&&(y==3)){
       letra = "#";
       Serial.println("#");
  }else if((x==4)&&(y==4)){
       letra = "D";
       Serial.println("D");
  }
       delay(10);
}
