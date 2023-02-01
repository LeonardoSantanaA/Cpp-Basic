// Esse algoritmo guloso pode ser utilizado para obter o caminho minimo (mais curto) dentro de um grafo, OBS: todos os custos não negativos.
#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
  int v; // numero de vertices

  list<pair<int, int>> *adj; // ponteiro para um array contendo as listas de adjacencias

public:
  Grafo(int v)
  {
    this->v = v;                       // atribui o numero de vertices
    adj = new list<pair<int, int>>[v]; // cria as listas onde cada lista é uma lista de pairs onde cada pair é formado pelo vertice destino e o custo
  }

  void addAresta(int v1, int v2, int custo) // adiciona uma aresta ao grafo de v1 a v2
  {
    adj[v1].push_back(make_pair(v2, custo));
  }

  int dijkstra(int orig, int dest) // algoritmo de Dijkstra
  {
    int dist[v];      // vetor de distancias
    int visitados[v]; // vetor de visitados, serve para caso o vertice ja tenha sido expandido(visitado) nao expandir mais

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // esta é nossa fila de prioridades, o primeiro elemento do par é a distancia e o segundo o vertice, lembrando que essa fila de prioridades é minima e nao maxima!

    for (int i = 0; i < v; i++) // inicia o vetor de distancia e visitados
    {
      dist[i] = INFINITO;   // comeca por infinito
      visitados[i] = false; // comeca por false
    }
    dist[orig] = 0;                       // a distancia de origem para origem é 0
    pq.push(make_pair(dist[orig], orig)); // insiro na fila de prioridades o primeiro elemento
    while (!pq.empty())                   // loop que rodara enquanto a fila nao estiver vazia
    {
      pair<int, int> p = pq.top(); // extrai o pair do topo
      int u = p.second;            // obtem o vertice do pair
      pq.pop();                    // remove da fila

      if (visitados[u] == false) // verifica se o vertice ainda nao foi expandido
      {
        visitados[u] = true;               // marca como visitado
        list<pair<int, int>>::iterator it; // crio um iterator para percorrer

        for (it = adj[u].begin(); it != adj[u].end(); it++) // percorrendo os vertices "v" adjacentes de "u"
        {
          int v = it->first;            // obtem o vertice adjacente
          int custoAresta = it->second; // obtem o custo da aresta

          // relaxamento (u,v)
          if (dist[v] > (dist[u] + custoAresta))
          {
            dist[v] = dist[u] + custoAresta; // atualiza a distancia de "v" e insere na fila
            pq.push(make_pair(dist[v], v));  // insiro na fila de prioridades
          }
        }
      }
    }
    return dist[dest]; // retorna a distancia minima ate o destino
  }
};

int main(int argc, char const *argv[])
{
  Grafo g(5); // crio um grafo com 5 vertices
  g.addAresta(0, 1, 4);
  g.addAresta(0, 2, 2);
  g.addAresta(0, 3, 5);
  g.addAresta(0, 1, 4);
  g.addAresta(1, 4, 1);
  g.addAresta(2, 1, 1);
  g.addAresta(2, 3, 2);
  g.addAresta(2, 4, 1);
  g.addAresta(3, 4, 1);

  cout << "Dijkstra: " << g.dijkstra(0, 1) << endl;

  return 0;
}
