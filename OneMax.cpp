// vamos usar algoritmo genetico para resolver o problema do onemax, para resolver é maximizar a quantidade de "1" em um vetor
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int tamGenes = 20;        // quantidade de genes
int tamPop = 50;          // quantidade de individuos numa populacao
int tamTorneio = 20;      // quantidade de cruzamentos
int geracoes = 100;       // quantidade de geracoes
double probMutacao = 0.1; // probabilidade de mutacao, o valor depende muito do problema
double probCruz = 0.7;    // probabilidade de cruzamento

vector<vector<int>> populacao; // a populacao é basicamente um conjunto de individuos

void inicializaPopulacao()
{
  for (int i = 0; i < tamPop; i++)
  {
    vector<int> individuo; // um individuo é um conjunto de genes, entao vou criar um vetor pra guardar os individuos

    for (int j = 0; j < tamGenes; j++) // o tamanho do vetor é determinado pela quantidade de gnes
    {
      int gene = rand() % 2;     // randomizar valores de 0 e 1
      individuo.push_back(gene); // adiciono o gene ao vetor de individuos
    }

    populacao.push_back(individuo); // adiciono o vetor individuo ao vetor populacao, entao a populacao tera 50 individuos, e cada individuo tera 10 genes
  }
}

void mostrarPopulacao()
{
  for (int i = 0; i < tamPop; i++)
  {
    for (int j = 0; j < tamGenes; j++)
      cout << populacao[i][j] << " ";
    cout << endl;
  }
}

int obterPontuacao(vector<int> individuo)
{
  int soma = 0;

  for (int i = 0; i < tamGenes; i++)
    soma += individuo[i];

  return soma; // esse seria o score do individuo
}

void mutacao(vector<int> &individuo) // a mutacao seria selecionar uma posicao aleatoria do invididuo, e troca de 0 pra 1 e de 1 pra 0
{
  int gene = rand() % tamGenes; // randomiza de 0 ate tamGenes-1
  // troca de valores:
  if (individuo[gene] == 0)
    individuo[gene] = 1;
  else
    individuo[gene] = 0;
}

void cruzar(int indicePai1, int indicePai2, vector<int> &filho)
{
  int ponto = rand() % tamGenes; // vou gerar um valor aleatorio pra saber quantas casas vou pegar do pai1

  for (int i = 0; i <= ponto; i++)
    filho.push_back(populacao[indicePai1][i]); // puxo o valor pro filho

  for (int i = ponto + 1; i < tamGenes; i++)
    filho.push_back(populacao[indicePai2][i]); // o restante pego do pai2
}

int obterMelhor() // pegar o melhor individuo gerado
{
  int indiceMelhor = 0;
  int scoreMelhor = obterPontuacao(populacao[0]); // comeco pegando o primeiro

  for (int i = 1; i < tamPop; i++)
  {
    int score = obterPontuacao(populacao[i]);
    if (score > scoreMelhor) // se for melhor(maior), atualizo os valores
    {
      indiceMelhor = i;
      scoreMelhor = score;
    }
  }
  return indiceMelhor;
}

int main(int argc, char const *argv[])
{
  srand(time(NULL)); // define o ponto de partida para gerar uma serie de inteiros pseudoaleatorios
  inicializaPopulacao();
  for (int i = 0; i < geracoes; i++)
  {
    for (int j = 0; j < tamTorneio; j++)
    {
      double prob = ((double)rand() / ((double)RAND_MAX + 1)); // isto vai gerar um numero quebrado entre 0 e 1

      // Cruzamento:
      if (prob < probCruz) // se o numero gerado for menor que o numero da probabilidade de cruzamento, eu vou cruzar
      {
        int indicePai1 = rand() % tamPop;
        int indicePai2;

        do // esse do-while vai garantir que o pai1 e pai2 nao serao iguais
        {
          indicePai2 = rand() % tamPop;
        } while (indicePai1 == indicePai2);

        vector<int> filho; // crio um vetor pra guardar os filhos do cruzamento
        cruzar(indicePai1, indicePai2, filho);

        // Mutacao:
        prob = ((double)rand() / (double)RAND_MAX + 1); // gero um novo randomico para mutacao
        if (prob < probMutacao)
          mutacao(filho);

        // Verificar se a pontuacao do filho é melhor que a do pai:
        int scorePai = obterPontuacao(populacao[indicePai1]);
        int scoreFilho = obterPontuacao(filho);

        if (scoreFilho > scorePai) // se for maior, eu passo uma copia dos genes do filho para o pai
        {
          for (int k = 0; k < tamGenes; k++)
            populacao[indicePai1][k] = filho[k];
        }
      }
    }
    cout << "Geracao " << i + 1 << endl;
    cout << "Melhor: ";
    int indiceMelhor = obterMelhor();
    int scoreMelhor = obterPontuacao(populacao[indiceMelhor]);

    for (int j = 0; j < tamGenes; j++)
      cout << populacao[indiceMelhor][j] << " ";

    cout << "\nPontuacao: " << scoreMelhor << "\n\n";

    if (scoreMelhor == tamGenes)
      break;
  }

  return 0;
}
