#include <iostream>
#include <stdio.h>
using namespace std;

struct rep {
    unsigned dni;
    string nombre;
    string patente;
    unsigned cont=0;
};

void inicializar(int m[][4], unsigned f, unsigned c);


int main()
{
    rep zonas [14][4];
    inicializar(zonas, 14, 4);
    cargar(zonas);
    
    
    return 0;
}

void inicializar(rep m[][4], unsigned f, unsigned c)
{
    for(int i=0; i<f ;i++)
    {
        for(int j=0; i<j ;j++)
            m[i][j]=0;
    }
}



