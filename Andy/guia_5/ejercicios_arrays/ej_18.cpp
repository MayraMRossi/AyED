//Idem al 17 pero los códigos de vendedor son números de 4 cifras (25 vendedores)
//REHACER 
#include <iostream>
using namespace std;

struct ventas
{
    int cod, cant;
    float importe;
};

int validarDatos(int d, int h);
int cargar(ventas v[], unsigned t);
void ordenar (ventas v[], unsigned t);
void importeTotal(ventas v[], unsigned t);
void mostrar(ventas v[], unsigned t);
int busquedaSecuencial(ventas v[], unsigned t, int bus);
void busqueda(ventas v[], int t);
int busquedaBinaria(ventas v[], unsigned t, int bus);

int main()
{
    ventas v1[25];
    int cant=cargar(v1, 25);
    ordenar(v1, cant);
    mostrar(v1, cant);
    importeTotal(v1, cant);
    busqueda(v1, cant);

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
    int i=0, cod, importe, numFac, cantV=0, pos;
    cout<<"Ingrese Nro de Factura, cero para finalizar: ";
    cin>>numFac;
    while(numFac!=0)
    {
        cout<<"Ingrese Codigo del vendedor: ";
        cod=validarDatos(1000,9999);
        cout<<"Ingrese Importe: ";
        cin>>importe;
        pos=busquedaSecuencial(v, cantV, cod);
        if(pos!=-1)
        {
            v[pos].cant++;
            v[pos].importe+=importe;
        }
        else
        {
            v[cantV].cant=1;
            v[cantV].cod=cod;
            v[cantV].importe=importe;
            cantV++;
        }

        cout<<"Ingrese Nro de Factura, cero para finalizar: ";
        cin>>numFac;
    }
    return cantV;
}

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

void mostrar(ventas v[], unsigned t)
{
    for(int i=0; i<t; i++)
        cout<<"  Codigo: "<<v[i].cod<<"  Importe: "<<v[i].importe<<endl;
    cout<<endl;
}

int busquedaSecuencial(ventas v[], unsigned t, int bus)
{
    unsigned i=0;
    while(i<t && v[i].cod!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}

int busquedaBinaria(ventas v[], unsigned t, int bus)
{
    int pos=-1, desde=0, hasta=t-1, medio;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(v[medio].cod==bus)
            pos=medio;
        else
        {
            if(bus<v[medio].cod)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}

void busqueda(ventas v[], int t)
{
    int bus;
    cout<<"Ingrese el nro de vendedor para saber la cant de ventas: ";
    cin>>bus;
    int pos=busquedaBinaria(v, t, bus);
    if(pos==-1)
        cout<<"El vendedor no existe o no realizo ninguna venta. "<<endl;
    else
        cout<<"Cant de ventas: "<<v[pos].cant<<endl;
}