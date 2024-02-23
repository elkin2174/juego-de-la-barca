/*
  Archivo: Orilla.h
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 21/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
/**
  CLASE: Orilla
  INTENCION: TODO
  RELACIONES:
  -es un Lugar
  
  -conoce  Barca
 
*/

#ifndef ORILLA_H
#define ORILLA_H

#include "Lugar.h"

class Orilla : public Lugar
{
  public:
  /*
    Constructores
  */
  // Constructor vacio
  Orilla();
  // Constructor con atributos heradados de la clase Lugar.
  Orilla(string _nombre); 

  // Destructor;
  /* 
    Invoca al destructor de la clase padre
  */
  ~Orilla();
  /*
    Implementacion de estallena()
  */
  bool estaLlena();
  /*
    Implementacio de sePuedeMover;
  */
  bool sePuedeMover();
};

#else
  class Orilla; // Declaración adelantada
#endif