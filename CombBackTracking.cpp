#include <iostream>

using namespace std;

void combinar(int v[], int vBool[], int i, int tamV)
{
  if (i == tamV)
  {
    for (int j = 0; j < tamV; j++)
    {
      if (vBool[j] == 1)
        cout << v[j] << " ";
    }
    cout << endl;
  }
  else
  {
    vBool[i] = true;
    combinar(v, vBool, i + 1, tamV);
    vBool[i] = false;
    combinar(v, vBool, i + 1, tamV);
  }
}

int main(int argc, char const *argv[])
{
  int v[] = {1, 2, 3};
  int tamV = sizeof(v) / sizeof(int);
  int vBool[tamV];

  for (int i = 0; i < tamV; i++)
    vBool[i] = false;

  combinar(v, vBool, 0, tamV);

  return 0;
}
