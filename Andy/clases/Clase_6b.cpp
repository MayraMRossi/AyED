//Al crear una funcion con arreglos, es redundante llamarlo por referencia, porque ya de por si el vetor ES una referencia, por lo que hace REFERENCIA a los mismos esapcios en memoria que el original.


#include <iostream>
using namespace std;

//Ingresar 5 numeros enteros e informar cuantos de ellos son mayores a su promedio.
//Usando funciones

void ingresarNros(int [], unsigned);
int sumar(int[], unsigned);
int calcularProm (int[], unsigned);
int cantMayor(int[], unsigned, int);

int main()
{
    int nros[5];
    ingresarNros(nros, 5);
    int prom=calcularProm(nros, 5);
    cout<<"Hay "<<cantMayor(nros, 5, prom)<<" numeros mayores al promedio "<<calcularProm<<endl;

    return 0;
}

void ingresarNros(int v[], unsigned tam)
{
    for(int i=0; i<tam; i++)
    {
        cout<<"Ingrese el numero de orden "<<i+1<<": "<<endl;
        cin>>v[i];
    }
}

int sumar(int vect[], unsigned tam)
{
    int suma=0;
    for(int i=0; i<tam; i++)
        suma+=vect[i];

    return suma;    
}

int calcularProm (int vec[], unsigned tam)
{
    return sumar(vec, tam)/tam;
}

int cantMayor(int v[], unsigned tam, int prom)
{
    unsigned cont=0;
    for(int i=0; i<tam; i++)
    {
        if(v[i]>prom)
            cont++;
    }
    return cont;
}