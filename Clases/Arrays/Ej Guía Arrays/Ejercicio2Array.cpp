#include <iostream>

#define PROD 100
#define TALLE 5

using namespace std;

struct ArtPrecio
{
    unsigned codArt;
    unsigned talle;
	float precio;
};
struct ArtPedido
{
    unsigned codArt;
    unsigned talle;
	unsigned cantidad;
};

void ingresarPrecios(float m[][TALLE]);
void procesarVtas(float mp[][TALLE],unsigned mcv[][TALLE]);
void listado(unsigned m[][TALLE]);
void inicializar(unsigned m[][TALLE]);

int main()
{
    float precios[PROD][TALLE];
    unsigned cantVendida[PROD][TALLE];
    inicializar(cantVendida);
    ingresarPrecios(precios);
    procesarVtas(precios,cantVendida);
    listado(cantVendida);

    return 0;
}

void ingresarPrecios(float m[][TALLE])
{
    ArtPrecio a;
    for(int i=1;i<=PROD*TALLE;i++)
    {
        cout<<"Codigo ";
        cin>>a.codArt;
        cout<<"Talle ";
        cin>>a.talle;
        cout<<"Precio ";
        cin>>a.precio;
        m[a.codArt-1][a.talle-1]=a.precio;
    }
}

void procesarVtas(float mp[][TALLE],unsigned mcv[][TALLE])
{
    ArtPedido a;
    float precioVta;
    cout<<"Codigo ";
    cin>>a.codArt;
    while(a.codArt>0)
    {
        cout<<"Talle ";
        cin>>a.talle;
        cout<<"Cantidad ";
        cin>>a.cantidad;
        precioVta=a.cantidad*mp[a.codArt-1][a.talle-1];
        if(a.cantidad>3)
            precioVta-=precioVta*0.10;
        precioVta+=precioVta*0.21;
        cout<<precioVta<<endl;
        mcv[a.codArt-1][a.talle-1]+=a.cantidad;
        cout<<"Codigo ";
        cin>>a.codArt;
    }
}

void listado(unsigned m[][TALLE])
{
    unsigned totProd,total=0;
    for(int i=0;i<PROD;i++)
    {
        totProd=0;
        cout<<"Producto "<<i+1<<endl;
        for(int j=0;j<TALLE;j++)
        {
            cout<<"Talle "<<j+1<<" Cantidad "<<m[i][j]<<endl;
            totProd+=m[i][j];
            //total+=m[i][j];
        }
        cout<<"Total por Prod "<<totProd<<endl;
        total+=totProd;
     }
     cout<<"Total General "<<total<<endl;
}

void inicializar(unsigned m[][TALLE])
{
    for(int i=0;i<PROD;i++)
        for(int j=0;j<TALLE;j++)
            m[i][j]=0;
}
