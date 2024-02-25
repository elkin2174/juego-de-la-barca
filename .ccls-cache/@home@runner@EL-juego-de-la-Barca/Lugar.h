/*
  Archivo: Lugar.h
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 24/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
/**
  CLASE: Lugar
  INTENCION: Esta clase moldea los lugares, y tiene la resposabilidad de verificar los distintos estados para decidir si el jugador perdio.
  RELACIONES:
  -conoce Individuo
*/

#ifndef LUGAR_H
#define LUGAR_H

#include <vector>
#include <iostream>
#include "Individuo.h"

using namespace std;
class Lugar
{
  private:
    string nombre;
    Lugar *vecino;
    Lugar *vecinoAlternanitivo;
    vector<Individuo*> individuos;

  public:
    /*
      Constructore y Destructor.
    */
    // Constructor Vacio.
    Lugar();

    // Constructor Con Atributos.
    Lugar(string _nombre);

    /*
      Destruye el lugar y los individuos en el vector de individuos.
    */
    virtual ~Lugar();

    //Getters - obtienen el atributo al que hacen referencia en el nombre.
    string getNombre();
    Lugar* getVecino();
    Lugar* getVecinoAltenativo();

    // Setters - Cambian el atributo al que hacen referencia en el nombre.
    void setNombre(string _nombre);
    void setVecino(Lugar *_vecino);
    void setVecinoAlternativo(Lugar *_vecino);

    /*
      Estos son los metodos de la clase distintos a los Getters y Setters, metodos virtuales, etc.
    */
    /*
      Verifica si el Robot se encuentra en el lugar.
    */
    bool buscarRobot();

    /*
      Verifica si hay un individuo que se pueda comer a otro mientras no este el robot
    */
    bool PuedeComer();

    /*
      Verifica si al mover un individuo se cae a el agua o no
    */
    bool seAhogo();

    /* 
      Agrega individuos a el vector de individuos
    */
    void addIndividuos(Individuo *_individuo);

    /*
      Metodo virtual para verificar si el lugar se encuentra lleno.
    */
    virtual bool estaLlena() = 0;

    /*
      Retorna el vector de individuos
    */
    vector<Individuo*> vectorIndividuos();

    /*
      Retorna el indice del individuo al recibir la orden del individuo.
    */
    int retornarIndice(char orden);

    /*
      Borra los individuos que han sido movidos a otras instacias de la clase lugar
    */
    void eliminarIndividuo(int indice);

    /*
      Mueve el individuo al Vecino y retorna true si este es movido
    */
    bool moverIndividuo(char orden);

    /*
      Verifica si el individuo esta en el lugar;
    */
    bool verificarIndividuo(char orden);
};

#else
  class Lugar; // Declaración adelantada
#endif