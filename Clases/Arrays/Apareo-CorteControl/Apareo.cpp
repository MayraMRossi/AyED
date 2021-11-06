/*
Ingresa los empleados que trabajaron en la sucursal1
y los que trabajaron en la 2 en el día de ayer
Mostrar todos los empleados que trabajaron ayer
*/

#include <iostream>


using namespace std;


struct Empleado
{
    unsigned nroLeg;
    string nomApe;

};

Empleado ingresarEmple();
void ingresarEmpleados(Empleado v[],int ce);
void mostrar(Empleado v[],int t);
void ordenar(Empleado v[],unsigned t);
void apareo(Empleado vs1[],unsigned t1,Empleado vs2[],unsigned t2);

int main()
{
    Empleado vecEmpleS1[10],vecEmpleS2[10];
    ingresarEmpleados(vecEmpleS1,8);
    ordenar(vecEmpleS1,8);
    cout<<"Empleados Suc1"<<endl;
    mostrar(vecEmpleS1,8);
    ingresarEmpleados(vecEmpleS2,4);
    ordenar(vecEmpleS2,4);
    cout<<"Empleados Suc2"<<endl;
    mostrar(vecEmpleS2,4);
    cout<<"Empleados"<<endl;
    apareo(vecEmpleS1,8,vecEmpleS2,4);
    return 0;
}

Empleado ingresarEmple()
{
    Empleado emple;
    cout<<"Ingresar nro de Legajo ";
    cin>>emple.nroLeg;
    cout<<"Ingresar nombre ";
    cin>>emple.nomApe;

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
        cout<<v[i].nroLeg<<"-"<<v[i].nomApe<<endl;
 }

 void apareo(Empleado vs1[],unsigned t1,Empleado vs2[],unsigned t2)
 {
     //ambos vectores tienen que estar ordenados
     unsigned i=0,j=0;
     while(i<t1 && j<t2)
     {
         if(vs1[i].nroLeg<vs2[j].nroLeg)
         {
             cout<<vs1[i].nroLeg<<"-"<<vs1[i].nomApe<<endl;
             i++;
         }
         else
         {
             if(vs1[i].nroLeg==vs2[j].nroLeg)
             {
                cout<<vs1[i].nroLeg<<"-"<<vs1[i].nomApe<<endl;
                //cout<<vs2[j].nroLeg<<"-"<<vs2[j].nomApe<<endl;
                i++;
                j++;
             }
             else
             {
                cout<<vs2[j].nroLeg<<"-"<<vs2[j].nomApe<<endl;
                j++;
             }
         }

     }
     for(int k=i;k<t1;k++)
        cout<<vs1[k].nroLeg<<"-"<<vs1[k].nomApe<<endl;
     for(int k=j;k<t2;k++)
        cout<<vs2[k].nroLeg<<"-"<<vs2[k].nomApe<<endl;

 }


















