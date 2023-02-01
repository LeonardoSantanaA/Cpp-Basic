#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



int fatorar(int n){
  int resultado = 1;
   for (int i = n; i > 1 ; i--){
    resultado *= i;
   }
   return resultado;
}

string fatorarEquacao(int n){
  string frase;

  for(int i = n; i >= 1; i --){
    if(i > 1){
    frase += to_string(i) + " * ";
    }else{
    frase += to_string(i) + " = " + to_string(fatorar(n));
    }
  }
 return frase;
}

int main(){
cout << fixed;
cout.precision(2);
int n;
cout << "Insira um numero inteiro para fatorar: " << endl;
cin >> n;
cout << fatorarEquacao(n);
  return 0;
}