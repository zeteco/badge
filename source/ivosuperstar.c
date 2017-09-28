// Source from; https://wiki.zeteco.ch/wiki/Badge#Ivos_Code
#include <avr/pgmspace.h>

/*
 * Copyleft 2017 by Ivo Blöchliger, Kontakt: vorname@bloechligair.ch
 */


// returns the button number pressed, or zero for none pressed
int readButtons() {
  int c = analogRead(A0); // get the analog value from ADC0 (on pin 5)
  if (c>600) {
    return 1;
  } else if (c>400 && c<550) {
    return 2; // button 2 pressed
  } else if (c>300 && c<400) {
    return 3; // button 3 pressed
  } else if (c>240 && c<290) {
     return 4; // button 4 pressed
  } else if (c>180 && c<230) {
     return 5; // button 5 pressed
  } else if (c>160 && c<175) {
     return 6;  // button 6 pressed
  } else if (c>100 && c<155) {
    return 7;
  }
  return 0;
}

void setup() {
  // Set sound and letter pins
  for (int i=0; i<5; i++) {
    pinMode(i,OUTPUT);
  }
}

// Poor mans PWM (you should not take time to do much else)
// To use, set duty[0] to duty[3] to values between 0.0 and 1.0
// and call this function continously
float duty[] = {1.0,1.0,1.0,1.0};
void pwmLoop() {
  for (int i=0; i<4; i++) {
    int us = duty[i]*duty[i]*500;  // quadratic function in order to compensate for logarithmic perception of light intensity
    digitalWrite(i+1, HIGH);
    delayMicroseconds(us);
    digitalWrite(i+1, LOW);
    delayMicroseconds(500-us);
  }
}

int periods[48] = {1132, 1069, 1009, 952, 898, 848, 800, 755, 713, 673, 635, 600, 566, 534, 504, 476, 449, 424, 400, 377, 356, 336, 317, 300, 283, 267, 252, 238, 224, 212, 200, 188, 178, 168, 158, 150, 141, 133, 126, 119, 112, 106, 100, 94, 89, 84, 79, 75};

void myTones(int duration, int t1, int t2, int t3) {
  int limits[3]={-1,-1,-1};
  if (t1>-24 && t1<=24) limits[0]=periods[t1+23];
  if (t2>-24 && t2<=24) limits[1]=periods[t2+23];
  if (t3>-24 && t3<=24) limits[2]=periods[t3+23];

  int counters[3] = {0,0,0};
  long start = millis();
  long tleft = start+duration-millis();
  while (tleft>0) {
    tleft = start+duration-millis();
    for (int k=0; k<3; k++) {
      counters[k]++;
      if (counters[k]==limits[k]) {
        counters[k]=0;
        digitalWrite(0,HIGH);
      }
      if (counters[k]==17) {
        digitalWrite(0,LOW);
      }
    }
  }
}

void america() {

  myTones(160, 0,4,7);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 0,4,7);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 0,4,7);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 4,7,12);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 4,7,12);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 4,7,12);
  delay(40);
  if (readButtons()>0) return;

  myTones(260, 0,5,9);
  delay(40);
  if (readButtons()>0) return;
  myTones(260, 0,5,-3);
  delay(40);
  if (readButtons()>0) return;
  myTones(260, 0,-7,-3);
  delay(40);
  if (readButtons()>0) return;

  myTones(160, 0,4,7);
  if (readButtons()>0) return;
  delay(40);
  myTones(160, 0,4,7);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 0,4,7);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 4,7,12);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 4,7,12);
  delay(40);
  if (readButtons()>0) return;
  myTones(160, 4,7,12);
  delay(40);
  if (readButtons()>0) return;

  myTones(260, 14,11,7);
  delay(40);
  if (readButtons()>0) return;
  myTones(260, 11,7,2);
  delay(40);
  if (readButtons()>0) return;
  myTones(260, -1,2,7);
  delay(40);
  if (readButtons()>0) return;



  myTones(160,10,7,3);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,10,7,3);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,10,7,3);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,10,7,15);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,10,7,15);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,10,7,15);
  delay(40);
  if (readButtons()>0) return;

  myTones(260, 14,10,5);
  delay(40);
  if (readButtons()>0) return;
  myTones(260, 10,5,2);
  delay(40);
  if (readButtons()>0) return;
  myTones(260, 5,2,-2);
  delay(40);
  if (readButtons()>0) return;

  myTones(160,3,0,-4);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,3,0,-4);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,3,0,-4);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,0,3,8);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,0,3,8);
  delay(40);
  if (readButtons()>0) return;
  myTones(160,0,3,8);
  delay(40);
  if (readButtons()>0) return;

  myTones(260, 7,2,-1);
  delay(40);
  if (readButtons()>0) return;
  myTones(260, 2,-1,-5);
  delay(40);
  if (readButtons()>0) return;
  myTones(260, -1,-5,-10);
  delay(40);
  if (readButtons()>0) return;

}

void fader() {
  int counter=0;
  while (readButtons()==0) {
    counter++;
    if (counter>1000) counter=0;
    duty[0] = abs(500-counter)/500.0;
    for (int i=1; i<4; i++) {
      duty[i] = duty[0];
    }
    pwmLoop();
  }
}

void roller(int period) {
  int counter=0;
  while (readButtons()==0) {
    counter++;
    if (counter>2*period) counter=0;
    for (int i=0; i<4; i++) {
      duty[i] = abs(period-((counter+2*period-i*period/2)%(2*period)))/(1.0*period);
    }
    pwmLoop();
  }
}

void fullpower(int period) {
  int pin=1;
  while (readButtons()==0) {
    digitalWrite(pin, HIGH);
    delay(period);
    digitalWrite(pin, LOW);
    pin+=1;
    if (pin==5) pin=1;
  }
}

// from http://www.mariopiano.com/mario-sheet-music-overworld-main-theme.html

const signed char mario[][4] PROGMEM = {{-10,6,16,4},
    {-10,6,16,4},
    {100,100,100,3},
    {-10,6,16,4},
    {100,100,100,3},
    {-10,6,12,4},
    {-10,6,16,4},
    {100,100,100,3},
    {7,11,19,4},
    {100,100,100,9},
    {7,-5,100,4},
    {100,100,100,9},
    {-5, 4, 12,3},  // Start Line 2, Index 12
    {100,100,100,6},
    {-8,0,7,3},
    {100,100,100,6},
    {-12,-5,4,3},
    {100,100,100,6},
    {-7,0,9,3},
    {100,100,100,3},
    {-5,2,11,3},
    {100,100,100,3},
    {-6,1,10,3},
    {-7,0,9,3},
    {100,100,100,3},
    {-8,0,7,4},
    {0,7,16,4},
    {4,11,19,4},
    {5,12,21,3},
    {100,100,100,3},
    {2, 9, 17, 3},
    {4,11,19,3},
    {100,100,100,3},
    {0,9,16,3},
    {100,100,100,3},
    {-3,4,12,3},
    {-1,5,14,3},
    {-5,2,11,3},
    {100,100,100,6},  // Index 38
/*    {-12,100,100,3},  // Page 2
    {100,100,100,6},
    {16, 19,100,3},
    {15,18,-8,3},
    {14,17,100,3},
    {11,15,100,3},
    {-5,100,100,3},
    {0,12,16,3},
    {100,100,100,3},
    {17,19,24,3},
    {100,100,100,3},
    {17,19,24,3},
    {17,19,24,3}, // INDEX 51
    {100,100,100,3},
    {-5,100,100,3},
    {100,100,100,3} // INDEX 54, end of line 2 (page 2)    */
    };
// C 0, D 2, E 4, F 5, G 7, A 9, H 11

void supermario() {
  signed char chords[4]={0,0,0,0};
  for (int ii=0;ii<39+27; ii++) {
    int i = (ii<39)? ii : ii-27;
    for (int k=0; k<4; k++) {
      chords[k] = pgm_read_byte(&(mario[i][k]));
    }
    int pin = (chords[0]>=-24 && chords[0]<24) ? (chords[0]+24)%4+1 : -1;
    if (pin>0) digitalWrite(pin, HIGH);
    myTones(chords[3]*30, chords[0], chords[1], chords[2]);
    if (pin>0) digitalWrite(pin, LOW);
    delay(15*chords[3]);
    if (readButtons()!=0) return;
  }
}



void piano() {
  int chords[6][3] = {{0,4,7}, {2,5,9}, {4,8,11}, {0,5,9}, {-1,2,7}, {0,4,9}};
  int b;
  while (true) {
    while ((b=readButtons())==0);
    if (b==7) return;
    digitalWrite((b%4)+1, HIGH);
    while (readButtons()==b) {
      myTones(50,chords[b-1][0], chords[b-1][1], chords[b-1][2]);
    }
    digitalWrite((b%4)+1, LOW);
  }

}


void loop() {
  int b;
  int i=0;
  while ((b=readButtons()) == 0) {
    i++;
    digitalWrite(i%4 + 1, HIGH);
    delay(1);
    digitalWrite(i%4 +1 , LOW);
    delay(1);
  }
  while (readButtons()!=0);
  if (b==1) {
    fader();
  } else if (b==2) {
    america();
  } else if (b==3) {
    roller(200);
  } else if (b==4) {
    fullpower(200);
  } else if (b==5) {
    supermario();
  } else if (b==7) {
    piano();
  }
  while (readButtons()!=0);
}
