#include <iostream>

using namespace std;

int main(){
int idade;
float renda;
cout << "Informe sua idade e renda, respectivamente: " << endl;
cin >> idade >> renda;
if(idade >= 21 && renda <= 1200){
  cout << "Voce Pode participar do programa!" << endl;
}else{
  cout << "Voce nao pode participar do programa..." << endl;
}
  return 0;
}