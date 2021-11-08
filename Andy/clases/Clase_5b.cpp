//La funcion llamadora puede pedirle datos a la funcion llamada por return o por diferentes parámetros (de entrada, salida, y entrada y salida).
//Los parametros son una copia del argumento.
//Entrada => Parametros por valor.
//Salida o Entrada y Salida => Parametros por referencia: trabajo directamente, sin saberlo, sobre el argumento (se le agreaga un & despues del int).


#include <iostream>
using namespace std;

void sumar(int, int, int&);

int main()
{
    int n1, n2, suma;

    cout<<"Ingrese un valor: ";
    cin>>n1;
    cout<<"Ingrese otro valor: ";
    cin>>n2;
    sumar(n1, n2, suma);
    cout<<"Suma: "<<suma<<endl;
    

    return 0;
}

void sumar(int a, int b, int &c) //a y b son parámetros por valor, c por referencia.
{
    c=a+b;
}