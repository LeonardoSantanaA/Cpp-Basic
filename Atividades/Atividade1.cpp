#include <iostream>
#include <math.h>

using namespace std;

int main(){
  float a, f;
  cout << "Insira o valor de a, para calcular: " << endl;
  cin >> a;
  f = pow(a, 2) - (3 * a) + 5;
  cout << "Resultado: " << f;

  return 0;
} 