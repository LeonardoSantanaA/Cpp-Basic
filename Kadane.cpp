// O algoritmo de Kadane calcula a soma maxima dos valores de um vetor
#include <iostream>
#include <vector>

using namespace std;

void kadane(vector<int> &vet)
{
  int maxAtual = 0, maxTotal = -1;
  int sizeVet = vet.size();
  for (int i = 0; i < sizeVet; i++)
  {
    maxAtual = maxAtual + vet[i];

    if (maxAtual < 0)
    {
      maxAtual = 0;
    }
    if (maxAtual > maxTotal)
    {
      maxTotal = maxAtual;
    }
  }

  cout << "Soma maxima: " << maxTotal << endl;
}

int main(int argc, char const *argv[])
{
  vector<int> vet(5); // criando vetor
  vet[0] = -2;
  vet[1] = 5;
  vet[2] = -1;
  vet[3] = 2;
  vet[4] = -3;

  kadane(vet);

  return 0;
}
