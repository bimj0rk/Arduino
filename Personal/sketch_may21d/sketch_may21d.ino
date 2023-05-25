#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB + NEO_KHZ800);
void setup() {
  pinMode(A7, INPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  pix.begin();
}
int q = 0;
void loop() {
  int x = analogRead(A7);
  if (x == 0) {
    q++;
    delay(200);
  }
  if (q == 2) {
    pix.setPixelColor(0, pix.Color(23, 25, 24));
    pix.setPixelColor(1, pix.Color(255, 23, 255));
    pix.show();
  }
}
