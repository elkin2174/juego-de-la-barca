/*
  Archivo: Jugador.h
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 23/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
/**
  CLASE: jugador
  INTENCION: Esta clase va a se la encargada de la interfaz del juego y de la interaccion entre las clases lugares
  RELACIONES:
  -contiene lugares
  -conoce Individuos
*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Lugar.h"
#include "Orilla.h"
#include "Barca.h"
#include <algorithm>

class Jugador
{
  private:
    vector<Lugar*> lugares; //Aqui se agregaran los lugares que participan en el juego

  public:
    /*
      Constructores y destructores
    */
    Jugador();
    ~Jugador();

    /*
      agrega los lugares al vector de lugares en la clase-
    */
    void addLugar(Lugar* lugar);

    /*
      Mueve los individuos de un objeto a otro
    */
    void moverIndividuo(Lugar* origen, Lugar* destino, char orden);

    /*
      Verifica si el usuario perdion dependiendo de lo que se retornen los metodos de la clase Lugar
    */
    bool validarPerdida(char orden);

    /*
      Verifica si el usuario gano
    */
    bool victoria();
    /* 
      configura la partida creando los objetos
    */
    void configurarInicio();
    /*
      Elimina la configuracion de Inicio al elminianar los objetos creados.
    */
    void eliminarConfiguracion();
    /*
      Crea el menu inicial del juego
    */
    void menuInicial();

    /*
      Imprime el juego en el frame con la informacion
    */
    void frame();
    /*
      Inicia el juego con toda la configuracion
    */
    void jugar();
    /*
      Imprime los controles del juego;  
    */
    void controles();

    /*
      Esta funcion intercambia los vecinos de Lugar sera llamada al mover la barca.
    */
    void intercambiarVecino();

    /*
      imprime las lineas del frame
    */
    string imprimirLinea(int horizontal);

};

#else
  class Jugador; // Declaración adelantada
#endif