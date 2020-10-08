#include <iostream>
#include <fstream>
#include <string>

#include "producto.h"
#include "lista_doble.h"

#include "entrega1.h" //namespace proj_one
#include "entrega2.h" //namespace proj_two


int main()
{
  int eleccion_entrega = 0;
  std::cout<<"Elija el tipo de estructura de dato que quiera utilizar para su búsqueda (Escriba el número)"<<std::endl<<"    1:Vectores (Actividad Integral 1)"<<std::endl<<"    2:Listas (Actividad Integral 2)"<<std::endl<<std::endl;
  std::cin>>eleccion_entrega;
  if(eleccion_entrega == 1)
  {
    proj_one::Entrega1();
  }
  else if(eleccion_entrega == 2)
  {
    proj_two::Entrega2();
  }

  std::cout<<"FIN "<<std::endl;
  std::cin.get();
}



