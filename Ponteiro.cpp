#include <iostream>
#include <cstddef>

int main(){
  int var1 = 5;
  int* pont1 = &var1;

  std::cout << "Valor da variavel atraves do nome: " << var1 << std::endl;
  std::cout << "Endereco armazenado no ponteiro: " << pont1 << std::endl;
  std::cout << "Valor atraves do ponteiro: " << *pont1 << std::endl;

  *pont1 = 30;
  std::cout << "Valor alterado: " << var1 << std::endl;

 // int* pont2 = NULL;
 // std::cout << "valor: " << *pont2 << std::endl;
 // std::cout << "endereco: " << *pont2 << std::endl;

  int* pont3 = new int;
  std::cout << "valor: " << *pont3 << std::endl;
  std::cout << "endereco: " << *pont3 << std::endl;

  delete pont3;
  pont3 = pont1;
}