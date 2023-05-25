#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB+NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
 pinMode(A7, INPUT);
 Serial.begin(9600);
 pix.begin();
 pinMode(8, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
 int x = analogRead(A7);
 if (x == 0){
  Serial.println("Apasat");
  delay(1000);
  pix.setPixelColor(0, pix.Color(255, 0, 255));
  pix.setPixelColor(1, pix.Color(0, 255, 0));
  pix.show();
  tone(8, 1000, 100);
 }else{
  pix.setPixelColor(0, pix.Color(0, 0, 0));
  pix.setPixelColor(1, pix.Color(0, 0, 0));
  pix.show();
 }
}

