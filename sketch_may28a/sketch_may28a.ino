#include <MeMCore.h>
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);
int8_t motorSpeed = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(A7, INPUT);
}
int x = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int y = analogRead(A7);
  if (y == 0) {
    x++;
    delay(200);
    if (x >= 3) {
    x = 0;
    }
  }
  if (x == 1) {
    motor1.run(motorSpeed);
    motor2.run(-motorSpeed);
  }
  if (x == 2) {
    motor1.stop();
    motor2.stop();
    delay(100);
  }
}


