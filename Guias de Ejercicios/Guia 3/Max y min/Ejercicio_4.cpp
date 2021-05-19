#include <iostream>

using namespace std;

//4) Dados 10 valores distintos que se ingresan por teclado, mostrar los dos mayores.

int main(){
    int numero=0, mayor_G=2,mayor_C=1,troque=0;

    cout<<"Ingrese el numero de orden 1: "<<endl;
    cin>>mayor_G;
    cout<<"Ingrese el numero de orden 2: "<<endl;
    cin>>mayor_C;

    if(mayor_C>mayor_G){
        troque = mayor_C;
        mayor_C = mayor_G;
        mayor_G = troque;
    }


    for (int i=3; i<=10;i++)
    {
        cout<<"ingrese el numero de orden "<<i<<endl;
        cin>>numero;

        if(numero>=mayor_G){
            mayor_G = numero;
        }else{
        if(numero>=mayor_C){
            mayor_C = numero;
        }
        }
    }
    cout<<"Los mayores numeros son "<<mayor_G<<" y "<<mayor_C<<endl;

return 0;
}