#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo*sig;
};

int size(Nodo*lista);
void agregar(Nodo*&lista, int nro);

int main()
{
    int nro, cant;
    Nodo*lista = NULL;
    cout<<"Nro: ";
    cin>>nro;
    while(nro!=0)
    {
        agregar(lista, nro);
        cout<<"Nro: ";
        cin>>nro;
    }
    cant = size(lista);
    cout<<"Cantidad de elementos: "<<cant<<endl;
}

void agregar(Nodo*&lista, int nro) 
{
    Nodo*n = new Nodo;
    n->info = nro;
    if(lista!=NULL)
    {
        n->sig = lista->sig;
        lista->sig = n;
    }
    else
    {
        n->sig = n;
        lista = n;
    }
}

int size(Nodo*lista)
{
    int cont=0;
    if(lista!=NULL)
    {
        Nodo*p = lista->sig;
        do
        {
            cont++;
            p = p->sig;
        } while(p != lista->sig);
    }
    return cont;
}