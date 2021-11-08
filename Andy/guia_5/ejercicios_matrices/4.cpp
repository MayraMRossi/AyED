#include <iostream>
using namespace std;

void cargar(int m[][5], int f, int c);
int validarDatos(int d, int h);
void inicializar(int m[][5], int f, int c);
void mostrarTotal(int m[][5], int f, int c);
void mostrarModelo(int m[][5], int f, int c);
void mostrarColor(int m[][5], int f, int c);
void sumaTotal(int m[][5], int f, int c);

int main()
{
    int calzados[7][5];
    inicializar(calzados, 7, 5);
    cargar(calzados, 7, 5);
    cout<<endl<<"Resumen de compra Total: "<<endl;
    mostrarTotal(calzados, 7, 5);
    mostrarModelo(calzados, 7, 5);
    mostrarColor(calzados, 7, 5);
    sumaTotal(calzados, 7, 5);

    return 0;
}

void cargar(int m[][5], int f, int c)
{
    int i=0, j=0, cont=0, num, color;
    cout<<"Nro modelo: ";
    num=validarDatos(0,7);
    while(num!=0)
    {
        cout<<"Color: ";
        color=validarDatos(1,5);
        
        m[num-1][color-1]+=1;

        cout<<"Nro modelo: ";
        num=validarDatos(0,7);
    }
}

int validarDatos(int d, int h)
{
    int num;
    do
    {
        cin>>num;
    } while (num<d || num>h);
    return num;
}

void inicializar(int m[][5], int f, int c)
{
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
            m[i][j]=0;
    }
}

void mostrarTotal(int m[][5], int f, int c)
{
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
            cout<<"Nro Modelo:  "<<i+1<<"   Color:"<<j+1<<"   Cantidad vendida: "<<m[i][j]<<endl;
    }
}

void mostrarModelo(int m[][5], int f, int c)
{
    int suma;
    for(int i=0; i<f; i++)
    {
        suma=0;
        for(int j=0; j<c; j++)
            suma+=m[i][j];
        cout<<"Cantidad del Modelo "<<i+1<<": "<<suma<<endl;
    }
}

void mostrarColor(int m[][5], int f, int c)
{
    int suma;
    for(int j=0; j<c; j++)
    {
        suma=0;
        for(int i=0; i<f; i++)
            suma+=m[i][j];
        cout<<"Cantidad del Color "<<j+1<<": "<<suma<<endl;
    }
}

void sumaTotal(int m[][5], int f, int c)
{
    int suma=0;
    for(int j=0; j<c; j++)
    {
        for(int i=0; i<f; i++)
            suma+=m[i][j];
    }
    cout<<"Cantidad Total: "<<suma<<endl;
}