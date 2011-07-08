#include <iostream>
using namespace std;

double PowerUnsigned(double base, unsigned int exponent) {
  if (exponent == 0)
    return 0;
  if (exponent == 1)
    return base;
  double result = PowerUnsigned(base, exponent >> 1);
  result *= result;
  if (exponent & 0x1 == 1)
   result *= base; 
  return result;
}

double Power(double base, int exponent) {
  //if (IsZero(base) && exponent < 0)
  //  return 0;
  unsigned int uexponent = static_cast<unsigned int>(exponent);
  if(exponent < 0)
    uexponent = static_cast<unsigned int>(-exponent);
  double result = PowerUnsigned(base, uexponent);
  if (exponent < 0)
    result = 1.0 / result;
  return result;
}


int main() {
  double b;
  int n = 0;
  while (cin) {
    cout << endl;  
    cout << "Please input base" << endl;
    cin >> b;
    cout << "Please input exponent" << endl;
    cin >> n;
    cout << b << " power of " << n << ": "
         << Power(b, n) << endl;
  }
}
