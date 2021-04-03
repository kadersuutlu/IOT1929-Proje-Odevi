#include <LiquidCrystal.h> 
LiquidCrystal lcd(8,7,4,5,6,12);

const int higro=A0;
int kirmizi_led=2;
int yesil_led=3;
int buzzer=13;

int olcum_sonucu;

void setup() 
{
  lcd.begin(16,2);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(13,OUTPUT);
}
void loop() 
{
  

  
  olcum_sonucu=analogRead(higro);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nem:");
  lcd.print(olcum_sonucu);
  delay(500);
  if(olcum_sonucu>500)
  {
    lcd.setCursor(0,1);
    lcd.print("Toprak susuz");
    digitalWrite(kirmizi_led,HIGH);
    delay(500);
    
    digitalWrite(kirmizi_led,LOW);
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
  }
  
  else 
  {
    lcd.setCursor(0,1);
    lcd.print("Toprak normal");
    digitalWrite(yesil_led,HIGH);
    delay(500);
    digitalWrite(yesil_led,LOW);
  }
  
}
