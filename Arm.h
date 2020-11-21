class Arm : public Rotator {
  private:
  public:
    Arm(int pin):Rotator(pin) { 
      this->setMinDegree(armDefaultMinDegree);
      this->setMaxDegree(armDefaultMaxDegree);
      this->setRotationRate(armDefaultRotationRate);
    }
};
