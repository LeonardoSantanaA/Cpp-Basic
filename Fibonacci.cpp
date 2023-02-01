#include <iostream>
// vamos fazer um teste utilizando o constexpr, que é um recurso adicionado no c++11, a ideia principal é a melhoria do desempenho dos programas fazendo cálculos em tempo de compilacao em vez de tempo de execucao
using namespace std;

constexpr long int fib(int n)
{
  return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[])
{
  long int z = fib(30);
  cout << "O numero Fibonacci e: " << z << endl;
  return 0;
}
