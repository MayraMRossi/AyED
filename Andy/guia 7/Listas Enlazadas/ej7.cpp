#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo*ant;
    Nodo*sig;
};

void insertar(Nodo*&lista, int nro);
Nodo* completarAntecesores(Nodo*lista);
void mostrarAsc(Nodo*l);
void mostrarDesc(Nodo*l);

int main()
{
    Nodo*lista = NULL, *lista2;
    int nro;
    cout<<"Nro: ";
    cin>>nro;
    while(nro!=0)
    {
        insertar(lista, nro);
        cout<<"Nro: ";
        cin>>nro;
    }
    lista2 = completarAntecesores(lista);
    //mostrarAsc(lista);
    mostrarDesc(lista2);
}

void insertar(Nodo*&lista, int nro)
{
    Nodo*n, *l, *ant;
    n = new Nodo;
    n->info = nro;
    l = lista;
    while(l!=NULL && l->info < nro)
    {
        ant = l;
        l = l->sig;
    }
    n->sig = l;
    n->ant = NULL;
    if(l != lista)
        ant->sig = n;
    else
        lista = n;
}

Nodo* completarAntecesores(Nodo*lista)
{
    Nodo*p;
    while(lista != NULL)
    {
        p = lista;
        lista = lista->sig;
        if(lista!=NULL)
            lista->ant = p;

    }
    return p;
}

void mostrarAsc(Nodo*l)
{
    while(l!=NULL)
    {
        cout<<l->info<<endl;
        l=l->sig;
    }
}

void mostrarDesc(Nodo*l)
{
    while(l!=NULL)
    {
        cout<<l->info<<endl;
        l=l->ant;
    }
}