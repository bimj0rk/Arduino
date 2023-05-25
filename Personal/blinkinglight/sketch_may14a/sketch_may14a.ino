void setup() {
  // put your setup code here, to run once:
 pinMode(A6, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int x;
 x = analogRead(A6);
 Serial.println(x);
if(x<500){
Serial.println("Lumina Slaba");
}
if(501<x<900){
  Serial.println("Lumina Normala");
}
if(x<900){
  Serial.println("Lumina Puternica");
}
delay(1000);
}
