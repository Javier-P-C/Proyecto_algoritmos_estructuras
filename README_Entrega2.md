---------------------------------------------------------------------
DOCUMENTACIÓN
1.-Explicación general del código
2.-Explicación por Función
3.-Complejidades de los algoritmos
4.-Casos de Prueba

---------------------------------------------------------------------------
1)EXPLICACIÓN GENERAL DEL CÓDIGO

Este programa lee un archivo csv con datos de varias medicinas para realizar búsquedas relevantes para el usuario. Consta de cuatro partes: la lectura de datos, realizar busqueda, acotar la búsqueda por rango y mostrar resultados.

Para esta segunda entrega se utilizan listas hechas por mí para guardar los objetos Producto y realizar las búsquedas.

Lo primero que hace el código es leer el archivo csv y usar los datos de cada línea para crear un objeto que es enviado a una lista de tipo Producto.
Con la lista ya llenada se le pregunta al usuario que cadenas quiere encontrar en el nombre del producto, laboratorio del producto y/o componente del producto. Los nodos de la lista que no corresponden a la búsqueda son eliminados de la lista.
Una vez que se tienen los resultados se le pregunta al usuario el valor máximo y mínimo de su búsqueda. Una vez más se eliminan de la lista los nodos que no correspondan a las especificaciones del usuario.
Por último, se muestran los nodos restantes de la lista en la pantalla y se escriben esos mismos resultados junto con todos sus atributos en el archivo resultado_busqueda.txt.

**Se ha dividido separado el código de la primera y segunda entrega en distintos archivo .h para facilitar la lectura del código

-----------------------------------------------------------------------------
2)EXPLICACIÓN POR FUNCIÓN

void Entrega2();
  -Es la función que sirve como cuerpo de la entrega. Se encarga de realizar las cuatro etapas menicionadas por medio de llamado de funciones. Aquí se  instancia la lista donde se realiza la búsqueda.

void ListarProductos(DList<Producto>*);
  -Lee el archivo csv y crea objetos Producto que son enviados a la lista creada en Entrega2() para la creación de nodos
  
int ParametrosLista(DList<Producto>*);
  -Aquí se le pregunta al usuario las cadenas que quiere que aparezcan en el los resultados de búsqueda.

void FiltrarLista(DList<Producto>*,std::string,std::string);
  -En base a las cadenas ingresadas por el usuario se eleiminan los nodos que no le sirvan al usuario.

MÉTODOS RELEVANTES EN listas_dobles.h
void MostrarLista(bool,bool,bool,bool,bool,int);
  -Despliega en consola los valores de los nodos en la lista.

void removeFalseName(std::string);
void removeFalseLab(std::string);
void removeFalseComponente(std::string);
    -Los tres métodos remove sirven para eliminar los valores que no tengan lo buscado por el usuario;
  
void AcotarRango(int,int,std::string);
  -Recibe los valores mácimos y mínimos del rango y quita aquelloas nodos que no los cumplan
   
void CrearDocLista();
  -Es el encargado de pasar el estado final de la lista resultado_busqueda.txt

-----------------------------------------------------------------------------
3)COMPLEJIDADES DE LOS ALGORITMOS

void ListarProductos(DList<Producto>*);
  Recorre todo el archivo y crea la cantidad de objetos correspondientes a la cantidad de filas por lo que su complejidad es O(n).
  
int ParametrosLista(DList<Producto>*);
  -Como hace llamar tres veces a la función FiltrarLista y esta es de complejidad O(n) la complejidad de esta función es de O(3n).

void FiltrarLista(DList<Producto>*,std::string,std::string);
  -Recorre toda la lista por lo que su complejidad es lineal O(n)

MÉTODOS RELEVANTES EN listas_dobles.h
void MostrarLista(bool,bool,bool,bool,bool,int);
void removeFalseName(std::string);
void removeFalseLab(std::string);
void removeFalseComponente(std::string);  
void AcotarRango(int,int,std::string);
void CrearDocLista();
  -Todas estas funciones tienen que recorrer lalista entera para comprobar los valores de los nodos por lo que todas son de comlejidad lineal O(n)

----------------------------------------------------------------------------
4)CASOS DE PRUEBA

LEER ARCHIVO
INPUT:
2
todos
todos
todos
3
100
0
OUTPUT:
En pantalla deben desplegarse los nombres de 8048 productos que son todos los que se encuentran en el archivo Farmacia.csv

REALIZAR BÚSQUEDAS
INPUT:
2
PEDIALYTE
ABBOTT
todos
100
20
OUTPUT:
Deben aparecer en pantalla todos 15 productos que contengan en su nombre PEDIALYTE y en sulaboratorio ABBOTT

ESCRITURA DE ARCHIVO
INPUT:
2
rexona
todos
todos
1
50 
10
OUTPUT:
72 productos deben aparecer en el archivo resultado_busqueda.txt

