#include <iostream>
#include <string.h>
using namespace std;

struct Empleado
{
    int leg;
    int DNI;
    int cod_dep; // departamento actual
    char nombre[20];
};

struct Vacante
{
    int cod_dep; // de 1 a 50
    int cant_vac;
};

struct Postulante
{
    int leg, cod_dep;
};

void cargar_arch1();
cout<<endl;
void cargar_arch2();
cout<<endl;
void cargar_arch3();
int validar(int desde, int hasta);

int main()
{
    cargar_arch1();
    cargar_arch2();
    cargar_arch3();

    return 0;
}

void cargar_arch1()
{
    FILE*f = fopen("Empleados.dat", "wb");
    if(f==NULL)
        cout<<"Error."<<endl;
    else
    {
        Empleado emp;
        cout<<"CARGANDO EMPLEADOS"<<endl<<endl;
        cout<<"Legajo: ";
        cin>>emp.leg;
        while(emp.leg!=0)
        {
            cout<<"DNI: ";
            cin>>emp.DNI;
            cout<<"Codigo de departamento: ";
            cin>>emp.cod_dep;
            cout<<"Nombre:";
            cin.ignore();
            cin.getline(emp.nombre, 20);
            fwrite(&emp, sizeof(Empleado), 1, f);
            cout<<endl<<"Legajo: ";
            cin>>emp.leg;
        }
    }
    fclose(f);
}

void cargar_arch2()
{
    FILE*f = fopen("Vacantes.dat", "wb");
    if(f==NULL)
        cout<<"Error."<<endl;
    else
    {
        Vacante v;
        cout<<"CARGANDO VACANTES"<<endl<<endl;
        cout<<"Codigo de departamento: ";
        v.cod_dep = validar(0, 50);
        while(v.cod_dep != 0)
        {
            cout<<"Cantidad de vacantes: ";
            cin>>v.cant_vac;
            fwrite(&v, sizeof(Vacante), 1, f);
            cout<<"Codigo de departamento: ";
            v.cod_dep = validar(0, 50);
        }
    }
    fclose(f);
}

void cargar_arch3()
{
    FILE*f = fopen("Postulantes.dat", "wb");
    if(f==NULL)
        cout<<"Error."<<endl;
    else
    {
        Postulante p;
        cout<<"CARGANDO POSTULANTES"<<endl<<endl;
        cout<<"Legajo: ";
        cin>>p.leg;
        while(p.leg != 0)
        {
            cout<<"Cod de departamento: ";
            cin>>p.cod_dep;
            fwrite(&p, sizeof(Postulante), 1, f);
            cout<<"Legajo: ";
            cin>>p.leg;
        }
    }
    fclose(f);
}

int validar(int desde, int hasta)
{
    int n;
    cin>>n;
    while(n<desde || n>hasta)
    {
        cout<<"Numero invalido. Volver a ingresar: ";
        cin>>n;
    }
    return n;
}