#include <Servo.h>

class Rotator {
  private:
    Servo servo;
    int minDegree;
    int maxDegree;
    int currentDegree;
    int pin;
    double msPerDegreeRotation;
    virtual void printStats(int goalDeg, int degToRotate, int timeInMs, int delayPerDegInMs);
  public:
    Rotator(int pin);
    virtual void rotate(int deg, int timeInMs);
    virtual void setMinDegree(int degree);
    virtual void setMaxDegree(int degree);
    virtual void rotateMinDegree(int timeInMs);
    virtual void rotateMaxDegree(int timeInMs);
    virtual void rotateToPercentage(int percentage, int timeInMs);
    virtual void setRotationRate(double msPerDegree);
};

Rotator::Rotator(int pin) {
  servo.write(this->minDegree);
  this->pin = pin;
}

void Rotator::rotate(int deg, int timeInMs) {
  servo.write(this->minDegree);
  servo.attach(pin);
  int degToRotate = deg - this->currentDegree;

  if(degToRotate == 0) { return; }
  
  double delayPerDegInMs = (double)timeInMs / (double)abs(degToRotate);
  int factor = (degToRotate > 0) ? 1 : -1;

  while(deg != currentDegree) {
    currentDegree += factor;
    this->servo.write(currentDegree); 
    
    if(delayPerDegInMs < this->msPerDegreeRotation) {
      delayPerDegInMs = 0;
    }
    
    delay(delayPerDegInMs);     
  }

  Serial.print("dms=");
  Serial.println(delayPerDegInMs);
  Serial.print("mspdr=");
  Serial.println(this->msPerDegreeRotation);

  // wait for rotation to finish if rotation is full speed
  if(delayPerDegInMs <= this->msPerDegreeRotation) {
    int del = (int)(abs(degToRotate) * this->msPerDegreeRotation);
    Serial.println("delay");
    Serial.println(del);
    delay(del);
  }

  this->printStats(deg, degToRotate, timeInMs, delayPerDegInMs);

  servo.detach();
}

void Rotator::setMinDegree(int degree) {
  this->minDegree = degree;
}

void Rotator::setMaxDegree(int degree) {
  this->maxDegree = degree;
}

void Rotator::setRotationRate(double msPerDegree) {
  this->msPerDegreeRotation = msPerDegree;
}

void Rotator::rotateMinDegree(int timeInMs=0) {
  this->rotate(this->minDegree, timeInMs);
}

void Rotator::rotateMaxDegree(int timeInMs=0) {
  this->rotate(this->maxDegree, timeInMs);
}

void Rotator::rotateToPercentage(int percentage, int timeInMs=0) {
  int degreeDifference = this->maxDegree - this->minDegree;
  
  double degreeToRotate = (((double)degreeDifference / (double)100) * percentage) + this-> minDegree;
  
  Serial.println(degreeToRotate);
  this->rotate((int)degreeToRotate, timeInMs);
}

void Rotator::printStats(int goalDeg, int degToRotate, int timeInMs, int delayPerDegInMs) {
//  Serial.print("Current pos: ");
//  Serial.println(currentDegree);
//  Serial.print("Goal pos: ");
//  Serial.println(goalDeg);
//  Serial.print("Deg to rotate: ");
//  Serial.println( degToRotate);
//  Serial.print("Time to rotate: ");
//  Serial.println(timeInMs);
//  Serial.print("MS per deg: ");
//  Serial.println(delayPerDegInMs );
}
