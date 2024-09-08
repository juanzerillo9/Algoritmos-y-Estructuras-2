#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TElememtoA;
typedef struct nodo
{
    TElememtoA dato;
    struct nodo *izq;
    struct nodo *der;
} NODO;
typedef NODO *arbol;

void addnodo(arbol *a, TElememtoA e);

int main()
{
    arbol a;
    int x;
    int n = 0;
    addnodo(&a, 1);
    addnodo(&a->izq, 4);
    addnodo(&a->izq->izq, 5);

    addnodo(&a->izq->izq->izq, 11);
    addnodo(&a->izq->der, 6);
    addnodo(&a->izq->der->izq, 10);
    addnodo(&a->izq->der->der, 12);
    addnodo(&a->der, 2);
    addnodo(&a->der->izq, 3);
    addnodo(&a->der->izq->der, 9);

    char arreglo[10];
    charGrado1(a, arreglo, &n);
    return 0;
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void charGrado1(arbol a, char arreglo[], int *n)
{
    if (a != NULL)
    {
        if (a->der != NULL || a->izq != NULL)
        {
            arreglo[(*n)++] = a->dato;
        }

        charGrado1(a->der, arreglo, &n);
        charGrado1(a->izq, arreglo, &n);
    }
}