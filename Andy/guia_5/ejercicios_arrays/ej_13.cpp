//Se tiene un vector de notas (cada elemento tiene nombre del alumnos y nota obtenida) correspondientes al primer parcial y otro vector 
//del mismo tipo del anterior con las notas correspondientes al segundo parcial, ambos vectores están ordenados alfabéticamente por nombre.
//Se pide hacer un listado ordenado por nombre con la condición obtenida por el alumno en la materia, según lo siguiente:
//- Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
//- Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
//- Primer o segundo parcial con nota menor a 6: RECURSA

#include <iostream>
using namespace std;

void cargarParalelo(string nombre[], int n1[], int n2[], unsigned t);
void burbujeo (string nombre[], int n1[], int n2[], unsigned t);
void estadoAlumno (string nombre[], int n1[], int n2[], unsigned t);
int validarDatos(int d, int h);

int main()
{
    int notas1[5], notas2[5];
    string nombres[5];

    cargarParalelo(nombres, notas1, notas2, 5);
    burbujeo(nombres, notas1, notas2, 5);
    cout<<endl;
    estadoAlumno(nombres, notas1, notas2, 5);

    return 0;
}

void cargarParalelo(string nombre[], int n1[], int n2[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"Ingrese el Nombre: ";
        cin>>nombre[i];
        cout<<"Ingrese la Nota del 1er Parcial: ";
        n1[i]=validarDatos(1, 10);
        cout<<"Ingrese la Nota del 2do Parcial: ";
        n2[i]=validarDatos(1, 10);
        cout<<endl;
    }
    
}

void burbujeo (string nombre[], int n1[], int n2[], unsigned t)
{
    int i, j, aux1;
    string aux2;
    for(i=1; i<t; i++)
    {
        for(j=0; j<t-i; j++)
        {
            if(nombre[j]>nombre[j+1])
            {
                aux2=nombre[j];
                nombre[j]=nombre[j+1];
                nombre[j+1]=aux2;

                aux1=n1[j];
                n1[j]=n1[j+1];
                n1[j+1]=aux1;

                aux1=n2[j];
                n2[j]=n2[j+1];
                n2[j+1]=aux1;
            }
        }
    }
}

void estadoAlumno (string nombre[], int n1[], int n2[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        if(n1[i]>=8 && n2[i]>=8)
            cout<<"Alumno: "<<nombre[i]<<" PROMOCION"<<endl;
        else if(n1[i]>=6 && n2[i]>=6)
            cout<<"Alumno: "<<nombre[i]<<" RINDE FINAL"<<endl;
        else 
            cout<<"Alumno: "<<nombre[i]<<" RECURSA"<<endl;
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