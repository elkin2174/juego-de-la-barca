/*
  Archivo: Individuo.h
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 21/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/
/**
  CLASE: Individuo
  INTENCION: ESta clase tiene la intencion de moldear a lo individuos que participan en el juego, robor, zorro, etc 
  RELACIONES:


*/

#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>

using namespace std;

class Individuo
{
  private:
    string nombre;
    string comida;
    char orden;

  public:
    /*
      Constructore y Destructor.
    */
    // Constructor Vacio.
    Individuo();
    // Constructor Con Atributos.
    Individuo(string _nombre, string _comida, char _orden);
    // Destructor
    ~Individuo();
    /*
      Destruye el lugar y los individuos en el vector de individuos.
    */
    string getNombre();
    string getComida();
    char getOrden();
    /*
      Setters - Cambian el atributo al que hacen referencia en el nombre.
    */
    void setNombre(string _nombre);
    void setComida(string _cominda);
    void setOrden(char _orden);
    /*
      Estos son los metodos de la clase distintos a los Getters y Setters ya sea tanto metodos virtuales, etc.
    */
  // TODO

};

#else
  class Individuo; // Declaración adelantada
#endif