// ler arquivo de outra forma
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
  ifstream entrada("teste.txt");
  char c;
  while (true)
  {
    entrada >> c;
    if (entrada.fail()) // o metodo fail() verifica se é possivel ler o caractere
    {
      break;
    }
    cout << c;
  }
  return 0;
}
