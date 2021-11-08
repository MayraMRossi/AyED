// Lista doble: cada elemento tiene un antecesor y un sucesor

#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo*ant;
    Nodo*sig;
};

void insertar(Nodo*&l1, Nodo*&l2, int nro);
void mostrarAsc(Nodo*l);
void mostrarDesc(Nodo*l);

int main()
{
    Nodo*listaD1=NULL, *listaD2=NULL;
    int nro;
    cout<<"Nro: ";
    cin>>nro;
    while(nro!=0)
    {
        insertar(listaD1, listaD2, nro);
        cout<<"Nro: ";
        cin>>nro;
    }
    cout<<endl<<"Ascendente"<<endl;
    mostrarAsc(listaD1);
    cout<<endl<<"Descendente"<<endl;
    mostrarDesc(listaD2);
    
}

void insertar(Nodo*&l1, Nodo*&l2, int nro)
{
    Nodo*p= new Nodo, *r;
    p->info=nro;
    if(l1==NULL && l2==NULL) //si esta vacia
    {
        p->sig=p->ant=NULL;
        l1=l2=p;
    }
    else
    {
        r=l1;
        while(r!=NULL && r->info<nro)
            r=r->sig;
        if(r==l1) //p va a tener sucesor pero no antecesor (es el primero)
        {
            p->ant=NULL;
            p->sig=r;
            r->ant=p;
            l1=p;
        }
        else
        {
            if(r==NULL) // p va a tener antecesor y no sucesor (es el ultimo)
            {
                p->ant=l2;
                p->sig=r;
                l2->sig=p;
                l2=p;
            }
            else //p va a tener antecesor y sucesor (esta en el medio)
            {
                p->ant=r->ant;
                p->sig=r;
                r->ant->sig=p;
                r->ant=p;
            }
        }
    }
}

void mostrarAsc(Nodo*l)
{
    while(l!=NULL)
    {
        cout<<l->info<<endl;
        l=l->sig;
    }
}

void mostrarDesc(Nodo*l)
{
    while(l!=NULL)
    {
        cout<<l->info<<endl;
        l=l->ant;
    }
}