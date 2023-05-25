#include "MeMCore.h"           
MeHumiture x(PORT_2);
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 x.update();
 Serial.print("Humidity (%) =");
 Serial.print( x.getHumidity() );
 Serial.print(",Temperature (C) =");
 Serial.println( x.getTemperature() );
 delay(1000);
}
