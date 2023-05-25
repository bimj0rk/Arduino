#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB+NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
 pix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
 pix.setPixelColor(0, pix.Color(255, 0, 0));
 pix.show();
 delay(5000);
 pix.setPixelColor(0, pix.Color(255, 255, 0));
 pix.show();
 delay(750);
 pix.setPixelColor(0, pix.Color(0, 0, 0));
 pix.show();
 delay(250);
 pix.setPixelColor(0, pix.Color(255, 255, 0));
 pix.show();
 delay(750);
 pix.setPixelColor(0, pix.Color(0, 255, 0));
 pix.show();
 delay(5000);
}
