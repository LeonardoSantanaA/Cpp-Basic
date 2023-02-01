#include <iostream>
#include <fstream>

using namespace std;

class Pessoa
{
private:
  string nome;
  int idade;

public:
  string getNome()
  {
    return nome;
  }
  int getIdade()
  {
    return idade;
  }
  void setNome(string nome)
  {
    this->nome = nome;
  }
  void setIdade(int idade)
  {
    this->idade = idade;
  }

  // sobrecarga do operador de insercao de dados <<
  // ostream = output stream (usado para escrever)
  // o parametro da direita fica na direita, e o da esquerda na esquerda, entao quando eu chamar os << p, essa funcao vai ser executada, e vai escrever no arquivo o nome e idade.
  friend ostream &operator<<(ostream &os, const Pessoa &p)
  {
    // escrever cada membro
    os << "\n"
       << p.nome << "\n";
    os << p.idade;
    return os;
  }

  // sobrecarga do operador de extracao de dados >>
  // istream >> input stream

  friend istream &operator>>(istream &is, Pessoa &p)
  {
    // ler cada membro
    is >> p.nome >> p.idade;
    return is;
  }
};

char menu()
{
  char resp;
  cout << "Digite 1 para inserir pessoas\n";
  cout << "Digite 2 para listar pessoas\n";
  cout << "Digite 0 para sair\n";
  cin >> resp;
  return resp;
}

int main(int argc, char const *argv[])
{
  char resp;
  while (true)
  {
    resp = menu();
    if (resp == '1')
    {
      Pessoa pessoa;
      string nome;
      int idade;
      ofstream ofs("arquivo.txt", fstream::app); // app = append(adiciona ao final do arquivo)

      cout << "Digite o nome da pessoa: ";
      cin >> nome;
      cout << "Digite a idade da pessoa: ";
      cin >> idade;
      cout << endl;

      pessoa.setNome(nome);
      pessoa.setIdade(idade);

      ofs << pessoa; // o operador "<<" precisa ser sobrecarregado para inserir objetos!
      ofs.close();
    }
    else if (resp == '2')
    {
      Pessoa p;
      ifstream ifs("arquivo.txt");
      cout << "\nListando pessoas...\n\n";

      if (ifs.good())
      { // good() verifica se o arquivo existe e se é possivel ler
        while (!ifs.eof())
        {           // eof -> end of file.
          ifs >> p; // faz a extracao dos dados
          cout << "Nome: " << p.getNome() << " - Idade: " << p.getIdade() << endl;
        }
        ifs.close();
      }
      else
      {
        cout << "Falha ao abrir o arquivo!\n\n";
      }
    }
    else if (resp == '0')
    {
      cout << "\nBye!" << endl;
      break;
    }
    else
    {
      cout << "Opcao invalida! tente novamente.\n";
    }
  }
  return 0;
}
