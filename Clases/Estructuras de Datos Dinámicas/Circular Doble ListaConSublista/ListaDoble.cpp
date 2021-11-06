#include <iostream>
#include <stdio.h>

using namespace std;


struct Nodo
{
    int dato;
    Nodo*sig;
    Nodo*ant;
};


void insertar(Nodo*&lis1,Nodo*&lis2, int nro);
void mostrarAsc(Nodo*l);
void mostrarDesc(Nodo*l);
void ej8(Nodo*&l1,Nodo*&l2,int n);

int main()
{
    Nodo*listaD1=NULL,*listaD2=NULL;
    int nro;
    cin>>nro;
    while(nro!=0)
    {
        insertar(listaD1,listaD2,nro);
        cin>>nro;
    }
    cout<<"ascendente"<<endl;
    mostrarAsc(listaD1);
    cout<<"descendente"<<endl;
    mostrarDesc(listaD2);

    return 0;
}


void insertar(Nodo*&lis1,Nodo*&lis2, int nro)
{
    Nodo*p,*r;
    p=new Nodo;
    p->dato=nro;
    if(lis1==NULL && lis2==NULL) //p no va a tener ni sucesor ni antecesor (agrega a lista vacía)
    {
        p->sig=p->ant=NULL;
        lis1=lis2=p;
    }
    else
    {
        r=lis1;
        while(r!=NULL&&r->dato<nro)
            r=r->sig;

       if(r==lis1) //p va a tener sucesor y no antecesor
        {
            p->ant=NULL;
            p->sig=r;
            r->ant=p;
            lis1=p;
        }
        else
        {
            if(r==NULL) //p va a tener antecesor y no sucesor
            {
                p->ant=lis2;
                p->sig=r;
                lis2->sig=p;
                lis2=p;
            }
            else
            {   //p va a tener sucesor y antecesor
                p->ant=r->ant;
                p->sig=r;
                //Nodo*anterior=r->ant;
                //anterior->sig=p;
                r->ant->sig=p;
                r->ant=p;
            }
        }
    }
}

void mostrarAsc(Nodo*l)
{
    Nodo*p=l;
    while(p!=NULL)
    {
        cout<<p->dato<<endl;
        p=p->sig;
    }
}

void mostrarDesc(Nodo*l)
{
    Nodo*p=l;
    while(p!=NULL)
    {
        cout<<p->dato<<endl;
        p=p->ant;
    }
}












