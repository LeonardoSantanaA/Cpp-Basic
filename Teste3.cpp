#include <iostream>

using namespace std;

long long fatRecursivo(int n)
{
  if (n == 0 || n == 1)
    return 1;

  if (n < 0)
    return -1;

  return n * fatRecursivo(n - 1);
}

long long fatNaoRecursivo(int n)
{
  if (n == 0 || n == 1)
    return 1;

  else if (n < 0)
    return -1;

  int aux = 1;
  long long f = 1;
  while (aux <= n)
  {
    f *= aux;
    aux++;
  }
  return f;
}

int main(int argc, char const *argv[])
{
  cout << "Fatorial Recursivo: " << fatRecursivo(20) << endl;
  return 0;
}
