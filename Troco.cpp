// vamos fazer um algoritmo guloso para resolver o problema do troco, que consiste em dar um troco com a menor quantidade de moedas possiveis
// um algoritmo guloso nao é 100% eficaz, e segue a frase "Estratégia gulosa é aquela usada por um montanhista que decide caminhar sempre para cima, na direção de maior subida, na esperança de assim chegar ao pico mais alto da montanha."
// Um algoritmo guloso escolhe, em cada iteração, o objeto mais apetitoso que vê pela frente. (A definição de apetitoso é estabelecida a priori, antes da execução do algoritmo.) O objeto escolhido passa a fazer parte da solução que o algoritmo constrói.
// Um algoritmo guloso é míope: ele toma decisões com base nas informações disponíveis na iteração corrente, sem olhar as consequências que essas decisões terão no futuro. Um algoritmo guloso jamais se arrepende ou volta atrás: as escolhas que faz em cada iteração são definitivas.
// Embora algoritmos gulosos pareçam naturalmente corretos, a prova de sua correção é, em geral, difícil e sutil. Para compensar, algoritmos gulosos são muito eficientes. Mas os problemas que admitem solução gulosa são um tanto raros.
#include <iostream>
#include <vector>

using namespace std;

int numMoedas(vector<int> &moedas, int troco)
{
  int qtdMoedas = 0;
  int tam = moedas.size();

  /*
  troco = 26
  m = {1, 2, 5, 10, 20}
  aux = 26 / 20 = 1 ou seja, o 20 cabe uma vez dentro do 26 (lembre-se que estamos usando tipo int)
  troco = 26 - 1 * 20 = 26 - 20 = 6
  qtdMoedas = 1
  e assim vai...
  */

  for (int i = tam - 1; i >= 0; i--)
  {
    int aux = troco / moedas[i];
    troco -= aux * moedas[i];
    qtdMoedas += aux;
  }

  return qtdMoedas;
}

int main(int argc, char const *argv[])
{
  vector<int> moedas;
  int n;
  n = 26;
  moedas.push_back(1);
  moedas.push_back(2);
  moedas.push_back(5);
  moedas.push_back(10);
  moedas.push_back(20);
  // repare que o vetor esta com os valores em ordem crescente!
  cout << "Numero de moedas: " << numMoedas(moedas, n) << endl;

  return 0;
}
