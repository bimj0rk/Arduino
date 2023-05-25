#define LED 13
#define button1 2
#define button2 3

#define LED PB5
#define Button1 PD2
#define Button2 PD3

int timeDelay = 500;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  DDRB |= (1 << LED);
  PORTD |= (1 << Button1);
  PORTD |= (1 << Button2);
}

void loop() {
  //1a
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);

  //1b
  PORTB |= (1 << LED);
  delay(500);
  PORTB &= ~(1 << LED);
  delay(500);

  //2a
  int valueButton1 = digitalRead(button1);
  if(valueButton1 == HIGH) digitalWrite(LED, LOW);
  else digitalWrite(LED, HIGH);

  //2b
  int valueButton1 = PIND & (1 << Button1);
  if(valueButton1 == LOW) PORTB |= (1 << LED);
  else PORTB &= ~(1 << LED);

  //3a
  int valueButton1 = digitalRead(button1);
  int valueButton2 = digitalRead(button2);
  if(valueButton1 == LOW) timeDelay -= 100;
  if(valueButton2 == LOW) timeDelay += 100;

  digitalWrite(LED, HIGH);
  delay(timeDelay);
  digitalWrite(LED, LOW);
  delay(timeDelay);
  
  //3b
  int valueButton1 = PIND & (1 << Button1);
  int valueButton2 = PIND & (1 << Button2);

  if(valueButton1 == LOW) timeDelay -= 100;
  if(valueButton2 == LOW) timeDelay += 100;

  PORTB |= (1 << LED);
  delay(timeDelay);
  PORTB &= ~(1 << LED);
  delay(timeDelay);
}
