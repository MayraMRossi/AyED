#include <iostream>


using namespace std;


struct Empleado
{
    unsigned nroLeg;
    string nomApe;
    float sueldo;
};

Empleado ingresarEmple();
float promedio(Empleado v[],int t);
void ingresarEmpleados(Empleado v[],int ce);
void mostrar(Empleado v[],int t);
void ordenar(Empleado v[],unsigned t);

int main()
{
    Empleado vecEmple[3];
    ingresarEmpleados(vecEmple,3);
    cout<<"Sueldo promedio: "<<promedio(vecEmple,3)<<endl;
    ordenar(vecEmple,3);
    mostrar(vecEmple,3);
    return 0;
}

Empleado ingresarEmple()
{
    Empleado emple;
    cout<<"Ingresar nro de Legajo ";
    cin>>emple.nroLeg;
    cout<<"Ingresar nombre ";
    cin>>emple.nomApe;
    cout<<"Ingresar sueldo ";
    cin>>emple.sueldo;
    return emple;
}

void ingresarEmpleados(Empleado v[],int ce)
{
    for(int i=0;i<ce;i++)
        v[i]=ingresarEmple();
}

float promedio(Empleado v[],int t)
{
    float sum=0;
    for(int i=0;i<t;i++)
        sum+=v[i].sueldo;
    return sum/t;
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
        cout<<v[i].nroLeg<<"-"<<v[i].nomApe<<"-"<<v[i].sueldo<<endl;
 }
