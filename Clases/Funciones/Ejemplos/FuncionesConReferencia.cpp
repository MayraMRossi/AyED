#include <iostream>

using namespace std;

int sumar(int,int);
void sumar(int,int,int&);
void incrementar(int&);

int main()
{
    int num1,num2,suma;
    cout<<"valor 1: ";
    cin>>num1;
    cout<<"valor 2: ";
    cin>>num2;
    //suma=sumar(num1,num2);
    sumar(num1,num2,suma);
    cout<<"Suma: "<<suma<<endl;
    //cout<<"Suma: "<<sumar(num1,num2)<<endl;
    int cont=2;
    incrementar(cont);
    cout<<cont;
    return 0;
}
int sumar(int a,int b)
{
    int c;
    c=a+b;
    return c;
}
void sumar(int a,int b,int&c) //a y b son parámetros por valor c parámetro por referencia
{
    c=a+b;
}

void incrementar(int &x)
{
    x++;
}
