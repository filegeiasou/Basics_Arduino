#include <LiquidCrystal.h>

const int rs=12 ,en=11, db4=5 ,db5=4 , db6=3 ,db7=2;

LiquidCrystal lcd(rs,en,db4,db5,db6,db7);

void setup()
{
  lcd.begin(16,2);
  lcd.print("Created by filegeiasou");
}

void loop()
{
  for(int pc =1 ; pc++;)
  {
		lcd.scrollDisplayLeft();
    	delay(100);
  }
  delay(5000);
}