/*
  Archivo: Barca.cpp
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 24/02/2024
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
  if (vectorIndividuos().size() >= 2)
  {
    return true;
  }
  return false;
}
