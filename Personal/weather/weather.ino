#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int reading = analogRead(5);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float tempC = (voltage * 0.5) * 100;
  int humidityLevel = analogRead(4);

  lcd.setCursor(0, 0);
  lcd.print("Temp :");
  lcd.setCursor(5, 0);
  lcd.print(tempC);
  lcd.setCursor(0, 1);
  lcd.print("Umid :");
  lcd.setCursor(5, 1);
  lcd.print(humidityLevel);
}
