#include <iostream>
using namespace std;

struct Empleado
{
    unsigned nroLeg;
    string nomApe;
    float sueldo;
};

Empleado ingresarEmple();
float promSueldo(Empleado v[], unsigned t);
void ingresarEmpleados(Empleado v[], unsigned t);
void mostrar(Empleado v[], unsigned t);

int main()
{
    Empleado vecEmple[3];
    ingresarEmpleados(vecEmple, 3);
    mostrar(vecEmple, 3);
    cout<<"Sueldo promedio: "<<promSueldo(vecEmple, 3);

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
    cout<<"Ingresar sueldo: ";
    cin>>emple.sueldo;
    
    return emple;
}

float promSueldo(Empleado v[], unsigned t)
{
    float suma=0;
    for(int i=0; i<t; i++)
        suma+=v[i].sueldo;
    return (suma/t);
}

//Si ordeno el struck por un elemento, se ordenan todos los demas

void mostrar(Empleado v[], unsigned t)
{
    cout<<"Empleados: "<<endl;
    for(int i=0; i<t; i++)
        cout<<v[i].nroLeg<<" - "<<v[i].nomApe<<" - "<<v[i].sueldo<<endl;
}