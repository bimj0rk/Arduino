void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT);
 pinMode(A6, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 int x;
 x = analogRead(A6);
 if (x < 500){
  digitalWrite(13, HIGH);
 }
 else{
  digitalWrite(13, LOW);
 }
 Serial.println(x);
 delay(1000);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
