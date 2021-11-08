#include <iostream>
using namespace std;

float calcular(float a, float b, char operador);

int main()
{
    float a, b;
    char operador;
    cout<<"Ingrese el primer operando: ";
    cin>>a;
    cout<<"Ingrese el segundo operando: ";
    cin>>b;
    cout<<"Seleccione la operacion a realizar: "<<endl<<"1: suma, 2: resta, 3: multiplicacion, 4: division: "<<endl;
    cin>>operador;

    cout<<"Resultado = "<<calcular(a, b, operador)<<endl;

    return 0;
}

float calcular(float a, float b, char operador)
{
    switch(operador)
    {
        case '1': return a+b; break;
        case '2': return a-b; break;
        case '3': return a*b; break;
        case '4': return a/b; break;
    }
}

