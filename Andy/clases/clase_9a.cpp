//Un stuck es una estructura de datos donde puedo almacenar variables de distinto tipo.

#include <iostream>
using namespace std;

struct Fecha
{
    unsigned dia, mes, anio;
};

struct Empleado
{
    unsigned nroLeg;
    string nomApe;
    float sueldo;
    Fecha fechaIng;
};

Empleado ingresarEmple();
Fecha ingresarFecha();

int main()
{
    /*
    Empleado emple, e;
    cout<<"Ingresar numero de Legajo ";
    cin>>emple.nroLeg;
    cout<<"Ingresar nombre ";
    cin>>emple.nomApe;
    cout<<"Ingresar sueldo ";
    cin>>emple.sueldo;
    
    e=emple; //Puedo asignarle un struck a otro del MISMO TIPO
    */
    Empleado e=ingresarEmple();
    cout<<e.nroLeg<<"-"<<e.nomApe<<"-"<<e.sueldo;

    return 0;
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
    emple.fechaIng=ingresarFecha();
    
    return emple;
}

//Tambien podria ser una funcion VOID con un parametro por REFERENCIA
/*
void ingresarEmple(Empleado &emple)
{
    cout<<"Ingresar numero de Legajo ";
    cin>>emple.nroLeg;
    cout<<"Ingresar nombre ";
    cin>>emple.nomApe;
    cout<<"Ingresar sueldo ";
    cin>>emple.sueldo;
}
*/

Fecha ingresarFecha()
{
    Fecha f;
    cout<<"Fecha de Ingreso: "<<endl;
    cout<<"Dia: ";
    cin>>f.dia;
    cout<<"Mes: ";
    cin>>f.mes;
    cout<<"Anio: ";
    cin>>f.anio;
    
    return f;
}