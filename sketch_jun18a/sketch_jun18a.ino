long r;
#include <MeMCore.h>
MeUltrasonicSensor us(PORT_1);
MeLineFollower lf(PORT_3);
MeDCMotor m1(M1);
MeDCMotor m2(M2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int v = lf.readSensors();
  int x = us.distanceCm();
  if (x >= 10) {
    if (v == 3) {
      m1.run(-100);
      m2.run(100);
    }
    if (v == 2) {
      m1.run(-100);
      m2.stop();
    }
    if (v == 1) {
      m1.stop();
      m2.run(100);
    }
    if (v == 0) {
      m1.run(100);
      m2.run(-100);
      delay(1000);
      m1.stop();
      m2.run(100);
    }
  } else {
    m1.run(-205);
    m2.run(205);
  }
 Serial.println(x);
 delay(50);
}

