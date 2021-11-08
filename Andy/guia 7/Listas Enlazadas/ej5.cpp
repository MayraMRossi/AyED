#include <iostream>
using namespace std;

struct Productos
{
    int cod, stock;
    string descripcion;
    float importe;
};

struct Nodo
{
    Productos info;
    Nodo *sig;
};

void imprimirLista(Nodo *lista);
void insertar(Nodo *&lista, Productos ins);
void fusionarListas(Nodo *lista1, Nodo *lista2, Nodo *&listaTotal);


int main()
{
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;
    Nodo *listaTotal = NULL;
    Productos prod;
    
    cout<<"Lista 1: "<<endl;
    cout<<"Cod: ";
    cin>>prod.cod;
    while(prod.cod != 0)
    {
        cout<<"Desc: ";
        cin>>prod.descripcion;
        cout<<"Stock: ";
        cin>>prod.stock;
        cout<<"Importe: ";
        cin>>prod.importe;
        insertar(lista1, prod);
        cout<<"Cod: ";
        cin>>prod.cod;
    }

    cout<<"Lista 2: "<<endl;
    cout<<"Cod: ";
    cin>>prod.cod;
    while(prod.cod != 0)
    {
        cout<<"Desc: ";
        cin>>prod.descripcion;
        cout<<"Stock: ";
        cin>>prod.stock;
        cout<<"Importe: ";
        cin>>prod.importe;
        insertar(lista2, prod);
        cout<<"Cod: ";
        cin>>prod.cod;
    }
    fusionarListas(lista1, lista2, listaTotal);
    cout<<endl<<"Lista total be like: "<<endl;
    imprimirLista(listaTotal);
}

void imprimirLista(Nodo *lista)
{
    Nodo *l;
    l=lista;
    while(l != NULL)
    {
        cout<<"Cod: "<<l->info.cod<<endl<<
        "Desc: "<<l->info.descripcion<<endl<<
        "Stock: "<<l->info.stock<<endl<<
        "Importe: "<<l->info.importe<<endl<<endl;
        l = l->sig;
    }
}

void insertar(Nodo *&lista, Productos ins)
{
    Nodo *n, *l, *ant;
    n = new Nodo;
    n->info = ins;
    l = lista;
    while(l != NULL && l->info.cod < ins.cod)
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

void fusionarListas(Nodo *lista1, Nodo *lista2, Nodo *&listaTotal)
{
    while(lista1 != NULL && lista2 != NULL)
    {
        if(lista1->info.cod < lista2->info.cod)
        {
            insertar(listaTotal, lista1->info);
            lista1 = lista1->sig;
        }
        else if(lista1->info.cod == lista2->info.cod)
        {
            insertar(listaTotal, lista1->info);
            lista1 = lista1->sig;
            lista2 = lista2->sig;
        }
        else
        {
            insertar(listaTotal, lista2->info);
        lista2 = lista2->sig;
        }
    }
    while(lista1 != NULL)
    {
        insertar(listaTotal, lista1->info);
        lista1 = lista1->sig;
    }
    while(lista2 != NULL)
    {
        insertar(listaTotal, lista2->info);
        lista2 = lista2->sig;
    }
}