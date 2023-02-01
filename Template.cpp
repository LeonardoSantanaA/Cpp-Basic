// vamos criar uma funcao que serve para qualquer tipo de dado
#include <iostream>

using namespace std;

template <typename T>
T soma(T n1, T n2)
{
  return n1 + n2;
}

int main(int argc, char const *argv[])
{
  cout << "Soma de inteiros: " << soma(10, 20) << endl;
  cout << "Soma de floats: " << soma((float)10, 2.5f) << endl;
  return 0;
}
