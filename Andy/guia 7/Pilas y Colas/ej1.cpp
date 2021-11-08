#include <iostream>
using namespace std;

struct Stock
{
    int cant;
    int cod;
};

struct Nodo
{
    Stock info;
    Nodo *sig;
};

void apilar(Nodo *&pila, Stock s);
Stock desapilar(Nodo *&pila);
void cargarPila(Nodo *&pila, Stock s);
void remplazar(Nodo *&pila, Stock stock);
void mostrarPila(Nodo *&pila);

int main()
{
    Stock stock;
    Nodo *pilaStock = NULL;

    cargarPila(pilaStock, stock);
    remplazar(pilaStock, stock);
    mostrarPila(pilaStock);

    return 0;
}

void apilar(Nodo *&pila, Stock s)
{
    Nodo *p = new Nodo;
    p->info = s;
    p->sig = pila;
    pila = p;
}

Stock desapilar(Nodo *&pila)
{
    Stock s;
    Nodo *p;
    p = pila;
    s = p->info;
    pila = p->sig;
    delete p;
    return s;
}

void cargarPila(Nodo *&pila, Stock stock)
{
    cout<<"Cod: ";
    cin>>stock.cod;
    while(stock.cod!=0)
    {
        cout<<"Cant: ";
        cin>>stock.cant;
        apilar(pila, stock);
        cout<<"Cod: ";
        cin>>stock.cod;
    }
}

void remplazar(Nodo *&pila, Stock stock)
{
    for(int i = 0; i<2; i++)
        desapilar(pila);
    
    cout<<"Cod: ";
    cin>>stock.cod;
    cout<<"Cant: ";
    cin>>stock.cant;
    apilar(pila, stock);
}

void mostrarPila(Nodo *&pila)
{
    Stock stock;
    while(pila != NULL)
    {
        stock = desapilar(pila);
        cout<<stock.cod<<" - "<<stock.cant<<endl;
    }
}