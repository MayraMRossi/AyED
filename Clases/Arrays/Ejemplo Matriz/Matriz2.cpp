/*
Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos
donde existen 15 departamentos en cada piso.
El valor de las expensas es de $ 3000.
Para registrar la cobranza se ingresa el número de piso (1 a 5)
y el número de departamento (correlativo de 1 a 15 en cada piso).
El ingreso finaliza con un piso igual a 0.
Al finalizar mostrar el dinero total recaudado y
una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:
TOTAL RECAUDADO
DEPARTAMENTOS DEUDORES
PISO    DPTO 1 DPTO2 … DPTO 15
PISO 1    X
PISO 2    X     X
PISO 3    X
PISO 4    X     X
PISO 5    X
*/
#include <iostream>


using namespace std;


int ingresoEntero(int desde,int hasta);
void inic(bool m[][15],int cf, int cc);
int registrarPagos(bool m[][15],int cf,int cc);
void mostrarDeudores(bool m[][15],int cf,int cc);

int main()
{
    bool pago[5][15];
    inic(pago,5,15);
    registrarPagos(pago,5,15);
    mostrarDeudores(pago,5,15);
    return 0;
}


int registrarPagos(bool m[][15],int cf,int cc)
{
    unsigned piso,dpto;
    cout<<"Piso"<<endl;
    piso=ingresoEntero(0,cf);
    while(piso!=0)
    {
        cout<<"Dpto"<<endl;
        dpto=ingresoEntero(1,cc);
        m[piso-1][dpto-1]=true;
        cout<<"Piso"<<endl;
        piso=ingresoEntero(0,cf);
    }

}

void mostrarDeudores(bool m[][15],int cf,int cc)
{
    cout<<"      1    2    3    4    5    6    7    8    9    10   11   12   13   14   15 "<<endl;
    for(int i=0;i<cf;i++)
    {
        cout<<i+1<<"   ";
        for(int j=0;j<cc;j++)
        {
            if(!m[i][j])
                cout<<"  X  ";
            else
                cout<<"     ";
        }
        cout<<endl;
    }
}
void inic(bool m[][15],int cf, int cc)
{
    for(int j=0;j<cc;j++)
        for(int i=0;i<cf;i++)
            m[i][j]=false;
}

int ingresoEntero(int desde,int hasta)
{
    int nroEnt;
    do
    {
        cin>>nroEnt;
    }while(nroEnt<desde || nroEnt>hasta);
    return nroEnt;
}




