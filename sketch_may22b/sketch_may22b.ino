#include <MeMCore.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB + NEO_KHZ800);
MeUltrasonicSensor y(PORT_3);
MeBuzzer x;
void setup() {
  Serial.begin(9600);
  pix.begin();
}

void loop() {
  if (y.distanceCm() < 10) {
    pix.setPixelColor(0, pix.Color(0, 51, 102));
    pix.setPixelColor(1, pix.Color(0, 51, 102));
    pix.show();
    x.tone(1000, 250);
    delay(250);
  } else if (y.distanceCm() < 50){
    pix.setPixelColor(0, pix.Color(49, 99, 0));
    pix.setPixelColor(1, pix.Color(49, 99, 0));
    pix.show();
    x.tone(500, 125);
    delay(500);
  } else {
    pix.setPixelColor(0, pix.Color(0, 0, 0));
    pix.setPixelColor(1, pix.Color(0, 0, 0));
    pix.show();
    x.tone(0, 0);
  }
  Serial.println(y.distanceCm());
}
