#include <iostream>
using namespace std;

struct Inscriptos
{
    string nombre;
    int DNI;
};

struct Nodo
{
    Inscriptos info;
    Nodo *sig;
};

void ordenarPorNombre(Nodo *&lista);
void imprimirLista(Nodo *lista);
void insertar(Nodo *&lista, Inscriptos ins);
void insertarPorNombre(Nodo *&lista, Inscriptos ins);

int main()
{
    Nodo *lista = NULL;
    Inscriptos ins;

    cout<<"DNI: ";
    cin>>ins.DNI;
    while(ins.DNI != 0)
    {
        cout<<"Nombre: ";
        cin>>ins.nombre;
        insertar(lista, ins);
        cout<<"DNI: ";
        cin>>ins.DNI;
    }
    ordenarPorNombre(lista);
    imprimirLista(lista);

}

void ordenarPorNombre(Nodo *&lista)
{
    Nodo *listaOrdenada = NULL;
    while(lista != NULL)
    {
        insertarPorNombre(listaOrdenada, lista->info);
        lista = lista->sig;
    }
    lista = listaOrdenada;
}

void imprimirLista(Nodo *lista)
{
    Nodo *l;
    l=lista;
    while(l != NULL)
    {
        cout<<l->info.nombre<<" - "<<l->info.DNI<<endl;
        l = l->sig;
    }
}

void insertar(Nodo *&lista, Inscriptos ins)
{
    Nodo *n, *l, *ant;
    n = new Nodo;
    n->info = ins;
    l = lista;
    while(l != NULL && l->info.DNI < ins.DNI)
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

void insertarPorNombre(Nodo *&lista, Inscriptos ins)
{
    Nodo *n, *l, *ant;
    n = new Nodo;
    n->info = ins;
    l = lista;
    while(l != NULL && l->info.nombre < ins.nombre)
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