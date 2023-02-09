long r;
#include <MeMCore.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_RGB + NEO_KHZ800);
MeDCMotor m1(M1);
MeDCMotor m2(M2);
MeIR ir;
MeLineFollower lf(PORT_3);
MeUltrasonicSensor s(PORT_1);
void setup() {
  // put your setup code here, to run once:
  pix.begin();
  ir.begin();
  Serial.begin(9600);
}
int x = 0;
int q = 0;
int y = 0;
void loop() {
  // put your main code here, to run repeatedly:
  if (ir.decode()) {
    uint32_t value = (ir.value >> 16) & 0xFF;
    Serial.print("0x");
    Serial.println(value, HEX);
    if (value == 0x45) {
      x = 1;
    }
    if (value == 0x46) {
      x = 2;
    }
    if (value == 0x47) {
      x = 3;
    }
    if (value == 0x15) {
      y = 0;
    }
    if (value == 0x40) {
      y = 1;
    }
    if (value == 0x7) {
      y = 2;
    }
    if (value == 0x9) {
      y = 3;
    }
    if (value == 0x19) {
      y = 4;
    }
    if (value == 0x16) {
      q = 80;
    }
    if (value == 0xC) {
      q = 100;
    }
    if (value == 0x18) {
      q = 120;
    }
    if (value == 0x5E) {
      q = 140;
    }
    if (value == 0x8) {
      q = 160;
    }
    if (value == 0x1C) {
      q = 180;
    }
    if (value == 0x5A) {
      q = 200;
    }
    if (value == 0x42) {
      q = 220;
    }
    if (value == 0x52) {
      q = 240;
    }
    if (value == 0x4A) {
      q = 250;
    }
  }
  else {
    y = 0;
  }
  if (x == 3) {
    if (y == 1) {
      m1.run(-q);
      m2.run(q);
    }
    if (y == 2) {
      m1.stop();
      m2.run(q);
    }
    if (y == 3) {
      m1.run(-q);
      m2.stop();
    }
    if (y == 4) {
      m1.run(q);
      m2.run(-q);
    }
    if (y == 0) {
      m1.stop();
      m2.stop();
    }
    delay(100);
  }
  if (x == 2) {
    int val = lf.readSensors();
    if (val == 0) {
      m1.run(-q);
      m2.run(q);
    }
    if (val == 1) {
      m1.stop();
      m2.run(q);
    }
    if (val == 2) {
      m1.run(-q);
      m2.stop();
    }
  }
  if (x == 1) {
    r = random(0, 2);
    if (s.distanceCm() <= 10) {
      if (r == 1) {
        m1.run(-q);
        m2.run(0);
        delay(125);
      }
      if (r == 0) {
        m1.run(0);
        m2.run(q);
        delay(125);
      }
    }
    if (s.distanceCm() > 11) {
      m1.run(-q);
      m2.run(q);
    }
  }
  delay(100);
}
