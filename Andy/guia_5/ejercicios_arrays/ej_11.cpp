//Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los productos, se pide:
//a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
//b) Dado un código de producto informar su precio.
//Usar structs en vez de vectores paralelos

#include <iostream>
using namespace std;

struct Productos
{
    unsigned cod;
    float precio;
};

void mayorAmenor(Productos v[], int cant);
void informarPrecio(Productos v[], int cant);
void cargar(Productos v[], int cant);

int main()
{
    Productos prod[5];
    cargar(prod, 5);
    mayorAmenor(prod, 5);
    for(int i=0; i<5; i++)
        cout<<"Codigo: "<<prod[i].cod<<"  Precio: "<<prod[i].precio<<endl;
    informarPrecio(prod, 5);

    return 0;
}

void cargar(Productos v[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        cout<<"Ingrese el codigo: ";
        cin>>v[i].cod;
        cout<<"Ingrese el precio: ";
        cin>>v[i].precio;
        cout<<endl;
    }
}

void mayorAmenor(Productos v[], int cant)
{
    int i, j;
    Productos aux;
    for(i=1; i<cant; i++)
    {
        for(j=0; j<cant-1; j++)
        {
            if(v[j].precio < v[j+1].precio)
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }   
        
    }
}

void informarPrecio(Productos v[], int cant)
{
    int c;
    bool pri=true;
    cout<<"Ingrese el codigo de producto que desea buscar: ";
    cin>>c;

    for(int i=0; i<cant; i++)
    {
        if(v[i].cod==c)
        {    
            cout<<"El precio es: "<<v[i].precio<<endl;
            pri=false;
        }
    }
    if(pri)
        cout<<"No se encontro el producto."<<endl;
}