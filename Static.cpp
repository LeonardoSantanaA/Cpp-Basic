#include <iostream>

using namespace std;

class Pessoa
{
private:
  string nome;

public:
  string getNome()
  {
    return this->nome;
  }
  void setNome(string nome)
  {
    this->nome = nome;
  }
};

int gerarId()
{
  static int id = 0; // tire a palavra static e rode para ver como funciona! uma variavel statica tem a vida util do programa, ou seja, ela mantem o mesmo valor ate o programa finalizar, por isso mesmo quando ela retorna ela mantem o mesmo valor
  return id++;
}

int main(int argc, char const *argv[])
{
  Pessoa p;
  string n;
  while (true)
  {
    cout << "Digite o nome: ";
    cin >> n;
    p.setNome(n);
    cout << "Id gerado: " << p.getNome() << " - " << gerarId() << endl;
  }
  return 0;
}
