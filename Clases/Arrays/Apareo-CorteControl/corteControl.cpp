/*
Ingresa los empleados que trabajaron en las distintas sucursales ayer

Mostrar todos los empleados que trabajaron ayer informando en cuantas sucursales trabajaron
*/

#include <iostream>


using namespace std;


struct Empleado
{
    unsigned nroLeg;
    int suc;
};

Empleado ingresarEmple();
void ingresarEmpleados(Empleado v[],int ce);
void mostrar(Empleado v[],int t);
void ordenar(Empleado v[],unsigned t);
void apareo(Empleado vs1[],unsigned t1,Empleado vs2[],unsigned t2);
void corteControl(Empleado v[],unsigned t);

int main()
{
    Empleado vecEmple[10];
    ingresarEmpleados(vecEmple,10);
    cout<<"Empleados desordenados"<<endl;
    mostrar(vecEmple,10);
    ordenar(vecEmple,10);
    cout<<"Empleados ordenados"<<endl;
    mostrar(vecEmple,10);
    cout<<"Empleados con cant de suc en las que trabajaron"<<endl;
    corteControl(vecEmple,10);
    return 0;
}

Empleado ingresarEmple()
{
    Empleado emple;
    cout<<"Ingresar nro de Legajo ";
    cin>>emple.nroLeg;
    cout<<"Ingresar suc ";
    cin>>emple.suc;

    return emple;
}

void ingresarEmpleados(Empleado v[],int ce)
{
    for(int i=0;i<ce;i++)
        v[i]=ingresarEmple();
}


void ordenar(Empleado v[],unsigned t)
{
    unsigned i=1,j;
    Empleado aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-i;j++)
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
    }while(i<t && cambio);
}
 void mostrar(Empleado v[],int t)
 {
     for(int i=0;i<t;i++)
        cout<<v[i].nroLeg<<"-"<<v[i].suc<<endl;
 }
/*
 void corteControl(Empleado v[],unsigned t)
 {
     int i=0,cont,legA;
     while(i<t)
     {
         cont=0;
         legA=v[i].nroLeg;
         do
         {
             cont++;
             i++;
         }while(i<t && legA==v[i].nroLeg);
         cout<<legA<<" trabajo en "<<cont<<" sucursales"<<endl;
     }
 }
*/
 void corteControl(Empleado v[],unsigned t)
 {
     int i=0,j,cont;
     while(i<t)
     {
         cont=0;
         j=i;
         do
         {
             cont++;
             j++;
         }while(j<t && v[i].nroLeg==v[j].nroLeg);
         cout<<v[i].nroLeg<<" trabajo en "<<cont<<" sucursales"<<endl;
         i=j;
     }
 }
