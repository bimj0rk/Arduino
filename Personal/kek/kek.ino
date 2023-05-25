#include <MeMCore.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB + NEO_KHZ800);
MeDCMotor m1(M1);
MeDCMotor m2(M2);
MeIR ir;
MeUltrasonicSensor s(PORT_3);
void setup() {
  // put your setup code here, to run once:
pix.begin();
ir.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
if(ir.decode()); {
  uint32_t value = (ir.value >> 16) & 0xFF;
  if (value == 0x40){
    m1.run(-100);
    m2.run(100);
  }
  if (value == 0x7){
    m1.run(0);
    m2.run(100); 
  }
  if (value == 0x9){
    m1.run(-100);
    m2.run(0);
  }
  if (value == 0x19){
    m1.run(100);
    m2.run(-100); 
  }
    else {
    m1.stop();
    m2.stop();
  }
  delay(100);
}
  if (s.distanceCm() < 10) {
    pix.setPixelColor(0, pix.Color(0, 51, 102));
    pix.setPixelColor(1, pix.Color(0, 51, 102));
    pix.show();
    m1.stop();
    m2.stop();
  } else {
    pix.setPixelColor(0, pix.Color(0, 0, 0));
    pix.setPixelColor(1, pix.Color(0, 0, 0));
    pix.show(); 
  }
}
