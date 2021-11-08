#include <iostream>
using namespace std;

void cargar(int m[][25], int f, int c);
void mostrarPorCol(int m[][25], int f, int c);
float prom(int m[][25], int f, int c);
void sumarPorCol(int m[][25], int f, int c, int v[]);
void Filamax(int m[][25], int f, int c, int v[]);
void mostrarVec(int v[], int t);

int main()
{
    int m[30][25], filas, col;
    cout<<"Ingrese el nro de filas: ";
    cin>>filas;
    cout<<"Ingrese el nro de columnas: ";
    cin>>col;
    cout<<endl;
    cargar(m, filas, col);
    int suma[col], max[filas];

    cout<<"Promedio de la matriz: "<<prom(m, filas, col)<<endl;
    cout<<"Vector Suma por Columna: "<<endl;
    sumarPorCol(m, filas, col, suma);
    mostrarVec(suma, col);
    cout<<endl;
    cout<<"Vector con el valor max de cada fila: "<<endl;
    Filamax(m, filas, col, max);
    mostrarVec(max, filas);

    return 0;
}

void cargar(int m[][25], int f, int c)
{
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
        {
           cout<<"Fila "<<i+1<<", Columna "<<j+1<<endl;
           cin>>m[i][j];
        }
    }
}

void mostrarPorCol(int m[][25], int f, int c)
{
    for(int j=0; j<c; j++)
    {
        for(int i=0; i<f; i++)
            cout<<m[i][j]<<"  "<<endl;
    }
}

float prom(int m[][25], int f, int c)
{
    float prom;
    int suma=0;
    for(int j=0; j<c; j++)
    {
        for(int i=0; i<f; i++)
        {
            suma+=m[i][j];
        }
    }
    prom=(float)suma/(f*c);
    return prom;
}

void sumarPorCol(int m[][25], int f, int c, int v[])
{
    int suma;
    for(int j=0; j<c; j++)
    {
        suma=0;
        for(int i=0; i<f; i++)
            suma+=m[i][j];
        v[j]=suma;
    }
}

void Filamax(int m[][25], int f, int c, int v[])
{
    int mayor;
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(j==0 || m[i][j]>mayor)
                mayor=m[i][j];
        }
        v[i]=mayor;
    }
}

void mostrarVec(int v[], int t)
{
    for(int i=0; i<t; i++)
        cout<<v[i]<<" ";
}