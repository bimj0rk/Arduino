#include "pitches.h"

#define speakerPin 8
#define tempo 250 //tempo-ul piesei
#define length 640 // the number of notes

uint16_t notes[] = { NOTE_E5, NOTE_E5, ' ', NOTE_E5, ' ', NOTE_C5, NOTE_E5, ' ', NOTE_G5, ' ', ' ', ' ', NOTE_G4, ' ', ' ', ' ',           //0

                   NOTE_C5, ' ', ' ', NOTE_G4, ' ', ' ', NOTE_E4, ' ', ' ', NOTE_A4, ' ', NOTE_B4, ' ', NOTE_AS4, NOTE_A4, ' ',          //1
                   NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, ' ', NOTE_F5, NOTE_G5, ' ', NOTE_E5, ' ', NOTE_C5, NOTE_D5, NOTE_B4, ' ', ' ',
                   NOTE_C5, ' ', ' ', NOTE_G4, ' ', ' ', NOTE_E4, ' ', ' ', NOTE_A4, ' ', NOTE_B4, ' ', NOTE_AS4, NOTE_A4, ' ',
                   NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, ' ', NOTE_F5, NOTE_G5, ' ', NOTE_E5, ' ', NOTE_C5, NOTE_D5, NOTE_B4, ' ', ' ',

                   ' ', ' ', NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, ' ', NOTE_E5, ' ', NOTE_GS4, NOTE_A4, NOTE_C5, ' ', NOTE_A4, NOTE_C5, NOTE_D5, //1'
                   ' ', ' ', NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, ' ', NOTE_E5, ' ', NOTE_C6, ' ', NOTE_C6, NOTE_C6, ' ', ' ', ' ',
                   ' ', ' ', NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, ' ', NOTE_E5, ' ', NOTE_GS4, NOTE_A4, NOTE_C5, ' ', NOTE_A4, NOTE_C5, NOTE_D5,
                   ' ', ' ', NOTE_DS5, ' ', ' ', NOTE_D5, ' ', ' ', NOTE_C5, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',

                   ' ', ' ', NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, ' ', NOTE_E5, ' ', NOTE_GS4, NOTE_A4, NOTE_C5, ' ', NOTE_A4, NOTE_C5, NOTE_D5, //1'
                   ' ', ' ', NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, ' ', NOTE_E5, ' ', NOTE_C6, ' ', NOTE_C6, NOTE_C6, ' ', ' ', ' ',
                   ' ', ' ', NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, ' ', NOTE_E5, ' ', NOTE_GS4, NOTE_A4, NOTE_C5, ' ', NOTE_A4, NOTE_C5, NOTE_D5,
                   ' ', ' ', NOTE_DS5, ' ', ' ', NOTE_D5, ' ', ' ', NOTE_C5, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',

                   NOTE_C5, NOTE_C5, ' ', NOTE_C5, ' ', NOTE_C5, NOTE_D5, ' ', NOTE_E5, NOTE_C5, ' ', NOTE_A4, NOTE_G4, ' ', ' ', ' ',       //2
                   NOTE_C5, NOTE_C5, ' ', NOTE_C5, ' ', NOTE_C5, NOTE_D5, NOTE_E5, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                   NOTE_C5, NOTE_C5, ' ', NOTE_C5, ' ', NOTE_C5, NOTE_D5, ' ', NOTE_E5, NOTE_C5, ' ', NOTE_A4, NOTE_G4, ' ', ' ', ' ',
                   NOTE_E5, NOTE_E5, ' ', NOTE_E5, ' ', NOTE_C5, NOTE_E5, ' ', NOTE_G5, ' ', ' ', ' ', NOTE_G4, ' ', ' ', ' ',

                   NOTE_C5, ' ', ' ', NOTE_G4, ' ', ' ', NOTE_E4, ' ', ' ', NOTE_A4, ' ', NOTE_B4, ' ', NOTE_AS4, NOTE_A4, ' ',          //1
                   NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, ' ', NOTE_F5, NOTE_G5, ' ', NOTE_E5, ' ', NOTE_C5, NOTE_D5, NOTE_B4, ' ', ' ',
                   NOTE_C5, ' ', ' ', NOTE_G4, ' ', ' ', NOTE_E4, ' ', ' ', NOTE_A4, ' ', NOTE_B4, ' ', NOTE_AS4, NOTE_A4, ' ',
                   NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, ' ', NOTE_F5, NOTE_G5, ' ', NOTE_E5, ' ', NOTE_C5, NOTE_D5, NOTE_B4, ' ', ' ',

                   NOTE_E5, NOTE_C5, ' ', NOTE_G4, ' ', ' ', NOTE_GS4, ' ', NOTE_A4, NOTE_F5, ' ', NOTE_F5, NOTE_A4, ' ', ' ', ' ',        //3
                   NOTE_B4, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5, ' ', NOTE_A4, NOTE_G4, ' ', ' ', ' ',
                   NOTE_E5, NOTE_C5, ' ', NOTE_G4, ' ', ' ', NOTE_GS4, ' ', NOTE_A4, NOTE_F5, ' ', NOTE_F5, NOTE_A4, ' ', ' ', ' ',
                   NOTE_B4, NOTE_F5, ' ', NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, ' ', ' ', ' ', ' ', ' ', ' ', ' ',

                   NOTE_E5, NOTE_C5, ' ', NOTE_G4, ' ', ' ', NOTE_GS4, ' ', NOTE_A4, NOTE_F5, ' ', NOTE_F5, NOTE_A4, ' ', ' ', ' ',        //3
                   NOTE_B4, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5, ' ', NOTE_A4, NOTE_G4, ' ', ' ', ' ',
                   NOTE_E5, NOTE_C5, ' ', NOTE_G4, ' ', ' ', NOTE_GS4, ' ', NOTE_A4, NOTE_F5, ' ', NOTE_F5, NOTE_A4, ' ', ' ', ' ',
                   NOTE_B4, NOTE_F5, ' ', NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, ' ', ' ', ' ', ' ', ' ', ' ', ' ',

                   NOTE_C5, NOTE_C5, ' ', NOTE_C5, ' ', NOTE_C5, NOTE_D5, ' ', NOTE_E5, NOTE_C5, ' ', NOTE_A4, NOTE_G4, ' ', ' ', ' ',       //2
                   NOTE_C5, NOTE_C5, ' ', NOTE_C5, ' ', NOTE_C5, NOTE_D5, NOTE_E5, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                   NOTE_C5, NOTE_C5, ' ', NOTE_C5, ' ', NOTE_C5, NOTE_D5, ' ', NOTE_E5, NOTE_C5, ' ', NOTE_A4, NOTE_G4, ' ', ' ', ' ',
                   NOTE_E5, NOTE_E5, ' ', NOTE_E5, ' ', NOTE_C5, NOTE_E5, ' ', NOTE_G5, ' ', ' ', ' ', NOTE_G4, ' ', ' ', ' ',

                   NOTE_E5, NOTE_C5, ' ', NOTE_G4, ' ', ' ', NOTE_GS4, ' ', NOTE_A4, NOTE_F5, ' ', NOTE_F5, NOTE_A4, ' ', ' ', ' ',        //3
                   NOTE_B4, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5, ' ', NOTE_A4, NOTE_G4, ' ', ' ', ' ',
                   NOTE_E5, NOTE_C5, ' ', NOTE_G4, ' ', ' ', NOTE_GS4, ' ', NOTE_A4, NOTE_F5, ' ', NOTE_F5, NOTE_A4, ' ', ' ', ' ',
                   NOTE_B4, NOTE_F5, ' ', NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, ' ', ' ', ' ', ' ', ' ', ' ', ' ',

                   NOTE_E5, NOTE_C5, ' ', NOTE_G4, ' ', ' ', NOTE_GS4, ' ', NOTE_A4, NOTE_F5, ' ', NOTE_F5, NOTE_A4, ' ', ' ', ' ',        //3
                   NOTE_B4, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5, ' ', NOTE_A4, NOTE_G4, ' ', ' ', ' ',
                   NOTE_E5, NOTE_C5, ' ', NOTE_G4, ' ', ' ', NOTE_GS4, ' ', NOTE_A4, NOTE_F5, ' ', NOTE_F5, NOTE_A4, ' ', ' ', ' ',
                   NOTE_B4, NOTE_F5, ' ', NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, ' ', ' ', ' ', ' ', ' ', ' ', ' '



                 };
//am folosit tipul de date uint8_t deoarece ocupa jumatate din memoria pe care o ocupa un int normal
//uint8_t stocheaza numere intregi pozitive pe 8 biti (de la 0 la 255)
//int stocheza numere intregi (negative si pozitive) pe 16 biti (de la -32768 pana la 32768)
//in beats se stocheaza durata notei, de ex: doime, patrime, optime etc.
uint8_t beats[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //0

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //1
                    3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //1'
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //1'
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //2
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //1
                    3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //3
                    3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //3
                    3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //2
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //3
                    3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,

                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,     //3
                    3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4
                  };

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(tempo / beats[i]); //rest
    } else {
      tone(speakerPin, notes[i], tempo / beats[i]);
    }

    // pause between notes
    delay(tempo / (beats[i] / 1.7));
  }
}
