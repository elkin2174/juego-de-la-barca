/*
  Archivo: Individuo.cpp
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 21/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
#include "Individuo.h"

Individuo::Individuo(){};
Individuo::Individuo(string _nombre, string _comida, char _orden ) : nombre(_nombre), comida(_comida), orden(_orden) {};
Individuo::~Individuo(){};


string Individuo::getNombre()
{
  return nombre;
}
string Individuo::getComida()
{
  return comida;
}
char Individuo::getOrden()
{
  return orden;
}

void Individuo::setNombre(string _nombre)
{
  this->nombre = _nombre;
}
void Individuo::setComida(string _cominda)
{
  this->comida = _cominda;
}
void Individuo::setOrden(char _orden)
{
  this->orden = _orden;
}