#include <iostream>

int main(){
  int matriz[2][3];

  matriz[0][0] = 11;
  matriz[0][1] = 12;
  matriz[0][2] = 13;
  matriz[0][3] = 14;
  matriz[0][4] = 15;

  matriz[1][0] = 21;
  matriz[1][1] = 22;
  matriz[1][2] = 23;
  matriz[1][3] = 24;

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}