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

void sacarRepetidos(Nodo *&lista);
void insertar(Nodo *&lista, Productos ins);
void imprimirLista(Nodo *lista);

int main()
{
    Nodo *lista = NULL;
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
        insertar(lista, prod);
        cout<<"Cod: ";
        cin>>prod.cod;
    }
    sacarRepetidos(lista);
    imprimirLista(lista);
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

void sacarRepetidos(Nodo *&lista) //es como un corte de control (?
{
    Nodo *l = NULL;
    Productos prod;
    int suma;
    while(lista != NULL)
    {
        prod = lista->info;
        suma=0;
        do
        {
            suma+=lista->info.stock;
            lista = lista->sig;
        } while (lista != NULL && lista->info.cod == prod.cod);
        prod.stock = suma;
        insertar(l, prod);
    }
    lista = l;
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