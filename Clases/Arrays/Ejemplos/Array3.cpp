#include <iostream>

using namespace std;

//Ingresar como máximo 100 números enteros,
//el ingreso de datos finaliza con un cero que no se procesa.
//Informar cuántos de ellos son mayores al primer número ingresado y
//cuántos mayores al último (no el cero)
int cantMayores(int v[],unsigned ce,int x);
int cargarNros(int v[],int cme);

int main()
{
    int nros[100];
    int cant=cargarNros(nros,100); //cant es la cantidad de numeros almacenados en el vector
    cout<<"Hay "<<cantMayores(nros,cant,nros[0])<<" mayores al primer elemento ingresado"<<endl;
    cout<<"Hay "<<cantMayores(nros,cant,nros[cant-1])<<" mayores al ultimo elemento ingresado"<<endl;

    return 0;
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

int cargarNros(int v[],int cme)
{
    int nro,i=0;
    cin>>nro;
    while(nro!=0 && i<cme)
    {
        v[i]=nro;
        i++;
        cin>>nro;
    }
    return i;
}


