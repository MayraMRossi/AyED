//Mostrar el archivo ordenado
//Ordenar un archivo

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

int cargarVector(Parcial v[], FILE*a);
void ordenar(Parcial v[], int t);
void mostrar(Parcial v[], int t);
void grabarArch(Parcial v[], int c);

int main()
{
    Parcial vec[40]; //40 es la cant de alumnos = cant max de parciales
    FILE*arch=fopen("Parcial.dat", "rb");
    if(arch!=NULL)
    {
        int cant = cargarVector(vec, arch);
        ordenar(vec, cant);
        mostrar(vec, cant);
        fclose(arch);
    }
}

int cargarVector(Parcial v[], FILE*a)
{
    Parcial ex;
    int i=0;
    fread(&ex, sizeof(Parcial), 1, a);
    while(!feof(a))
    {
        v[i]=ex;
        i++;
        fread(&ex, sizeof(Parcial), 1, a);
    }
    fclose(a);
}

void ordenar(Parcial v[], int t)
{
    int i=1, j;
    Parcial aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0; j<t-i; j++)
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
    } while(i<t && cambio);
}

void mostrar(Parcial v[], int t)
{
    FILE*file2=fopen("Parcial.dat","rb");
    if(file2==NULL)
        cout<<"Error al crear el archivo"<<endl;
    else
    {
        Parcial ex;
        fread(&ex, sizeof(ex), 1, file2);
        while(!feof(file2))
        {
            cout<<ex.legajo<<" "<<" "<<ex.nombre<<" "<<ex.nota<<endl;
            fread(&ex, sizeof(ex), 1, file2);
        }
        fclose(file2);
    }

}

void grabarArch(Parcial v[], int c)
{
    FILE*a=fopen("Parcial.dat", "wb");
    for(int i=0; i<c; i++)
        fwrite(&v[i], sizeof(Parcial), 1, a);
    fclose(a);
}