#include <iostream>

using namespace std;

int main(){
  char resp = ' ';
  do{
int tamanho = 0;
 cout << "Digite o tamanho do vetor: ";
 cin >> tamanho;
 cout << endl;
float* vetor = new float[tamanho];
for(int i = 0; i < tamanho; i++){
  cout << "Digite o valor na posicao " << i+1 << ": ";
  cin >> vetor[i];
  cout << endl;
}
for(int i = 0; i < tamanho; i++){
  cout << vetor[i] << " ";
}
delete [] vetor; //Deleta o vetor da memoria, pois nao sera mais usado.
cout << endl;
cout << "Deseja imprimir outro vetor?\n s para Sim\n Qualquer outra letra para Nao \nResposta: ";
cin >> resp;
cout << endl;
  }while(resp == 's');

  return 0;
}
