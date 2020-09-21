#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "producto.h"
#include "quicksort.h"

void VectorizarArchivo(std::vector<Producto> &v);
void InvertirVector(std::vector<Producto> &v);
void MostrarVector(std::vector<Producto> &v,int);
int ElegirParametros(std::vector<Producto> &v);
void Filtrar(std::vector<Producto> &v,std::string,std::string);
std::string Mayus(std::string);
void acotarResultados(std::vector<Producto>&);
int busqueda_binaria(std::vector<Producto>&,float,std::string);
void CrearDoc(std::vector<Producto> &v);

//variables para determinar qué imprimir
//Se usan en ElegirParametros() y MostrarVector()
bool bool_laboratorio = false;
bool bool_precio = false;
bool bool_costo = false;
bool bool_descuento = false;
bool bool_componente = false;

int main()
{
  int opcion_orden=1;
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
  CrearDoc(vect_search);
  std::cout<<"FIN"<<std::endl;
  return 0;
}

//Pasa todos los productos del archivo csv a un vector de tipo Producto
void VectorizarArchivo(std::vector<Producto> &v)
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
      v.push_back(temp);
    }
    reader.close();
  }
  else
  {
    std::cout<<"No se puede abrir el archivo"<<std::endl;
  }
}

//Invierte el orden de los elementos del vector
void InvertirVector(std::vector<Producto> &v)
{
  std::vector<Producto> vect_aux(v.size());
  int pos_aux = v.size()-1;
  for(int i=0;i<v.size();i++)
  {
    vect_aux[pos_aux-i]=v[i];
  }
  for(int i=0;i<v.size();i++)
  {
    v[i]=vect_aux[i];
  }
}

//Muestra todos los nombres de los productos y los atributos que se hayan seleccionado
void MostrarVector(std::vector<Producto> &v,int opcion_orden)
{
  int count=0;
  if(opcion_orden==2)
  {
    InvertirVector(v);
  }
  for(int i=0;i<v.size();i++)
  {
    std::cout<<"ID:"<<v[i].getId()<<" / Nombre:"<<v[i].getNombre();

    if(bool_laboratorio) {std::cout<<" / Lab:"<<v[i].getLaboratorio();}
    if(bool_precio) {std::cout<<" / Precio:"<<v[i].getPrecio();}
    if(bool_costo) {std::cout<<" / Costo:"<<v[i].getCosto();}
    if(bool_descuento) {std::cout<<" / Descuento:"<<v[i].getDescuento();}
    if(bool_componente) {std::cout<<" / Componente:"<<v[i].getComponente();}
    std::cout<<std::endl;
    
    count++;
  }
  std::cout<<"Total: "<<count<<std::endl;
}

//Recibe del usuario los parametros de búsqueda y ordenamiento
int ElegirParametros(std::vector<Producto> &v)
{
  std::string input,input2;
  std::cout<<"Si quiere filtrar por nombre escriba lo que debe contener el nombre del producto o escriba TODOS si quiere incluir todos los productos"<<std::endl;
  std::cin>>input;
  Filtrar(v,input,"nombre");
  std::cout<<std::endl<<"Si quiere filtrar por laboratorio escriba lo que debe contener el nombre lab o escriba TODOS si quiere incluirlos a todos"<<std::endl;
  std::cin>>input;
  Filtrar(v,input,"laboratorio");
  std::cout<<std::endl<<"Si quiere filtrar por componente escriba lo que debe contener el nombre del componente o escriba TODOS si quiere incluirlos a todos"<<std::endl;
  std::cin>>input;
  Filtrar(v,input,"componente");
  std::cout<<std::endl<<"Elija por cual criterio quiere ordenarlos (1.costo, 2.precio, 3.descuento) Escriba el NÚMERO"<<std::endl;
  std::cin>>input;
  if(std::stoi(input)==1) {bool_costo=true;}
  else if(std::stoi(input)==2) {bool_precio=true;}
  else if(std::stoi(input)==3) {bool_descuento=true;}
  std::cout<<std::endl<<"Escoja una opción para el ordenamiento (NÚMERO) 1.menor a mayor, 2.mayor a menor"<<std::endl;
  std::cin>>input2;
  return std::stoi(input2);
}

//Elimina del vector recibido aquellos elementos que no tienen el parámetro elegido por el usuario
void Filtrar(std::vector<Producto> &v,std::string input,std::string tipo)
{
  input=Mayus(input);
  
  //std::vector<int> aux;
  if(input=="TODOS")
  {
    return;
  }
  else
  {
    if(tipo=="nombre")
    {
      for(int i=0;i<v.size();i++)
      {
        std::size_t found = (v[i].getNombre()).find(input);
        if(found == std::string::npos)
        {
          v.erase(v.begin()+i);
          i--;
        }
        else
        {
          std::cout<<"Elemento encontrado ("<<i+1<<")..."<<std::endl;
        }
      }
    }
    else if(tipo=="laboratorio")
    {
      bool_laboratorio=true;
      for(int i=0;i<v.size();i++)
      {
        std::size_t found = (v[i].getLaboratorio()).find(input);
        if(found == std::string::npos)
        {
          v.erase(v.begin()+i);
          i--;
        }
        else
        {
          std::cout<<"Elemento encontrado ("<<i+1<<")..."<<std::endl;   
        }
      }
    }
    else if(tipo=="componente")
    {
      bool_componente=true;
      for(int i=0;i<v.size();i++)
      {
        std::size_t found = (v[i].getComponente()).find(input);
        if(found == std::string::npos)
        {
          v.erase(v.begin()+i);
          i--;
        }
        else
        {
          std::cout<<"Elemento encontrado ("<<i+1<<")..."<<std::endl;
        }
      }
    }
  }
  return;
}

//Pasa el string a mayúsculas
std::string Mayus(std::string cadena)
{
  for(int i=0;i<cadena.length();i++)
  {
    cadena[i]= toupper(cadena[i]);
  }
  return cadena;
}

//Crea un archivo de texto con el vector
void CrearDoc(std::vector<Producto> &v)
{
  std::ofstream writer("resultado_busqueda.txt");
  if(writer.is_open())
  {
    for(int i=0;i<v.size();i++)
    {
      writer<<"ID:"<<v[i].getId();
      writer<<"; Nombre:"<<v[i].getNombre();
      writer<<"; Lab:"<<v[i].getLaboratorio();
      writer<<"; Precio:"<<v[i].getPrecio();
      writer<<"; Costo:"<<v[i].getCosto();
      writer<<"; Descuento:"<<v[i].getDescuento();
      writer<<"; Componente:"<<v[i].getComponente()<<"\n";
    }
    writer.close();
  }
  else
  {
    std::cout<<"No se puede abrir el archivo"<<std::endl;
  }
}

//Búsqueda Binaria
int busqueda_binaria(std::vector<Producto> &v,float val,std::string tipo)
{
  int low=0;
  int high=v.size()-1;
  int mid;
  while(low<=high)
  {
    mid=(low+high)/2;
    if(tipo=="COSTO")
    {
      if(val==v[mid].getCosto())
      {
        return mid;
      }
      else if(val<v[mid].getCosto())
      {
        high=mid-1;
      }
      else if(val>v[mid].getCosto())
      {
        low=mid+1;
      }
    }
    else if(tipo=="DESCUENTO")
    {
      if(val==v[mid].getDescuento())
      {
        return mid;
      }
      else if(val<v[mid].getDescuento())
      {
        high=mid-1;
      }
      else if(val>v[mid].getDescuento())
      {
        low=mid+1;
      }
    }
    else if(tipo=="PRECIO")
    {
      if(val==v[mid].getPrecio())
      {
        return mid;
      }
      else if(val<v[mid].getPrecio())
      {
        high=mid-1;
      }
      else if(val>v[mid].getPrecio())
      {
        low=mid+1;
      }
    }
  }
  return low;
}

//Delimita el vector por Rango
void acotarResultados(std::vector<Producto> &v)
{
  int aux;
  float num;
  int pos;
  std::cout<<"¿Quiere acotar la busqueda por rango?"<<std::endl<<"1.Sí 2.No"<<std::endl;
  std::cin>>aux;
  if(aux==2)
  {
    return;
  }
  else
  {
    std::string tipo;
    if(bool_costo){tipo="COSTO";}
    else if(bool_precio){tipo="PRECIO";}
    else if(bool_descuento){tipo="DESCUENTO";}

    std::cout<<"Ingrese el valor máximo: ";
    std::cin>>num;
    std::cout<<std::endl;
    //Búsqueda binaria
    pos=busqueda_binaria(v,num,tipo);
    //Borramos los resultados fuera del rango
    for(int i=v.size()-1;i>=pos;i--)
    {
      v.erase(v.begin()+i);
    }

    std::cout<<"Ingrese el valor mínimo: ";
    std::cin>>num;
    std::cout<<std::endl;
    //Búsqueda binaria
    pos=busqueda_binaria(v,num,tipo);
    //Borramos los resultados fuera del rango
    for(int i=0;i<pos;pos--)
    {
      v.erase(v.begin());
    }
  }
}
