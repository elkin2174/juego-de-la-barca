/*
  Archivo: Jugador.cpp
  Autor: Elkin Tovar, elkin.tovar@correounivalle.edu.co
  Fecha de creación: 21/02/2024
  Fecha última modificación: 25/02/2024
  version: 0.1
  Licencia: GNU-GPL
*/

#include "Jugador.h"

Jugador::Jugador()
{
}
Jugador::~Jugador()
{
  //eliminarConfiguracion();
}

void Jugador::addLugar(Lugar *lugar)
{
  lugares.push_back(lugar);
}

void Jugador::configurarInicio()
{
  // Crea los lugares
  addLugar(new Orilla("OrillaIzquierda"));// lugares[0] -> Orilla Izquierda
  addLugar(new Barca("Barca"));// lugares[1] -> Barca
  addLugar(new Orilla("OrillaDerecha"));// lugares[2] -> Orilla Derecha
  
  // agrega los vecinos a los lugares
  lugares[0]->setVecino(lugares[1]);// vecino: Barca
  lugares[0]->setVecinoAlternativo(nullptr); // Vecino Alternativo: Agua(nullptr)
  lugares[1]->setVecino(lugares[0]);// Vecino: orilla izquierda
  lugares[1]->setVecinoAlternativo(lugares[2]);// Vecino Alternativo: orilla derecha
  lugares[2]->setVecino(nullptr);// Vecino: Agua(nullptr)
  lugares[2]->setVecinoAlternativo(lugares[1]);// Vecino Alternativo: BArca
  
  // agrega los individuos a el lugar inicial(Orilla Izquierda)
  lugares[0]->addIndividuos(new Individuo("Robot","Recarga",'R'));
  lugares[0]->addIndividuos(new Individuo("Zorro", "Conejo", 'Z'));
  lugares[0]->addIndividuos(new Individuo("Conejo","Lechuga",'C'));
  lugares[0]->addIndividuos(new Individuo("Lechuga", "Luz", 'L'));
}

void Jugador::eliminarConfiguracion()
{
  for (Lugar *lugar : lugares)
  {
    delete lugar;
  }
  lugares.clear();
}

void Jugador::menuInicial() 
{
  cout<<"|--------------------------|"<<endl;
  cout<<"|  !EL JUEGO DE LA BARCA!  |"<<endl;
  cout<<"|--------------------------|"<<endl<<endl;
  while(true)
  {
    cout<<"\tEscoja una opcion: "<<endl<<endl; 
    cout << "\t S - Iniciar partida."<<endl;
    cout << "\t H - acerca del juego."<<endl;
    cout << "\t X - Salir."<<endl;
    char opt = 'A';
    cout << "->  ";cin >> opt;cout << endl;
    if(opt == 'X')
    {
      cout << "|-- Se a finalizado el programa --|"<<endl;
      break;
    }
    else if (opt == 'S')
    {
      configurarInicio();
      jugar();
    }
    else if (opt == 'H')
    {
      cout << "\nEl juego consiste en lo siguiente: hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del río hasta la otra orilla, usando una barca. En la barca solo cabe uno de los tres individuos, además del robot. El problema es que si el robot deja solos al zorro y el conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga. El jugador debe controlar que órdenes dar, para lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos.\n\n";
    }
    else
    {
      cout << "Por favor, ingresa una opcion correcta."<<endl;
    }
  }
}

void Jugador::frame()
{
  string  barca = "| BARCA     ";
  string  rio = "          | ";
  if(lugares[1]->getVecino() == lugares[0])
  {
    cout << "| IZQUIERDA "<<barca<<"|          "<<" | DERECHA   |"<<endl;
    // Representa que linea se va a imprimir
    for (int i = 0; i < 4; i++)
    {
      cout << "| ";
      if(i < lugares[0]->vectorIndividuos().size())
      {
        cout<<lugares[0]->vectorIndividuos()[i]->getNombre();
        cout << " \t| ";
      }else cout << rio;
      
      if(i < lugares[1]->vectorIndividuos().size())
      {
        cout<<lugares[1]->vectorIndividuos()[i]->getNombre();
        cout << " \t| ";
      }else cout << rio;
      cout<<rio; // Imprime el rio cuando la basa se encuentra al otro lado
      if(i < lugares[2]->vectorIndividuos().size())
      {
        cout<<lugares[2]->vectorIndividuos()[i]->getNombre();
        cout<<" \t|"<<endl;
      }else cout << rio <<endl;
    } 
  }
  else if(lugares[1]->getVecino() == lugares[2])
  {
    rio = "          | ";
    cout << "| IZQUIERDA "<<"|           "<<barca<<"| DERECHA   |"<<endl;
    for (int i = 0; i < 4; i++)
    {
      cout << "| ";
      if(i < lugares[0]->vectorIndividuos().size())
      {
        cout<<lugares[0]->vectorIndividuos()[i]->getNombre();
        cout << " \t| ";
      }else cout << rio;
      cout<<rio; // Imprime el rio cuando la basa se encuentra al otro lado
      if(i < lugares[1]->vectorIndividuos().size())
      {
        cout<<lugares[1]->vectorIndividuos()[i]->getNombre();
        cout << " \t| ";
      }else cout << rio;
      
      if(i < lugares[2]->vectorIndividuos().size())
      {
        cout<<lugares[2]->vectorIndividuos()[i]->getNombre();
        cout<<" \t|"<<endl;
      }else cout << rio <<endl;
    }
  }
}

void Jugador::jugar()
{
  char ordenMenu = 'M';
  while(true)
  {
    frame();
    controles();
    cout << "->  ";cin >> ordenMenu;cout<<endl;
    
    if(ordenMenu == 'R' or ordenMenu == 'Z' or ordenMenu == 'C' or ordenMenu == 'L' or ordenMenu == 'Q')
    {
      if (ordenMenu == 'Q' or validarPerdida(ordenMenu)) // Verificacion adelantada para cuando un individuo se ahoga
      {
        cout << "\t¡PERDISTE!"<<endl<<endl;
        this->eliminarConfiguracion();
        cout << "  Regresando al menú..."<<endl<<endl;
        break;
      }
      
      if(lugares[1]->estaLlena() and not lugares[1]->verificarIndividuo(ordenMenu))
      {
        cout<<"\t ¡La Barca Está llena!"<<endl<<endl;
        continue;
      }
      
      for(Lugar *lugar : lugares)
      {
        if(lugar->moverIndividuo(ordenMenu))
        {
          break;
        }
      }
    
      if (validarPerdida(ordenMenu))// Verificacion para cuando alguien es devorado
      {
        cout<<"\t¡PERDISTES!"<<endl<<endl;
        cout<<"  Regresando al menú..." << endl<<endl;
        this->eliminarConfiguracion();
        break;
      }
      
      if(victoria()) break;
    }
    else if(ordenMenu == 'B')
    {
      if (lugares[1]->buscarRobot())
      {
        this->intercambiarVecino();
      }
      else
      {
        cout << "\t ¡El robot no se encuentra en la barca!\n"<<endl<<endl; 
      }    
    }
    else
    {
      cout<<"\t Por favor, Ingresa una acción válida. "<<endl<<endl;
    }
  }
}

void Jugador::controles()
{
  cout << endl;
  cout << "\t R - Mover Robot"<<endl;
  cout << "\t B - Mover Barcar" <<endl;
  cout << "\t Z - Mover Zorro"<<endl;
  cout << "\t C - Mover Conejo" <<endl;
  cout << "\t L - Mover Lechuga"<<endl;
  cout << "\t Q - Rendirte"<<endl<<endl;
}

void Jugador::intercambiarVecino()
{
  for (Lugar *lugar : lugares )
  {
    Lugar* aux = lugar->getVecino();
    lugar->setVecino(lugar->getVecinoAltenativo());
    lugar->setVecinoAlternativo(aux);
  }
}

bool Jugador::validarPerdida(char orden)
{
  for(Lugar *lugar : lugares)
  {
    if(lugar->vectorIndividuos().size() == 0){
      continue;
    }
    if(lugar->PuedeComer())
    {
      cout << "  ¡Alguien ha sido devorado!"<<endl<<endl;
      return true;
    }
    if(lugar->getNombre() == "Barca" or lugar->retornarIndice(orden) == 99)
    {
      continue;
    }
    if(lugar->seAhogo())
    {
      cout << " !" + lugar->vectorIndividuos()[lugar->retornarIndice(orden)]->getNombre() + " se cayó al agua!" <<endl<<endl;
      return true;
    }
  }
  return false;
}

bool Jugador::victoria()
{
  if(lugares[2]->estaLlena())
  {
    frame();
    cout<<"\n\t¡¡Ganaste!!"<<endl<<endl;
    cout<<"¡Felicidades, Resolviste el enigma! " << endl<<endl;
    cout<<"  Regresando al menú..." << endl<<endl;
    this->eliminarConfiguracion();
    return true;
  }
  return false;
}