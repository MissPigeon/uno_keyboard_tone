//#include <pitches.h>
/*************************************************
   Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define PIN 12

const int row[6] = {
  A0, A1, A2, A3, A4, A5
};

const int col[8] = {
  0, 2, 3, 4, 5, 6, 7, 8
};

int note, r, c;

//Array storing notes for each key
const int notes[6][8] = {
  {NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1},
  {NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2},
  {NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2, NOTE_B2},
  {NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3 , NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3},
  {NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4},
  {NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4}
};

int on[6][8];

void setup() {

  //Initialize row pins to output, set to high
  for (int j = 0; j < 6; j++) {
    pinMode(row[j], OUTPUT);
    digitalWrite(row[j], HIGH);
  }

  //Initialize colunm pins with pullup resistor
  for (int i = 0; i < 8; i++) {
    pinMode(col[i], INPUT_PULLUP);
    digitalWrite(col[i], HIGH);
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 8; j++) {
      on[i][j] = 0;
    }
  }
}

void loop() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(row[i] , LOW);
    for (int j = 0; j < 8; j++) {
      if (digitalRead(col[j]) == LOW) {
        //if note is off, set note, play tone, set note on
        if (on[i][j] == 0) {
          //set note
          note = notes[i][j];
          tone(PIN, note);
          //set current note on
          on[i][j] = 1;
          //set current note to pointers r,c
          r = i;
          c = j;
        }
      }
      //else (if col[j] reads high)
      else {
        if (on[r][c] == 1 && r == i && c == j){
          noTone(PIN);
          on[r][c] = 0;
        }
        on[i][j] = 0;
      }
    }
    digitalWrite(row[i], HIGH);
  }
}

/*
         if (digitalRead(col[j]) == LOW) {

        //if note is off, set note, play tone, set note on
        while (on[i][j] == 0) {
          note = notes[i][j];
          tone(PIN, note);
          on[i][j] = 1;
        }
      }

      //if note is set to on but key not pressed, tone off, set to off
      else {
        if (on[i][j] == 1) {
          noTone(PIN);
          on[i][j] = 0;
        }
      }

*/



