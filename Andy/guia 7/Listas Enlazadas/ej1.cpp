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

int main()
{

}

void mostrarPorIndice(Nodo *lista, int index)
{
    int i=0;
    Nodo *l;
    l = lista;
    while(l != NULL && i!=index)
    {
        if(i == index)
        {
            cout<<"Cod: "<<l->info.cod<<endl<<
            "Desc: "<<l->info.descripcion<<endl<<
            "Stock: "<<l->info.stock<<endl<<
            "Importe: "<<l->info.importe<<endl;
        }
        l = l->sig;
        i++;
    }
}

void incrementarPrecio(Nodo *lista, int index)
{
    int i=0;
    Nodo *l;
    l = lista;
    while(l != NULL && i!=index)
    {
        if(i == index)
        {
            l->info.importe = l->info.importe*0,1;
        }
        l = l->sig;
        i++;
    }
}

int buscarStock(Nodo *lista, int index)
{
    int i=0;
    Nodo *l;
    l = lista;
    while(l!=NULL && i!=index)
    {
        l = l->sig;
        i++;
    }
    if(l==NULL) //llego al final de la lista y no encontro el producto
        return 0;
    else
        return l->info.stock;
}