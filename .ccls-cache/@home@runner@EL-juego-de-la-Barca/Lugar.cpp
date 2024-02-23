/*
  Archivo: Lugar.cpp
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 23/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
#include "Lugar.h"

using namespace std;

Lugar::Lugar()
{ 
};
Lugar::Lugar(string _nombre) : nombre(_nombre) 
{ 
};
Lugar::~Lugar()
{

  for(Individuo *individuo : individuos)
  {
    delete individuo;
  }
  individuos.clear();
}

string Lugar::getNombre()
{
  return nombre;
}
Lugar* Lugar::getVecino()
{
  return vecino;
}
Lugar* Lugar::getVecinoAltenativo()
{
  return vecinoAlternanitivo;
}

void Lugar::setNombre(string _nombre)
{
  this->nombre = _nombre;
}
void Lugar::setVecino(Lugar *_vecino)
{
  this->vecino = _vecino;
}
void Lugar::setVecinoAlternativo(Lugar *_vecino)
{
  this->vecinoAlternanitivo = _vecino;
}

bool Lugar::buscarRobot()
{
  for (Individuo *individuo : individuos)
  {
    if (individuo->getNombre() == "Robot")
    {
      return true;
      break;
    }
  }
  return false;
}

bool Lugar::PuedeComer()
{
  if (buscarRobot())
  {
    return false;
  }
  for (Individuo *depredador : individuos)
  {
    for (Individuo *presa : individuos)
    {
      if (depredador->getComida() == presa->getNombre())
      {
        cout << " !El " + depredador->getNombre() + " se comio a " + presa->getNombre()+ "!"<<endl<<endl;
        return true;
      }  
    }
  }
  return false;
  
}
bool Lugar::seAhogo(Individuo *individuo)
{
  if (getVecino() == nullptr)
  {
    cout << " !" + individuo->getNombre() + " se cayó al agua!" <<endl<<endl;
    return true;
  }else
    return false;
}
void Lugar::addIndividuos(Individuo *_individuo)
{
  individuos.push_back(_individuo);
}

int Lugar::getTamanio()
{
  return individuos.size();
}

vector<Individuo*> Lugar::vectorIndividuos()
{
  return individuos;
}

int Lugar::retornarIndice(char orden)
{
  for (int i = 0; i < individuos.size(); i++)
    {
      if ( orden == individuos[i]->getOrden())
        return i;
    }
  return 99;
}

void Lugar::eliminarIndividuo(int indice)
{
  individuos.erase(individuos.begin() + indice);
}

bool Lugar::moverIndividuo(char orden)
{  
  
  int indice = this->retornarIndice(orden);
  if(indice != 99)
  {
    vecino->addIndividuos(move(individuos[indice]));
    this->eliminarIndividuo(indice);
    return true;
  }
  return false;
  
}

bool Lugar::verificarIndividuo(char orden)
{
  for(Individuo * ind : individuos)
  {
    if(ind->getOrden() == orden) return true;
  }
  return false;
}