#include <iostream>
#include <stdio.h>
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

struct NodoCola
{
    Empleado info;
    NodoCola *sig;
};

struct Cola // struct adentro de cada posicion del vector
{
    NodoCola *pri, *ult;
    int cant_vac;
};

void inicializar(Cola v[], int t);
void encolar(NodoCola *&pri, NodoCola *&ult, Empleado emp);
Empleado deseconlar(NodoCola *&pri, NodoCola *&ult);
Empleado buscar_empleado(int leg, FILE*f);
void empleados_postulados(Cola v[]);
void cargar_cant_vac(Cola v[]);
void listar_postulados(Cola v[], int t);

int main()
{
    Cola vac[50];
    inicializar(vac, 50);
    cargar_cant_vac(vac);
    empleados_postulados(vac);
    listar_postulados(vac, 50);

    return 0;
}

void inicializar(Cola v[], int t)
{
    for(int i=0; i<t; i++)
    {
        v[i].pri=NULL;
        v[i].ult=NULL;
        v[i].cant_vac = 0;
    }
}

void cargar_cant_vac(Cola v[])
{
    FILE* f = fopen("Vacantes.dat", "rb");
    if(f==NULL)
        cout <<"Error."<<endl;
    else
    {
        Vacante vac;
        fread(&vac, sizeof(Vacante), 1, f);
        while(!feof(f))
        {
            v[vac.cod_dep-1].cant_vac = vac.cant_vac;
            fread(&vac, sizeof(Vacante), 1, f);
        }
    }
    fclose(f);
}

void encolar(NodoCola *&pri, NodoCola *&ult, Empleado emp)
{
    NodoCola*p = new NodoCola;
    p->info = emp;
    p->sig = NULL;
    if(ult!=NULL)
        ult->sig = p;
    else
        pri = p;
    ult=p;
}

Empleado deseconlar(NodoCola *&pri, NodoCola *&ult)
{
    Empleado emp;
    NodoCola *p;
    p = pri;
    emp = p->info;
    pri = p->sig;
    delete p;
    if(pri == NULL) 
        ult = NULL;
    return emp;
}

void empleados_postulados(Cola v[])
{
    FILE*f = fopen("Postulantes.dat", "rb");
    if(f == NULL)
        cout <<"Error."<<endl;
    else
    {
        FILE*f2 = fopen("Empleados.dat", "rb");
        if(f2 == NULL)
            cout<<"Error."<<endl;
        else
        {
            Postulante pos;
            Empleado emp;
            fread(&pos, sizeof(Postulante), 1, f);
            while(!feof(f))
            {
                emp = buscar_empleado(pos.leg, f2); //hay que buscar en el archivo de empleados para tener todos los datos y encolarlo en el vector
                encolar(v[emp.cod_dep-1].pri, v[emp.cod_dep-1].ult, emp);
                fread(&pos, sizeof(Postulante), 1, f);
            }
        }
        fclose(f2);
    }
    fclose(f);
}

void listar_postulados(Cola v[], int t)
{
    Empleado emp;
    FILE*f = fopen("Empleados.dat", "rb+");
    if(f==NULL)
        cout<<"Error"<<endl;
    else
    {
        for(int i=0; i<t; i++)
        {
            if(v[i].pri != NULL)
                cout<<"Codigo de departamento: "<<i+1<<endl<<endl;
            while(v[i].pri!=NULL && v[i].cant_vac>0)
            {
                emp = deseconlar(v[i].pri, v[i].ult);
                //Mostrar empleado desencolado
                cout<<"Legajo: "<<emp.leg<<endl
                <<"Nombre: "<<emp.nombre<<endl
                <<"DNI: "<<emp.DNI<<endl<<endl;

                //Disminuir la cant de vacantes disponibles
                v[i].cant_vac-1;

                //Actualizar el archivo de Empleados con los nuevos departamentos asignados
                emp = buscar_empleado(emp.leg, f);
                emp.cod_dep = i+1;
                fseek(f, -sizeof(Empleado), SEEK_CUR); //retroceder un lugar el puntero
                fwrite(&emp, sizeof(Empleado), 1, f);
                
            }
            while(v[i].pri!=NULL) //muestra los que quedaron sin actualizar
            {
                emp = deseconlar(v[i].pri, v[i].ult);
                cout<<"Legajo: "<<emp.leg<<endl
                <<"Nombre: "<<emp.nombre<<endl
                <<"DNI: "<<emp.DNI<<endl<<endl;
            }
        }
    }
    fclose(f);
}

Empleado buscar_empleado(int leg, FILE*f)
{
    Empleado emp;
    fread(&emp, sizeof(Empleado), 1, f);
    while(!feof(f) && emp.leg != leg)
        fread(&emp, sizeof(Empleado), 1, f);

    return emp;
}