#include <iostream>
using namespace std;

struct Nodo
{
    int nro;
    Nodo *sig;
};

void apilar(Nodo *&pila, int a);
int desapilar(Nodo *&pila);
int cargarPila(Nodo *&pila);
void mostrarPila(Nodo *&pila);

int main()
{
    Nodo *pila = NULL;
    int a;
    int tamPila = cargarPila(pila);
    for(int i=0; i<tamPila-2; i++)
        desapilar(pila);
    cout<<endl<<"Nro: ";
    cin>>a;
    apilar(pila, a);
    mostrarPila(pila);
}

void apilar(Nodo *&pila, int a)
{
    Nodo *p = new Nodo;
    p->nro = a;
    p->sig = pila;
    pila = p;
}

int desapilar(Nodo *&pila)
{
    int a;
    Nodo *p;
    p = pila;
    a = p->nro;
    pila = p->sig;
    delete p;
    return a;
}

int cargarPila(Nodo *&pila)
{
    int a, i=0;
    cout<<"Nro: ";
    cin>>a;
    while(a != 0)
    {
        apilar(pila, a);
        cout<<"Nro: ";
        cin>>a;
        i++;
    }
    return i;
}

void mostrarPila(Nodo *&pila)
{
    int a;
    while(pila != NULL)
    {
        a = desapilar(pila);
        cout<<a<<endl;
    }
}