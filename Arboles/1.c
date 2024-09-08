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



int contNodos(arbol a)
{
    if(a == NULL)
    {
        return 0;
    }else
    {   
        if(a->dato < 0)
        {
            return 1 + contNodos(a->der) + contNodos(a->izq);
        }
        else
        {
            return contNodos(a->der) + contNodos(a->izq);
        }
    }
}



int ElemX5(arbol a)
{
    if(a == NULL)
    {
        return 0;
    }
    else
    {
        if(a->dato % 5 == 0)
        {
            return a->dato + ElemX5(a->der) + ElemX5(a->izq);
        }
        else
        {
            return ElemX5(a->der) + ElemX5(a->izq);
        }       
    }       
}


int hojas(arbol a)
{
    if(a == NULL)
    {
        return 0;
    }
    else
    {
        if(a->der == NULL && a->izq == NULL)
        {
            return 1;
        }
        else
        {
            return 0 + hojas(a->izq) + hojas(a->der);
        }
    }
}



