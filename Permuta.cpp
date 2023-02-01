#include <iostream>

using namespace std;

void trocar(int v[], int i, int j)
{
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

void permutar(int v[], int inf, int sup)
{
  if (inf == sup)
  {

    for (int i = 0; i <= sup; i++)
      cout << v[i] << " ";

    cout << endl;
  }
  else
  {
    for (int i = inf; i <= sup; i++)
    {
      trocar(v, inf, i);
      permutar(v, inf + 1, sup);
      trocar(v, inf, i); // backtracking
    }
  }
}

int main(int argc, char const *argv[])
{
  int v[] = {1, 2, 3};
  int tamV = sizeof(v) / sizeof(int);

  permutar(v, 0, tamV - 1);
  return 0;
}
