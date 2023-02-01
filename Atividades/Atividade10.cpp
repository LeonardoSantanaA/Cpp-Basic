#include <iostream>

using namespace std;

void trocar(int* &v1, int* &v2){
  int* temp = new int;
  *temp = *v1;
  *v1 = *v2;
  *v2 = *temp;
}

int main(){
int* valor1 = new int;
int* valor2 = new int;

cout << "Digite o valor do primeiro ponteiro: ";
cin >> *valor1;
cout << endl;
cout << "Digite o valor do segundo ponteiro: ";
cin >> *valor2;
cout << "Valor original ponteiro 1: " << *valor1 << endl;
cout << "Valor original ponteiro 2: " << *valor2 << endl;
trocar(valor1, valor2);
cout << "Valor trocado ponteiro 1: " << *valor1 << endl;
cout << "Valor trocado ponteiro 2: " << *valor2 << endl;
  return 0;
}