#include <iostream>

using namespace std;

struct Libro
{
    string titulo;
    string materia;
};

struct NodoPila
{
    Libro info;
    NodoPila*sig;
};

void apilar(NodoPila*&pila,Libro lib);
Libro desapilar(NodoPila*&pila);

int main()
{
    NodoPila *pilaLibros=NULL;
    Libro libro;
    cin>>libro.titulo;
    while(libro.titulo!="fin")
    {
        cin>>libro.materia;
        apilar(pilaLibros,libro);
        cin>>libro.titulo;
    }
    while(pilaLibros!=NULL)
    {
        libro=desapilar(pilaLibros);
        cout<<libro.titulo<<" - "<<libro.materia<<endl;
    }
}

void apilar(NodoPila*&pila,Libro lib)
{
    NodoPila*p=new NodoPila;
    p->info=lib;
    p->sig=pila;
    pila=p;
}

Libro desapilar(NodoPila*&pila)
{
    Libro lib;
    NodoPila*p;
    //lib=pila->info;
    p=pila;
    lib=p->info;
    pila=p->sig;
    delete p;
    return lib;
}
