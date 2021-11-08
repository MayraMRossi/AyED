//MATRICES: arreglos de 2 dimensiones (fila y columna)
//No exiten limites de la cantidad de dimensiones que puede tener un arreglo
//Puedo llenarlas por fila o por columna


#include <iostream>
using namespace std;

void cargarPorColumna(int m[][3], int cf, int cc);
void mostrarPorFila(int m[][3], int cf, int cc);
void sumatoriaFilas(int m[][3], int cf, int cc, int v[]);
void mostrarVec(int v[], unsigned t);
void sumatoriaColum(int m[][3], int cf, int cc, int v[]);

int main()
{
    int matriz[4][3], sumaFila[4], sumaColum[3];
    cargarPorColumna(matriz, 4, 3);
    mostrarPorFila(matriz, 4, 3);
    sumatoriaFilas(matriz, 4, 3, sumaFila);
    cout<<"Sumatoria de las filas: ";
    mostrarVec(sumaFila, 4);
    sumatoriaColum(matriz, 4, 3, sumaColum);
    cout<<endl;
    cout<<"Sumatoria de las columnas: ";
    mostrarVec(sumaColum, 4);

    return 0;
}

void cargarPorColumna(int m[][3], int cf, int cc)
{
    for(int j=0; j<cc; j++)
    {
        for(int i=0; i<cf; i++)
        {
            cout<<"Ingresar elemento de la fila "<<i+1<<", columna "<<j+1<<endl;
            cin>>m[i][j];
        }
    }
}

void mostrarPorFila(int m[][3], int cf, int cc)
{
    for(int i=0; i<cf; i++)
    {
        for(int j=0; j<cc; j++)
            cout<<m[i][j]<<"  ";
        cout<<endl;
    }
}

void sumatoriaFilas(int m[][3], int cf, int cc, int v[])
{
    int s;
    for(int i=0; i<cf; i++)
    {
        s=0;
        for(int j=0; j<cc; j++)
            s+=m[i][j];
        v[i]=s;
    }
}

void mostrarVec(int v[], unsigned t)
{
    for(int i=0; i<t; i++)
        cout<<v[i]<<"  ";
}

void sumatoriaColum(int m[][3], int cf, int cc, int v[])
{
    int s;
    for(int i=0; i<cc; i++)
    {
        s=0;
        for(int j=0; j<cf; j++)
            s+=m[j][i];
        v[i]=s;
    }
}
