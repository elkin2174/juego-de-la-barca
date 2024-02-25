#include <iostream>
#include "Jugador.h"

int main() 
{
  Jugador *jugador = new Jugador();
  jugador->menuInicial();
  delete jugador;

  return 0;
}