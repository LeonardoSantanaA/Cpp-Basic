#include <iostream>

using namespace std;

class Complexo
{
public:
  int real, imag;
  Complexo(int real, int imag)
  {
    this->real = real;
    this->imag = imag;
  }

  Complexo operator+(Complexo &c) // sobrecarregando o operador "+", não é obrigado a passar necessariamente o endereco do obj (&), mas um endereco é mais leve que o valor do objeto, entao é mais rapido, por isso o parametro é &c.
  {
    // lembre-se que estamos dentro da classe, entao o this->real pertence a variavel de um obj e o c.real é de outro obj
    cout << "////////" << endl;
    cout << "real: " << this->real << endl;
    cout << "imag: " << this->imag << endl;
    cout << "////////" << endl;
    return Complexo(this->real + c.real, this->imag + c.imag);
  }
};

int main(int argc, char const *argv[])
{
  Complexo c1(1, 2);
  Complexo c2(3, 4);
  Complexo c3 = c2 + c1;
  // o this->real e o this->imag sao os valores do objeto que está a esquerda do sinal. Entao é o objeto da esquerda que puxa a sobrecarga!
  cout << "c3 real: " << c3.real << "\nc3 imag: " << c3.imag << endl;

  return 0;
}
