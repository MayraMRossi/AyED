//APAREO: trabajar con dos vectores a la par. Tienen que estar ordenados por un miembro en comun.
//En este caso, se busca ingresar los empleados del vector 1 y 2 en un mismo struct.

#include <iostream>
using namespace std;

struct Empleado
{
    unsigned nroLeg;
    string nomApe;
};

Empleado ingresarEmple();
void ingresarEmpleados(Empleado v[], unsigned t);
void ordenar(Empleado v[], unsigned t);
void mostrar(Empleado v[], unsigned t);
void apareo(Empleado v1[], unsigned t1, Empleado v2[], unsigned t2);


int main()
{
    Empleado vecEmple1[3];
    Empleado vecEmple2[2];
    cout<<"Empleados de la Sucursal 1: "<<endl;
    ingresarEmpleados(vecEmple1, 3);
    cout<<"Empleados de la Sucursal 2: "<<endl;
    ingresarEmpleados(vecEmple2, 2);
    ordenar(vecEmple1, 3);
    ordenar(vecEmple2, 2);
    cout<<"Empleados de la Sucursal 1: "<<endl;
    mostrar(vecEmple1, 3);
    cout<<"Empleados de la Sucursal 2: "<<endl;
    mostrar(vecEmple2, 2);
    cout<<"Empleados de la sucursal general: "<<endl;
    apareo(vecEmple1, 3, vecEmple2, 2);

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
    cout<<"Ingresar nombre: ";
    cin>>emple.nomApe;
    
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
        cout<<v[i].nroLeg<<" - "<<v[i].nomApe<<endl;
}

void apareo(Empleado v1[], unsigned t1, Empleado v2[], unsigned t2)
{
    unsigned i=0, j=0, k;
    while(i<t1 && j<t2)
    {
        if(v1[i].nroLeg<v2[j].nroLeg)
        {
            cout<<v1[i].nroLeg<<" - "<<v1[i].nomApe<<endl;
            i++;
        }
        else
        {
            if(v1[i].nroLeg==v2[j].nroLeg)
            {
                cout<<v1[i].nroLeg<<" - "<<v1[i].nomApe<<endl;
                i++;
                j++;
            }
            else
            {
                cout<<v2[i].nroLeg<<" - "<<v2[i].nomApe<<endl;
                j++;
            }
        }
    }
    for(k=i; k<t1; k++)
        cout<<v1[i].nroLeg<<" - "<<v1[i].nomApe<<endl;
    for(k=j; k<t2; k++)
        cout<<v2[i].nroLeg<<" - "<<v2[i].nomApe<<endl;
}