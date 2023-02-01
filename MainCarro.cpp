#include <iostream>
#include "Carro.h"

using namespace std;

int main(){
  Carro palio(1997, 7000, 50000);
  cout << "Palio:\n";
  cout << "Ano: " << palio.getAno() << "\nValor: " << palio.getValor() << "\nKm: " << palio.getKm() << endl;

   Carro celta(1997, 7000, 50000);
   celta.setAno(1995);
   celta.setValor(1000);
   celta.setKm(80000);
   cout << "Celta:\n";
   cout << "Ano: " << celta.getAno() << "\nValor: " << celta.getValor() << "\nKm: " << celta.getKm() << endl;
   //system("pause");
  return 0;
}