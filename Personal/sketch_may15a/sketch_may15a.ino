void setup() {
  // put your setup code here, to run once:
 pinMode(8, OUTPUT);
 pinMode(A6, INPUT);
 pinMode(13, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int x = analogRead(A6);
 if (x < 500){
  tone(8, 6900, 1); 
  delay(10);
  tone(8, 3450, 1); 
  delay(10);
  tone(8, 6900, 1); 
  delay(10);
  tone(8, 3450, 1);
  delay(10);
  tone(8, 6900, 1); 
  delay(10);
  tone(8, 3450, 1); 
  delay(10);
  tone(8, 6900, 1); 
  delay(10);
  tone(8, 3450, 1);
  delay(1);
  tone(8, 6900, 1); 
  delay(1);
  tone(8, 3450, 1); 
  delay(1);
  tone(8, 6900, 1); 
  delay(1);
  tone(8, 3450, 1);
  delay(1);
  tone(8, 6900, 1); 
  delay(1);
  tone(8, 3450, 1); 
  delay(1);
  tone(8, 6900, 1); 
  delay(1);
  tone(8, 3450, 1);
  delay(1);
  digitalWrite(13, HIGH);
  delay(69);
  digitalWrite(13, LOW);
  delay(69);
 }
 Serial.println(x);
}
