#include <iostream>
#include <stdio.h>


//Apareo: Dadas dos listas (ordenadas por legajo) con alumnos que rindieron en dos fechas,
//informar el resultado de todos en un listado ordenado por legajo
//si se repiten informar con la mayor nota
//CC: Dada una lista con alumnos repetidos mostrar alumno y promedio
/*
Apareo
lista simple de alumnos, cada nodo tiene legajo, nombre y nota.
La nota de todos es cero
otra lista con los alumnos que rindieron
completar la nota de la primera lista
*/

using namespace std;

struct Alumno
{
    unsigned leg;
    string nom;
    unsigned nota;
};

struct Nodo
{
    Alumno info;
    Nodo*sig;
};


void apareo(Nodo*lista1, Nodo*lista2)
{
    Nodo *p1,*p2;
    p1=lista1;
    p2=lista2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->info.leg<p2->info.leg)
        {
            cout<<p1->info.leg<<p1->info.nom<<p1->info.nota<<endl;
            p1=p1->sig;
        }
        else
        {
            if(p1->info.leg==p2->info.leg)
            {
                cout<<p1->info.leg<<p1->info.nom;
                if(p1->info.nota>p2->info.nota)
                    cout<<p1->info.nota<<endl;
                else
                    cout<<p2->info.nota<<endl;
                p1=p1->sig;
                p2=p2->sig;
            }
            else
            {
                cout<<p2->info.leg<<p2->info.nom<<p2->info.nota<<endl;
                p2=p2->sig;
            }
        }
    }
    while(p1!=NULL)
    {
        cout<<p1->info.leg<<p1->info.nom<<p1->info.nota<<endl;
        p1=p1->sig;
    }
    while(p2!=NULL)
    {
        cout<<p2->info.leg<<p2->info.nom<<p2->info.nota<<endl;
        p2=p2->sig;
    }
}

void cc(Nodo*lista)
{
    Nodo *p=lista;
    int legA,suma,cont;
    string nomA;
    while(p!=NULL)
    {
        legA=p->info.leg;
        nomA=p->info.nom;
        suma=cont=0;
        do
        {
            suma+=p->info.nota;
            cont++;
            p=p->sig;
        }while(p!=NULL && p->info.leg==legA);
        cout<<legA<nomA<<<suma/cont<<endl;
    }


}
void cc(Nodo*lista) //versión con 2 punteros
{
    Nodo*p,*q;
    int suma,cont;
    p=q=lista;
    while(p!=NULL)
    {
        //q=p;
        suma=cont=0;
        do
        {
            suma+=q->info.nota;
            cont++;
            q=q->sig;
        }while(q!=NULL && p->info.leg==q->info.leg);
        cout<<p->info.leg<<p->info.nom<<suma/cont<<endl;
        p=q;
    }
}







