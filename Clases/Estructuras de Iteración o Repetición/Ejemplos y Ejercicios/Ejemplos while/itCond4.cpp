#include <iostream>

using namespace std;

//Confeccionar un programa para ingresar diversos valores de temperatura
//preguntando si quiere seguir ingresando datos
//Calcular e informar el promedio de los valores ingresados, sin considerar el cero.

int main()
{
    int suma,cont,temp,prom;
    char resp;
    suma=0;
    cont=0;
    cout<<"Ingrese s si quiere ingresar temperatura y n en caso contrario"<<endl;
    cin>>resp;
    while(resp=='s'||resp=='S')
    {
        cout<<"Ingrese temperatura"<<endl;
        cin>>temp;
        suma+=temp;
        cont++;
        cout<<"Ingrese s si quiere seguir ingresando temperatura y n en caso contrario"<<endl;
        cin>>resp;
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
