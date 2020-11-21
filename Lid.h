class Lid : public Rotator {
  private:
  public:
    Lid(int pin):Rotator(pin) {
      this->setMinDegree(lidDefaultMinDegree);
      this->setMaxDegree(lidDefaultMaxDegree);
      this->setRotationRate(lidDefaultRotationRate);
    }
    void fullyOpen(int timeInMs);
    void fullyClose(int timeInMs);
    void openToPercentage(int percentage, int timeInMs);
};

void Lid::fullyOpen(int timeInMs=0) {
  this->rotateMaxDegree(timeInMs); 
}

void Lid::fullyClose(int timeInMs=0) {
  this->rotateMinDegree(timeInMs); 
}

void Lid::openToPercentage(int percentage, int timeInMs=0) {
  this->rotateToPercentage(percentage, timeInMs); 
}
