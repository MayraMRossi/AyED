// Lista circular

#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo*sig;
};

int main()
{

}

void mostrar(Nodo*listaC)
{
    if(listaC!=NULL)
    {
        Nodo*p=listaC->sig;
        do
        {
            cout<<p->info<<endl;
            p=p->sig;
        } while (p!=listaC->sig);
    }
}

void agregar(Nodo*&listaC, int nro) //agrega a una lista sin orden
{
    Nodo*n=new Nodo;
    n->info=nro;
    if(listaC!=NULL)
    {
        n->sig=listaC->sig;
        listaC->sig=n;
    }
    else
    {
        n->sig=n;
        listaC=n;
    }
}

void insertar(Nodo*&listaC, int nro) //agregar a una lista ordenada
{
    Nodo*n=new Nodo;
    n->info=nro;
    if(listaC==NULL)
    {
        n->sig=n;
        listaC=n;
    }
    else
    {
        Nodo*p=listaC->sig, *ant=listaC;
        if(p->info<nro)
        {
            do
            {
                ant=p;
                p=p->sig;
            } while (p!=listaC->sig && p->info<nro);
        }
        n->sig=p;
        ant->sig=n;
        if(n->info>listaC->info)
            listaC=n;
    }
}