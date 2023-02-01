// abrir um arquivo para entrada
// ler o conteúdo desse arquivo

#include <iostream>
#include <fstream> //biblioteca para ler arquivos

using namespace std;

int main(int argc, char const *argv[])
{
  ifstream entrada("teste.txt"); // a classe ifstream recebe o arquivo que queremos passar, voce pode passar o caminho tambem (eu nao coloquei o caminho inteiro pois o teste.txt esta na mesma pasta do codigo)
  string texto;                  // vamos usar essa string para armazenar todo o texto
  char c = entrada.get();        // o metodo get() retorna o proximo caractere
  texto.push_back(c);            // insere o caractere na string
  cout << "Mostrando cada caractere: \n";
  // este loop while é responsavel por armazenar todos os caracteres dentro da string texto

  while (entrada.good()) // good() verifica enquanto é possivel extrair caracteres do arquivo
  {
    cout << c;          // mostra o caractere atual
    c = entrada.get();  // pega o proximo caractere
    texto.push_back(c); // inserindo o caractere na string
  }

  cout << "\nMostrando a string:\n"
       << texto << endl;

  return 0;
}
