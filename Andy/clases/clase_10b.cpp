//Cargar la matriz aleatoriamente

#include <iostream>
using namespace std;

void inicializar(bool m[][15], int cf, int cc);
void cargar(bool m[][15], int cf, int cc);
int validarDatos(int d, int h);

int main()
{
    bool pago[5][15];


}

void inicializar(bool m[][15], int cf, int cc)
{
    for(int i=0; i<cf; i++)
    {
        for(int j=0; j<cc; j++)
            m[i][j]=0;
    }
}

void cargar(bool m[][15], int cf, int cc)
{
    int piso, dep;
    cout<<"Nro de Piso: ";
    piso=validarDatos(0, 5);
    while(piso!=0)
    {
        cout<<"Nro de Departamento: ";
        dep=validarDatos(1, 15);
        m[piso-1][dep-1]=1;

        cout<<"Nro de Piso: ";
        piso=validarDatos(0, 5);
    }
}

int validarDatos(int d, int h)
{
    int n;
    do
    {
        cin>>n;
    } while (n<d || n>h);
    return n;
}
