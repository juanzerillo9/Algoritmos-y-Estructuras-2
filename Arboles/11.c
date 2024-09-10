//  Mediante una función entera obtener el nivel máximo de un árbol binario
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *izq, *der;
}NODO;

typedef NODO *arbol;


int maximoArbol(arbol a, int n)
{
    if(a == NULL)
    {
        return n-1;
    }
    else
    {
        int resultIzq = maximoArbol(a->izq, n+1);

        int resultDer = maximoArbol(a->der, n+1);

        return (resultIzq > resultDer) ? resultIzq : resultDer;        
    }
}