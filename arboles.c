#include <stdio.h>
#include <stdlib.h>

typedef int TDato;
typedef struct nodo
{
    TDato Dato;
    struct nodo *Izq;
    struct nodo *Der;
} NODO;
typedef NODO *arbol;

void addnodo(arbol *a, TDato e);

int main()
{
    arbol a;
    int x;
    addnodo(&a, 1);
    addnodo(&a->Izq, 4);
    addnodo(&a->Izq->Izq, 5);

    addnodo(&a->Izq->Izq->Izq, 11);
    addnodo(&a->Izq->Der, 6);
    addnodo(&a->Izq->Der->Izq, 10);
    addnodo(&a->Izq->Der->Der, 12);
    addnodo(&a->Der, 2);
    addnodo(&a->Der->Izq, 3);
    addnodo(&a->Der->Izq->Der, 9);

    return 0;
}

void addnodo(arbol *a, TDato e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->Dato = e;
    (*a)->Izq = NULL;
    (*a)->Der = NULL;
}
void Inserta(arbol *A, TDato X)
{
    if (*A == NULL)
    {
        *A = (arbol)malloc(sizeof(struct nodo));
        (*A)->Dato = X;
        (*A)->Der = NULL;
        (*A)->Izq = NULL;
    }
    else if (X > (*A)->Dato)
        Inserta(&((*A)->Der), X);
    else
        Inserta(&((*A)->Izq), X);
}

void Borrar(arbol *p, arbol aux)
{
    if ((*p)->Der != NULL)
        Borrar(&((*p)->Der), aux) ;
        else
        {
            aux->Dato = (*p)->Dato;
            aux = *p;
            *p = (*p)->Izq;
            free(aux);
        }
}

void Elimina(arbol *A, TDato X)
{
    arbol aux;
    if (*A != NULL)
        if (X < (*A)->Dato)
            Elimina(&((*A)->Izq), X);
        else if (X > (*A)->Dato)
            Elimina(&((*A)->Der), X);
        else
        {
            aux = *A;
            if (aux->Der == NULL)
            {   
                (*A) = aux->Izq;
                free(aux);
            }
            else if (aux->Izq == NULL)
            {
                (*A) = aux->Der;
                free(aux);
            }
            else
                Borrar(&(aux->Izq), aux);
        }
};



void preorden(arbol a, TDato b)
{
    if(!isnull(a->Dato))
    {
        info(a);
    }
}