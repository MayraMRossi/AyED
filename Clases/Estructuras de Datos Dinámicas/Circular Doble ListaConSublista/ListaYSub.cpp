#include <iostream>
#include <stdio.h>


using namespace std;
struct Examen
{
    unsigned fecha;
    unsigned codMat;
    unsigned nota;
};
struct NodoSub
{
    Examen info;
    NodoSub*sig;
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

void insertar(NodoSub*&,Examen);
Nodo* buscarInsertar(Nodo*&,Alumno);
void generar(Nodo*&);


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
    unsigned dniAl,codMateria,fechaEx,notaOb;
    string nomAl;
    cout<<"DNI alumno: ";
    cin>>dniAl;
    while(dniAl!=0)  //ingresa datos del examen
    {
        cout<<"Nombre alumno: ";
        cin>>nomAl;
        cout<<"Fecha examen: ";
        cin>>fechaEx;
        cout<<"Materia rendida: ";
        cin>>codMateria;
        cout<<"Nota: ";
        cin>>notaOb;

        al.dni=dniAl;
        al.nombre=nomAl;
        al.listaExam=NULL;
        Nodo*p=buscarInsertar(lista,al);
        ex.codMat=codMateria;
        ex.fecha=fechaEx;
        ex.nota=notaOb;
        insertar(p->info.listaExam,ex);

        cout<<"DNI alumno: ";
        cin>>dniAl;
    }
}

void insertar(NodoSub*&lista,Examen ex)  //ordenado por codigo de materia
{
    NodoSub*n,*p,*ant;
    n=new NodoSub;
    n->info=ex;
    p=lista;
    while(p!=NULL && p->info.fecha < ex.fecha)
    {
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    if(p!=lista)
        ant->sig=n;
    else
        lista=n;
}

Nodo* buscarInsertar(Nodo*&lista,Alumno al)
{
    Nodo*ant,*p=lista;
   while(p!=NULL && p->info.dni<al.dni)
   {
       ant=p;
       p=p->sig;
   }
   if(p!=NULL && al.dni==p->info.dni)
        return p;
   else
   {
       Nodo*n=new Nodo;
       n->info=al;
        n->sig=p;
        if(p!=lista)
            ant->sig=n;
        else
            lista=n;
        return n;
   }
}
































