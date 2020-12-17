
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
  //lid->rotate(0,0);
  //arm->rotateToPercentage(0);
  //lid->fullyClose(0);
  //arm->rotateToPercentage(0);
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  //arm->rotateToPercentage(0, 0);
  //delay(1000);
  //delay(1000);
  //arm->rotate(0, 0);
  //delay(1000);
  //arm->rotate(65, 0);
  //delay(1000);
  //delay(1000);
  //arm->rotate(75, 1000);
  //delay(1000);
  //lid->fullyOpen(0);
  //delay(4000);
  //
  //delay(1000);

  if(digitalRead(SWITCH_PIN) == HIGH) {
    box.executeRandomFunction(); 
  }

  //arm->rotateToPercentage(100, 0);
 //lid->fullyOpen(0);
 //delay(1000);
 //arm->rotateToPercentage(100, 0);
 //lid->fullyClose(0);
 //arm->rotateToPercentage(0, 0);
}
