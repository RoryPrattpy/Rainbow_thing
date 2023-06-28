/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/CTD_2023/Rainbow_thing/src/Rainbow_thing.ino"
void setup();
void loop();
float r(float x);
float b(float x);
float g(float x);
#line 1 "/Users/admin/CTD_2023/Rainbow_thing/src/Rainbow_thing.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

void setup() {
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  float x = map(analogRead(A0), 0, 4095, 0, 765);

  analogWrite(D5, 255 - r(x));
  analogWrite(D6, 255 - b(x));
  analogWrite(D7, 255 - g(x));
}

float r(float x) {
  float y = max(0, (255 - abs(x)));
  if (y == 0) {
    return max(0, (255 - abs(x - 255*3)));
  } else {
    return y;
  }
}

float b(float x) {
  return max(0, (255 - abs(x - 255*2)));
}

float g(float x) {
  return max(0, (255 - abs(x - 255)));
}