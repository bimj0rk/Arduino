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
 if(x < 500){
  Serial.println("Lumina Slaba");
 }
 else if(501 < x && x < 900){
  Serial.println("Lumina normala");
 }
 else{
  Serial.println("Lumina puterinca");
 }
 delay(1000);

}
