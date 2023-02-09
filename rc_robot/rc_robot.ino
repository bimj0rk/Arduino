#include <MeMCore.h>
#include <Adafruit_NeoPixel.h>
#include <rp2040_pio.h>

long r;
Adafruit_NeoPixel pix(2, 13, NEO_GRB + NEO_KHZ800);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
MeIR ir;
MeBuzzer bz;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  ir.begin();
  pix.begin();
}
int q = 0;
void loop() {
  // put your main code here, to run repeatedly:

  if (ir.decode()) {
    uint32_t value = (ir.value >> 16) & 0xFF;
    Serial.print("0x");
    Serial.println(value, HEX);
x
    if (value == 0x40) {
      motor1.run(-q);
      motor2.run(q);
    }
    if (value == 0x19) {
      motor1.run(q);
      motor2.run(-q);
    }
    if (value == 0x7) {
      motor1.run(0);
      motor2.run(q);
    }
    if (value == 0x9) {
      motor1.run(-q);
      motor2.run(0);
    }
  } else {
    motor1.stop();
    motor2.stop();
  }
  delay(100);
}
