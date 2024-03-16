#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) { 
  int mayorValor = arr[0];
  for(int i = 1; i < size ; i++){
    if(arr[i] > mayorValor){
      mayorValor = arr[i];
    }
  }
  return mayorValor;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int temporal; //Necesitamos un temporal
  for(int i = 0 ; i < size/2 ; i++){  //En el mismo paso intercambiamos estremos, hasta la mitad
    temporal = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temporal;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una dirección válida que no ha sido inicializada con nigún valor específico. 
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 
  int *newArr = (int*) malloc(sizeof(int) * size); 
  int contador = 0;
  for(int i = 0 ; i < size ; i++){
    if(arr[i] % 2 == 0){
      newArr[contador] = arr[i];
      contador ++;
    }
  }
  *newSize = contador; //Como se solicita
  return newArr;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado de menor a mayor.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {
  // Poner los datos del arr1 y arr2 en el result, los recorremos
  for(int i = 0 ; i < size1 ; i++){
    result[i] = arr1[i];
  }
  for(int i = 0 ; i < size2 ; i++){
    result[size1 + i] = arr2[i];
  }
  //bubble sort
  for(int i = 0 ; i < (size1 + size2) - 1 ; i++){
    for(int j = 0 ; j < (size1 + size2) - 1 - i ; j++){
      if(result[j] > result[j+1]){
        int temp = result[j+1];
        result[j+1] = result[j];
        result[j] = temp;
      }
    }
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) { 
  int ascendente = 1;
  int descendente = 1;
  for(int i = 0; i < size - 1 ; i++){   //No podemos comprar con el último
    if(arr[i] > arr[i + 1]){        //Ya no es ascendente
      ascendente = 0;
    } else if(arr[i] < arr[i + 1]){ //Ya no es descendente
      descendente = 0;
    }
  }
  if(ascendente == 1){
    return 1;
  } else if(descendente == 1){
    return -1;
  } else {
    return 0;
  }
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {

//Datos numericos
  libro.autor.anioNacimiento = anioNacimiento;
  libro.anioPublicacion = anioPublicacion;
//Punteros a vectores de texto
  strcopy(libro.titulo, titulo);
  strcopy(libro.autor.nombre, nombreAutor);
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
Puedes guiarte con lo que vimos en las clases (diapos).
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { return NULL; }
