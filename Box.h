class Box{
  private:
    Arm* arm;
    Lid* lid;
    void a(void);
    void b(void);
    void c(void);
    void d(void);
    void e(void);
    void f(void);
    void g(void);
    void h(void);
  public:
    Box(Arm* arm, Lid* lid) { 
      this->arm = arm;
      this->lid = lid;
    }
    void executeRandomFunction(void);
};

void Box::executeRandomFunction(void) {
  int numberOfFunctions = 8;
  
  Serial.println("");
  Serial.println("");
  Serial.println("--------------------------------");
  Serial.println("--------------------------------");
  int vvar = rand() % numberOfFunctions;
  switch(vvar) {
    case 0: this->a(); break;
    case 1: this->b(); break;
    case 2: this->c(); break;
    case 3: this->d(); break;
    case 4: this->e(); break;
    case 5: this->f(); break;
    case 6: this->g(); break;
    case 7: this->h(); break;
  }
  Serial.println("--------------------------------");
  Serial.println("--------------------------------");
  Serial.println("");
  Serial.println("");
  
  delay(3000);
}

// basic 
void Box::a(void) {
  Serial.println("Function a");
  this->lid->fullyOpen();
  
  this->arm->rotateToPercentage(100, 0);
  this->arm->rotateToPercentage(0, 0);
 
  this->lid->fullyClose();
}

// antäuschen und anschleichen
void Box::b(void) {
   Serial.println("Function b");
   
  this->lid->fullyOpen();
  
  this->arm->rotateToPercentage(80, 0);
  delay(1000);
  this->arm->rotateToPercentage(0, 3000);
 
  this->lid->fullyClose(3000);

  delay(500);

  this->lid->rotateToPercentage(40, 2000);
  delay(1000);

  this->lid->fullyOpen();

  this->arm->rotateToPercentage(100, 0);
  this->arm->rotateToPercentage(0, 0);

  this->lid->fullyClose();
}

// lauern
void Box::c(void) {
  Serial.println("Function c");

  this->lid->rotateToPercentage(50);
  
  delay(4000);

  this->lid->fullyClose(4000);

  delay(3000);

  this->lid->fullyOpen();

  this->arm->rotateToPercentage(100, 0);
  this->arm->rotateToPercentage(0, 0);

  this->lid->fullyClose();
}

//abspasten
void Box::d(void) {
  Serial.println("Function d");

  for(int i = 0; i <= 5; i++) {
    this->lid->fullyOpen();
    this->lid->fullyClose();
  }

  this->lid->fullyOpen();

  for(int i = 0; i <= 5; i++) {
    this->arm->rotateToPercentage(80, 0);
    this->arm->rotateToPercentage(0, 0);
  }

  this->arm->rotateToPercentage(100, 0);
  this->arm->rotateToPercentage(0, 0);
  
  this->lid->fullyClose();
}

//halten
void Box::e(void) {
  Serial.println("Function e");
  this->lid->fullyOpen();

  this->arm->rotateToPercentage(100, 0);
  delay(3000);
  
  this->arm->rotateToPercentage(50, 1000);

  this->arm->rotateToPercentage(90, 0);
  delay(3000);

  this->arm->rotateToPercentage(0, 2000);

   this->lid->fullyClose(3000);
}

//basic slow
void Box::f(void) {
  Serial.println("Function f");
  this->lid->fullyOpen(3000);
   
  this->arm->rotateToPercentage(100, 2000);
  this->arm->rotateToPercentage(0, 2000);
 
  this->lid->fullyClose(3000);
}

void Box::g(void) {
  Serial.println("Function g");
  this->lid->fullyOpen(3000);

  delay(2000);
  
  this->arm->rotateToPercentage(100, 0);
  this->arm->rotateToPercentage(0, 0);
 
  this->lid->fullyClose(0);
}

// fast but reopen to look
void Box::h(void) {
  Serial.println("Function h");
  this->a();

  delay(1000);

  this->lid->fullyOpen();
  delay(1000);

  this->lid->fullyClose(2000);
}
