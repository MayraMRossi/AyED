#include <iostream>


using namespace std;

//Dados los legajos y sueldos de los empleados de una empresa que,
//como máximo tiene 100  empleados,
//se pide mostrar los legajos de los empleados que tienen el mayor sueldo.
//El ingreso de datos finaliza con legajo cero.
//1)Los legajos son números entre 1 y 100
//Además mostrar legajo y sueldo de cada empleado ORDENADO POR LEGAJO
//AGREGADO 1: Ingresar un legajo, informar su sueldo
//AGREGADO 2: verificar en la carga que el legajo no hay sido previamente ingresado

void cargarDatos(int v[]);
int ingresarVal(int d, int h);
void inicializar(int v[],int n);
void mostrar(int v[],int tam);
int mayor(int v[],int t);
void mostrarMS(int v[],int tam,int m);
void mostrarMS(int v[],int t);
int mayor(int v[],int t,int pos[],int &j);


int main()
{
    int sueldos[100];
    inicializar(sueldos,100);
    cargarDatos(sueldos);
    //mostrar(sueldos,100);
    int mayorSueldo=mayor(sueldos,100);
    if(mayorSueldo==-1)
        cout<<"No hay empleados"<<endl;
    else
    {
        mostrar(sueldos,100);
        cout<<endl<<"Legajos con mayor sueldo "<<mayorSueldo<<endl;
        mostrarMS(sueldos,100,mayorSueldo);
    }
    int vecPos[100],tamVP;
    mayorSueldo=mayor(sueldos,100,vecPos,tamVP);
    if(mayorSueldo==-1)
        cout<<"No hay empleados"<<endl;
    else
    {
        mostrar(sueldos,100);
        cout<<endl<<"Legajos con mayor sueldo "<<mayorSueldo<<endl;
        mostrarMS(vecPos,tamVP);

        //AGREGADO1
        int unLeg;
        cout<<endl<<"Ingresar legajo para mostrar sueldo ";
        //cin>>unLeg;
        unLeg=ingresarVal(1,100);
        //if((unLeg<1 || unLeg>100)||v[unLeg-1]==0)
        if(sueldos[unLeg-1]==0)
            cout<<"No existe un empleado con ese legajo"<<endl;
        else
            cout<<"el sueldo de "<<unLeg<<" es "<<sueldos[unLeg-1]<<endl;

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
        if(v[leg-1]==0)
        {
            cout<<"Sueldo"<<endl;
            cin>>v[leg-1];
        }
        else
             cout<<"Ese legajo ya fue ingresado"<<endl;
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


int mayor(int v[],int t) //ignora ceros
{
    int may=-1;
    bool pri=true;
    for(int i=0;i<t;i++)
    {
        if(v[i]!=0)
        {
            if(pri || v[i]>may)
            {
                may=v[i];
                pri=false;
            }
        }
    }
    return may;
}
int mayor(int v[],int t,int pos[],int &j)
{ //ignorar ceros
    int may=-1;
    bool pri=true;
    for(int i=0;i<t;i++)
    {
        if(v[i]!=0)
        {
            if(pri || v[i]>may)
            {
                pri=false;
                may=v[i];
                j=0;
                pos[j]=i;
                j++;
            }
            else
            {
                if(v[i]==may)
                {
                    pos[j]=i;
                    j++;
                }
            }
        }
    }
    return may;
}


void mostrarMS(int v[],int tam,int m)
{
    for(int i=0;i<tam;i++)
    {
        if(v[i]==m)
            cout<<i+1<<endl;
    }

}
void mostrarMS(int v[],int t)
{
    for(int i=0;i<t;i++)
        cout<<v[i]+1<<endl;
}

