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
  INTENCION: Esta clase moldea la barca del juego esta envia si esta llena.
  RELACIONES:
  -es un Lugar
  -conoce Orilla, mediante los punteros de veciono y vecinoAlternativo.
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
      Retorna verdadero si la barca se encuentra llena, metodo abstracto heredado de la clase padre y sobre escrito.
    */
    bool estaLlena();    
};

#else
  class Barca; // Declaración adelantada
#endif