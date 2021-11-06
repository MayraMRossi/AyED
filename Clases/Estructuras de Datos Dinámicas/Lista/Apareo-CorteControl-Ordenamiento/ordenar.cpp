#include <iostream>
#include <stdio.h>

using namespace std;


struct Nodo
{
    int info;
    Nodo*sig;
};
void ordenar1(Nodo*&lista);
void insertar(Nodo*&lista,int dato);
void ordenar2(Nodo*&lista);
void insertarLog(Nodo*&lista,Nodo*n);
void agregarAdelante(Nodo*&lis,int nro);
void listar(Nodo*lista);

int main()
{
    Nodo*listaNros=NULL;
    int nro;
    cin>>nro;
    while(nro!=0)
    {
        agregarAdelante(listaNros,nro);
        cin>>nro;
    }
    cout<<"Desordenado"<<endl;
    listar(listaNros);
    ordenar2(listaNros);
    cout<<"Ordenado"<<endl;
    listar(listaNros);

    return 0;
}


void ordenar1(Nodo*&lista)
{
    Nodo*listaAux=NULL;
    Nodo*p;
    while(lista!=NULL)
    {
        insertar(listaAux,lista->info);
        p=lista;
        lista=lista->sig;
        delete p;
    }
    lista=listaAux;
}

void insertar(Nodo*&lista,int dato)
{
    Nodo *n,*r,*ant;
    n=new Nodo;
    n->info=dato;
    r=lista;
    while(r!=NULL && r->info<dato)
    {
        ant=r;
        r=r->sig;
    }
    n->sig=r;
    if(r!=lista)
        ant->sig=n;
    else
        lista=n;
}

void ordenar2(Nodo*&lista)
{
    Nodo*listaAux=NULL;
    Nodo*p;
    while(lista!=NULL)
    {
        p=lista;
        lista=lista->sig;
        insertarLog(listaAux,p);
    }
    lista=listaAux;
}

void insertarLog(Nodo*&lista,Nodo*n)
{
    Nodo *r,*ant;

    r=lista;
    while(r!=NULL && r->info<n->info)
    {
        ant=r;
        r=r->sig;
    }
    n->sig=r;
    if(r!=lista)
        ant->sig=n;
    else
        lista=n;
}

void agregarAdelante(Nodo*&lis,int nro)
{
    Nodo*p=new Nodo;
    p->info=nro;
    p->sig=lis;
    lis=p;
}

void listar(Nodo*lista)
{
    Nodo*r;
    r=lista;
    while(r!=NULL)
    {
        cout<<r->info<<endl;
        r=r->sig;
    }
}
