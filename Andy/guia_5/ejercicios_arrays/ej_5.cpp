#include <iostream>
using namespace std;

void inicializar(bool v[], unsigned t);
void cargar(bool v[]);
void mostrarIngresados(bool v[], unsigned t);
void mostrarNoIngresados(bool v[], unsigned t);
int validarNum(int d, int h);

int main()
{
    bool num[500];
    inicializar(num, 500);
    cargar(num);
    cout<<"Los numeros ingresados son: ";
    mostrarIngresados(num, 500);
    cout<<endl;
    cout<<"Los numeros no ingresados son: ";
    mostrarNoIngresados(num, 500);


    return 0;
}

void inicializar(bool v[], unsigned t)
{
    for(int i=0; i<t; i++)
        v[i]=0;
}

void cargar(bool v[])
{
    int num;
    cout<<"Ingrese el numero, cero para finalizar: ";
    num = validarNum(0, 500);
    while(num!=0)
    {
        v[num-1]=1;

        cout<<"Ingrese el numero, cero para finalizar: ";
        num = validarNum(0, 500);
    }
}

int validarNum(int d, int h)
{
    int n;
    do
    {
        cin>>n;
    } while (n<d || n>h);
    return n;
}

void mostrarIngresados(bool v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        if(v[i]==1)
            cout<<i+1<<" ";
    }
}
void mostrarNoIngresados(bool v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        if(v[i]==0)
            cout<<i+1<<" ";
    }
}