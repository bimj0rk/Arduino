#include "MeMCore.h"    
#include <Adafruit_NeoPixel.h>       
MeHumiture x(PORT_2);
MeBuzzer y;
Adafruit_NeoPixel pix(2, 13, NEO_RGB+NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
 x.update();
if (x.getTemperature() > 29){
  pix.setPixelColor(0, pix.Color(102, 51, 0));
  pix.setPixelColor(1, pix.Color(49, 0, 99));
  pix.show();
  Serial.println("Temperatura ridicata");
  y.tone(500, 500);
} else {
  pix.setPixelColor(0, pix.Color(0, 0, 0));
  pix.setPixelColor(1, pix.Color(0, 0, 0));
  pix.show();
}
 Serial.print("Temperatura (C) =");
 Serial.println(x.getTemperature());
 delay(500);
}
