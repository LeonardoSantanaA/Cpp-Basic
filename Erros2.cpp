#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

class ExcecaoCustomizada : public exception // crio uma classe que herda da classe exception
{
protected:
  char msg[100];

public:
  ExcecaoCustomizada(const char *e) // construtor
  {
    strcpy(msg, e); // vou copiar as mensagem de "e" passar para "msg"
  }

  virtual const char *what() // vamos sobrecarregar esse metodo what() (ela é virtual para sobrescrever independente do obj), este metodo é usado para identificar o erro
  {
    return msg; // agora ela retorna a msg
  }
};

int fat(int n)
{
  if (n < 0)
    throw ExcecaoCustomizada("Numero negativo!"); // agora vou usar a classe que criei acima

  if (n == 0 || n == 1)
    return 1;

  return n * fat(n - 1);
}

int main(int argc, char const *argv[])
{
  try
  {
    cout << fat(10) << endl;
    cout << fat(-5) << endl;
  }
  catch (ExcecaoCustomizada e) // perceba que no parametro agora eu passo a minha classe
  {
    cerr << "Erro: " << e.what(); // agora eu uso o metodo que sobrecarreguei
  }
  return 0;
}
