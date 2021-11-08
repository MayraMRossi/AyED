#include <iostream>
using namespace std;

//Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
//informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor nota.

void cargarParalelo(int c[], int [], int);
int mayor (int v[], unsigned cant);
int menor (int v[], unsigned cant);
void informarDNI(int dni[], int notas[], int cant, int mayor, int menor);
int validarDatos(int d, int h);

int main()
{
    int notas[5], dni[5];
    cargarParalelo(dni, notas, 5);
    int max=mayor(notas, 5);
    int min=menor(notas, 5);
    informarDNI(dni, notas, 5, max, min);




    return 0;
}

void cargarParalelo(int a[], int b[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        cout<<"Ingrese el DNI del alumno Nro "<<i+1<<": ";
        cin>>a[i];
        cout<<"Ingrese la nota del alumno Nro "<<i+1<<": ";
        b[i]=validarDatos(1, 10);
    }
}

int mayor (int v[], unsigned cant)
{
    int mayor;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || v[i]>mayor)
        {
            mayor=v[i]; 
        }
    }
    return mayor;
}

int menor (int v[], unsigned cant)
{
    int menor;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || v[i]<menor)
        {
            menor=v[i];
        }
    }
    return menor;
}

void informarDNI(int dni[], int notas[], int cant, int mayor, int menor)
{
    cout<<"DNI con la nota mayor ("<<mayor<<"): ";
    for(int i=0; i<cant; i++)
    {
        if(notas[i]==mayor)
            cout<<dni[i]<<" ";
    }
    cout<<endl<<"DNI con la nota menor ("<<menor<<"): ";
    for(int i=0; i<cant; i++)
    {
        if(notas[i]==menor)
            cout<<dni[i]<<" ";
    }
}

int validarDatos(int d, int h)
{
    int num;
    do 
    {
        cin>>num;
    } while (num<d || num>h);
    return num;
}