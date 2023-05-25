#include <SPI.h>

#define SS_PIN 10 

//1S
volatile char receivedMessage[50];
volatile int messageIndex = 0;
volatile int messageLength = 0;
volatile bool messageReceived = false;

void setup() {
  //1M
  Serial.begin(9600);
  SPI.begin();
  pinMode(SS_PIN, OUTPUT);
  SPI.attachInterrupt();
  //1S
  Serial.begin(9600);
  SPI.begin();
  pinMode(SS_PIN, INPUT);
  SPI.attachInterrupt();
}

void loop() {
  //1M
  char message[] = "Hello Slave!"; 
  digitalWrite(SS_PIN, LOW);   
  SPI.transfer(strlen(message)); 
  for(int i = 0; i < strlen(message); i++) SPI.transfer(message[i]);  
  
  digitalWrite(SS_PIN, HIGH); 
  delay(1000);

  //1S
  if(messageReceived){  
    Serial.print("Received message: ");
    for(int i = 0; i < messageLength; i++) Serial.print(receivedMessage[i]); 
    Serial.println();
    messageReceived = false;
    messageIndex = 0;
    messageLength = 0;
  }
}

ISR(SPI_STC_vect){ 
  char c = SPDR;
  if(messageIndex == 0) messageLength = c;
  else receivedMessage[messageIndex - 1] = c;
  messageIndex++;
  if(messageIndex > messageLength) messageReceived = true;
}