#include <iostream>

using namespace std;



int main(){
int linha = 0, coluna = 0;

cout << "Informe a quantidade de linhas da matriz: ";
cin >> linha;
cout << endl;
cout << "Informe a quantidade de colunas da matriz: ";
cin >> coluna;
cout << endl;
float matriz1[linha][coluna];
float matriz2[linha][coluna];
//Matriz 1
for(int i = 0; i < linha; i++){
  for(int j = 0; j < coluna; j++){
    cout << "Digite o valor na linha " << i+1  << " Coluna " << j+1 << " da primeira matriz: ";
    cin >> matriz1[i][j];
    cout << endl;
  }
}
//Matriz 2
for(int i = 0; i < linha; i++){
  for(int j = 0; j < coluna; j++){
    cout << "Digite o valor na linha " << i+1  << " Coluna " << j+1 << " da segunda matriz: ";
    cin >> matriz2[i][j];
    cout << endl;
  }
}
//Soma das matrizes
float somaMatriz[linha][coluna];
cout << "A soma foi: " << endl;
for(int i = 0; i < linha; i++){
  for(int j = 0; j < coluna; j++){
     somaMatriz[i][j] = matriz1[i][j] + matriz2[i][j];
     cout << somaMatriz[i][j] << " ";
  }
  cout << endl;
}



return 0;
}