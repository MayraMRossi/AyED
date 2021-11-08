#include <iostream>
using namespace std;

//Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados), se pide
//determinar el/los empleados de máximo sueldo
//a) Los números de legajo son números correlativos de 1 a 100
//b) Los números de legajo son números no correlativos de 4 cifras.

void cargar(int v[]);
void inicializar(int v[], unsigned cant);
int mayorSueldo(int v[], unsigned cant);
void mostrarLegajos(int leg[], int sueldo[], int cant, int mayor);

int main()
{
    //a)

    int leg[100], sueldos[100];
    inicializar(sueldos, 100);
    cargar(sueldos);
    int mayorS=mayorSueldo(sueldos,100);
    cout<<"Legajos de los empleados con el mayor sueldo: ";
    mostrarLegajos(leg, sueldos, 100, mayorS);


    return 0;
}
void cargar(int v[])
{
    int leg;
    cout<<"Ingrese el numero de legajo, cero para finalizar: ";
    cin>>leg;
    while(leg!=0)
    {
        cout<<"Ingrese el Sueldo: ";
        cin>>v[leg-1];

        cout<<"Ingrese el numero de legajo, cero para finalizar: ";
        cin>>leg;
    }

}

void inicializar(int v[], unsigned cant)
{
    for(int i=0; i<cant; i++)
        v[i]=0;
}

int mayorSueldo(int v[], unsigned cant)
{
    int m;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || v[i]>m)
            m=v[i];
    }
    return m;
}

void mostrarLegajos(int leg[], int sueldo[], int cant, int mayor)
{
    for(int i=0; i<cant; i++)
    {
        if(sueldo[i]==mayor)
            cout<<i+1;
    }
}