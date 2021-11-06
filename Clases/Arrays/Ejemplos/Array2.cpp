#include <iostream>

using namespace std;

//Ingresar 5 números  enteros e
//informar cuántos de ellos son mayores a su promedio

void ingresarNros(int[],unsigned);
int calcularPromedio(int[],unsigned);
int cantMayores(int[],unsigned,int);
int sumar(int[],unsigned);

int main()
{
    int nros[5];
    ingresarNros(nros,5);
    int prom=calcularPromedio(nros,5);
    cout<<"hay "<<cantMayores(nros,5,prom)<<" nros mayores al promedio "<<prom<<endl;


    return 0;
}


void ingresarNros(int v[],unsigned tam)
{
    for(int i=0;i<tam;i++)
    {
        cout<<"nro de orden "<<i+1<<endl;
        cin>>v[i];
    }
}

int calcularPromedio(int vec[],unsigned ce)
{
    return sumar(vec,ce)/ce;
}

int sumar(int vect[],unsigned n)
{
    int suma=0;
    for(int j=0;j<n;j++)
        suma+=vect[j];
    return suma;
}

int cantMayores(int v[],unsigned ce,int x)
{
    unsigned cont=0;
    for(int i=0;i<ce;i++)
    {
        if(v[i]>x)
            cont++;
    }
    return cont;
}
