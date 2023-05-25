byte seven_segment_digits[10] = {B11111100, B01100000, B11011010, B11110010, B01100110, B10110110, B10111110, B11100000, B11111110, B11100110};

#define dataPin 2
#define latchPin 3
#define clockPin 4

void setup(){
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void sevenSegmentWrite(byte digit){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, seven_segment_digits[digit]);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  for(byte i = 10; i > 0; --i){
    delay(1000);
    sevenSegmentWrite(i - 1);
  }
  
  delay(3000);
}
