#include <iostream>

using namespace std;

int main(){
int* idade1 = new int;
int* idade2 = new int;
float* media = new float;
cout << "Qual a idade da primeira pessoa? ";
cin >> *idade1;
cout << "Qual a idade da segunda pessoa? ";
cin >> *idade2;
cout << endl;
*media = (*idade1 + *idade2) / 2;
cout << "A media e: " << *media << endl;

  return 0;
}