class Box{
  private:
    Arm* arm;
    Lid* lid;
    void a(void);
    void b(void);
    void c(void);
    void d(void);
  public:
    Box(Arm* arm, Lid* lid) { 
      this->arm = arm;
      this->lid = lid;
    }
    void executeRandomFunction(void);
};

void Box::executeRandomFunction(void) {
  int numberOfFunctions = 1;
  
  Serial.println("");
  Serial.println("");
  Serial.println("--------------------------------");
  Serial.println("--------------------------------");
  switch(rand() % numberOfFunctions) {
    case 0: this->a(); break;
    case 1: this->b(); break;
    case 2: this->c(); break;
    case 3: this->d(); break;
  }
  Serial.println("--------------------------------");
  Serial.println("--------------------------------");
  Serial.println("");
  Serial.println("");
  
  delay(3000);
}

void Box::a(void) {
  Serial.println("Function a");
  this->arm->rotateToPercentage(100, 1000);
  this->arm->rotateToPercentage(0, 1000);
  
  this->lid->fullyOpen(1000);
  this->lid->fullyClose(1000);
}

void Box::b(void) {
  Serial.println("Function b");
  
  for(int i = 0; i <= 5; i++) {
    this->lid->rotateToPercentage(50);  
    this->lid->rotateToPercentage(40);  
  }
  
  this->lid->fullyClose(0);
  delay(1000);
  this->lid->fullyOpen(0);
  this->lid->fullyClose(0);
}

void Box::c(void) {
  Serial.println("Function c");
  
  this->lid->fullyOpen(5000);
  this->lid->fullyClose(0);
}

void Box::d(void) {
  Serial.println("Function d");
  
  this->lid->fullyOpen(0);
  delay(2000);
  this->lid->fullyClose(3000);
}
