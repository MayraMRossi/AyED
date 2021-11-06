#include <iostream>

using namespace std;

//Confeccionar un programa para ingresar diversos valores de temperatura
//hasta que aparezca uno igual a cero.
//Calcular e informar el promedio de los valores ingresados, sin considerar el cero.

int main()
{
    int suma,cont,temp,prom;
    suma=0;
    cont=0;
    cout<<"Ingrese temperatura, para finalizar ingrese cero"<<endl;
    cin>>temp;
    while(temp!=0)
    {
        suma+=temp;
        cont++;
        cout<<"Ingrese temperatura, para finalizar ingrese cero"<<endl;
        cin>>temp;
    }
    if(cont > 0)
    {
        prom=suma/cont;
        cout<<"El promedio de temperaturas es:"<<prom<<endl;
    }
    else
        cout<<"No se ingresaron temperaturas"<<endl;

    return 0;
}
