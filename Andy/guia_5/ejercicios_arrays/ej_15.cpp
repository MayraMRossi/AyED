//Se tiene un vector con las notas de los exámenes rendidos por los alumnos (nombre y nota) ordenado por nombre con un elemento 
//por cada examen rendido (un alumno puede haber rendido 1, 2, ó más exámenes). 
//Se pide generar un vector con un elemento por alumno con el promedio de las notas de sus exámenes, ordenado por nombre.

#include <iostream>
using namespace std;

struct Alumno
{
    unsigned nota[10];
    string nombre;
    float prom;
    int cant;
};

void cargar(Alumno v[], unsigned t);
void ordenar(Alumno v[], unsigned t);
void promedio(Alumno v[], unsigned t1);
void mostrar(Alumno v[], unsigned t);
int validarDatos(int d, int h);

int main()
{
    Alumno inf[5];
    cargar(inf, 5);
    ordenar(inf, 5);
    promedio(inf, 5);
    mostrar(inf, 5);

    return 0;
}

void cargar(Alumno v[], unsigned t)
{
    int j;
    for(int i=0; i<t; i++)
    {
        j=0;
        cout<<"Ingrese nombre: ";
        cin>>v[i].nombre;
        cout<<endl;
        do
        {
            cout<<"Ingrese nota, cero para finalizar: ";
            v[i].nota[j]=validarDatos(0,10);
            j++;
        } while (v[i].nota[j-1]!=0);
        v[i].cant=j;
    }
}

void ordenar(Alumno v[], unsigned t)
{
    int i=1, j;
    Alumno aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0; j<t-i; j++)
        {
            if(v[j].nombre>v[j+1].nombre)
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

void promedio(Alumno v[], unsigned t1)
{
    int cont=0;
    for(int i=0; i<t1; i++)
    {
        for(int j=0; i<v[i].cant; j++)
            cont+=v[i].nota[j];
        v[i].prom=cont/v[i].cant;
    }
}

void mostrar(Alumno v[], unsigned t)
{
    for(int i=0; i<t; i++)
        cout<<"Alumno: "<<v[i].nombre<<"   Promedio: "<<v[i].prom<<endl;
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