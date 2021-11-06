#include <iostream>
#include <stdio.h>

#define MAXV 500

using namespace std;
/*
1)	Una empresa de aviación realiza 500 vuelos semanales a distintos
puntos del país y requiere desarrollar un programa para la venta de pasajes.
Para ello se ingresan los datos de los 500 vuelos que realizan, sin ningún orden, por cada vuelo se ingresa:
	código de vuelo
	cantidad de pasajes disponibles
A continuación se ingresan los datos de los potenciales compradores,
el ingreso finaliza con código de vuelo cero, por cada uno se ingresa:
	código de vuelo
	cantidad de pasajes solicitados
	DNI del solicitante
	apellido y nombre del solicitante

Se pide:
a) Para los solicitantes a los cuales se les venden pasajes, emitir el siguiente listado:
DNI  Apellido y Nombre   Cantidad de pasajes        Código de Vuelo
b) Al final del proceso emitir el siguiente listado ordenado por código de vuelo
Código de Vuelo      Pasajes disponibles               Pasajes no vendidos
Nota: Se le vende al solicitante si la cantidad de pasajes que solicita está disponible,
en caso contrario se computa como pasajes no vendidos.
*/

struct Vuelo
{
    unsigned nroVuelo;
    unsigned pasajDisp;
    unsigned noVendidos;
};
struct Solicitud
{
    unsigned codVuelo;
    unsigned cantSolic;
    unsigned dni;
    string nombre;
};

void mostrar(Solicitud s);
void ingresarVuelos(Vuelo v[],unsigned ce);
void procesarSolic(Vuelo v[],unsigned ce,FILE*);
void listado(Vuelo v[], unsigned ce);
void ordenar(Vuelo v[],unsigned t);
int buscar(Vuelo v[],unsigned t,unsigned bus);

void titulo(FILE*a);
void guardarArchTExto(FILE*listado,Solicitud solic);

int main()
{
    Vuelo vuelos[MAXV];
    ingresarVuelos(vuelos,MAXV);
    ordenar(vuelos,MAXV);

    FILE *lisVendidos=fopen("ListadoVendidos.txt","w"); //para hacer el listado en archivo de texto
    if(lisVendidos!=NULL)
    {
        titulo(lisVendidos);
        cout<<endl<<"Ingreso de solicitudes"<<endl;
        procesarSolic(vuelos,MAXV,lisVendidos);
        listado(vuelos,MAXV);
        fclose(lisVendidos);
    }
    return 0;
}

void ingresarVuelos(Vuelo v[],unsigned ce)
{
    for(unsigned i=0;i<ce;i++)
    {
        cout<<"Vuelo "<<i+1<<endl;
        cout<<"Nro Vuelo ";
        cin>>v[i].nroVuelo;
        cout<<"Pasajes disponibles ";
        cin>>v[i].pasajDisp;
        v[i].noVendidos=0;
    }
}

void procesarSolic(Vuelo v[],unsigned ce,FILE*listado)
{
    Solicitud solic;
    int pos;
    cout<<"nro vuelo ";
    cin>>solic.codVuelo;
    while(solic.codVuelo!=0)
    {
        cout<<"cant Pasajes ";
        cin>>solic.cantSolic;
        cout<<"dni ";
        cin>>solic.dni;
        cout<<"nombre ";
        cin>>solic.nombre;
        pos=buscar(v,ce,solic.codVuelo);
        if(pos==-1)
            cout<<"vuelo inexistente"<<endl;
        else
        {
            if(v[pos].pasajDisp>=solic.cantSolic)
            {
                //mostrar(solic);
                guardarArchTExto(listado,solic);
                v[pos].pasajDisp-=solic.cantSolic;
            }
            else
                v[pos].noVendidos+=solic.cantSolic;
        }
        cout<<endl<<"nro vuelo ";
        cin>>solic.codVuelo;
    }
}

void mostrar(Solicitud s)
{
    cout<<endl<<"DNI "<<s.dni<<" Nombre "<<s.nombre<< "Cantidad de pasajes "<<s.cantSolic<<" Vuelo "<<s.codVuelo<<endl;
}

void listado(Vuelo v[], unsigned ce)
{
    for(unsigned i=0;i<ce;i++)
        cout<<v[i].nroVuelo<<" - "<<v[i].pasajDisp<<" - "<<v[i].noVendidos<<endl;
}

void ordenar(Vuelo v[],unsigned t)
{
    unsigned i=0,j;
    Vuelo aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-1-i;j++)
        {
            if(v[j].nroVuelo>v[j+1].nroVuelo)
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

int buscar(Vuelo v[],unsigned t,unsigned bus)
{
    int pos=-1,desde=0,hasta=t-1,medio;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(v[medio].nroVuelo==bus)
            pos=medio;
        else
        {
            if(bus<v[medio].nroVuelo)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}

void titulo(FILE*a)
{
    fprintf(a,"  DNI     Nombre    Canti Solicitada  Número de vuelo\n");
}
void guardarArchTExto(FILE*listado,Solicitud solic)
{
    fprintf(listado,"%6d\t%s\t%4d\t\t\t%d\n",solic.dni,solic.nombre.c_str(),solic.cantSolic,solic.codVuelo);
}
