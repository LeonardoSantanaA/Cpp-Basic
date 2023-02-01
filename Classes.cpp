#include <iostream>

using namespace std;
class carro{
 private:
  int ano;
  float valor, km;
  string modelo;
  
 public:
//Construtor
 carro(string m = " ", int a = 0, float v = -1, float km = -1){
   this->modelo = m;
   this->ano = a;
   this->valor = v;
   this->km = km;
 }


//Getters e Setters.
  void setAno(int a){
    this->ano = a;
  } 
  int getAno(){
    return this->ano;
  }
  void setValor(float v){
    this->valor = v;
  }
  float getValor(){
    return this->valor;
  }
  void setKm(float km){
    this->km = km;
  }
  float getKm(){
    return this->km;
  }
  void setModelo(string m){
    this->modelo = m;
  }
  string getModelo(){
    return this->modelo;
  }
};

int main(){
   carro c1;
   c1.setAno(1997);
   c1.setValor(7000);
   c1.setModelo("Palio");
   cout << "Modelo: " << c1.getModelo() << "\nAno: " << c1.getAno() << "\nValor: " << c1.getValor() << endl;
  return 0;
}