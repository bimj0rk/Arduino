#include <MeMCore.h>
MeLineFollower lf(PORT_2);
MeDCMotor m1(M1);
MeDCMotor m2(M2);
MeUltrasonicSensor us(PORT_4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int y = 0;
void loop() {
  // put your main code here, to run repeatedly
  int x = us.distanceCm();
  if (x >= 6) {
    y = 0;
  }
  if (x <= 5) {
    y = 1;
  }
  while (y == 0) {
    int val = lf.readSensors();
    if (val == 0) {
      m1.run(-90);
      m2.run(90);
    }
    if (val == 1) {
      m1.stop();
      m2.run(90);
    }
    if (val == 2) {
      m1.run(-90);
      m2.stop();
    }
  }
  while (y == 1) {
    int val = lf.readSensors();
    m1.run(-100);
    m2.run(0);
    delay(100);
    if (val == 0) {
      y = 0;
    }
  }
}

