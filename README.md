# Proyecto_algoritmos_estructuras
[![Run on Repl.it](https://repl.it/badge/github/Javier-P-C/Proyecto_algoritmos_estructuras)](https://repl.it/github/Javier-P-C/Proyecto_algoritmos_estructuras)

-------------------------------------------------------------------
DOCUMENTACIÓN:
1.-Explicación general del código
2.-Explicación por Función
3.-Complejidades de los algoritmos
4.-Input de usuarios
5.-Casos de Prueba

-------------------------------------------------------------------

1)EXPLICACIÓN GENERAL DEL CÓDIGO

  El programa consiste de tres archivos: main.cpp, producto.h y quicksort.h
El main empieza leyendo el documento Farmacias.csv que contiene una base de datos de productos
de una farmacia. La información de cada línea del archivo se usa para instanciar un objeto 
Producto. Cada Producto es guardado en un vector para el fácil manejo de los datos. Se crea un 
vector copia para hacer el ordenamiento y filtrar los datos en base a parámetros de busqueda 
que el usuario ingresa. Los elementos del vector copia que no cumplen los parámetros se 
eliminan para finalmente imprimir los datos relevantes de la búsqueda en consola y se escribir
un documento con todos los atributos de los Productos ordenados en base a costo, precio o 
descuento. El atributo ordenado depende del usuario y el input que ingresa al programa.
  El documento que se escribe es el archivo resultado_busqueda.txt


-------------------------------------------------------------------

2)EXPLICACIÓN POR FUNCIÓN

  -VectorizarArchivo():
  Lee el archivo Farmacia.csv con ifstream y usa la información para crear un vector de 
  objetos Producto.

  -ElegirParametros():
  Recibe el vector copia creado del archivo y regresa un entero que representa la forma de 
  ordenamiento que quiere el usuario (de menor a mayor o de mayor a menor). En la función 
  se pregunta al usuario que filtros quiere usar en su búsqueda. Cada parámetro que es elegido 
  llama a la función Filtro. Se elige un filtro al poner un input distinto a "todos" o "TODOS".

  -Filtrar():
  El filtro recibe la referencia del vector mandado por ElegirParametros(), un string que 
  hace referencia a un atributo de la clase Producto y un string que sirve como filtro. Con 
  este atributo se elimina del vector a aquellos elementos que no contienen de subcadena el 
  filtro.

  -Class Quicksort:

    -Sort():
    Recibe la instancia del vector copia para iniciar el ordenamiento Quicksort y recibe un 
    string que le da valor al atributo parametro. Llama a Sort_helper() para empezar el proceso 
    recursivo.

    -Sort_helper():
    Recibe referencia de un vector y recibe valores del ínidice low y high. La función llama a 
    Partition() para calcular el índice del pivote y con él se divide el vector con dos 
    llamados recursivos. Si al ser llamada los valores de low y high son iguales o low ws mayor 
    a high la función retorna sin hacer nada.

    -Partition():
    Recibe referencia de un vector y los valores de low y high. Se calcula el valor del pivote 
    con el valor del índice high. Los elementos menores al pivote se acomodan al inicio y al 
    final se recorre el pivote a lado de estos.

    -Swap():
    Recibe la referencia de un vector y dos int que sirven como índices. Se usa para intercambiar valores de dos posiciones del un vector.

  -acotarResultados():
  Recibe la referenciad del vectro coía. Permite al usuario delimitar más la búsqueda por 
  medio de un rango de valores. Elimina los elementos que no están dentro del parámetro. Usa 
  la función busqueda_binaria() para saber la posición en que se encuntra el rango de 
  números.

  -busqueda_binaria():
  Es llamada por acotarResultados() y recibe la referecnia de un vector a la vez que el 
  valor del elemento que se busca. Regresa la posición del elemento como un entero.

  -MostrarVector():
  Imprime los resultados el vector copia. Si el ordenamiento elegido por el usuario fue de 
  mayor a menor primero invierte el vector para imprimirlo posteriormente.

  -CrearDoc():
  Recibe la referencia del vector copia. Abre un archivo de texto y escribe en cada línea 
  todos los atributos de cada objeto que se encuentra en el vector.

  -Funciones de Apoyo
      -Mayus(): Usado para estandarizar los string que se reciben de input.
      -InvertirVector(): Invierte la posición de los elementos en un vector.


-------------------------------------------------------------------

3)COMPLEJIDADES DE LOS ALGORITMOS
-VectorizarArchivo():
Esta función recorre un archivo con n líneas para sacar los datos de ellas. Por lo que su 
complejidad depende de la cantidad de líneas. Su complejidad por tanto es O(n);

-Filtrar():
Esta función se usa en un momento en que el vector no está ordenado por lo que tiene que 
recorrer la totalidad de este para encontrar los datos deseados. Su complejidad es lineal 
O(n).

-Quicksort():
Al ser un algritmo que divie de acuerdo al pivote que se calcule su complejidad puede ser 
muy buena o muy mala. En le mejor de los casos y en uno intermedio la complejidad es de 
O(logn). Esto se debe a que se divide en cada iteración en dos grupos y cadad vez los elementos se ordenan a mayor velocidad. Pero si los datos resultan dejar al pivote hasta el último en cadad iteración se estará recorriendo la lista completa. Lo que da una complejidad de O(n^2). A pesar de este inconveniente, debido a la aleateoridad de las busquedas del usuario es poco probable un caso de O(n^2) en mi programa.

-busqueda_binaria():
La busquedad binaria va delimitando a la mitad el vector en cada iteración. Esto lo hace 
mandando como valor de low a mid+1 cuando el valor de mid es mayor al valor buscado y 
mandando a mid-1 como valor de high cuando el valor de mid es menor al valor buscado. Como 
 va acortando la busqueda su complejidad es logaritmica, O(log(n)).

-MostrarVector():
El ciclo for de esta función se repite el mismo número de veces que la longitud del vector. 
Es un algoritmo de complejifad O(n).

-InvertirVector():
Esta función recorre el vector dos veces, una para copiar los valores en un vector auxiliar 
de forma inversa y otra para copiar los elemento de la copia en el vector original. Su 
complejidad es enontoces 0(2n).

-CrearDoc():
Esta función recorre todo el vector resultante de la búsqueda para ponerlo en un archivo 
txt. Por lo que su complejidad es O(n).


-------------------------------------------------------------------

4)INPUT DEL USUARIO

El programa pide cinco inputs
    1.La cadena de busqueda de un producto por su nombre, si no quieres buscar un producto por su nombre ingrese en la consola TODOS.
    2.La cadena de busqueda de un producto por su laboratorio, si no quieres buscar un producto por su laboratorio ingrese en la consola TODOS.
    3.La cadena de busqueda de un producto por su componente, si no quieres buscar un producto por su componente ingrese en la consola TODOS.
        
        **Puedes realizar tu busqueda con todos los parámetros de búsqueda, con uno o con dos.
        **Si en el input de laboratorio o componente ingresas TODOS no van a imprimirse en consola estos atributos cuando termine la búsqueda. Aunque sí apareceran en el archivo txt
        **Cuando ingrese el primer filtro, sin considerar el input TODOS como filtro, se tardara un poco en salir la siguiente instrucción debido a la búsqueda que está realizando el programa.

  4.El atributo que va a ser ordenado 1(costo), 2(precio), 3(descuento)
  5.La opción 1(ordenar de menor a mayor los datos) o 2(ordenar de mayor a menor los datos)
  6.Opción para decidir si acotar la búsqueda por un rango de números 1(Si), 2(No)
          **Si en el input 6 se ingresa 1 el programa pedirá al usuario el valor máximo y el mínimo del rango
  7.El valor máximo del rango
  8.El valor mínimo del rango

-------------------------------------------------------------------


5)CASOS DE PRUEBA
  -ORDENAMIENTO (Menor a mayor)-
    INPUTS
      pedialyte
      TODOS
      TODOS
      1
      1
      2
    OUTPUT
      En consola deben aparecer 15 productos que en su nombre contengan PEDIALYTE
      Debe marcar en Total: el número 15
      Los costos impresos deben ir de menor a mayor en orden descendente
      El archivo "resultado_busqueda.txt" debe contener los mismos productos con todos sus atributos. Los costos deben estar ordenados de menor a mayor

  -ORDENAMIENTO (Mayor a menor)-
    INPUTS
      TODOS
      takeda
      TODOS
      2
      2
      2
    OUTPUT
      En consola deben aparecer 49 productos con Lab: TAKEDA.
      A lado de Total: debe haber un 49
      Los precios deben imprimirse de mayor a menor de forma descendente
      El archivo "resultado_busqueda.txt" debe contener los mismos productos con todos sus atributos. Los precios deben estar ordenados de mayor a menor
  
  -RANGOS-
    INPUTS
      TODOS
      TODOS
      vitamina
      3
      1
      60
      30
    OUTPUT
      En consola deben aparecer 20 productos con VITAMINA en su componente.
      A lado de Total: debe haber un 20
      Los descuentos deben imprimirse de menor a mayor de forma descendente
      El archivo "resultado_busqueda.txt" debe contener los mismos productos con todos sus atributos. Los descuentos deben estar ordenados de menor a mayor
  
  -VARIOS FILTROS-
    INTPUTS
      aspirina
      otc
      cafeina
      2
      2
      2
    OUTPUT
      En consola deben aparecer 3 productos con ASPIRINA en su nombre, OTC en su laboratorio y CAFEINA en su componente.
      A lado de Total: debe haber un 3
      Los precios deben imprimirse de mayor a menor de forma descendente
      El archivo "resultado_busqueda.txt" debe contener los mismos productos con todos sus atributos. Los precios deben estar ordenados de mayor a menor

  -SIN FILTROS/ESCRITURA/LECTURA-
    INTPUTS
      TODOS
      TODOS
      TODOS
      3
      2
      2
    OUTPUT
      En consola deben aparecer 8048 productos.
      A lado de Total: debe haber un 8048
      Los descuentos deben imprimirse de mayor a menor de forma descendente
      El archivo "resultado_busqueda.txt" debe contener los mismos productos con todos sus atributos. Los descuentos deben estar ordenados de mayor a menor
