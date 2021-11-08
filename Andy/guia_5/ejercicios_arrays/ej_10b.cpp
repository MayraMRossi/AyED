#include <iostream>
using namespace std;

int cargarDatos(int vl[], int vs[], int cant);
int mayor(int vs[], int cant, int pos[], int &t);
void mostrarLegMax(int vl[], int pos[], int t);
//Agregado: hacer una busqueda de sueldos


int main()
{
    int legajos[100], sueldos[100];
    int cant=cargarDatos(legajos, sueldos, 100);
    if(cant==0)
        cout<<"No se ingresaron datos.";
    else
    {
        int vecPos[cant], tamVecPos;
        int mayorSueldo=mayor(sueldos, cant, vecPos,tamVecPos);
        cout<<endl<<"Legajos de los empleados con el mayor sueldo: "<<mayorSueldo<<endl;
        mostrarLegMax(legajos, vecPos,tamVecPos);
    }

    cout<<"Ingrese un legajo para buscar el sueldo: ";
    


    return 0;
}

int cargarDatos(int vl[], int vs[], int cant)
{
    int leg, i=0;
    cout<<"Ingrese un legajo, cero para finalizar: ";
    cin>>leg;
    while (leg!=0)
    {
        vl[i]=leg;
        cout<<"Ingrese el sueldo: ";
        cin>>vs[i];
        i++;

        cout<<"Ingrese un legajo, cero para finalizar: ";
        cin>>leg;
    }
    return i;
} 

int mayor(int vs[], int cant, int pos[], int &t)
{
    int m;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || vs[i]>m)
        {
            m=vs[i];
            t=0;
            pos[t]=i;
            t++;
        }
        else if(vs[i]==m)
        {
            pos[t]=i;
            t++;
        }
    }
    return m;
}

void mostrarLegMax(int vl[], int pos[], int t)
{
    for(int i=0; i<t; i++)
        cout<<vl[pos[i]]<<endl;
}