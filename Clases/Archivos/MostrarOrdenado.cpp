#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Parcial
{
    int legajo;
    char nombre[36];
    int nota;
};

void ordenar(Parcial v[],unsigned t);
void mostrar(Parcial v[],int t);
int cargarVector(Parcial v[],FILE *a);

int main()
{
    Parcial vec[40]; //40 es la cantidad de alumnos, por lo tanto es la cantidad max de parciales
    FILE *arch=fopen("Parcial1.dat","rb");
    if(arch!=NULL)
    {
        int cant=cargarVector(vec,arch);
        ordenar(vec,cant);
        mostrar(vec,cant);
        fclose(arch);
    }

    return 0;
}

int cargarVector(Parcial v[],FILE *a)
{

    Parcial ex;
    int i=0;
    fread(&ex,sizeof(Parcial),1,a);
    while(!feof(a))
    {
        v[i]=ex;
        i++;
        fread(&ex,sizeof(Parcial),1,a);
    }
    return i;
}


void ordenar(Parcial v[],unsigned t)
{
    unsigned i=1,j;
    Parcial aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-i;j++)
        {
            if(v[j].legajo>v[j+1].legajo)
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

void mostrar(Parcial v[],int t)
{
    for(int i=0;i<t;i++)
        cout<<v[i].legajo<<v[i].nombre<<v[i].nota<<endl;
}
/*
void cargarVecConCantidad(Parcial v[],FILe *a)
{
    fread(v,sizeof(Parcial),5,a); //en el archivo hay 5 registros
}
*/
