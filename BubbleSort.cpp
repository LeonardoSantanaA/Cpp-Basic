#include <iostream>
#include <string.h>
#define MAX 10

using namespace std;

class Carro
{
public:
  char nome[100];
  char cor[20];
  char placa[20];
  float preco;
};

void bubbleSort(Carro carros[], int tam)
{
  Carro aux;
  for (int i = tam; i >= 0; i--)
  {
    for (int j = 1; j <= i; j++)
    {
      // strcmp retorna -1 quando a string precede a outra, e 1 quando prossegue
      if (strcmp(carros[j - 1].nome, carros[j].nome) == 1)
      {
        strcpy(aux.nome, carros[j - 1].nome);
        aux = carros[j - 1];
        carros[j - 1] = carros[j];
        carros[j] = aux;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  Carro carros[MAX];
  int i = 0;

  while (true)
  {
    char resp;
    cout << "Digite o nome do carro: ";
    cin >> carros[i].nome;
    cout << "Digite o valor: ";
    cin >> carros[i].preco;
    cout << "Deseja continuar? <S>SIM ou <N>NAO ";
    cin >> resp;
    if (resp != 'S')
    {
      break;
    }
    i++;
  }
  cout << "Exibindo carros (desordenados):"
       << "\n";
  for (int j = 0; j <= i; j++)
  {
    cout << "Nome: " << carros[j].nome << "\n";
    cout << "Valor: $" << carros[j].preco << "\n";
    cout << "//////" << endl;
  }

  bubbleSort(carros, i); // ordenando!

  cout << "Exibindo carros (ordenados):"
       << "\n";
  for (int j = 0; j <= i; j++)
  {
    cout << "Nome: " << carros[j].nome << "\n";
    cout << "Valor: $" << carros[j].preco << "\n";
    cout << "//////" << endl;
  }
  return 0;
}
