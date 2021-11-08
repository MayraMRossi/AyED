#include <iostream>
using namespace std;

void inicializar(bool m[][9], unsigned f, unsigned c);
void mostrar(bool m[][9], unsigned f, unsigned c);
void reservaciones(bool m[][9], unsigned f, unsigned c);
int validarDatos(int d, int h);
int validarFila(int h);
void filaMax(int v[], unsigned f);
void contarAsientos(bool m[][9], unsigned f, unsigned c, int []);

int main()
{
    bool cine[12][9];
    int filaM[12];
    inicializar(cine, 12, 9);
    mostrar(cine, 12, 9);
    reservaciones(cine, 12, 9);
    contarAsientos(cine, 12, 9, filaM);
    filaMax(filaM, 12);


    return 0;
}

void inicializar(bool m[][9], unsigned f, unsigned c)
{
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
            m[i][j]=0;
    }
}

void mostrar(bool m[][9], unsigned f, unsigned c)
{
    int j;
    for(int i=0; i<f; i++)
    {
        for(j=c-2; j>0; j-=2)
        {
            if(m[i][j]==0)
                cout<<"D ";
            else
                cout<<"R ";
        }
        for(j=0; j<c; j+=2)
        {
            if(m[i][j]==0)
                cout<<"D ";
            else
                cout<<"R ";
        }
        cout<<endl;
    }
    cout<<endl;
} 

void reservaciones(bool m[][9], unsigned f, unsigned c)
{
    int fila, col;

    cout<<"Elija sus butacas. Para terminar seleccione una fila negativa. "<<endl<<endl;
    mostrar(m, f, c);
    cout<<"Fila: ";
    fila=validarFila(12);
    while(fila>=0)
    {
        cout<<"Columna: ";
        col=validarDatos(1, 9);
        //Actualizar butacas
        if(m[fila-1][col-1]==1)
            cout<<"Esa butaca ya esta reservada. Elegi otra: ";
        else
        {
            m[fila-1][col-1]=1;
            cout<<endl;
            mostrar(m, f, c);
        }

        cout<<"Fila: ";
        fila=validarFila(12);
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

int validarFila(int h)
{
    int n;
    do
    {
        cin>>n;
    } while (n==0 || n>h);
    return n;
}

void contarAsientos(bool m[][9], unsigned f, unsigned c, int maxFilas[])
{
    int contD=0, contR, contVacias, contOcupadas;
    for(int i=0; i<f; i++)
    {
        contVacias=0;
        contOcupadas=0;
        for(int j=0; j<c; j++)
        {
            if(m[i][j]==0)
            {
                contD++;
                contVacias++;
            }
            else
            {
                contR++;
                contOcupadas++;
            }
        }
        if(contVacias==0)
            cout<<"La fila "<<i+1<<" esta vacia."<<endl;

        maxFilas[i]=contOcupadas;
    }
    cout<<endl;
    cout<<"Asientos disponibles: "<<contD<<endl;
    cout<<"Asientos reservados: "<<contR<<endl;
}

void filaMax(int v[], unsigned f)
{
    int mayor;
    for(int i=0; i<f; i++)
    {
        if(i==0 || v[i]>mayor)
            mayor=v[i];
    }
    cout<<endl<<"La fila/s con mayor reservaciones es/son:"<<" ("<<mayor<<")"<<endl;
    for(int i=0; i<f; i++)
    {
        if(v[i]==mayor)
            cout<<i+1<<" ";
    }
}