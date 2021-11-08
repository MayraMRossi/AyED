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

void imprimirLista(Nodo *lista);
void imprimirInversa(Nodo *lista);
void apilar(Nodo *&pila, Inscriptos s);
Inscriptos desapilar(Nodo *&pila);
void insertar(Nodo *&lista, Inscriptos ins);
void quitar(Nodo *&lista, int DNI);

int main ()
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
    cout<<endl<<"Lista: "<<endl;
    imprimirLista(lista);
    cout<<endl<<"Lista inversa: "<<endl;
    imprimirInversa(lista);
    cout<<"DNI nuevo: ";
    cin>>ins.DNI;
    cout<<"Nombre nuevo: ";
    cin>>ins.nombre;
    insertar(lista, ins);
    cout<<"DNI a eliminar de la lista: ";
    cin>>ins.DNI;
    quitar(lista, ins.DNI);
    cout<<endl;
    imprimirLista(lista);
    
    return 0;
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

void imprimirInversa(Nodo *lista)
{
    Nodo *l;
    Nodo *pilaAux = NULL;
    Inscriptos ins;
    l=lista;
    while(l != NULL)
    {
        apilar(pilaAux, l->info);
        l = l->sig;
    }
    while(pilaAux != NULL)
    {
        ins = desapilar(pilaAux);
        cout<<ins.nombre<<" - "<<ins.DNI<<endl;
    }
}

void apilar(Nodo *&pila, Inscriptos s)
{
    Nodo *p = new Nodo;
    p->info = s;
    p->sig = pila;
    pila = p;
}

Inscriptos desapilar(Nodo *&pila)
{
    Inscriptos s;
    Nodo *p;
    p = pila;
    s = p->info;
    pila = p->sig;
    delete p;
    return s;
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

void quitar(Nodo *&lista, int DNI)
{
    Nodo *l, *ant;
    l = lista;
    while(l != NULL && l->info.DNI < DNI)
    {
        ant = l;
        l = l->sig;
    }
    if(l == NULL || l->info.DNI!=DNI)
        cout<<"No esta en la lista."<<endl;
    else
    {
        if(l == lista)
            lista = l->sig;
        else
            ant->sig = l->sig;
        delete l;
    }
}