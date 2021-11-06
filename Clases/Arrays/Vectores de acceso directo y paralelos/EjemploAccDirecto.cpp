#include <iostream>


using namespace std;

//Dados los legajos y sueldos de los empleados de una empresa que,
//como máximo tiene 100  empleados,
//se pide mostrar los legajos de los empleados que tienen el mayor sueldo.
//El ingreso de datos finaliza con legajo cero.
//1)Los legajos son números entre 1 y 100
//Además mostrar legajo y sueldo de cada empleado

void cargarDatos(int v[]);
int ingresarVal(int d, int h);
void inicializar(int v[],int n);
void mostrar(int v[],int tam);
int mayor(int v[],int t);
void mostrarLegMS(int v[],int t,int ms);
int mayor(int v[],int t,int pos[],int &j);
void mostrarLegMS(int v[],int t);

int main()
{
    int sueldos[100];
    inicializar(sueldos,100);
    cargarDatos(sueldos);
    mostrar(sueldos,100);
    /*
    int mayorSueldo=mayor(sueldos,100);
    if(mayorSueldo==-1)
        cout<<"No se ingresaron empleados"<<endl;
    else
    {
        cout<<endl<<"Legajos de los empleados con el mayor sueldo: "<<mayorSueldo<<endl;
        mostrarLegMS(sueldos,100,mayorSueldo);
    }
    */
    int vecPos[100],tamVecPos;
    int mayorSueldo=mayor(sueldos,100,vecPos,tamVecPos);
    if(mayorSueldo==-1)
        cout<<"No se ingresaron empleados"<<endl;
    else
    {
        cout<<endl<<"Legajos de los empleados con el mayor sueldo: "<<mayorSueldo<<endl;
        mostrarLegMS(vecPos,tamVecPos);
    }
    return 0;
}

void cargarDatos(int v[])
{
    int leg;
    cout<<"Legajo (cero para finalizar)"<<endl;
    leg=ingresarVal(0,100);
    while(leg!=0)
    {
        cout<<"Sueldo ";
        cin>>v[leg-1];
        cout<<"Legajo (cero para finalizar)"<<endl;
        leg=ingresarVal(0,100);
    }
}

int ingresarVal(int d, int h)
{
    int dato;
    do
        cin>>dato;
    while(dato<d || dato>h);
    return dato;
}

void inicializar(int v[],int n)
{
    for(int i=0;i<n;i++)
        v[i]=0;
}

void mostrar(int v[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        if(v[i]!=0)
            cout<<"Legajo: "<<i+1<<" Sueldo: "<<v[i]<<endl;
    }

}
/*
int mayor(int v[],int t)
{
    int m=v[0];
    for(int i=1;i<t;i++)
        if(v[i]>m)
            m=v[i];
    return m;
}
*/

int mayor(int v[],int t)  //ignora los ceros
{
    int m;
    m=-1;
    bool pri=true;
    for(int i=0;i<t;i++)
    {
        if(v[i]!=0)
        {
            if(pri || v[i]>m)
            {
                pri=false;
                m=v[i];
            }

        }
    }
    /*
    if(pri)
        return -1;
    else
        return m;
    */
    return m;
}

void mostrarLegMS(int v[],int t,int ms)
{
    for(int i=0;i<t;i++)
    {
        if(v[i]==ms)
            cout<<i+1<<endl;
    }
}
/*
int mayor(int v[],int t,int &pos) //fuera de ejercicio
{   //devuelve el mayor único y su posición
    int m=v[0];
    pos=0;
    for(int i=1;i<t;i++)
        if(v[i]>m)
        {
            m=v[i];
            pos=i;
        }

    return m;
}

int mayor(int v[],int t,int pos[],int &j) //fuera de ejercicio
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
*/
int mayor(int v[],int t,int pos[],int &j)
{   //devuelve el mayor(sin considerar los ceros) y un vector con las posiciones
    int m=-1;
    bool pri=true;
    for(int i=0;i<t;i++)
    {
        if(v[i]!=0)
        {
            if(pri || v[i]>m)
            {
                pri=false;
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
    }

    return m;
}

void mostrarLegMS(int v[],int t)
{
    for(int i=0;i<t;i++)
        cout<<v[i]+1<<endl;
}
