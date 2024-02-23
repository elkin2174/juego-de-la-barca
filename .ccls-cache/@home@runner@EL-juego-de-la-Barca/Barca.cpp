/*
  Archivo: Barca.cpp
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 22/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
#include "Barca.h"

Barca::Barca()
{
};
Barca::Barca(string _nombre) : Lugar(_nombre)
{ 
};
Barca::~Barca()
{
};

bool Barca::estaLlena()
{
  if (getTamanio() >= 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Barca::sePuedeMover()
{
  for (Individuo *indiviuo : individuos)
  {
    if (indiviuo->getNombre()=="Robot")
    {
      return true;  
    }
  }
  return false;
}