#include <iostream>
using namespace std;

void cargar(int m[][25], int fc);
int sumaPrin(int m[][25], int fc);
int sumaSec(int m[][25], int fc);
void mostrarPrin(int m[][25], int fc);
void mostrarSec(int m[][25], int fc);


int main()
{
    int m[25][25], fc, sumaDP, sumaDS;
    cout<<"Ingrese el nro de filas y columnas: ";
    cin>>fc;
    
    cargar(m, fc);
    sumaDP=sumaPrin(m, fc);
    sumaDS=sumaSec(m, fc);
    if(sumaDP>sumaDS)
        mostrarPrin(m, fc);
    else if(sumaDS>sumaDP)
        mostrarSec(m, fc);
    else
        cout<<"La suma de Diag.Princ. es igual a de Diag.Sec.";
        
    return 0;
}

void cargar(int m[][25], int fc)
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

int sumaPrin(int m[][25], int fc)
{
    int suma=0;
    for(int i=0; i<fc; i++)
    {
        for(int j=0; j<fc; j++)
        {
            if(i==j)
                suma+=m[i][j];
        }
    }
    return suma;
}

int sumaSec(int m[][25], int fc) //MAL
{
    int suma=0;
    int i=fc-1, j=0;
    while(i>=0 && j<fc)
    {
        suma+=m[i][j];
        i--;
        j++;
    }
    return suma;
}

void mostrarPrin(int m[][25], int fc)
{
    cout<<"Diagonal principal: "<<endl;
    int suma=0;
    for(int i=0; i<fc; i++)
    {
        for(int j=0; j<fc; j++)
        {
            if(i==j)
                cout<<m[i][j]<<" ";
        }
    }
}

void mostrarSec(int m[][25], int fc)
{
    cout<<"Diagonal secundaria: "<<endl;
    int i=0, j=fc-1;
    while(j>=0 && i<fc)
    {
        cout<<m[i][j]<<" ";
        i++;
        j--;
    }
}