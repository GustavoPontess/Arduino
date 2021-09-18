void setup() 
{
  //setando os pinos de saida
  for (int counter = 22; counter < 33; ++counter) 
  {
    pinMode(counter,OUTPUT);
  }
  //setando os pinos de entrada
  for (int counter = 33; counter < 36; ++counter) 
  {
    pinMode(counter,INPUT);
  } 
  Serial.begin(9600);
  //led que esta no pino 30 pisca
  digitalWrite(30, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(30, LOW);
}
//definindo variaveis 
int led = 22, i=0;
int binario[8];
int decimal=0;
int dec[8] = {128, 64, 32, 16, 8, 4, 2, 1};
int de[]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88};
const char cha[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X'};
void loop() 
{
  if(led<30)
  { 
    digitalWrite(led, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    digitalWrite(led, LOW);
    delay(100); // Wait for 100 millisecond(s)
  }
  
  if(led<30)
  {
    if(digitalRead(35))//botão 0
    {
      delay(150);
      digitalWrite(led, LOW);
      binario[i]=0;
      led++; i++;
      if(led<24){Serial.print("Binario: ");}
      Serial.print("0");
      digitalWrite(30, HIGH);
      delay(100); // Wait for 100 millisecond(s)
      digitalWrite(30, LOW);
    }
    if(digitalRead(34))//botão 1
    {
      delay(150);
      digitalWrite(led, HIGH);
      binario[i]=1;
      led++; i++;
      if(led<24){Serial.print("Binario: ");}
      Serial.print("1");
      
      digitalWrite(30, HIGH);
      delay(100); // Wait for 100 millisecond(s)
      digitalWrite(30, LOW);
    }
  }
  else
  {
    if(i < 9)
    {
      delay(150);
      Serial.println(" ");
      Serial.println("-");
      Serial.print("Decimal: ");
      for (byte i = 0; i < 8; i = i + 1) 
      {
        if(binario[i] == 1)
        {
          decimal = decimal + dec[i];
        }
      }
      Serial.print(decimal);
      Serial.println(" ");
      Serial.println("-");
      Serial.print("Character: ");
      for (byte i = 0; i < 24; i++) 
      {
        if(de[i]==decimal)
        {
          Serial.print(cha[i]);
          Serial.println(" ");
        }
      }
      i++;
    }
    if(digitalRead(33))
    {
      for(byte i = 0;i<8;i++)
      {
        if(binario[i]==0)
        {
          digitalWrite(32,HIGH);
          delay(100);
          digitalWrite(32,LOW);
          digitalWrite(31, LOW);
          delay(1500); // Wait for 100 millisecond(s)
        }
        else
        {
          digitalWrite(32,HIGH);
          delay(100);
          digitalWrite(32,LOW);
          digitalWrite(31, HIGH);
          delay(1500); // Wait for 100 millisecond(s)
        }
      }
      digitalWrite(31,LOW);
    }
  }
}
