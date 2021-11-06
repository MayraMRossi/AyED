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

int buscSecuencial(int v[],unsigned t,int bus);
int busqBinaria(int v[],unsigned t,int bus);
void ordenar(int v[],float vi[],int vc[],unsigned t);
int ingresarVtas(int vn[],int vc[],float vi[],int cme);
void listadoOrdenado(int vn[],float vi[],int ce);
void mostrarCantVtas(int vn[],int vc[],int ce);

int main()
{
    int vendedores[25],cantVtas[25];
    float importes[25];
    int cantVendedores=ingresarVtas(vendedores,cantVtas,importes,25);
    ordenar(vendedores,importes,cantVtas,cantVendedores);
    listadoOrdenado(vendedores,importes,cantVendedores);
    mostrarCantVtas(vendedores,cantVtas,cantVendedores);

    return 0;
}

int ingresarVtas(int vn[],int vc[],float vi[],int cme)
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
        //procesar la venta
        pos=buscSecuencial(vn,cantV,nroV);
        if(pos!=-1)
        {
            vc[pos]++;
            vi[pos]+=imp;
        }
        else
        {
            if(cantV<cme)
            {
                vn[cantV]=nroV;
                vc[cantV]=1;
                vi[cantV]=imp;
                cantV++;
            }

        }
        cout<<"Factura ";
        cin>>nroFac;
    }
    return cantV;
}

void listadoOrdenado(int vn[],float vi[],int ce)
{
    for(int i=0;i<ce;i++)
        cout<<vn[i]<<"  "<<vi[i]<<endl;
}

void mostrarCantVtas(int vn[],int vc[],int ce)
{
    int v;
    cout<<"Ingrese el numero de vendedor del que quiere saber la cantidad de ventas ";
    cin>>v;
    int pos=busqBinaria(vn,ce,v);
    if(pos==-1)
        cout<<"el vendedor no existe o no realizo ventas"<<endl;
    else
        cout<<vc[pos]<<endl;
}

int buscSecuencial(int v[],unsigned t,int bus)
{
    unsigned i=0;
    while(i<t && v[i]!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}


void ordenar(int v[],float vi[],int vc[],unsigned t)
{
    unsigned i=0,j;
    int aux;
    float auxi;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-1-i;j++)
        {
            if(v[j]>v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;

                auxi=vi[j];
                vi[j]=vi[j+1];
                vi[j+1]=auxi;

                aux=vc[j];
                vc[j]=vc[j+1];
                vc[j+1]=aux;

                cambio=true;
            }
        }
        i++;
    }while(i<t && cambio);
}

int busqBinaria(int v[],unsigned t,int bus)
{
    int pos=-1,desde=0,hasta=t-1,medio;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(v[medio]==bus)
            pos=medio;
        else
        {
            if(bus<v[medio])
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}
