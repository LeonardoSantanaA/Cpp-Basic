// Este é um algoritmo que nos permite buscar uma arvore geradora minima para um grafo conexo com pesos, ou seja, ele forma uma arvore que inclui todos os vertices onde o peso total é minimo
// Para detectar ciclos iremos utilizar o algoritmo Union-Find que detecta ciclos em grafos nao direcionados
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Aresta
{
private:
  int vertice1, vertice2, peso;

public:
  Aresta(int v1, int v2, int peso)
  {
    vertice1 = v1;
    vertice2 = v2;
    this->peso = peso;
  }

  int getVertice1()
  {
    return vertice1;
  }

  int getVertice2()
  {
    return vertice2;
  }

  int getPeso()
  {
    return peso;
  }

  // sobrecarga operador "<"
  bool operator<(const Aresta &aresta2) const // com essa sobrecarga, quando eu comparar uma aresta com outra eu vou olhar o peso delas
  {
    return (peso < aresta2.peso);
  }
};

class Grafo
{
private:
  int v;                  // numero de vertices
  vector<Aresta> arestas; // vetor de arestas

public:
  Grafo(int v)
  {
    this->v = v;
  }

  void adicionarAresta(int v1, int v2, int peso)
  {
    Aresta aresta(v1, v2, peso);
    arestas.push_back(aresta);
  }

  // funcao que busca o subconjunto de um elemento "i" (Union-Find)
  int buscar(int subset[], int i)
  {
    if (subset[i] == -1)
      return i;
    return buscar(subset, subset[i]);
  }

  // funcao para unir dois subconjuntos em um unico subconjunto (Union-Find)
  void unir(int subset[], int v1, int v2)
  {
    int v1_set = buscar(subset, v1);
    int v2_set = buscar(subset, v2);
    subset[v1_set] = v2_set;
  }

  void kruskal() // funcao que vai rodar o algoritmo de kruskal
  {
    vector<Aresta> arvore; // todas as arestas que fazem parte da arvore geradora minima eu vou colocar nesse vetor
    int sizeArestas = arestas.size();

    // ordena as arestas pelo menor peso
    sort(arestas.begin(), arestas.end());

    int *subset = new int[v]; // aloca memoria para criar "v" subconjuntos

    memset(subset, -1, sizeof(int) * v); // inicializa todos os subconjuntos como conjuntos de um unico elemento

    for (int i = 0; i < sizeArestas; i++)
    {
      int v1 = buscar(subset, arestas[i].getVertice1());
      int v2 = buscar(subset, arestas[i].getVertice2());

      if (v1 != v2) // se for diferente, é por que nao forma ciclo, insere no vetor pois faz parte da arvore geradora minima
      {
        arvore.push_back(arestas[i]);
        unir(subset, v1, v2);
      }
    }

    // Printar:
    int sizeArvore = arvore.size();
    for (int i = 0; i < sizeArvore; i++)
    {
      // transformar em letras ('A'+ 1 = 'B', 'A' + 3 = 'D' etc...)
      char v1 = 'A' + arvore[i].getVertice1();
      char v2 = 'A' + arvore[i].getVertice2();
      cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].getPeso() << endl;
    }
    // mostra as arestas selecionadas com seus respectivos pesos
  }
};

int main(int argc, char const *argv[])
{
  Grafo g(7); // crio o grafo
  g.adicionarAresta(0, 1, 7);
  g.adicionarAresta(0, 3, 5);
  g.adicionarAresta(1, 2, 8);
  g.adicionarAresta(1, 3, 9);
  g.adicionarAresta(1, 4, 7);
  g.adicionarAresta(2, 4, 5);
  g.adicionarAresta(3, 4, 15);
  g.adicionarAresta(3, 5, 6);
  g.adicionarAresta(4, 5, 8);
  g.adicionarAresta(4, 6, 9);
  g.adicionarAresta(5, 6, 11);

  g.kruskal(); // roda o algoritmo de Kruskal
  return 0;
}
