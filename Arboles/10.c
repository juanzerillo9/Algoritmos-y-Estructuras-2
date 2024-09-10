#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    char dato;
    struct nodo *izq, *der;
}NODO;

typedef NODO *arbol;

void arreglo(arbol a, char arr[], int *n)
{
    if(a != NULL)
    {
        arreglo(a->der,arr, n);
        arr[(*n)] = a->dato;
        (*n)++;
        arreglo(a->izq,arr, n);
    }
}