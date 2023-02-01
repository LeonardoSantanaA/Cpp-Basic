#include <iostream>
#include "Carro.h"

   //Construtor
 Carro::Carro(int a, float v, float km){
  this->ano = a;
  this->valor = v;
  this->km = km;
 }
 //Getters e Setters
 void Carro::setAno(float a){
  this->ano = a;
 }
 void Carro::setValor(float v){
  this->valor = v;
 }
 void Carro::setKm(float km){
  this->km = km;
 }
 int Carro::getAno(){
  return this->ano;
 }
 float Carro::getValor(){
 return this->valor;
 }
 float Carro::getKm(){
 return this->km;
 }