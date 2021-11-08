#include <iostream>
using namespace std;

struct proyectos
{
    int cod, cantEmp;
    string nombre;
    float costo, sueldoTotal, sueldoI, sueldoA, sueldoP, sueldoT, sueldoO;
};

void inicializar(proyectos v[], unsigned t);
int cargar(proyectos v[], unsigned t);
void ingresarEmpleados(proyectos v[], unsigned t);
int busqueda(proyectos v[], unsigned t, int bus);
void sinEmpleados(proyectos v[], unsigned t);
void costos(proyectos v[], unsigned t);
void ordenar(proyectos v[], unsigned t);
char validarResp();
void cantEmpleados(proyectos v[], unsigned t);
void sueldoPorResp(proyectos v[], unsigned t);

int main()
{
    proyectos datos[100];

    int cant=cargar(datos, 100);
    inicializar(datos, cant);
    ingresarEmpleados(datos, cant);
    ordenar(datos, cant);
    cout<<endl;
    cantEmpleados(datos, cant);
    cout<<endl;
    sueldoPorResp(datos, cant);
    cout<<endl;
    costos(datos, cant);
    cout<<endl;
    sinEmpleados(datos, cant);

    return 0;
}

int cargar(proyectos v[], unsigned t)
{
    int i=0;
    cout<<"Nombre de proyecto, 'fin' para finalizar: ";
    cin>>v[i].nombre;
    while(v[i].nombre!="fin" && i<t)
    {
        cout<<"Codigo: ";
        cin>>v[i].cod;
        cout<<"Costo estimado: ";
        cin>>v[i].costo;
        i++;
        cout<<"Nombre de proyecto, 'fin' para finalizar: ";
        cin>>v[i].nombre;
    }
    return i;
}

void ingresarEmpleados(proyectos v[], unsigned t)
{
    int numLeg, codProy, pos, mayorLeg;
    string nombre, mayorNombre;
    char respons;
    float sueldo, mayorSueldo;
    bool pri=true;

    cout<<"Ingreso de info de los empleados: "<<endl<<endl;
    cout<<"Numero de legajo: ";
    cin>>numLeg;
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Responsabilidad: "<<endl<<"I-Ingeniero"<<endl<<"A-Analista"<<endl<<"P-Programador"<<endl<<"T-Testeador o probador"<<endl<<"O-Operacion)"<<endl;
    respons=validarResp();
    while(respons!='F')
    {
        cout<<"Sueldo a pagar: ";
        cin>>sueldo;
        cout<<"Codigo de proyecto: ";
        cin>>codProy;

        pos=busqueda(v, t, codProy);
        if(pos!=-1)
        {
            v[pos].cantEmp++;

            if(pri || sueldo>mayorSueldo)
            {
                mayorSueldo=sueldo;
                mayorNombre=nombre;
                mayorLeg=numLeg;
                pri=false;
            }

            v[pos].sueldoTotal+=sueldo;

            switch(respons)
            {
                case 'I':
                    v[pos].sueldoI+=sueldo;
                    break;
                case 'A':
                    v[pos].sueldoA+=sueldo;
                    break;
                case 'P':
                    v[pos].sueldoP+=sueldo;
                    break;
                case 'T':
                    v[pos].sueldoT+=sueldo;
                    break;
                case 'O':
                    v[pos].sueldoO+=sueldo;
                    break;
            }
        }

        cout<<"Numero de legajo: ";
        cin>>numLeg;
        cout<<"Nombre: ";
        cin>>nombre;
        cout<<"Responsabilidad: "<<endl<<"I-Ingeniero"<<endl<<"A-Analista"<<endl<<"P-Programador"<<endl<<"T-Testeador o probador"<<endl<<"O-Operacion)"<<endl;
        respons=validarResp();
        
    }
    cout<<endl<<"El programador con el mayor sueldo es: "<<endl;
    cout<<"Legajo: "<<mayorLeg<<"   Nombre:"<<mayorNombre<<"  Sueldo: "<<mayorSueldo<<endl;
}

void inicializar(proyectos v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        v[i].cantEmp=0;
        v[i].sueldoTotal=0;
        v[i].sueldoI=0;
        v[i].sueldoA=0;
        v[i].sueldoP=0;
        v[i].sueldoT=0;
        v[i].sueldoO=0;
    }
}

int busqueda(proyectos v[], unsigned t, int bus)
{
    int i=0;
    while(i<t && v[i].cod!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}

void costos(proyectos v[], unsigned t)
{
    cout<<"Proyectos cuyos costos totales son mayores a los estimados: "<<endl;
    for(int i=0; i<t; i++)
    {
        if(v[i].sueldoTotal>v[i].costo)
            cout<<"Codigo: "<<v[i].cod<<"   Nombre: "<<v[i].nombre<<endl;
    }
}

void sinEmpleados(proyectos v[], unsigned t)
{
    cout<<"Proyectos sin empleados asignados: "<<endl;
    for(int i=0; i<t; i++)
    {
        if(v[i].cantEmp==0)
            cout<<"Codigo: "<<v[i].cod<<"   Nombre: "<<v[i].nombre<<endl;
    }
}

void ordenar(proyectos v[], unsigned t)
{
    int i=0;
    proyectos aux;
    for(int i=1; i<t; i++)
    {
        for(int j=0; j<t-1; j++)
        {
            if(v[j].cantEmp>v[j+1].cantEmp)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

char validarResp()
{
    char r;
    do
    {
        cin>>r;
    } while (r!='I' && r!='A' && r!='P' && r!='T' && r!='O' && r!='F');
    return r;
}

void cantEmpleados(proyectos v[], unsigned t)
{
    cout<<"Cant empleados ordenados: "<<endl;
    for(int i=0; i<t; i++)
    {
        cout<<"Codigo de proyecto: "<<v[i].cod<<"  Cantidad de empleados: "<<v[i].cantEmp<<endl;
    }
}


void sueldoPorResp(proyectos v[], unsigned t)
{
    int i,j;
    for(i=0; i<t; i++)
    {
        cout<<"Codigo de Proyecto: "<<v[i].cod<<"  Nombre: "<<v[i].nombre<<endl<<"Responsabilidades:"<<endl;
        cout<<"Ingeniero: "<<v[i].sueldoI<<endl<<"Analista: "<<v[i].sueldoA<<endl<<"Programador: "<<v[i].sueldoP<<endl<<"Testeador o probador: "<<v[i].sueldoT<<endl<<"Operacion: "<<v[i].sueldoO<<endl<<endl;
    }
}
