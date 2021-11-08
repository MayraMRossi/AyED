#include <iostream>
using namespace std;

//Ingresar como max. 100 numeros,
//el ingreso de datos finaliza con un cero, que no se procesa.
//Informar cuantos de ellos son mayores al primer numero ingresado y 
//cuantos mayores al ultimo.

int cantMayor(int [], unsigned, int);
int cargarNros(int [], int);

int main()
{
    int nros[100];
    int cant=cargarNros(nros, 100); //cantidad de numeros almacenados en el vector
    cout<<"Hay "<<cantMayor(nros, cant, nros[0] )<<" mayores al primer elemento ingresado"<<endl;
    cout<<"Hay "<<cantMayor(nros, cant, nros[cant-1] )<<" mayores al ultimo elemento ingresado"<<endl;





    return 0;
}

int cantMayor(int v[], unsigned tam, int x)
{
    unsigned cont=0;
    for(int i=0; i<tam; i++)
    {
        if(v[i]>x)
            cont++;
    }
    return cont;
}

int cargarNros(int v[], int cantElem)
{
    int num, i=0;
    cout<<"Ingrese un numero: ";
    cin>>num;
    while(num!=0 && i<cantElem)
    {
        v[i]=num;
        i++;
        cout<<"Ingrese un numero: ";
        cin>>num;
    }
    return i;
}