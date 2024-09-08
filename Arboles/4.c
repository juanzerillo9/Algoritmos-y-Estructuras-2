#include <stdio.h>
#include <stdlib.h>

typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);

int main(){
 arbol a;
 int x;
 /* carga arbol ejemplo */
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

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}


arbol nodoP(arbol a, arbol* p)
{
    if(a == NULL)
    {
        return NULL;
    }
    else
    {
        if(a->izq == p)
        {
            return a->der;
        }
        else if(a->der == p)
        {
            return a->izq;
        }
        else
        {
            arbol resultado = nodop(a->izq, p);
            
            if(resultado != NULL)
            {
                return resultado;
            }

            return nodop(a->der, p);
        }
    }
}

