#include <iostream>

using namespace std;

//Dados 5 valores distintos que se ingresan por teclado, mostrar el menor.

int main(){
    int numero = 0, menor = 0;

    cout<<"ingrese el numero de orden 1: "<<endl;
    cin>>numero;
    menor = numero;

    for (int i=2; i<=5;i++)
    {
        cout<<"ingrese el numero de orden "<<i<<endl;
        cin>>numero;
        if(numero<menor)
        {
            menor = numero;
        }
    }
    cout<<"El menor numero es: "<<menor;

return 0;
}