#include <iostream>

using namespace std;

//Dados 50 valores distintos que se ingresan por teclado, mostrar en qué posición se ingresó el mayor.

int main(){
    int numero = 0, mayor = 0, eli = 1;

    cout<<"ingrese el numero de orden 1: "<<endl;
    cin>>numero;
    mayor = numero;

    for (int i=2; i<=5;i++)
    {
        cout<<"ingrese el numero de orden "<<i<<endl;
        cin>>numero;
        if(numero>mayor)
        {
            mayor = numero;
            eli = i;
        }
    }
    cout<<"La posicion del mayor es: "<<eli;


return 0;
}