//Mostrar todos los empleados que trabajaron ayer en las distintas sucursales
//y en cuantas sucursales trabajó.

#include <iostream>
using namespace std;

struct Empleado
{
    unsigned nroLeg;
    int suc;
};

Empleado ingresarEmple();
void ingresarEmpleados(Empleado v[], unsigned t);
void ordenar(Empleado v[], unsigned t);
void mostrar(Empleado v[], unsigned t);
void apareo(Empleado v1[], unsigned t1, Empleado v2[], unsigned t2);
void corteControl(Empleado v[], unsigned t);


int main()
{
    Empleado vecEmple[10];
    ingresarEmpleados(vecEmple, 10);
    ordenar(vecEmple, 10);
    mostrar(vecEmple, 10);
    corteControl(vecEmple, 10);

    return 0;
}


void ingresarEmpleados(Empleado v[], unsigned t)
{
    for(int i=0; i<t; i++)
        v[i]=ingresarEmple();
}

Empleado ingresarEmple()
{
    Empleado emple;
    cout<<"Ingresar numero de Legajo: ";
    cin>>emple.nroLeg;
    cout<<"Ingresar numero de sucursal: ";
    cin>>emple.suc;
    
    return emple;
}

void ordenar(Empleado v[], unsigned t)
{
    int i=1, j;
    Empleado aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0; j<t-i; j++)
        {
            if(v[j].nroLeg>v[j+1].nroLeg)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    } while(i<t && cambio);
}

void mostrar(Empleado v[], unsigned t)
{
    cout<<"Empleados: "<<endl;
    for(int i=0; i<t; i++)
        cout<<v[i].nroLeg<<" - "<<v[i].suc<<endl;
}
/*
void corteControl(Empleado v[], unsigned t)
{
    int i=0, cont, leg;
    while(i<t)
    {
        cont=0;
        leg=v[i].nroLeg;
        do
        {
            cont++;
            i++;
        } while (i<t && leg==v[i].nroLeg);
        cout<<leg<<" trabajo en "<<cont<<" sucursales"<<endl;
    }
}
*/

void corteControl(Empleado v[], unsigned t)
{
    int i=0, cont, j;
    while(i<t)
    {
        cont=0;
        j=i;
        do
        {
            cont++;
            j++;
        } while (j<t && v[j].nroLeg==v[i].nroLeg);
        cout<<v[i].nroLeg<<" trabajo en "<<cont<<" sucursales"<<endl;
        i=j;
    }
}
