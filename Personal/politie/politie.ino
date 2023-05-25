#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB + NEO_KHZ800);
#include <MeMCore.h>
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeIR ir;
MeBuzzer bz;
void setup() {
  // put your setup code here, to run once:
  pix.begin();
  ir.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int y = 0 ; y < 1900 ; y += 1) {
    bz.tone(y, 10);
    if (y % 60 == 0) {
      pix.setPixelColor(0, pix.Color(255, 0, 0));
      pix.setPixelColor(1, pix.Color(0, 0 , 0));
      pix.show();
    }
    if (y % 120 == 0) {
      pix.setPixelColor(0, pix.Color(0, 0, 0));
      pix.setPixelColor(1, pix.Color(0, 0, 255));
      pix.show();
    }
    delay(1);
  }
  for (int y = 1900 ; y > 150 ; y -= 1) {
    bz.tone(y, 10);
    if (y % 60 == 0) {
      pix.setPixelColor(0, pix.Color(255, 0, 0));
      pix.setPixelColor(1, pix.Color(0, 0 , 0));
      pix.show();
    }
    if (y % 120 == 0) {
      pix.setPixelColor(0, pix.Color(0, 0, 0));
      pix.setPixelColor(1, pix.Color(0, 0, 255));
      pix.show();
    }
    delay(1);
  }
  if (ir.decode()) {
    uint32_t value = (ir.value >> 16) & 0xFF;
    Serial.print("0x");
    Serial.println(value, HEX);
    if (value == 0x40) {
      motor1.run(-100);
      motor2.run(100);
    }
    if (value == 0x19) {
      motor1.run(100);
      motor2.run(-100);
    }
    if (value == 0x7) {
      motor1.run(0);
      motor2.run(100);
    }
    if (value == 0x9) {
      motor1.run(-100);
      motor2.run(0);
    }
  }
  else {
    motor1.stop();
    motor2.stop();
  }
  delay(100);
}
