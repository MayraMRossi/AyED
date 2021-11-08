#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo*ant;
    Nodo*sig;
};

void insertar(Nodo*&l1, Nodo*&l2, int nro);
void eliminar(Nodo*lista, int cant);
void mostrarAsc(Nodo*l);

int main()
{
    Nodo*listaD1=NULL, *listaD2=NULL;
    int nro, cant;
    cout<<"Nro: ";
    cin>>nro;
    while(nro!=0)
    {
        insertar(listaD1, listaD2, nro);
        cout<<"Nro: ";
        cin>>nro;
    }
    cout<<"Cantidad de elementos a eliminar: ";
    cin>>cant;
    eliminar(listaD2, cant);
    mostrarAsc(listaD1);
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

void eliminar(Nodo*lista, int cant)
{
    Nodo*p;
    int cont=0;
    while(lista!=NULL && cont<cant)
    {
        p=lista;
        lista=lista->ant;
        delete p;
        lista->sig=NULL;
        cont++;
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