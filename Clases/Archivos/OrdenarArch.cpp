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
void grabarArch(Parcial v[],int c);
int cargarVector(Parcial v[],FILE *a);

int main()
{
    Parcial vec[40]; //40 es la cantidad de alumnos, por lo tanto es la cantidad max de parciales
    FILE *arch=fopen("Parcial2.dat","rb");
    if(arch!=NULL)
    {
        int cant=cargarVector(vec,arch);
        fclose(arch);
        ordenar(vec,cant);
        grabarArch(vec,cant);

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

void grabarArch(Parcial v[],int c)
{
    FILE *a=fopen("Parcial2.dat","wb");
    for(int i=0;i<c;i++)
        fwrite(&v[i],sizeof(Parcial),1,a);
    fclose(a);
}
