#include <iostream>


using namespace std;

struct Fecha
{
    //unsigned dia,mes,anio;
    unsigned dia;
    unsigned mes;
    unsigned anio;
};

struct Empleado
{
    unsigned nroLeg;
    string nomApe;
    float sueldo;
    Fecha fechaIngreso;
    Fecha fechaNac;
};

Empleado ingresarEmple();
void ingresarEmple(Empleado &emple);
void mostrarEmple(Empleado e);
Fecha ingresarFecha();

int main()
{
    /*
    Empleado emple,e;
    cout<<"Ingresar nro de Legajo ";
    cin>>emple.nroLeg;
    cout<<"Ingresar nombre ";
    cin>>emple.nomApe;
    cout<<"Ingresar sueldo ";
    cin>>emple.sueldo;
    e=emple;
    */
    Empleado e1,e2;
    e1=ingresarEmple();
    mostrarEmple(e1);
    ingresarEmple(e2);
    mostrarEmple(e2);


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

void ingresarEmple(Empleado &emple)
{
    cout<<"Ingresar nro de Legajo ";
    cin>>emple.nroLeg;
    cout<<"Ingresar nombre ";
    cin>>emple.nomApe;
    cout<<"Ingresar sueldo ";
    cin>>emple.sueldo;
    cout<<"Fecha de ingreso"<<endl;
    /*
    cout<<"dia ";
    cin>>emple.fechaIngreso.dia;
    cout<<"mes ";
    cin>>emple.fechaIngreso.mes;
    cout<<"anio ";
    cin>>emple.fechaIngreso.anio;
    */
    emple.fechaIngreso=ingresarFecha();
    cout<<"Fecha de nacimiento"<<endl;
    emple.fechaNac=ingresarFecha();
}
void mostrarEmple(Empleado e)
{
    cout<<e.nroLeg<<"-"<<e.nomApe<<"-"<<e.sueldo<<endl;
}
Fecha ingresarFecha()
{
    Fecha f;
    cout<<"dia ";
    cin>>f.dia;
    cout<<"mes ";
    cin>>f.mes;
    cout<<"anio ";
    cin>>f.anio;
    return f;
}



