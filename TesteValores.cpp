#include <iostream>
#include <string.h>

using namespace std;

void foo(int &n)
{
  n = 20;
}

int main()
{
  char nome[] = "leo";
  char *n = nome;
  while (*n != '\0')
  {
    cout << *n << endl;
    n++;
  }

  return 0;
}