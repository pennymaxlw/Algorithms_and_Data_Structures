#include <iostream>
using namespace std;

class FinalClass {
public:
  static FinalClass* GetInstance() {
    return new FinalClass();
  }
  static void DeleteInstance(FinalClass *p) {
    delete p;
    p = NULL;
  }
private:
  FinalClass() {}
  ~FinalClass() {}
};

class FinalClassAux {
friend class FinalClass2;
private:
  FinalClassAux() {}
  ~FinalClassAux() {}
};

template<typename T> 
class Final {
//friend T;  //Caution!! Can't pass build here
private:
  Final() {}
  ~Final() {}
};

class FinalClass2 : virtual public FinalClassAux {
//class FinalClass2 : public Final<FinalClass2> {
public:
  FinalClass2() {}
  ~FinalClass2() {}
};

//class Test : public FinalClass {
class Test : public FinalClass2 {
//class Test {
public:
  Test() {}
  ~Test() {}
};

int main() {
  FinalClass *obj = FinalClass::GetInstance();
  FinalClass::DeleteInstance(obj);

  FinalClass2 obj2;
  Test t;
}
