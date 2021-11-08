//En un comercio se ingresan los datos de las ventas realizadas en el día. Por cada una se ingresa número de factura, 
//código de vendedor que realizó la venta (de 1 a 25) e importe de la misma. El lote de datos finaliza con número de factura cero. 
//Se pide desarrollar un algoritmo que:
//- Imprima un listado ordenado por código de vendedor, detallando el importe total de ventas de cada uno de ellos
//- Dado un código de vendedor, imprima la cantidad de ventas realizadas por el mismo.

#include <iostream> //REHACER
using namespace std;

struct ventas
{
    int cantVentas;
    float importe;
};

int validarDatos(int d, int h);
int cargar(ventas v[], unsigned t);
//void ordenar (ventas v[], unsigned t);
void importeTotal(ventas v[], unsigned t);
//void corteControl(ventas v[], unsigned t);
void mostrar(ventas v[], unsigned t);
void inicializar(ventas v[], unsigned t);
void busqueda(ventas v[], unsigned t);

int main()
{
    ventas v1[25];
    inicializar(v1, 25);
    cargar(v1, 25);
    cout<<endl;
    importeTotal(v1, 25);
    cout<<endl;
    busqueda(v1, 25);

    return 0;
}

int validarDatos(int d, int h)
{
    int n;
    do
    {
        cin>>n;
    } while (n<d || n>h);
    return n;
}

int cargar(ventas v[], unsigned t)
{
    int i=0, cod, numFac;
    float importe;
    cout<<"Ingrese Nro de Factura, cero para finalizar: ";
    cin>>numFac;
    while(numFac!=0)
    {
        cout<<"Ingrese Codigo del vendedor: ";
        cod=validarDatos(1,25);
        cout<<"Ingrese Importe: ";
        cin>>importe;
        v[cod-1].importe+=importe;
        v[cod-1].cantVentas++;

        cout<<"Ingrese Nro de Factura, cero para finalizar: ";
        cin>>numFac;
    }
    return i;
}
/*
void ordenar (ventas v[], unsigned t)
{
    int i=1, j;
    ventas aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0; j<t-i; j++)
        {
            if(v[j].cod>v[j+1].cod)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    } while(i<t && cambio);
}
*/
/*
void importeTotal(ventas v[], unsigned t)
{
    int i=0, cont, j, suma;
    while(i<t)
    {
        cont=0;
        suma=0;
        j=i;
        do
        {
            suma+=v[j].importe;
            
            cont++;
            j++;
        } while (j<t && v[j].cod==v[i].cod);
        cout<<"Vendedor Nro: "<<v[i].cod<<"  Importe Total: "<<suma<<endl;
        i=j;
    }
}
*/
void importeTotal(ventas v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"Vendedor Nro: "<<i+1<<"  Importe Total: "<<v[i].importe<<endl;
    }
}
/*
void corteControl(ventas v[], unsigned t)
{
    int i=0, cont, j;
    while(i<t)
    {
        cont=0;
        j=i;
        do
        {
            cont++;
            j++;
        } while (j<t && v[j].cod==v[i].cod);
        cout<<v[i].cod<<" vendio "<<cont<<" productos"<<endl;
        i=j;
    }
}
*/

void busqueda(ventas v[], unsigned t)
{
    int bus;
    cout<<"Ingrese el codigo para saber la cant de ventas: ";
    cin>>bus;
    cout<<"La cantidad es: "<<v[bus-1].cantVentas<<endl;
}

void inicializar(ventas v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        v[i].cantVentas=0;
        v[i].importe=0;
    }
}