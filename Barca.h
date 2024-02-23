/*
  Archivo: Barca.h
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 23/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
/**
  CLASE: Barca
  INTENCION: TODO
  RELACIONES:
  -es un Lugar
  -conoce Individuo

*/

#ifndef BARCA_H
#define BARCA_H

#include "Lugar.h"

class Barca : public Lugar
{  
  public:
    /* 
      contructore y destructores
    */
    Barca();
    Barca(string _nombre);
    ~Barca();

    /*
      Metodos de la clase.
    */
    /*
      Retorna verdadero si la barca se encuentra llena
    */
    bool estaLlena();

    /*
      Verifica si el Robot se encuentra en la Barca, si esta retorna true en caso contrario false.
    */
    bool sePuedeMover();
    
};

#else
  class Barca; // Declaración adelantada
#endif