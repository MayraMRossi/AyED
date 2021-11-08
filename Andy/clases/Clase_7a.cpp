#include <iostream>
using namespace std;

//Dados los legajos de los empleados de una empresa que, como maximo tiene 
//100 empleados, se pide mostrar los legajos de los empleados que tienen el
//mayor sueldo. El ingreso de datos no es en orden y finaliza con legajo cero.
//1) Legajos entre 1 y 100.
//Ademas mostrar legajos y sueldos.

void cargarDatos(int v[]);
int validarIngreso (int d, int h);
void inicializar (int v[], unsigned cant);
void mostrar (int v[], unsigned cant);
//int mayor(int v[], unsigned cant);
int mayor(int v[], int cant, int pos[], int &j);
//void mostrarLegMax(int v[], unsigned cant, int mayor);
void mostrarLegMax(int v[], int t);

int main()
{
    int sueldos[100];
    inicializar(sueldos, 100);
    cargarDatos(sueldos);
    mostrar(sueldos, 100);
    /*
    int mayorSueldo=mayor(sueldos, 100);
    if(mayorSueldo==-1)
        cout<<"No se ingresaron datos."<<endl;
    else
    {
        cout<<endl<<"Legajos de los empleados con mayor sueldo("<<mayorSueldo<<"): "<<endl;
        mostrarLegMax(sueldos, 100, mayorSueldo);
    }
    */

    int pos[100], tamPos;
    int mayorSueldo=mayor(sueldos, 100, pos, tamPos);
    if(mayorSueldo==-1)
        cout<<"No se ingresaron datos."<<endl;
    else
    {
        cout<<endl<<"Legajos de los empleados con mayor sueldo("<<mayorSueldo<<"): "<<endl;
        mostrarLegMax(pos, tamPos);
    }


    return 0;
}

void inicializar (int v[], unsigned cant)
{
    for(int i=0; i<cant; i++)
        v[i]=0;
}

void cargarDatos(int v[])
{
    int leg;
    cout<<"Ingresar legajo, cero para finalizar: "<<endl;
    leg=validarIngreso(0, 100);
    while(leg!=0)
    {
        cout<<"Sueldo: ";
        cin>>v[leg-1];

        cout<<"Ingresar legajo, cero para finalizar: "<<endl;
        leg=validarIngreso(0, 100);
    }
}

int validarIngreso (int d, int h)
{
    int dato;
    do
    {
        cin>>dato;
    } while (dato<d || dato>h);
    return dato;
}

void mostrar (int v[], unsigned cant)
{
    for(int i=0; i<cant; i++)
    {
        if(v[i]!=0)
            cout<<"Legajo: "<<i+1<<"   Sueldo: "<<v[i]<<endl;
    }
}
/*
int mayor(int v[], unsigned cant)
{
    int max=v[0];
    for(int i=1;i<t; i++)
        if(v[i]>max)
            max=v[i];
    return max;
}
*/
/*
int mayor(int v[], unsigned cant)
{
    int m=-1;
    bool pri=true;
    for(int i=0; i<cant; i++)
    {
        if (v[i]!=0)
        {
            if (pri || v[i]>m)
            {
                pri=false;
                m=v[i];
            }
        }
    }
    return m;
}
*/
/*
void mostrarLegMax(int v[], unsigned cant, int mayor)
{
    for(int i=0; i<cant; i++)
    {
        if(v[i] == mayor)
            cout<<i+1<<endl;
    }
}
*/

void mostrarLegMax(int v[], int t)
{
    for(int i=0; i<t; i++)
        cout<<v[i]+1<<endl;
}

int mayor(int v[], unsigned cant, int pos[], int &j) 
{   //devuelve el mayor (sin considerar los ceros) y un vector con las posiciones.
    int max=-1;
    bool pri=true;

    for(int i=0;i<cant; i++)
    {
        if (v[i]!=0)
        {
            if(pri || v[i]>max)
            {
                pri=false;
                max=v[i];
                j=0;
                pos[j]=i;
                j++;
            }
            else if(v[i]==max)
            {
                pos[j]=i;
                j++;
            }
        }  
    }
        
    return max;
}