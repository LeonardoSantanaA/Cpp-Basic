#include <iostream>
#include <string.h>

using namespace std;

typedef struct pessoa
{
  char nome[100];
  int idade;
} t_pessoa;

int main(int argc, char const *argv[])
{
  t_pessoa p;
  p.idade = 20;
  char n[] = "leo";
  char *no = n;
  strcpy(p.nome, no);
  cout << p.nome << endl;
  return 0;
}
