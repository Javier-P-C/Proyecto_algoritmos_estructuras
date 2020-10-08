#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "producto.h"

template <class T> class DList;

template <class T>
class DLink 
{
  private:
    DLink(T);
    DLink(T,DLink<T>*,DLink<T>*);
    DLink(const DLink<T>&);

    T value;
    DLink<T> *next, *previous;

    friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val):value(val),next(0),previous(0) {}

template <class T>
DLink<T>::DLink(T val,DLink<T> *_next,DLink<T> *_previous):value(val),next(_next),previous(_previous) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source):value(source.value),next(source.next),previous(source.previous) {}

template <class T>
class DList
{
  private:
    int size;
    DLink<T> *head, *tail;

  public:
    DList();
    ~DList();

    void addFirst(T);
    void add(T);
    void removeFirst();
    int find(T) const;
    void update(int,T);
    void remove(int);
    std::string toStringForward() const;
    std::string toStringBackward() const;

    void MostrarLista(bool,bool,bool,bool,bool,int);
    void removeFalseName(std::string);
    void removeFalseLab(std::string);
    void removeFalseComponente(std::string);
    void AcotarRango(int,int,std::string);
    void CrearDocLista();
};

template <class T>
DList<T>::DList():size(0),head(0),tail(0) {}

template <class T>
DList<T>::~DList()
{
  DLink<T> *p;
  p=head;

  while(p->next!=0)
  {
    p = p->next;
    delete p->previous;
  }
  delete p;

  head = 0;
  tail = 0;
  size = 0;
}

template <class T>
void DList<T>::addFirst(T val)
{
  head = new DLink<T>(val);

  size++;
}

template <class T>
void DList<T>::add(T val)
{
  if (size == 0)
  {
    addFirst(val);
    tail = head;
    return;
  }
  else
  {
    tail->next = new DLink<T>(val);
    tail->next->previous = tail;
    tail = tail->next;
  }

  size++;
}

template <class T>
void DList<T>::removeFirst()
{
  if(head == tail)
  {
    delete head;
    head = 0;
    tail = 0;
    size = 0;
    return;
  }
  DLink<T> *p;
  p = head;
  p->next->previous = 0;
  head = p->next;
  delete p;
  size--;
}

template <class T>
void DList<T>::remove(int index)
{
  DLink<T> *p,*q;
  p=head;
  q=0;

  if(index == 0)
  {
    removeFirst();
    return;
  }
  else
  {
    for(int i=0;i<size;i++)
    {
      if(index==i)
      {
        if(p->next!=0)
        {
          p->previous->next = p->next;
          p->next->previous = p->previous;
        }
        else
        {
          p->previous->next = 0;
        }
        break;
      }
      p = p->next;
    }
  }
  delete p;

  size--;
}

template <class T>
int DList<T>::find(T val) const
{
  DLink<T> *p;
  p = head;

  for(int i=0;i<size;i++)
  {
    if(p->value == val)
    {
      return i;
    }
    p = p->next;
  }

  return -1;
}

template <class T>
void DList<T>::update(int index,T val)
{
  DLink<T> *p;
  p = head;

  for(int i=0;i<size;i++)
  {
    if(index==i)
    {
      p->value = val;
      break;
    }
    p = p->next;
  }
}

//Imprime los productos en la lista con los parametros elegidos en la búsqueda
template <class T>
void DList<T>::MostrarLista(bool bool_laboratorio,bool bool_precio,bool bool_costo,bool bool_descuento,bool bool_componente,int opcion_orden)
{
  std::cout<<"\n\n";
  DLink<T> *p;
  int count=0;

  if(opcion_orden==2)
  {
    p = tail;
  }
  else
  {
    p = head;
  }

  for(int i=0;i<size;i++)
  {
    std::cout<<"ID:"<<p->value.getId()<<" / Nombre:"<<p->value.getNombre();

    if(bool_laboratorio) {std::cout<<" / Lab:"<<p->value.getLaboratorio();}
    if(bool_precio) {std::cout<<" / Precio:"<<p->value.getPrecio();}
    if(bool_costo) {std::cout<<" / Costo:"<<p->value.getCosto();}
    if(bool_descuento) {std::cout<<" / Descuento:"<<p->value.getDescuento();}
    if(bool_componente) {std::cout<<" / Componente:"<<p->value.getComponente();}
    std::cout<<std::endl;
    
    if(opcion_orden==2)
    {
      p = p->previous;
    }
    else
    {
      p = p->next;
    }
      
    count++;
  }
  std::cout<<"\nTotal de productos en la lista: "<<count<<std::endl;
}


//Elimina de la lista los elementos que no contengan en su nombre el string recibido
template <class T>
void DList<T>::removeFalseName(std::string search)
{
  DLink<T> *p,*q;
  p=head;
  q=0;
  
  for(int i=0;i<size;i++)
  {
    std::size_t found = (p->value.getNombre()).find(search);
    if(found == std::string::npos)
    {
      if(p->previous == 0)
      {
        if(head == tail)
        {
          delete head;
          head = 0;
          tail = 0;
          size = 0;
          return;
        }
        else
        {
          p->next->previous = 0;
          head = p->next;
          q=head;
          delete p;
          p = q;
        }
      }
      else if(p->next!=0)
      {
        p->previous->next = p->next;
        p->next->previous = p->previous;
        q = p->next;
        delete p;
        p=q;
      }
      else
      {
        p->previous->next = 0;
        delete p;
      }
      size--;
      i--;
    }
    else
    {
      p = p->next;
    }
  }
}

//Elimina de la lista los elementos que no contengan en su laboratorio el string recibido
template <class T>
void DList<T>::removeFalseLab(std::string search)
{
  DLink<T> *p,*q;
  p=head;
  q=0;
  
  for(int i=0;i<size;i++)
  {
    std::size_t found = (p->value.getLaboratorio()).find(search);
    if(found == std::string::npos)
    {
      if(p->previous == 0)
      {
        if(head == tail)
        {
          delete head;
          head = 0;
          tail = 0;
          size = 0;
          return;
        }
        else
        {
          p->next->previous = 0;
          head = p->next;
          q=head;
          delete p;
          p = q;
        }
      }
      else if(p->next!=0)
      {
        p->previous->next = p->next;
        p->next->previous = p->previous;
        q = p->next;
        delete p;
        p=q;
      }
      else
      {
        p->previous->next = 0;
        delete p;
      }
      size--;
      i--;
    }
    else
    {
      p = p->next;
    }
  }
}




//Elimina de la lista los elementos que no contengan en su componente el string recibido
template <class T>
void DList<T>::removeFalseComponente(std::string search)
{
  DLink<T> *p,*q;
  p=head;
  q=0;
  
  for(int i=0;i<size;i++)
  {
    std::size_t found = (p->value.getComponente()).find(search);
    if(found == std::string::npos)
    {
      if(p->previous == 0)
      {
        if(head == tail)
        {
          delete head;
          head = 0;
          tail = 0;
          size = 0;
          return;
        }
        else
        {
          p->next->previous = 0;
          head = p->next;
          q=head;
          delete p;
          p = q;
        }
      }
      else if(p->next!=0)
      {
        p->previous->next = p->next;
        p->next->previous = p->previous;
        q = p->next;
        delete p;
        p=q;
      }
      else
      {
        p->previous->next = 0;
        delete p;
      }
      size--;
      i--;
    }
    else
    {
      p = p->next;
    }
  }
}


//Quita los nodos que no estén en el rango del atributo seleccionado
template <class T>
void DList<T>::AcotarRango(int max,int min,std::string atributo)
{
  DLink<T> *p,*q;
  p=head;
  q = 0;
  if(atributo == "COSTO")
  {
    while(p != 0)
    {
      if((p->value.getCosto()<min) || (p->value.getCosto()>max))
      {
        if(p->previous == 0)
        {
          if(head == tail)
          {
            delete head;
            head = 0;
            tail = 0;
            size = 0;
            return;
          }
          else
          {
            p->next->previous = 0;
            head = p->next;
            q=head;
            delete p;
            p = q;
          }
        }
        else if(p->next!=0)
        {
          p->previous->next = p->next;
          p->next->previous = p->previous;
          q = p->next;
          delete p;
          p=q;
        }
        size--;
      }
      else
      {
        p = p->next;
      }
    }
  }
  else if(atributo == "PRECIO")
  {
    while(p != 0)
    {
      if((p->value.getPrecio()<min) || (p->value.getPrecio()>max))
      {
        if(p->previous == 0)
        {
          if(head == tail)
          {
            delete head;
            head = 0;
            tail = 0;
            size = 0;
            return;
          }
          else
          {
            p->next->previous = 0;
            head = p->next;
            q=head;
            delete p;
            p = q;
          }
        }
        else if(p->next!=0)
        {
          p->previous->next = p->next;
          p->next->previous = p->previous;
          q = p->next;
          delete p;
          p=q;
        }
        size--;
      }
      else
      {
        p = p->next;
      }
    }
  }
  else if(atributo == "DESCUENTO")
  {
    while(p != 0)
    {
      if((p->value.getDescuento()<min) || (p->value.getDescuento()>max))
      {
        if(p->previous == 0)
        {
          if(head == tail)
          {
            delete head;
            head = 0;
            tail = 0;
            size = 0;
            return;
          }
          else
          {
            p->next->previous = 0;
            head = p->next;
            q=head;
            delete p;
            p = q;
          }
        }
        else if(p->next!=0)
        {
          p->previous->next = p->next;
          p->next->previous = p->previous;
          q = p->next;
          delete p;
          p=q;
        }
        size--;
      }
      else
      {
        p = p->next;
      }
    }
  }
}


template <class T>
void DList<T>::CrearDocLista()
{
  DLink<T> *p;
  p=head;
  std::ofstream writer("resultado_busqueda.txt");
  if(writer.is_open())
  {
    while(p != 0)
    {
      writer<<"ID:"<<p->value.getId();
      writer<<"; Nombre:"<<p->value.getNombre();
      writer<<"; Lab:"<<p->value.getLaboratorio();
      writer<<"; Precio:"<<p->value.getPrecio();
      writer<<"; Costo:"<<p->value.getCosto();
      writer<<"; Descuento:"<<p->value.getDescuento();
      writer<<"; Componente:"<<p->value.getComponente()<<"\n";
      p = p->next;
    }
    writer.close();
  }
  else
  {
    std::cout<<"No se puede abrir el archivo"<<std::endl;
  }
}

#endif /* DLIST_H_ */
