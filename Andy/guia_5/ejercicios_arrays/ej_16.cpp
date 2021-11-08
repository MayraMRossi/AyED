//Se tiene un vector de productos donde cada elemento tiene código de rubro, código de producto y descripción, ordenado por código de rubro.
//Se pide generar un vector ordenado por código de rubro que contenga el código de rubro y la cantidad de productos de ese rubro.

#include <iostream>
using namespace std;

void cargarParalelo(int r[], int p[], string d[], unsigned t);
void ordenar(int r[], int p[], string d[], unsigned t);
void contador(int r[], string d[], int cant[], unsigned t);
void contador(int r[], string d[], int cant[], unsigned t);
void mostrarParalelo(int r[], int c[], unsigned t);

int main()
{
    int codR[5], codP[5];
    string desc[5];

    cargarParalelo(codR, codP, desc, 5);
    ordenar(codR, codP, desc, 5);

    int cant[5];
    contador(codR, desc, cant, 5); //cuenta los que tienen la misma descripcion

    mostrarParalelo(codR, cant, 5);
}

void cargarParalelo(int r[], int p[], string d[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"Producto Nro "<<i+1<<": ";
        cout<<"Ingrese el Codigo de Rubro: ";
        cin>>r[i];
        cout<<"Ingrese el Codigo de Producto: ";
        cin>>p[i];
        cout<<"Ingrese la Descripcion: ";
        cin>>d[i];
        cout<<endl;
    }
}

void ordenar(int r[], int p[], string d[], unsigned t)
{
    int i, j, aux;
    string aux2;
    for(i=1; i<t; i++)
    {
        for(j=0; j<t-i; j++)
        {
            if(r[j]>r[j+1])
            {
                aux=r[j];
                r[j]=r[j+1];
                r[j+1]=aux;

                aux=p[j];
                p[j]=p[j+1];
                p[j+1]=aux;

                aux2=d[j];
                d[j]=d[j+1];
                d[j+1]=aux2;
            }
        }
    }
}

void contador(int r[], string d[], int cant[], unsigned t)
{
    int cont=0;
    string bus;
    for(int i=0; i<t; i++)
    {
        if(i==0 || d[i]!=bus)
        {
            bus=d[i];
            for(int i=0; i<t; i++)
            {
                if(d[i]==bus)
                    cont++;
            }
            cant[i]=cont;
            cont=0;
        }
    }
}

void mostrarParalelo(int r[], int c[], unsigned t)
{
    for(int i=0; i<t; i++)
        cout<<"Codigo de Rubro: "<<r[i]<<"   Cantidad de Productos: "<<c[i]<<endl;
}