// Conhecido como problema da mochila
//- Elementos -> cada elemento possui um valor (v) e um peso (w)
//- Objetivo -> maximizar o valor dos elementos colocados na mochila
// Essa mochila tem uma capacidade maxima: w
// Temos um conjunto S de n elementos
// Todo peso tem um peso wi e um valor valor/beneficio bi
// Se voce for fazer na "forca bruta", ou seja, todas as combinacoes, voce teria 2^n combinacoes, entao é inviavel
// por isso é utilizado a programacao dinamica
#include <iostream>

using namespace std;

int knapsack(int W, int wt[], int b[], int n)
{
  int v[n + 1][W + 1]; // tabela que sera preenchida

  // preenchendo primeira linha e primeira coluna com 0
  for (int w = 0; w <= W; w++)
    v[0][w] = 0;
  for (int i = 1; i <= n; i++)
    v[i][0] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int w = 1; w <= W; w++)
    {
      // verificar se o elemento pode fazer parte da solucao
      if (wt[i - 1] <= w)
      {
        if ((b[i - 1] + v[i - 1][w - wt[i - 1]]) > v[i - 1][w])
        { // valor max
          v[i][w] = b[i - 1] + v[i - 1][w - wt[i - 1]];
        }
        else
        {
          v[i][w] = v[i - 1][w];
        }
      }
      else
      {
        v[i][w] = v[i - 1][w];
      }
    }
  }
  return v[n][W]; // retorna o valor maximo colocado na mochila
}

int main(int argc, char const *argv[])
{
  int W = 20;                           // capacidade maxima da mochila
  int n = 5;                            // numero de elementos
  int b[] = {3, 5, 8, 4, 10};           // vetor com os valores (beneficio) de cada elemento
  int wt[] = {2, 4, 5, 3, 9};           // vetor com os pesos(w) de cada elemento
  int maxValor = knapsack(W, wt, b, n); // obter o maximo valor que pode ser colocado na mochila

  cout << "Valor maximo: " << maxValor << endl;

  return 0;
}
