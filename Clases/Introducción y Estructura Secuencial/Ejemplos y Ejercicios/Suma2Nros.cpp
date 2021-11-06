#include <iostream>

using namespace std;

//Dados dos números enteros ingresados por teclado mostrar la suma.

int main()
{
    int num1,num2,suma;
    /*
    cout<<"Ingrese dos numeros"<<endl;
    cin>>num1>>num2;
    */

    cout<<"Ingrese un valor ";
    cin>>num1;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num2;

    suma=num1+num2;
    cout<<"La suma entre "<<num1<<" y "<<num2<<" es "<<suma<<endl;

    return 0;
}


