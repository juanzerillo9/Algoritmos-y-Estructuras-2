#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}NODO;

typedef NODO *arbol;


void encuentraHermano(arbol a, NODO *p, NODO **h )
{
    if(a != NULL)
    {
        if(a->der == p)
        {
            (*h) = a->izq;
        }
        else if(a->izq == p)
        {
            (*h) = a->der;
        }
        else
        {
            encuentraHermano(a->der, p , h);
            encuentraHermano(a->izq, p, h); 
        }
    }
}
