#include <iostream>
#include <random>

int main(int argc, char const *argv[])
{
  // para gerar o numero randomico da forma correta, é necessario esses 3:
  std::random_device rd;                     // criamos um random_device, ele gera uma sequencia aleatoria de um dispositivo externo. rd é o nome
  std::mt19937 gen(rd());                    // um gerador pseudorandomico Mersenne Twister de numeros de 32 bits, o gerador Mersenne Twister é um gerador que produz numeros inteiros sem sinais. gen é o nome
  std::uniform_int_distribution<> dis(0, 9); // distribuicao randomica que produz valores inteiros em uma distribuicao discreta uniforme, seguindo uma equacao que voce pode ver na doc. dis é o nome

  int maxRd = {5}; // quantidade de casas

  if (argc > 1)
  {
    maxRd = atoi(argv[1]); // atoi é uma funcao que converte string em int
  }
  if (maxRd <= 0)
  {
    throw std::invalid_argument("ERRO: Execute com um numero e maior que 0!");
  }

  std::string y = {};
  try
  {
    for (int i = 0; i < maxRd; i++)
    {
      y += std::to_string(dis(gen)); // adiciono o novo numero na string
    }
    std::cout << y << "\n";
  }
  catch (std::invalid_argument &e)
  {
    std::cerr << e.what();
    return -1;
  }

  // execute pelo terminal e passe um parametro novo no argv para determinar quantos algarismos tera o seu numero randomico!
  return 0;
}
