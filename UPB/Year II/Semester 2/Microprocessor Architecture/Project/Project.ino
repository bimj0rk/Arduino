#include <Servo.h>
#include "SR04.h"
#include "IRremote.h"
#define TRIG_PIN 12
#define ECHO_PIN 11

int activeBuzzer = 13; //buzzer-ul este conectat pe pinul 13

Servo servoMotor; //initializez servo-ul

//initializez senzorul ultrasonic
SR04 ultrasonicSensor = SR04(ECHO_PIN, TRIG_PIN);
long distance = ultrasonicSensor.Distance();

//initializez senzorul IR
int reciever = 9;
IRrecv irrecv(reciever);
decode_results results;
int remoteButton;

//traducerea butoanelor folosite de pe telecomanda IR
void translateIR(){
    switch(results.value){
    case 0xFF30CF: //butonul 1 de pe telecomanda, va fi folosit pentru modul autonom
        remoteButton = 1;
    
    case 0xFF18E7: //butonul 2 de pe telecomanda, va fi folosit pentru deschiderea manuala
        remoteButton = 2;

    case 0xFF7A85: //butonul 3 de pe telecomanda, va fi folosit pentru inchiderea manuala
        remoteButton = 3;
    
    default:
        Serial.println("Button not found");
    }
}

void autonomousMode(){
    //servo-ul va deschide usor capacul
    for(int position = 0; position <= 215; position++){ 
        servoMotor.write(position);            
        delay(15);
    }

    delay(8000); //timp de asteptate: 8 secunde

    //sunet de avertizare
    digitalWrite(activeBuzzer, HIGH);
    delay(1);
    digitalWrite(activeBuzzer, LOW);

    //timp de asteptare: 2 secunde
    delay(2000);

    //servo-ul inchide capacul
    servoMotor.write(20);
}

void manualOverrideOpen(){
    //sunet de avertizare
    digitalWrite(activeBuzzer, HIGH);
    delay(1);
    digitalWrite(activeBuzzer, LOW);
    delay(1000);

    //servo-ul va deschide usor capacul
    for(int position = 0; position <= 215; position++){
        servoMotor.write(position);            
        delay(15);
    }

    //sunet de avertizare
    digitalWrite(activeBuzzer, HIGH);
    delay(1);
    digitalWrite(activeBuzzer, LOW);
    delay(1);
}

void manualOverrideClose(){
    //sunet de avertizare
    digitalWrite(activeBuzzer, HIGH);
    delay(1);
    digitalWrite(activeBuzzer, LOW);
    delay(1000);

    //servo-ul inchide capacul
    servoMotor.write(20);

    //sunet de avertizare
    digitalWrite(activeBuzzer, HIGH);
    delay(1);
    digitalWrite(activeBuzzer, LOW);
    delay(1);
}

void setup(){
    Serial.begin(9600); //pentru debugging
    pinMode(activeBuzzer, OUTPUT); //activez buzzer-ul ca output
    servoMotor.attach(10); //servo-ul este conectat pe pinul 10
    irrecv.enableIRIn(); //activez reciever-ul IR
}

void loop(){
    if(remoteButton == 1 || distance <= 4){ //daca este apasat butonul 1 de pe telecomanda sau mana trece la mai putin de 4cm, se porneste modul autonom
        Serial.println("Autonomous mode");
        autonomousMode();
        Serial.println("Autonomous mode ended");
    }
    else if(remoteButton == 2){ //daca este apasat butonul 2 de pe telecomanda, cutia se va deschide manual
        Serial.println("Manual override open");
        manualOverrideOpen();
        Serial.println("Manual override open ended");
    }
    else if(remoteButton == 3){ //daca este apasat butonul 3 de pe telecomanda, cutia se va inchide manual
        Serial.println("Manual override close");
        manualOverrideClose();
        Serial.println("Manual override close ended");
    }
}