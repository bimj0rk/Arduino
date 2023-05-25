#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop(){
  lcd.setCursor(3, 0);
  lcd.print("Buzzulache");
  lcd.setCursor(2, 1);
  lcd.print("is the best!");
  }
