#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  float c1, c2;
  cout << "Digite o primeiro valor: " << endl;
  cin >> c1;
  cout << "Digite o segundo valor: " << endl;
  cin >> c2;
  float re = pow(c1, c2);
  cout << "Potencia: " << re << endl;

  return 0;
}