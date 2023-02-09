#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB+NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
pix.begin();
pinMode(8, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int x=0 ; x<1900 ; x+=1){
 tone(8, x, 10);
 if(x%60 == 0){
 pix.setPixelColor(0, pix.Color(255, 0, 0));
 pix.setPixelColor(1, pix.Color(0, 0 ,0));
 pix.show();
 }
 if(x%120 == 0){
 pix.setPixelColor(0, pix.Color(0, 0, 0));
 pix.setPixelColor(1, pix.Color(0, 0, 255));
 pix.show();
 }
 delay(1);
 }
 for(int x=1900 ; x>150 ; x-=1){
 tone(8, x, 10);
 if(x%60 == 0){
 pix.setPixelColor(0, pix.Color(255, 0, 0));
 pix.setPixelColor(1, pix.Color(0, 0 ,0));
 pix.show();
 }
 if(x%120 == 0){
 pix.setPixelColor(0, pix.Color(0, 0, 0));
 pix.setPixelColor(1, pix.Color(0, 0, 255));
 pix.show();
 }
 delay(1);
 }
 digitalWrite(5, HIGH);
 digitalWrite(6, HIGH);
 delay(1);
 digitalWrite(5, LOW);
 digitalWrite(6, LOW);
 delay(1);
}
