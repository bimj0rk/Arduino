int tempSensorPin = A0;
int potMeterPin = A1;
int buttonPin = PD2;

int timer = 0;

void setup() {
  Serial.begin(9600);

  PORTD |= (1 << buttonPin);

  ADMUX = 0;
  ADMUX |= (1 << MUX0);
  ADMUX |= (1 << REFS0);

  ADCSRA = 0;
  ADCSRA |= (7 << ADPS0);
  ADCSRA |= (1 << ADEN);
}

void loop() {
  //1
  float valuePotMeter = analogRead(potMeterPin);
  float valueTempSensor = analogRead(tempSensorPin);

  float tempValue = (((valueTempSensor * 5) / 1024) - 0.5) * 100;

  Serial.print("Potential value: ");
  Serial.println(valuePotMeter);
  Serial.print("Temperature value: ");
  Serial.println(tempValue);
  Serial.println(" ");

  delay(500);

  //2
  int valueButton = PIND & (1 << buttonPin);
  if(valueButton == LOW){
    ADCSRA |= (1 << ADSC);
    while (!(ADCSRA & (1 << ADIF)));
    uint16_t valuePotMeter = ADC;
    Serial.print("Potential value: ");
    Serial.println(valuePotMeter);
    Serial.println();
    delay(1000);
  } 

  //3
  if(timer == 10){
    ADCSRA |= (1 << ADSC);
    while (!(ADCSRA & (1 << ADIF)));
    uint16_t valuePotMeter = ADC;
    Serial.print("Potential value: ");
    Serial.println(valuePotMeter);
    Serial.println();
    delay(1000);
    timer -= 10;
  } else timer++;
}
