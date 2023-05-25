long r;
#include <MeMCore.h>
MeLineFollower lf(PORT_2);
MeDCMotor m1(M1);
MeDCMotor m2(M2);
MeUltrasonicSensor s(PORT_3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A7, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
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
  r = random(0, 2);
  if (s.distanceCm() <= 10) {
    if (r == 1) {
      m1.run(-100);
      m2.run(0);
    }
    if (r == 0) {
      m1.run(0);
      m2.run(100);
    }
  }
  if (s.distanceCm() > 11) {
    m1.run(-100);
    m2.run(100);
  }
  delay(750);

}


