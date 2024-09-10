#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TElememtoA;
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

    return 0;
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int busquedaXeY(arbol a, int x, int y)
{
    if(a == NULL)
    {
        return 0;
    }
    else
    {
        if(a->dato > x && a->dato < y)
        {
            return 1 + busquedaXeY(a->der, x, y) + busquedaXeY(a->izq, x, y);
        }
        else if(a->dato > y)
        {
            return busquedaXeY(a->izq, x, y);
        }else
        {
            return busquedaXeY(a->der, x, y);
        }
    }
}