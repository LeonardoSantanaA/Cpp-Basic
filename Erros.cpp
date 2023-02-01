#include <iostream>

using namespace std;

int fat(int n)
{
  if (n < 0)
    throw "Numero negativo!"; // o throw serve para jogar um erro caso der, ele precisa vir junto com o try e catch!

  if (n == 0 || n == 1)
    return 1;

  return n * fat(n - 1);
}

int main(int argc, char const *argv[])
{
  try // vamos tentar(try) executar o comando abaixo
  {
    cout << fat(-1);
  }
  catch (const char *e) // se nao conseguir executar o codigo do try, pegue(catch) o erro, pode passar um int no parametro tambem, para ver o numero do erro
  {
    cerr << "Erro: " << e << endl;
    // cerr serve para printar um erro (significa character error)
  }
  catch (...)
  { //"..." como parametro significa "pegue qualquer coisa", ou seja, ele pode pegar um erro que eu nao defini no throw
    cerr << "Erro inesperado.\n";
  }

  return 0;
}
