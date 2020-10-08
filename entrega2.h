#ifndef ENTREGA2_H
#define ENTREGA2_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

#include "lista_doble.h"
#include "quicksort.h"

namespace proj_two
{
  //variables para determinar qué imprimir
  //Se usan en ..................................
  bool bool_laboratorio = false;
  bool bool_precio = false;
  bool bool_costo = false;
  bool bool_descuento = false;
  bool bool_componente = false;

  //Actividad Integral 2
  //Busqueda por listas
  void Entrega2();
  void ListarProductos(DList<Producto>*);
  int ParametrosLista(DList<Producto>*);
  void FiltrarLista(DList<Producto>*,std::string,std::string);

  void Entrega2()
  {
    int opcion_orden=1;
    //Leer datos
    DList<Producto> *lista_productos = new DList<Producto>();
    ListarProductos(lista_productos);
    //Realizar busqueda
    opcion_orden = ParametrosLista(lista_productos);
    //Rango
    std::string parametro;
    if(bool_costo){parametro="COSTO";}
    if(bool_precio){parametro="PRECIO";}
    if(bool_descuento){parametro="DESCUENTO";}
    float max=1000,min=0;
    std::cout<<"Escriba el valor maximo de la búsqueda"<<std::endl;
    std::cin>>max;
    std::cout<<"Escriba el valor minimo de la búsqueda"<<std::endl;
    std::cin>>min;
    lista_productos->AcotarRango(max,min,parametro);
    //Resultados
    lista_productos->MostrarLista(bool_laboratorio, bool_precio, bool_costo, bool_descuento, bool_componente,opcion_orden);
    lista_productos->CrearDocLista();
  }

  //Pone los datos del archivo en una lista
  void ListarProductos(DList<Producto> *list)
  {
    std::ifstream reader("Farmacia.csv");
    if(reader.is_open())
    {
      while(reader.good())//Hasta que no haya más que leer
      {
        //std::cout<<"-----------------------"<<std::endl;
        std::string l1,l2,l3,l4,l5,l6,l7;//Una variable para cada columna
        getline(reader,l1,';');
        //std::cout<<l1<<std::endl;
        getline(reader,l2,';');
        //std::cout<<l2<<std::endl;
        getline(reader,l3,';');
        l3.erase(remove(l3.begin(),l3.end(),'$'),l3.end()); //Borra $
        //std::cout<<l3<<std::endl;
        getline(reader,l4,';');
        l4.erase(remove(l4.begin(),l4.end(),'$'),l4.end()); //Borra $
        //std::cout<<l4<<std::endl;
        getline(reader,l5,';');
        //std::cout<<l5<<std::endl;
        getline(reader,l6,';');
        //std::cout<<l6<<std::endl;
        getline(reader,l7,'\n');
        //std::cout<<l7<<std::endl;
        Producto temp(l1,l2,std::stof(l3),std::stof(l4),l5,std::stof(l6),l7); 
        list->add(temp);
      }
      reader.close();
    }
    else
    {
      std::cout<<"No se puede abrir el archivo"<<std::endl;
    }
  }

  //Recibe del usuario los parametros de búsqueda 
  int ParametrosLista(DList<Producto> *list)
  {
    std::string input;
    std::cout<<"Si quiere filtrar por nombre escriba lo que debe contener el nombre del producto o escriba TODOS si quiere incluir todos los productos"<<std::endl;
    std::cin>>input;
    FiltrarLista(list,input,"nombre");
    std::cout<<std::endl<<"Si quiere filtrar por laboratorio escriba lo que debe contener el nombre lab o escriba TODOS si quiere incluirlos a todos"<<std::endl;
    std::cin>>input;
    FiltrarLista(list,input,"laboratorio");
    std::cout<<std::endl<<"Si quiere filtrar por componente escriba lo que debe contener el nombre del componente o escriba TODOS si quiere incluirlos a todos"<<std::endl;
    std::cin>>input;
    FiltrarLista(list,input,"componente");
    std::cout<<std::endl<<"Elija por cual criterio quiere buscar (1.costo, 2.precio, 3.descuento) Escriba el NÚMERO"<<std::endl;
    std::cin>>input;
    if(std::stoi(input)==1) {bool_costo=true;}
    else if(std::stoi(input)==2) {bool_precio=true;}
    else if(std::stoi(input)==3) {bool_descuento=true;}
    input="1";
    return std::stoi(input);
  }


  void FiltrarLista(DList<Producto> *list,std::string input,std::string tipo)
  {
    input=proj_one::Mayus(input);
    if(input=="TODOS")
    {
      return;
    }
    else
    {
      if(tipo=="nombre")
      {
        
        list->removeFalseName(input);
        
      }
      else if(tipo=="laboratorio")
      {
        bool_laboratorio=true;
        list->removeFalseLab(input);
      }
      else if(tipo=="componente")
      {
        bool_componente=true;
        list->removeFalseComponente(input);
      }
    }
  }
}

#endif