#include <iostream>
#include <fstream>

#include "producto.h"
#include "lista_doble.h"

#include "entrega1.h" //namespace proj_one

//variables para determinar qué imprimir
//Se usan en ..................................
bool bool_laboratorio = false;
bool bool_precio = false;
bool bool_costo = false;
bool bool_descuento = false;
bool bool_componente = false;

//Actividad Integral 2
//void Entrega2(); //Ordenamiento por Listas
void ListarProductos(DList<Producto>*);


int main()
{
  /*int eleccion_entrega = 0;
  std::cout<<"Elija el tipo de estructura de dato que quiera utilizar para su búsqueda (Escriba el número)"<<std::endl<<"    1:Vectores (Actividad Integral 1)<<std::endl<<"    2:Listas (Actividad Integral 2)"<<std::endl<<std::endl;
  std::cin>>eleccion_entrega;
  if(eleccion_entrega == 1)
  {
    proj_one::Entrega1();
  }
  else if(eleccion_entrega == 2)
  {
    Entrega2();
  }*/
  

  /*int opcion_orden=1;
  //Leer datos
  std::vector<Producto> vect_prod;
  VectorizarArchivo(vect_prod);
  //Realizar busqueda
  std::vector<Producto> vect_search(vect_prod);
  opcion_orden=ElegirParametros(vect_search);
  //Ordenar
  Quicksort vect_orden;
  std::string parametro;
  if(bool_costo){parametro="COSTO";}
  if(bool_precio){parametro="PRECIO";}
  if(bool_descuento){parametro="DESCUENTO";}
  vect_orden.Sort(vect_search, parametro);
  //Rango
  acotarResultados(vect_search);
  //Resultados
  MostrarVector(vect_search,opcion_orden);
  CrearDocVector(vect_search);*/

  int opcion_orden=1;
  //Leer datos
  DList<Producto> *lista_productos;
  ListarProductos(lista_productos);
  
  
  std::cout<<"FIN "<<std::endl;
  return 0;
}


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
      std::cout<<"ad"<<std::endl;
      list->add(temp);
      std::cout<<"added"<<std::endl;
    }
    reader.close();
  }
  else
  {
    std::cout<<"No se puede abrir el archivo"<<std::endl;
  }
}
