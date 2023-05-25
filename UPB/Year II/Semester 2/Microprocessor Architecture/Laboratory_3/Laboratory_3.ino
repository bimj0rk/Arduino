//1
volatile int dt = 500;

ISR(INT0_vect){
  PORTD ^= (1 << PD7);

  if((PIND & (1 << PD2)) == 0) dt += 100;
}
 
ISR(PCINT2_vect){
  if((PIND & (1 << PD4)) == 0) PORTD ^= (1 << PD7);

  if((PIND & (1 << PD4)) == 0) dt -= 100;
}
 
void setup_interrupts(){
  cli();
 
  DDRD &= ~(1 << PD2) & ~(1 << PD4);
  PORTD |= (1 << PD2) | (1 << PD4);
 
  EICRA |= (1 << ISC00);
  PCICR |= (1 << PCIE2);
 
  EIMSK |= (1 << INT0);
  PCMSK2 |= (1 << PCINT20);
 
  sei();
}
 
void setup(){
  setup_interrupts();
  DDRD |= (1 << PD7);
  PORTD &= ~(1 << PD7);
}

//2 
void loop(){
  PORTD |= (1 << PD7);
  delay(dt);
  PORTD &= ~(1 << PD7);
  delay(dt);
}