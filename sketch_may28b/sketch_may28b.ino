#include <MeMCore.h>
MeIR ir;
void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT);
 digitalWrite(13, LOW);
 ir.begin();
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(ir.decode()){
  uint32_t value = (ir.value>>16) & 0xFF;
  Serial.print("0x");
  Serial.println(value,HEX);
 }
}
