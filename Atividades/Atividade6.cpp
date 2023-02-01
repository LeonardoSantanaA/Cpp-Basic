#include <iostream>

using namespace std;

int main(){
 float* familia = new float[5];
 float media = 0;
 
 for(int i = 0; i < 5; i++){
  cout << "Digite o gasto com alimentacao da familia " << i+1 << ":" << endl;
  cin >> familia[i];
  media += familia[i];
 }
media/=5;
cout << "A media de gastos e: " << media << endl;

for (int i = 0; i < 5; i++){
  if(familia[i] < media){
    cout << "A familia " << i+1 << " esta abaixo da media!" << endl;
  }
  else if(familia[i] == media){
    cout << "A familia " << i+1 << " esta na media!" << endl;
  }else{
    cout << "A familia " << i+1 << " esta acima da media!" << endl;
  }
}
 return 0;
}