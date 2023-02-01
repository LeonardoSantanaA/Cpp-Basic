#include <iostream>

using namespace std;

  class cidadesBrasil{
    private: 
     float populacao, area;
     int anoFundacao;
     string regiao, estado;

    public:
    //Construtor
    cidadesBrasil(float p, float a, int aF, string r, string e);

    //Getters e Setters
     void setPopulacao(float p);
     float getPopulacao();
     void setArea(float a);
     float getArea();
     void setAnoFundacao(int aF);
     int getAnoFundacao();
     void setRegiao(string r);
     string getRegiao();
     void setEstado(string e);
     string getEstado();
  };

int main(){
 cidadesBrasil sjdr(10000, 57800, 1800, "Sudeste", "MG");
   std::cout << sjdr.getEstado() << std::endl;
  return 0;
}

//Criacao dos metodos:

   cidadesBrasil::cidadesBrasil(float p, float a, int aF, string r, string e){
    this->populacao = p;
    this->area = a;
    this->anoFundacao = aF;
    this->regiao = r;
    this->estado = e;
   }

     void cidadesBrasil::setPopulacao(float p){
      this->populacao = p;
     }
     float cidadesBrasil::getPopulacao(){
      return this->populacao;
     }
     void cidadesBrasil::setArea(float a){
      this->area = a;
     }
     float cidadesBrasil::getArea(){
      return this->area;
     }
     void cidadesBrasil::setAnoFundacao(int aF){
      this->anoFundacao = aF;
     }
     int cidadesBrasil::getAnoFundacao(){
      return anoFundacao;
     }
     void cidadesBrasil::setRegiao(string r){
      this->regiao = r;
     }
     string cidadesBrasil::getRegiao(){
      return this->regiao;
     }
     void cidadesBrasil::setEstado(string e){
      this->estado = e;
     }
     string cidadesBrasil::getEstado(){
      return this->estado;
     }