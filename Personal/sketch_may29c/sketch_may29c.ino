long r;
#include <MeMCore.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB + NEO_KHZ800);
MeDCMotor m1(M1);
MeDCMotor m2(M2);
MeIR ir;
MeUltrasonicSensor s(PORT_3);
MeBuzzer bz;
void setup() {
  // put your setup code here, to run once:
pix.begin();
ir.begin();
Serial.begin(9600);
randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
r = random(0, 2);
if(s.distanceCm() <= 10){
 if(r == 1){ 
  m1.run(-100);
  m2.run(0); 
  pix.setPixelColor(0, pix.Color(0, 51, 102));
  pix.setPixelColor(1, pix.Color(0, 51, 102));
  pix.show();
  bz.tone(500, 10);
 }
 if(r == 0){
  m1.run(0);
  m2.run(100); 
  pix.setPixelColor(0, pix.Color(0, 99, 49));
  pix.setPixelColor(1, pix.Color(0, 99, 49));
  pix.show();
  bz.tone(1000, 10);
 }
}
 if(s.distanceCm() > 11){
  m1.run(-100);
  m2.run(100);
  pix.setPixelColor(0, pix.Color(0, 0, 0));
  pix.setPixelColor(1, pix.Color(0, 0, 0)); 
  pix.show(); 
 }
 delay(750);
}
