#include <iostream>

using namespace std;

//void mensajeIngresar();
//void mensajeIngresar(string);
//void mensajeResultado(float);
void mensaje(string);
void mensaje(string,float);
int ingresoEntero(int,int);
float promedio(int,int);
int sumar(int,int);

int main()
{
    int nota1,nota2,dni;
    float prom;
    //mensajeIngresar("Ingresar dni");
    mensaje("Ingresar dni");
    dni=ingresoEntero(10000000,99999999);
    //mensajeIngresar("Ingresar primera nota");
    mensaje("Ingresar primera nota");
    nota1=ingresoEntero(1,10);
    //mensajeIngresar("Ingresar segunda nota");
    mensaje("Ingresar segunda nota");
    nota2=ingresoEntero(1,10);
    prom=promedio(nota1,nota2);
    //mensajeResultado(prom);
    mensaje("Promedio: ",prom);
    //mensajeResultado(promedio(nota1,nota2));

    return 0;
}
/*
void mensajeIngresar()
{
    cout<<"Ingrese nota"<<endl;
}
*/
/*
void mensajeIngresar(string mensaje)
{
    cout<<mensaje<<endl;
}
*/
void mensaje(string mens)
{
    cout<<mens<<endl;
}
/*
void mensajeResultado(float result)
{
    cout<<"Promedio: "<<result<<endl;
}
*/
void mensaje(string mens,float result)
{
    cout<<mens<<result<<endl;
}

int ingresoEntero(int desde,int hasta)
{
    int nroEnt;
    do
        cin>>nroEnt;
    while(nroEnt<desde || nroEnt>hasta);
    return nroEnt;
}

int sumar(int a,int b)
{
    /*
    int suma;
    suma=a+b;
    return suma;
    */
    return a+b;
}

float promedio(int n1,int n2)
{
    /*
    int suma=sumar(n1,n2);
    float prom=(float)suma/2;
    return prom;
    */
    /*
    int suma=sumar(n1,n2);
    return (float)suma/2;
    */
    return (float)sumar(n1,n2)/2;
}



