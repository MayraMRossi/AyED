// Estructuras dinamicas: pilas, colas, listas (enlazadas, dobles, circulares), arboles binarios

// Pila = estructura de tipo LIFO 
#include <iostream>
#include <string.h>
using namespace std;

struct Libro
{
    string titulo;
    string materia;
};

struct Nodo
{
    Libro info;
    Nodo *sig;
};

void apilar(Nodo *&pila, Libro lib);
Libro desapilar(Nodo*&pila);

int main()
{
    Nodo *pilaLibros = NULL; //el 1er elemento de la pila tiene NULL
    Libro libro;
    
    cout<<"Titulo: "; 
    cin>>libro.titulo;
    while(libro.titulo != "fin")
    {
        cout<<"Materia: ";
        cin>>libro.materia;
        apilar(pilaLibros, libro);

        cout<<"Titulo: "; 
        cin>>libro.titulo;
    }
    while(pilaLibros != NULL)
    {
        libro = desapilar(pilaLibros);
        cout<<libro.titulo<<" - "<<libro.materia<<endl;
    }
}

void apilar(Nodo *&pila, Libro lib) // paso "pila" por referencia para que se guarden los cambios
{
    Nodo *p = new Nodo;
    p->info = lib;
    p->sig = pila;
    pila = p;
}

Libro desapilar(Nodo*&pila)
{
    Libro lib;
    Nodo *p; //auxiliary pointer
    p = pila;
    lib = p->info;
    pila = p->sig;
    delete p;
    return lib;
}