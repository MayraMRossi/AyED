#include <iostream>
using namespace std;

int cargarDatos(int vl[], int vs[], int cant);
void mostrar(int vl[], int vs[], int tam);
//void mostrarLegMax (int vl[], int vs[], int t, int max);
//int mayor(int v[], unsigned cant);
int mayor(int v[],int t,int pos[],int &j);
void mostrarLegMax (int vl[], int vpos[], int tamPos);

int main()
{
    //Los legajos son numeros no correlativos de 4 digitos (entre 1000 y 9999)
    ///Ademas mostrar legajos y sueldos de cada empleado.
    //Para esto vamos a usar 2 vectores paralelos, que estan relacionados entre si.

    int legajos[100], sueldos[100];
    int cant=cargarDatos(legajos, sueldos, 100);
    if (cant==0)
        cout<<"No se ingresaron datos.";
    else
    {
        mostrar(legajos, sueldos, cant);
        /*
        int mayorSueldo=mayor(sueldos, cant);
        cout<<"Los legajos con el sueldo maximo son: "<<endl;
        mostrarLegMax(legajos, sueldos, cant, mayorSueldo);
        */
        int vecPos[cant],tamVecPos;
        int mayorSueldo=mayor(sueldos,cant,vecPos,tamVecPos);
        cout<<endl<<"Legajos de los empleados con el mayor sueldo: "<<mayorSueldo<<endl;
        mostrarLegMax(legajos,vecPos,tamVecPos);
    }
    
    

    return 0;
}

int cargarDatos(int vl[], int vs[], int cant)
{
    int leg, i=0; i=0;
    cout<<"Ingrese legajo, cero para finalizar: ";
    cin>>leg;
    while(leg!=0 && i<cant)
    {
        vl[i]=leg;
        cout<<"Sueldo: ";
        cin>>vs[i];
        i++;

        cout<<"Ingrese legajo, cero para finalizar: ";
        cin>>leg;
    }
    return i;
}

void mostrar(int vl[], int vs[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout<<"Legajo: "<<vl[i]<<"   Sueldos: "<<vs[i]<<endl;
    }
}
/*
int mayor(int v[], unsigned cant)
{
    int max=v[0];
    for(int i=1;i<cant; i++)
        if(v[i]>max)
            max=v[i];
    return max;
}
*/
/*
void mostrarLegMax (int vl[], int vs[], int t, int max)
{
    for(int i=0; i<t; i++)
    {
        if(vs[i]==max)
            cout<<vl[i]<<endl;
    }
}
*/

void mostrarLegMax (int vl[], int vpos[], int tamPos)
{
    //int pos;
    for(int i=0; i<tamPos; i++)
    {
        //pos=vpos[i];
        //cout<<vl[pos]<<endl;
        cout<<vl[vpos[i]]<<endl;
    }
}

int mayor(int v[],int t,int pos[],int &j)
{   //devuelve el mayor y un vector con las posiciones
    int m;
    for(int i=0;i<t;i++)
    {
        if(i==0 || v[i]>m)
        {
            m=v[i];
            j=0;
            pos[j]=i;
            j++;
        }
        else
        {
            if(v[i]==m)
            {
                pos[j]=i;
                j++;
            }
        }
    }
    return m;
}