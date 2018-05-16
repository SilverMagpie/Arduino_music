#include "notes.h"

static int t = 200;
int count;

float Gnotes[] = {as[1], as[4], as[5], as[6], s, as[1], as[4], as[5], as[6], s, as[2], as[4], as[5], as[6], s, as[0], as[4], as[5], as[6], s,
                  as[0], as[3], as[4], as[5], s, as[0], as[3], as[4], as[5], s, as[4], as[5], as[4], as[8], s,
                  as[1], as[4], as[5], as[6], s, as[1], as[4], as[5], as[6], s, as[2], as[4], as[5], as[6], s, as[0], as[4], as[5], as[6], s,
                  as[0], as[3], as[4], as[5], s, as[0], as[3], as[4], as[5], s, as[6], as[7], as[6], as[5], s,
                  as[2], as[6], as[5], as[4], as[2], as[3], s, as[3], as[4], as[3], as[2], s,
                  as[0], as[5], as[4], as[3], as[2], as[1], s, as[2], as[3], as[2], as[1], s
                 };
float Gwait[]  = {1, 1, 1, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 3, 1, 1, 1, 1, 3, 3,
                  1, 1, 1, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 5, 6,
                  1, 1, 1, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 3, 1, 1, 1, 1, 3, 3,
                  1, 1, 1, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 6, 8,
                  4, 3, 3, 2, 2, 3, 1, 1, 1, 1, 4, 3,
                  4, 3, 3, 2, 2, 3, 1, 1, 1, 1, 4, 3
                 };

float Tnotes[] = {a, d, f, a, d, f, a, C, b, g, f, g, a, d, c, e, d,
                  s, d, c, e, c, e, f, d, s, d, c, e, c, e, f, d,
                  a, C, b, C, a, C, g, a, d, c, e, d, s, f, g, f, g, e, c, f, e, d
                 };
float Twait[]  = {1, 2, 1, 1, 2, 1, .5, .5, 1, 1, .5, .5, 1, 1, .5, .5, 2,
                  .3, .5, .5, 1, 1, .5, .5, 2, .3, .5, .5, 1, 1, .5, .5, 2,
                  .5, .5, 1, 1, 1, 1, 1, 1, .5, .5, 1, 2, .5, .5, .5, 1, 1, .5, .5, 1, 1, 1.5
                 };
int Tlen = sizeof(Twait);

float Snotes[] = {d, f, D, s, d, f, D, s, E, F, E, F, E, C, a, s, a, d, f, g, a, s, a, s, a, d, f, g, e, s,
                  d, f, D, s, d, f, D, s, E, F, E, F, E, C, a, s, a, d, f, g, a, s, a, d,
                 };
float Swait[]  = {1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1,
                  1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, h, 2, 2,
                 };
int Slen = sizeof(Snotes);

float Mnotes[] = {g, g, g, g, g, g, g, g, g, g, C, g, C, C, D, E, F, G, s,
                  G, G, A, B, K, s, K, K, B, A, B, A, G, s,
                  G, F, G, A, s, G, F, Y, F, G, s, F, Y, D, E, Z, s,
                  y, z,
                  g, g, g, g, g, g, g, g, g, g, C, g, C, C, D, E, F, G, s,
                  G, G, A, B, K, s, K, K, B, A, B, A, G, s,
                  G, F, G, A, s, G, F, Y, F, G, s, F, Y, D, E, Z, s,
                  y, z
                 };
float Mwait[]  = {h, h, 1, h, h, 1, h, h, 1, 1, 2, 3, 1, h, h, h, h, 4, 1,
                  H, h, h, h, 4, 1, 1, h, h, h, H, h, 4, h,
                  2, H, h, 3, h, 1, 1, 2, h, 3, h, 1, 1, 2, h, 3, h,
                  2, 1,
                  h, h, 1, h, h, 1, h, h, 1, 1, 2, 3, 1, h, h, h, h, 4, 1,
                  H, h, h, h, 4, 1, 1, h, h, h, H, h, 4, h,
                  2, H, h, 3, h, 1, 1, 2, h, 3, h, 1, 1, 2, h, 3, h,
                  2, 1
                 };

float Dnotes[] = {cs[1], cs[5], cs[6], cs[5], cs[4], cs[3], cs[4], cs[3], cs[2], cs[1], cs[1], cs[7],
                  cs[1], cs[3], cs[4], cs[3], cs[2], cs[1], cs[2], cs[1], cs[0], cs[1], cs[7],
                  cs[1], cs[5], cs[6], cs[5], cs[4], cs[3], cs[4], cs[3], cs[2], cs[1], cs[1], cs[7],
                  cs[3], cs[4], cs[3], cs[2], cs[1], cs[0], cs[1]
                 };
float Dwait[]  = {2, 1, 1, 2, 2, 1, 1, 1, 1, 2, 2, 0.25,
                  2, 1, 1, 2, 2, 1, 1, 1, 1, 2, 2,
                  2, 1, 1, 2, 2, 1, 1, 1, 1, 2, 2, 0.25,
                  2, 1, 1, 2, 1, 1, 4
                 };

float tinkN[] = {c,c,g,g,a,a,g,s,f,f,e,e,d,d,c,s,g,g,f,f,e,e,d,s,g,g,f,f,e,e,d,s,c,c,g,g,a,a,g,s,f,f,e,e,d,d,c};
float tinkW[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

float Bnotes[] = {d,e,f,g,s,C,D,s,g,e,s,d,g,e,s,d,c,d,s,g,e};
float Bwait[]  = {4,1,1,2,1,2,2,1,2,2,1,4,2,2,1,1,1,3,1,2,2};

int Mlen = sizeof(Mnotes);

void muse(float note, float wait) {
  tone(12, note, wait);
  delay(wait + 20);
}

void sing(float notes[], float waits[], float fact, int len) {
  for (int i = 0; i < len; i++) {
    muse(notes[i], waits[i] * t * fact);
  }
  delay(2500);
}

void setup() {
  count = (sizeof(Bnotes)/sizeof(int));
  sing(Bnotes, Bwait, 1.25, count);
  
  count = (sizeof(tinkN)/sizeof(int));
  sing(tinkN, tinkW, 1, count);
  
  count = (sizeof(Dnotes) / sizeof(int));
  sing(Dnotes, Dwait, 0.5, count);

  count = (sizeof(Gnotes) / sizeof(int));
  sing(Gnotes, Gwait, 0.55, count);

  count = (sizeof(Mnotes) / sizeof(int));
  sing(Mnotes, Mwait, 1.2, count);

  count = (sizeof(Tnotes) / sizeof(int));
  sing(Tnotes, Twait, 3, count);

  count = (sizeof(Snotes) / sizeof(int));
  sing(Snotes, Swait, 0.75, count);
}

void loop() {

}

