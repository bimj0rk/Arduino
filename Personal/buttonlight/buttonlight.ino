void setup() {
  // put your setup code here, to run once:
 pinMode(11, OUTPUT);
 pinMode(7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int stareButon = digitalRead(7);
 if (stareButon == 1) {
       digitalWrite(11, HIGH);
 } else {
      digitalWrite(11, LOW);
 }
}

