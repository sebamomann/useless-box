
#include "config.h"

#include "Rotator.h"
#include "Arm.h"
#include "Lid.h"
#include "Box.h"

#define SWITCH_PIN D1

Arm* arm = new Arm(D2);
Lid* lid = new Lid(D3);
Box box(arm, lid);


void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT);
}

void loop() {
  box.executeRandomFunction();
}
