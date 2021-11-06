#include <iostream>


using namespace std;

//Dados los legajos y sueldos de los empleados de una empresa que,
//como máximo tiene 100  empleados,
//se pide mostrar los legajos de los empleados que tienen el mayor sueldo.
//El ingreso de datos finaliza con legajo cero.
//2)Los legajos son números no correlativos de 4 dígitos (entre 1000 y 9999)
//Además mostrar legajo y sueldo de cada empleado

int cargarDatos(int vl[],int vs[],int cme);
void mostrar(int vl[],int vs[],int t);
int mayor(int v[],int t);
void mostrarLegMS(int vl[],int vs[],int t,int m);
int mayor(int v[],int t,int pos[],int &j);

int main()
{
    int legajos[100],sueldos[100];
    int cant=cargarDatos(legajos,sueldos,100);
    if(cant==0)
        cout<<"No se ingresaron empleados"<<endl;
    else
    {
        mostrar(legajos,sueldos,cant);
        /*
        int mayorSueldo=mayor(sueldos,cant);
        cout<<endl<<"Legajos de los empleados con el mayor sueldo: "<<mayorSueldo<<endl;
        mostrarLegMS(legajos,sueldos,cant,mayorSueldo);
        */
        int vecPos[cant],tamVecPos;
        int mayorSueldo=mayor(sueldos,cant,vecPos,tamVecPos);
        cout<<endl<<"Legajos de los empleados con el mayor sueldo: "<<mayorSueldo<<endl;
        mostrarLegMS(legajos,vecPos,tamVecPos);
    }
    return 0;
}

int cargarDatos(int vl[],int vs[],int cme)
{
    int leg,i=0;
    cout<<"Legajo (0 para finalizar) ";
    cin>>leg;
    while(leg!=0 && i<cme)
    {
        vl[i]=leg;
        cout<<"Sueldo: ";
        cin>>vs[i];
        i++;
        cout<<"Legajo (0 para finalizar) ";
        cin>>leg;
    }
    return i;
}

void mostrar(int vl[],int vs[],int t)
{
    for(int i=0;i<t;i++)
        cout<<"Legajo: "<<vl[i]<<" Sueldo: "<<vs[i]<<endl;
}

int mayor(int v[],int t)
{
    int m=v[0];
    for(int i=1;i<t;i++)
        if(v[i]>m)
            m=v[i];
    return m;
}

void mostrarLegMS(int vl[],int vs[],int t,int m)
{
    for(int i=0;i<t;i++)
    {
        if(vs[i]==m)
            cout<<vl[i]<<endl;
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

void mostrarLegMS(int vl[],int vp[],int tp)
{
    //int pos;
    for(int i=0;i<tp;i++)
    {
        //pos=vp[i];
        //cout<<vl[pos]<<endl;
        cout<<vl[vp[i]]<<endl;
    }


}
