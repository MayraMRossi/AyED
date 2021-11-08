#include <iostream>
using namespace std;

int mes(int n);

int main()
{
    int fecha;
    cin>>fecha;
    cout<<mes(fecha);
}

int mes(int fecha)
{
    int dia, mes, anio;

    anio = fecha/10000;
    dia = fecha%100;
    mes = ((fecha-anio*10000)-dia)/100;

    return mes;
}