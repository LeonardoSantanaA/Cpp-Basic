#include <iostream>

using namespace std;

int main(){
//Alocacao Estática
  /*
int vet[] = {10, 15, 20, 8};
int x = sizeof(vet)/sizeof(int);
/*for(int i = 0; i < 4; i++){
  cout << vet[i] << endl;
}
cout<<x;
*/

//Alocacao Dinamica
int tamanho;
cout << "Digite o tamanho do vetor: " << endl;
cin >> tamanho;
int* vetor = new int[tamanho];
for(int i = 0; i < tamanho; i++){
  cout <<  "Digite o valor da posicao " << i << ": " << endl;
  cin >> vetor[i];
}
cout<< "Valores imprimidos: " << endl;
for(int i = 0; i < tamanho; i++){
  cout << vetor[i] << endl;
}
  return 0;
}