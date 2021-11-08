#include <iostream>
using namespace std;

//Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
//informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor nota.
//Usar structs en vez de vectores paralelos.

struct Alumno
{
    int nota, dni;
};

void cargar(Alumno v[], int cant);
int mayor (Alumno v[], unsigned cant);
int menor (Alumno v[], unsigned cant);
void informarDNI(Alumno v[], int cant, int mayor, int menor);
int validarDatos(int d, int h);

int main()
{
    Alumno inf[5];
    cargar(inf, 5);
    int max=mayor(inf, 5);
    int min=menor(inf, 5);
    informarDNI(inf, 5, max, min);

    return 0;
}

void cargar(Alumno v[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        cout<<"Ingrese nota: ";
        v[i].nota=validarDatos(1,10);
        cout<<"Ingrese DNI: ";
        cin>>v[i].dni;
        cout<<endl;
    }
}

int mayor (Alumno v[], unsigned cant)
{
    int mayor;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || v[i].nota>mayor)
        {
            mayor=v[i].nota; 
        }
    }
    return mayor;
}

int menor (Alumno v[], unsigned cant)
{
    int menor;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || v[i].nota<menor)
        {
            menor=v[i].nota;
        }
    }
    return menor;
}

void informarDNI(Alumno v[], int cant, int mayor, int menor)
{
    cout<<"DNI con la nota mayor ("<<mayor<<"): ";
    for(int i=0; i<cant; i++)
    {
        if(v[i].nota==mayor)
            cout<<v[i].dni<<" ";
    }
    cout<<endl<<"DNI con la nota menor ("<<menor<<"): ";
    for(int i=0; i<cant; i++)
    {
        if(v[i].nota==menor)
            cout<<v[i].dni<<" ";
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