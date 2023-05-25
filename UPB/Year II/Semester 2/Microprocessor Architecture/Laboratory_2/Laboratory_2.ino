#include "usart.h"
#include <SoftwareSerial.h>

#define led 13
#define button 2

#define led PB5
#define button PD2
long ts = 0;

SoftwareSerial serial1(10, 11);
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  DDRB |= (1 << led);
  PORTD |= (1 << button);
  USART0_init();

  Serial.begin(57600);
  while(!Serial){
    ;
  }

  Serial.println("Mesaj de pe placa 1");

  serial1.begin(4800);
  serial1.println("Mesaj de pe placa 2");
}

void loop() {
  //1a
  if(millis() - ts >= 100) ts = millis();

  if(Serial.available()){
    char command = Serial.read();
    char on = "on";
    char off = "off";
    char blink = "blink";
    char get = "get";
    if(strcmp(command, on) == 0) digitalWrite(led, HIGH);
    else if(strcmp(command, off) == 0) digitalWrite(led, LOW);
    else if(strcmp(command, blink) == 0){
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
    else if(strcmp(command, get) == 0){ //asta nu merge
      int valueButton = digitalRead(button);
      if(valueButton == HIGH) Serial.println("Button pressed");
      else if(valueButton == LOW) Serial.println("Button depressed");
    }
    else Serial.println("Wrong command");
  }

  //1b
  if(millis() - ts >= 100) ts = millis();

  char command = Serial.read();
    char on = "on";
    char off = "off";
    char blink = "blink";
    char get = "get";
    if(strcmp(command, on) == 0) PORTB |= (1 << LED);
    else if(strcmp(command, off) == 0) PORTB &= ~(1 << LED);
    else if(strcmp(command, blink) == 0){
      PORTB |= (1 << LED);
      delay(200);
      PORTB &= ~(1 << LED);
      delay(200);
    }
    else if(strcmp(command, get) == 0){ //asta nu merge
      int valueButton = PIND & (1 << Button1);
      if(valueButton == HIGH) Serial.println("Button pressed");
      else if(valueButton == LOW) Serial.println("Button depressed");
    }
    else Serial.println("Wrong command");
  }

  //2
  int valueButton = digitalRead(button);
  if(valueButton == LOW) USART0_print("Button pressed\n");
  else if(valueButton == HIGH) USART0_print("Button depressed\n");

  //3
  if(serial1.available()) Serial.write(serial1.read());
  if(Serial.available()) serial1.write(Serial.read());
}
