#include <Servo.h>
#include <SR04.h>
#include <IRremote.h>
#define trigPin 12
#define echoPin 11

int activeBuzzer = 13;

Servo servoMotor;
int position = 0;
bool open = false;

SR04 ultrasonicSensor = SR04(echoPin, trigPin);
long distance;

int reciever = 9;
IRrecv irrecv(reciever);
decode_results results;
bool autonomousLock = false;
bool enableAuto = false;

void setup(){
  Serial.begin(9600); 
  pinMode(activeBuzzer, OUTPUT);
  servoMotor.attach(10);
  irrecv.enableIRIn();
}

void translateIR(){
  switch(results.value){
    case 0xFF629D:
      if(!autonomousLock){
        enableAuto = false;
        autonomousLock = true;
        Serial.println(enableAuto);
      } else {
        enableAuto = true;
        autonomousLock = false;
        Serial.println(enableAuto);
      }
      break;
      
    case 0xFFA857:
      manualOverrideOpen();
      break;

    case 0xFFE01F:
      manualOverrideClose();
      break;

    default:
      break;
  }
}

void autonomousMode(){
  for(position = 0; position <= 115; position++){ 
      servoMotor.write(position);            
      delay(15);
  }

  delay(8000);

  digitalWrite(activeBuzzer, HIGH);
  delay(1);
  digitalWrite(activeBuzzer, LOW);

  delay(2000);

  servoMotor.write(20);
}

void manualOverrideOpen(){
  digitalWrite(activeBuzzer, HIGH);
  delay(1);
  digitalWrite(activeBuzzer, LOW);
  delay(1000);

  for(int position = 0; position <= 115; position++){
      servoMotor.write(position);            
      delay(15);
  }

  digitalWrite(activeBuzzer, HIGH);
  delay(1);
  digitalWrite(activeBuzzer, LOW);
  delay(1);
  
  open = true;
}

void manualOverrideClose(){
  digitalWrite(activeBuzzer, HIGH);
  delay(1);
  digitalWrite(activeBuzzer, LOW);
  delay(1000);

  servoMotor.write(20);

  delay(250);
  digitalWrite(activeBuzzer, HIGH);
  delay(1);
  digitalWrite(activeBuzzer, LOW);
  delay(1);

  open = false;
}

void loop(){
  distance = ultrasonicSensor.Distance(); 

  if(irrecv.decode(&results)){
    translateIR();
    irrecv.resume();
  }

  if(distance <= 3 && enableAuto) autonomousMode();
  if(distance <= 3 && !enableAuto){
    if(open) manualOverrideClose();
    else manualOverrideOpen();
  }
}