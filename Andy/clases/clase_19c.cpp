// lista dentro de una lista

#include <iostream>
using namespace std;

struct Examen
{
    unsigned fecha, codM, nota;
};

struct NodoSub
{
    Examen info;
    NodoSub *sig;
};

struct Alumno
{
    unsigned dni;
    string nombre;
    NodoSub*listaExam;
};

struct Nodo
{
    Alumno info;
    Nodo*sig;
};

int main()
{
    Nodo*listaAlumnos=NULL;
    generar(listaAlumnos);

    return 0;
}

void generar(Nodo*&lista)
{
    Alumno al;
    Examen ex;
    Nodo*p;
    unsigned dni, codM, fechaEx, nota;
    string nom;
    cout<<"DNI: ";
    cin>>dni;
    while(dni!=0)
    {
        cout<<"Nombre: ";
        cin>>nom;
        cout<<"Fecha examen: ";
        cin>>fechaEx;
        cout<<"Materia rendida: ";
        cin>>codM;
        cout<<"Nota: ";
        cin>>nota;

        al.dni=dni;
        al.nombre=nom;
        al.listaExam=NULL;
        Nodo*p=buscarInsertar(lista, al);
        ex.codM=codM;
        ex.fecha=fechaEx;
        ex.nota=nota;
        insertar(p->info.listaExam, ex);

        cout<<"DNI: ";
        cin>>dni;
    }
}

Nodo *buscarInsertar(Nodo* &lista, Alumno a) //Si el nuevo alumno está, lo modifica. De lo contrario, lo agrega
{
    Nodo *l, *ant;
    l = lista;
    while(l != NULL && l->info.dni < a.dni)
    {
        ant = l;
        l = l->sig;
    }
    if(l == NULL || l->info.dni!=a.dni) //si no está
    {
        Nodo *n = new Nodo;
        n->info = a;
        n->sig = l;
        if(l != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
    else
        return l;
}

void insertar(NodoSub* &lista, Examen ex) //inserta de manera ordenada
{
    NodoSub *n, *l, *ant;
    n = new NodoSub;
    n->info = ex;
    l = lista;
    while(l != NULL && l->info.fecha < ex.fecha)
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