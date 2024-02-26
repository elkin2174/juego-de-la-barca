/*
  Archivo: main.cpp
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 25/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
/**
  HISTORIA: Este programa es un juego que se realizó con el paradigma de la
  programación orientada a objetos, para realizar la validación del curso
  Fundamentos de la programación orientada a objetos - 750015C. En este
  programa se utilizaron conceptos como abstracción, herencia, encapsulamiento
  y polimorfismo, así como el paso de mensajes y conceptos de como punteros.
  El juego consiste en que el usuario tiene que llevar a los individuos 
  (robot, zorro, conejo, lechuga) al otro lado del río en una barca que solo
  puede llevar dos individuos, y solo puede ser manejada por el robot. El usuario
  tiene que pasar a un zorro, un conejo y una lechuga. Si el robot deja solo al
  zorro y el conejo, este será devorado por el zorro, y en el caso de la lechuga
  y el conejo, este devorará la lechuga. En ambos casos, se finaliza la partida.
  Además, si los individuos no se pueden mover correctamente, estos pueden caer
  al agua y finalizaría la partida.
*/

#include <iostream>
#include "Jugador.h"

int main() 
{
  Jugador *jugador = new Jugador();
  jugador->menuInicial();
  delete jugador;

  return 0;
}