#include <iostream>


using namespace std;

//En un comercio se ingresan los datos de las ventas realizadas en el día.
//Por cada una se ingresa número de factura,
//código de vendedor que realizó la venta (número de 4 dígitos) e importe de la misma.
//Hay como máximo 25 vendedores
//El lote de datos finaliza con número de factura cero.
//Se pide desarrollar un algoritmo que:
//- Imprima un listado ordenado por código de vendedor,
//detallando el importe total de ventas de cada uno de ellos
//- Dado un código de vendedor, imprima la cantidad de ventas realizadas por el mismo.

struct Vendedor
{
    int nroVend;
    int cantVtas;
    float impTotal;
};

int buscSecuencial(Vendedor v[],unsigned t,int bus);
int busqBinaria(Vendedor v[],unsigned t,int bus);
void ordenar(Vendedor v[],unsigned t);
int ingresarVtas(Vendedor v[],int cme);
void listadoOrdenado(Vendedor v[],int ce);
void mostrarCantVtas(Vendedor v[],int ce);

int main()
{
    Vendedor vec[25];
    int cantVendedores=ingresarVtas(vec,25);
    ordenar(vec,cantVendedores);
    listadoOrdenado(vec,cantVendedores);
    mostrarCantVtas(vec,cantVendedores);

    return 0;
}

int ingresarVtas(Vendedor v[],int cme)
{
    int nroFac, nroV, pos,cantV=0;
    float imp;
    cout<<"Factura ";
    cin>>nroFac;
    while(nroFac!=0)
    {
        cout<<"Vendedor ";
        cin>>nroV;
        cout<<"Importe ";
        cin>>imp;

        //procesar venta
        pos=buscSecuencial(v,cantV,nroV);
        if(pos!=-1)
        {
            v[pos].cantVtas++;
            v[pos].impTotal+=imp;
        }
        else
        {
            if(cantV < cme)
            {
                v[cantV].nroVend=nroV;
                v[cantV].cantVtas=1;
                v[cantV].impTotal=imp;
                cantV++;
            }

        }

        cout<<"Factura ";
        cin>>nroFac;
    }
    return cantV;
}

void listadoOrdenado(Vendedor v[],int ce)
{
    for(int i=0;i<ce;i++)
        cout<<v[i].nroVend<<"  "<<v[i].impTotal<<endl;
}


int buscSecuencial(Vendedor v[],unsigned t,int bus)
{
    unsigned i=0;
    while(i<t && v[i].nroVend!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}


void ordenar(Vendedor v[],unsigned t)
{
    unsigned i=0,j;
    Vendedor aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-1-i;j++)
        {
            if(v[j].nroVend > v[j+1].nroVend)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;

                cambio=true;
            }
        }
        i++;
    }while(i<t && cambio);
}

int busqBinaria(Vendedor v[],unsigned t,int bus)
{
    int pos=-1,desde=0,hasta=t-1,medio;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(v[medio].nroVend==bus)
            pos=medio;
        else
        {
            if(bus<v[medio].nroVend)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}

void mostrarCantVtas(Vendedor vec[],int ce)
{
    int v;
    cout<<"Ingrese el numero de vendedor del que quiere saber la cantidad de ventas ";
    cin>>v;
    int pos=busqBinaria(vec,ce,v);
    if(pos==-1)
        cout<<"el vendedor no existe o no realizo venta"<<endl;
    else
        cout<<vec[pos].cantVtas<<endl;
}


