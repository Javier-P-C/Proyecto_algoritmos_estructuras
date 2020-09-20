#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "producto.h"

class Quicksort
{
  private:
    int opcion;
    std::string parametro;
    void Swap(std::vector<Producto>&,int,int);
    void Sort_helper(std::vector<Producto>&,int,int);
    int Partition(std::vector<Producto>&,int,int);
  public:
    void Sort(std::vector<Producto> &v,int,std::string);
};

void Quicksort::Sort_helper(std::vector<Producto> &v,int low,int high)
{
  if(low<high)
  {
    int pivot = Partition(v,low,high);
    Sort_helper(v,low,pivot-1);
    Sort_helper(v,pivot+1,high);
  }
  return;
}

void Quicksort::Swap(std::vector<Producto> &v, int i, int j)
{
  Producto aux;
  aux=v[i];
  v[i]=v[j];
  v[j]=aux;
}

int Quicksort::Partition(std::vector<Producto> &v,int low,int high)
{
  float pivot;
  if(parametro=="DESCUENTO")
  {
    pivot=v[high].getDescuento();
  }
  else if(parametro=="COSTO")
  {
    pivot=v[high].getCosto();
  }
  else
  {
    pivot=v[high].getPrecio();
  }
  //std::cout<<"PIVOOOOOOOOOTEEEEEEEEEE:"<<pivot<<std::endl;
  int i=low;
  for(int j=low;j<high;j++)
  {
    if(opcion==1)//menor a mayor
    {
      if(parametro=="DESCUENTO")
      {
        if(v[j].getDescuento()<=pivot)
        {
          //std::cout<<"1.1"<<std::endl;
          Swap(v,j,i);
          i++;
        }
      }
      if(parametro=="COSTO")
      {
        if(v[j].getCosto()<=pivot)
        {
          //std::cout<<"1.2"<<std::endl;
          Swap(v,j,i);
          i++;
        }
      }
      if(parametro=="PRECIO")
      {
        if(v[j].getPrecio()<=pivot)
        {
          //std::cout<<"1.3"<<std::endl;
          Swap(v,j,i);
          i++;
        }
      }
    }
    else if(opcion==2) //mayor a menor
    {
      if(parametro=="DESCUENTO")
      {
        if(v[j].getDescuento()>=pivot)
        {
          //std::cout<<"2.1"<<std::endl;
          Swap(v,j,i);
          i++;
        }
      }
      if(parametro=="COSTO")
      {
        if(v[j].getCosto()>=pivot)
        {
          //std::cout<<"2.2"<<std::endl;
          Swap(v,j,i);
          i++;
        }
      }
      if(parametro=="PRECIO")
      {
        if(v[j].getPrecio()>=pivot)
        {
          //std::cout<<"2.3"<<std::endl;
          Swap(v,j,i);
          i++;
        }
      }
    }
  }
  Swap(v,high,i);
  return i;
}

void Quicksort::Sort(std::vector<Producto> &v,int op,std::string param)
{
  opcion=op;
  parametro=param;
  Sort_helper(v,0,v.size()-1);
  for(int i=0;i<v.size();i++)
  {
    std::cout<<v[i].getNombre()<<std::endl;
  }
}

#endif