#include <MeMCore.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB + NEO_KHZ800);
MeUltrasonicSensor usens(PORT_3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (usens.distanceCm() < 10) {
    pix.setPixelColor(0, pix.Color(0, 51, 102));
    pix.setPixelColor(1, pix.Color(0, 51, 102));
    pix.show();
  } else {
    pix.setPixelColor(0, pix.Color(0, 0, 0));
    pix.setPixelColor(1, pix.Color(0, 0, 0));
    pix.show(); 
  }
  Serial.println(usens.distanceCm());
}
