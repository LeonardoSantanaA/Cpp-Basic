#include <iostream>
#include <iomanip>

using namespace std;

float potencia(float b, int e){
 float pot = 1;
 int count = 0;
 while(count < e){
  pot *= b;
  count++;
 }
return pot;
}

int main(){
 cout << fixed;
 cout.precision(2);

 float b;
 int e;
 char respUser;

  do {
   cout << "Digite o valor da base e da potencia, respectivamente: " << endl;
   cin >> b >> e;
    if(e < 0){
      cout << "Numero invalido! Digite um numero positivo!" << endl;
     break;
    }
   cout << "Reposta da Potencia: \n" << potencia(b, e) << endl;
   cout << "Deseja fazer outro calculo?\n sim: s\n nao: n" << endl;
    while(true){
    cin >> respUser;
  if(respUser == 's' || respUser == 'n'){
    break;
  }else{
   cout << "resposta invalida! Tente novamente." << endl;
  }
   }
  } while(respUser == 's');
  return 0;
}