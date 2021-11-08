#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sig;
};

void apilar(Nodo *&pila, int nro);
int desapilar(Nodo *&pila);

int main()
{
    Nodo *pila1 = NULL;
    Nodo *pila2 = NULL;
    int nro, x, y;

    
    cout<<"Numero: ";
    cin>>nro;
    while(nro!=0)
    {
        apilar(pila1, nro);
        cout<<"Numero: ";
        cin>>nro;
    }

    cout<<"Ingrese x: ";
    cin>>x;
    cout<<"Ingrese y: ";
    cin>>y;

    cout<<endl;
    
    while(pila1 != NULL)
    {
        nro = desapilar(pila1);
        if(nro==y)
            nro = x;
        apilar(pila2, nro);
    }

    cout<<endl;

    while(pila2 != NULL)
    {
        nro = desapilar(pila2);
        apilar(pila1, nro);
        cout<<nro<<endl;
    }
}

void apilar(Nodo *&pila, int nro)
{
    Nodo *p = new Nodo;
    p->info = nro;
    p->sig = pila;
    pila = p;
}

int desapilar(Nodo *&pila)
{
    int nro;
    Nodo *p;
    p = pila;
    nro = pila->info;
    pila = p->sig;
    delete p;
    return nro;
}