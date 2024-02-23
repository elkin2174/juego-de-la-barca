/*
  Archivo: Orilla.cpp
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 21/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
#include "Orilla.h"

Orilla::Orilla()
{
  
}
Orilla::Orilla(string _nombre) : Lugar(_nombre)
{
  
}
Orilla::~Orilla()
{
}
bool Orilla::estaLlena()
{
  return false;
}; 

bool Orilla::sePuedeMover()
{
  return false;
}