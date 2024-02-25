/*
  Archivo: Jugador.h
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 24/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
/**
  CLASE: Jugador
  INTENCION: Esta clase va a se la encargada de la interfaz del juego, las interacciones entre las clases de Lugar y verifica si el jugar gana o pierde dependiendo de los mensajes recibidos de la clase Lugar.
  RELACIONES:
  -Contiene Lugar
*/

#ifndef JUGADOR_H
#define JUGADOR_H

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
      agrega los lugares al vector de lugares en la clase
    */
    void addLugar(Lugar* lugar);

    /*
      Verifica si el usuario perdion dependiendo de lo que se retornen los metodos de la clase Lugar.
    */
    bool validarPerdida(char orden);

    /*
      Verifica si el usuario gano al obtener un respuesta verdadera de la Orilla derecha.
    */
    bool victoria();

    /* 
      configura el inicio de la partida creando los objetos y añadiendolos los lugares al
      su vector de lugares y los individuos al su instacia de Lugar inical (orilla izquierda).
    */
    void configurarInicio();

    /*
      Elimina la configuracion actual al  elminianar los objetos creados.
    */
    void eliminarConfiguracion();

    /*
      Crea el menu inicial del juego en el cual se puede decidir si iniciar una partida, 
      ver informacio o salir.
    */
    void menuInicial();

    /*
      Imprime el juego en el frame con la informacion actual.
    */
    void frame();

    /*
      Inicia el juego con toda la configuracion
    */
    void jugar();

    /*
      Imprime los controles del juego en los cuales se especifican que letra se debe ingresar;  
    */
    void controles();

    /*
      Esta funcion intercambia vecino y vecinoAlternatico de la clase Lugar sera llamada
      al recibir la orden de mover la barca.
    */
    void intercambiarVecino();

};

#else
  class Jugador; // Declaración adelantada
#endif