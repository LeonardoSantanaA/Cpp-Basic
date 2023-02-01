#include <iostream>
#include <algorithm> //find_if_not
#include <iterator>  //std::begin e std::end

// Metodo sem Lambda:
/*
bool ehLetra(char c)
{
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main(int argc, char const *argv[])
{
  const char str[] = "eahiunadhnuisah4afuisghafsui";
  const char *it = std::find_if_not(std::begin(str), std::end(str), ehLetra); // encontra o primeiro elemento em uma sequencia que é falso
  std::cout << "O caracter que nao eh letra eh: " << *it << std::endl;

  return 0;
}
*/

// Metodo com Functor
/*
struct EhLetra
{
  bool operator()(char c) const // functor
  {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
  }
};

int main(int argc, char const *argv[])
{
  const char str[] = "eahiunadhnuisah4afuisghafsui";
  const char *it = std::find_if_not(std::begin(str), std::end(str), EhLetra{}); // desse jeito, da menos trabalho pro compilador!
  std::cout << "O caracter que nao eh letra eh: " << *it << std::endl;

  return 0;
}
*/

// Metodo com Lambda

int main(int argc, char const *argv[])
{
  const char str[] = "eahiunadhnuisah4afuisghafsui";

  auto it = std::find_if_not(std::begin(str), std::end(str), [](char c)
                             { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); }); // ou seja, uma lambda é feita assim: [](parametros){corpo;}
  std::cout << "O caracter que nao eh letra eh: " << it << std::endl;

  return 0;
}
