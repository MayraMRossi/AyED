#include <iostream>

using namespace std;

void cargarPorColumna(int m[][6],int cf,int cc);
void mostrarPorFila(int m[][6],int cf, int cc);
void sumatoriaFilas(int m[][6],int cf,int cc,int v[]);
void sumatoriaColumnas(int m[][6],int cf,int cc,int v[]);
void mostrarVector(int v[],int t);
void inicializar(int v[],int t);

int main()
{
    int matriz[4][6],sumaFila[4],sumaCol[6];
    inicializar(sumaFila,4);
    inicializar(sumaCol,6);
    cargarPorColumna(matriz,4,6);
    mostrarPorFila(matriz,4,6);
    sumatoriaFilas(matriz,4,6,sumaFila);
    sumatoriaColumnas(matriz,4,6,sumaCol);
    cout<<"sumatoria de las filas "<<endl;
    mostrarVector(sumaFila,4);
    cout<<"sumatoria de las columnas "<<endl;
    mostrarVector(sumaCol,6);
    return 0;
}

void cargarPorColumna(int m[][6],int cf,int cc)
{
    for(int j=0;j<cc;j++)
    {
        for(int i=0;i<cf;i++)
        {
            cout<<"Ingresar elemento de la posicion "<<i<<" , "<<j<<endl;
            cin>>m[i][j];
        }
    }
}
void mostrarPorFila(int m[][6],int cf, int cc)
{
    for(int i=0;i<cf;i++)
    {
        for(int j=0;j<cc;j++)
            cout<<m[i][j]<<"  ";
        cout<<endl;
    }
}
void sumatoriaFilas(int m[][6],int cf,int cc,int v[])
{
    //int s;
    for(int i=0;i<cf;i++)
    {
        //s=0;
        //v[i]=0;
        for(int j=0;j<cc;j++)
            v[i]+=m[i][j];
        //v[i]=s;
    }
}
/*
void sumatoriaColumnas(int m[][6],int cf,int cc,int v[])
{
     int s;
    for(int i=0;i<cc;i++)
    {
        s=0;
        for(int j=0;j<cf;j++)
            s+=m[j][i];
        v[i]=s;
    }
}
*/
void sumatoriaColumnas(int m[][6],int cf,int cc,int v[])
{

    for(int i=0;i<cf;i++)
    {

        for(int j=0;j<cc;j++)
           v[j]+=m[i][j];
    }
}

void mostrarVector(int v[],int t)
{
    for(int i=0;i<t;i++)
        cout<<v[i]<<endl;
}
void inicializar(int v[],int t)
{
    for(int i=0;i<t;i++)
        v[i]=0;
}
