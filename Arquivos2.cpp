// abrir um arquivo para saida
#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[])
{
  ofstream saida("saida.txt"); // a classe ofstream é para arquivos de saida
  saida << "Aprendendo C++\n";
  saida << "aaaa aa aaa a";
  return 0;
}
