// Source: https://wiki.zeteco.ch/wiki/Badge#Cantina_Band

#define A 15

#define C (A-9)
#define Cis (A-8)
#define D (A-7)
#define Dis (A-6)
#define E (A-5)
#define F (A-4)
#define Fis (A-3)
#define G (A-2)
#define Gis (A-1)
#define Bb (A+1)
#define B (A+2)

#define C2 (A-9+12)
#define D2 (A-7+12)
#define E2 (A-5+12)
#define F2 (A-4+12)
#define G2 (A-2+12)
#define B2 (A+2+12)

#define C0 (A-9-12)
#define D0 (A-7-12)
#define E0 (A-5-12)
#define F0 (A-4-12)
#define G0 (A-2-12)
#define A0 (A-12)
#define Bb0 (A+1-12)
#define B0 (A+2-12)

#define HALF 200
#define HALFB 300
#define QUART 100
#define QUARTB 150
#define EIGHTH 70
#define EIGHTHB 95

#define _HALF(t1,t2,t3) myTones(HALF, t1,t2,t3);delay(HALFB);if (readButtons()>0) return;
#define _QUART(t1,t2,t3) myTones(QUART, t1,t2,t3);delay(QUARTB);if (readButtons()>0) return;
#define _QUART_NB(t1,t2,t3) myTones(QUART, t1,t2,t3);if (readButtons()>0) return;
#define _EIGHTH(t1,t2,t3) myTones(EIGHTH, t1,t2,t3);delay(EIGHTHB);if (readButtons()>0) return;
#define _EIGHTH_NB(t1,t2,t3) myTones(EIGHTH, t1,t2,t3);if (readButtons()>0) return;

void cantina() {
  // http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0042308

  // Row 1

  _QUART(A,F,D);
  _QUART(D2,A,F);
  _QUART(A,F,D);
  _QUART(D2,A,F);

  _EIGHTH(A,F,D);
  _QUART(D2,A,F);
  _EIGHTH(A,F,D);
  delay(EIGHTHB);
  _EIGHTH(Gis,E,D);
  _QUART(A,F,D);

  _EIGHTH(A,F,D);
  _EIGHTH(Gis,E,Cis);
  _EIGHTH(A,F,D);
  _EIGHTH(G,E,C);
  delay(EIGHTHB);
  _EIGHTH(Fis,Dis,B0);
  _EIGHTH(G,E,C);
  _EIGHTH(Fis,Cis,Bb0);

  // Row 2

  _QUART_NB(F,C,A0);
  _EIGHTH_NB(F,C,A0);
  _EIGHTH_NB(D,A0,F0);
  _HALF(D,A0,F0);

  _QUART(A,F,D);
  _QUART(D2,A,F);
  _QUART(A,F,D);
  _QUART(D2,A,F);

  _EIGHTH(A,F,D);
  _QUART(D2,A,F);
  _EIGHTH(A,F,D);
  delay(EIGHTHB);
  _EIGHTH(Gis,E,D);
  _QUART(A,F,D);

  _EIGHTH(G,D,B0);
  delay(EIGHTHB);
  _QUART_NB(G,D,B0);
  _EIGHTH(G,D,B0);
  _EIGHTH(Fis,Cis,Bb0);
  _QUART(G,D,B);

  // Row 3

  _EIGHTH(C2,G,E);
  _QUART(Bb,F,D);
  _QUART(A,E,C);
  _QUART_NB(G,D,Bb0);
  _EIGHTH(G,D,Bb0);

  _QUART(A,F,D);
  _QUART(D2,A,F);
  _QUART(A,F,D);
  _QUART(D2,A,F);

  _EIGHTH(A,F,D);
  _QUART(D2,A,F);
  _EIGHTH(A,F,D);
  delay(EIGHTHB);
  _EIGHTH(Gis,E,D);
  _QUART(A,F,D);

  _EIGHTH(C,G,E);
  delay(EIGHTHB);
  _QUART_NB(C,G,E);
  _EIGHTH(C,G,E);
  _EIGHTH_NB(A,E,C);
  _QUART(G,E,C);

  // Row 4

  _QUART_NB(F,C,A0);
  _EIGHTH(F,C,A0);
  _EIGHTH_NB(D,A0,F0);
  _HALF(D,A0,F0);

}
