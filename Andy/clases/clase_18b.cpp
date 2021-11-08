#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sig;
};

void insertarAdelante(Nodo*&lista, int nro);
void ordenar(Nodo*&lista);
void ordenar2(Nodo*&lista);
void insertarLogico(Nodo* &lista, Nodo*n);
void insertar(Nodo* &lista, int num);
void listar(Nodo *lista);

int main()
{
    Nodo*listaNum=NULL;
    int nro;
    cout<<"Nro: ";
    cin>>nro;
    while(nro!=0)
    {
        insertarAdelante(listaNum, nro);
        cout<<"Nro: ";
        cin>>nro;
    }
    cout<<"Desordenado: "<<endl;
    listar(listaNum);
    ordenar2(listaNum);
    cout<<"Ordenado: "<<endl;
    listar(listaNum);
}

void insertarAdelante(Nodo*&lista, int nro)
{
    Nodo*p=new Nodo;
    p->info=nro;
    p->sig=lista;
    lista=p;
}

void ordenar(Nodo*&lista)
{
    Nodo*listaAux = NULL;
    Nodo *p;
    while(lista!=NULL)
    {
        insertar(listaAux, lista->info);
        p=lista;
        lista=lista->sig;
        delete p;
    }
    lista=listaAux;
}

void ordenar2(Nodo*&lista) // reenlazar los nodos para que la lista quede ordenada
{
    Nodo*listaAux = NULL;
    Nodo *p;
    while(lista!=NULL)
    {
        p=lista;
        lista=lista->sig;
        insertarLogico(listaAux, p);
    }
    lista=listaAux;
}

void insertarLogico(Nodo* &lista, Nodo*n)
{
    Nodo *l, *ant;
    l=lista;
    while(l != NULL && l->info < n->info)
    {
        ant = l; 
        l = l->sig; 
    }
    n->sig = l;
    if(l != lista)
        ant->sig = n;
    else
        lista = n;
}

void insertar(Nodo* &lista, int num)
{
    Nodo *n, *l, *ant;
    n = new Nodo;
    n->info = num;
    l = lista;
    while(l != NULL && l->info < num)
    {
        ant = l; 
        l = l->sig; 
    }
    n->sig = l;
    if(l != lista)
        ant->sig = n;
    else
        lista = n;
}

void listar(Nodo *lista)
{
    Nodo *l;
    l = lista;
    while(l != NULL)
    {
        cout<<l->info<<endl;
        l = l->sig;
    }
}