#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>

class Producto
{
  private:
    std::string nombre;
    std::string laboratorio;
    float	precio;
    float	costo;	
    std::string id;
    float descuento;
    std::string componente;
  public:
    Producto(std::string,std::string,float,float,std::string,float,std::string);
    Producto();
    
    //getters
    std::string getNombre() { return nombre; }
    std::string getLaboratorio() { return laboratorio; }
    float getPrecio() { return precio; }
    float getCosto() { return costo; }
    std::string getId() { return id; }
    float getDescuento() { return descuento; }
    std::string getComponente() { return componente; }
};

Producto::Producto(std::string _producto,std::string _laboratorio,float _precio,float _costo,std::string _id,float _descuento,std::string _componente)
{
  nombre=_producto;
  laboratorio=_laboratorio;
  precio=_precio;
  costo=_costo;
  id=_id;
  descuento=_descuento;
  componente=_componente;
}

Producto::Producto()
{
}

#endif
