/*
  Archivo: Lugar.h
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 23/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
/**
  CLASE: Lugar
  INTENCION: Esta clase moldea los lugares, y tiene la resposabilidad de decidir si el jugador perdio.
  RELACIONES:
  -conoce Individuos
  -conoce Lugar
*/

#ifndef LUGAR_H
#define LUGAR_H

#include <vector>
#include <iostream>
#include "Individuo.h"

using namespace std;
class Lugar
{
  protected:
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
      Estos son los metodos de la clase distintos a los Getters y Setters, tanto metodos virtuales, etc.
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
    bool seAhogo(Individuo *individuo);

    /* 
      Agrega individuos a el vector de individuos
    */
    void addIndividuos(Individuo *_individuo);
    /*
      Retorna el tamañno del arreglo 
    */
    int getTamanio();

    /*
      Metodo virtual para verificar si esta llena la barca en la clase hija
    */
    virtual bool estaLlena() = 0;

    /*
      Metodo virtual para ver si el Lugar se puede mover, solo es valido para la clase hija Barca
    */
    virtual bool sePuedeMover() = 0;

    /*
      Retorna el vector de individuos
    */
    vector<Individuo*> vectorIndividuos();

    /*
      Retorna el indice al recibir una orden
    */
    int retornarIndice(char orden);
    /*
      Borra los individuos que han sido movidos
    */
    void eliminarIndividuo(int indice);
    /*
      Mueve el individuo al Vecino
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