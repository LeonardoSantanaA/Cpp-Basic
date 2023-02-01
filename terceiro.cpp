#include <iostream>

using namespace std;

#define pi 3.14;
#define print cout << "Teste\n";

void teste()
{
  cout << "Teste de funcao aa" << endl;
}

int somar(int x, int y)
{
  int r = x + y;
  x = 30;
  return r;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << "soma:" << somar(a, b) << endl;
  cout << "a: " << a << endl;

  // print;
  // cout << "Pi: " << pi;
  return 0;
}