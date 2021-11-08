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
void crearListas(Nodo *lista, Nodo *&listaMayor, Nodo *&listaMenor);

int main()
{
    Nodo *listaProductos = NULL;
    Nodo *listaGrande = NULL;
    Nodo *listaChica= NULL;
    Productos prod;
    
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
        insertar(listaProductos, prod);
        cout<<"Cod: ";
        cin>>prod.cod;
    }
    crearListas(listaProductos, listaGrande, listaChica);
    cout<<endl<<"Lista con stock menor a 50: "<<endl;
    imprimirLista(listaChica);
    cout<<endl<<"Lista con stock mayor a 50: "<<endl;
    imprimirLista(listaGrande);

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

void crearListas(Nodo *lista, Nodo *&listaMayor, Nodo *&listaMenor)
{
    while(lista != NULL)
    {
        if(lista->info.stock<50)
            insertar(listaMenor, lista->info);
        else
            insertar(listaMayor, lista->info);

        lista = lista->sig;
    }
}