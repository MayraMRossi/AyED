#include <iostream>
using namespace std;

int sumaTrianguloSup(int m[][3], int fc);
void cargar(int m[][3], int fc);

int main()
{
    int m[3][3];
    cargar(m, 3);
    cout<<"La sumatoria del triangulo superior es: "<<sumaTrianguloSup(m, 3);
}

int sumaTrianguloSup(int m[][3], int fc)
{
    int suma=0;
    for(int i=0; i<fc; i++)
    {
        for(int j=i+1; j<fc; j++)
        {
            suma+=m[i][j];
        }
    }
    return suma;
}

void cargar(int m[][3], int fc)
{
    for(int i=0; i<fc; i++)
    {
        for(int j=0; j<fc; j++)
        {
            cout<<"Fila "<<i+1<<", Columna "<<j+1<<endl;
            cin>>m[i][j];
        }
    }
}