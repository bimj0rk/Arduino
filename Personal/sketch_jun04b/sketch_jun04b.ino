#include "MeMCore.h"
MeLineFollower lf(PORT_2);
MeDCMotor m1(M1);
MeDCMotor m2(M2);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 int valorie = lf.readSensors();
 if(valorie == 3){
  m1.run(-90);
  m2.run(90);
 }
 if(valorie == 0){
  m1.run(200);
  m2.run(-200);
 }
}
