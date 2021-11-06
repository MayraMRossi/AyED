#include <iostream>


using namespace std;

//Dados los legajos y sueldos de los empleados de una empresa que,
//como máximo tiene 100  empleados,
//se pide mostrar los legajos de los empleados que tienen el mayor sueldo.
//El ingreso de datos finaliza con legajo cero.
//2)Los legajos son números no correlativos de 4 dígitos (entre 1000 y 9999)
//Además mostrar legajo y sueldo de cada empleado  ORDENADO POR LEGAJO
//AGREGADO 1: Ingresar un legajo, informar su sueldo
//AGREGADO 2: verificar en la carga que el legajo no hay sido previamente ingresado

int cargarDatos(int vl[],int vs[],int cme);
void mostrar(int vl[],int vs[],int t);
int mayor(int v[],int t);
int mayor(int v[],int t,int pos[],int &j);
void mostrarMS(int vl[],int vs[],int t,int m);
void mostrarMS(int vl[],int vp[],int t);
int secuencial(int v[],unsigned t,int bus);
void burbujeo(int vl[],int vs[],unsigned t);
int binaria(int v[],unsigned t,int bus);


int main()
{
    int legajos[100],sueldos[100],cant;
    cant=cargarDatos(legajos,sueldos,100);
    if(cant==0)
        cout<<"No hay empleados "<<endl;
    else
    {
        burbujeo(legajos,sueldos,cant); //para mostrar ordenado por legajo

        mostrar(legajos,sueldos,cant);
        int mayorSueldo=mayor(sueldos,cant);
        cout<<endl<<"Legajos con mayor sueldo "<<mayorSueldo<<endl;
        mostrarMS(legajos,sueldos,cant,mayorSueldo);

        //USANDO VECTOR DE POSICIONES
        int vecPos[cant],tamVP;
        mayorSueldo=mayor(sueldos,cant,vecPos,tamVP);
        cout<<endl<<"Legajos con mayor sueldo "<<mayorSueldo<<endl;
        mostrarMS(legajos,vecPos,tamVP);

        //AGREGADO 1
        int unLeg;
        cout<<endl<<"Ingresar legajo para mostrar sueldo ";
        cin>>unLeg;
        //int p=secuencial(legajos,cant,unLeg);
        int p=binaria(legajos,cant,unLeg);
        if(p==-1)
            cout<<"No existe un empleado con ese legajo"<<endl;
        else
            cout<<"el sueldo de "<<unLeg<<" es "<<sueldos[p]<<endl;
    }
    return 0;
}

int cargarDatos(int vl[],int vs[],int cme)
{  //no carga legajos repetidos
    int leg,i=0,p;
    cout<<"Legajo (cero para finalizar) ";
    cin>>leg;
    while(leg!=0 && i<cme)
    {
       p=secuencial(vl,i,leg);
       if(p==-1)
       {
            vl[i]=leg;
            cout<<"Sueldo ";
            cin>>vs[i];
            i++;
       }
       else
            cout<<"Ya ingreso ese numero de legajo"<<endl;
        cout<<"Legajo (cero para finalizar) ";
        cin>>leg;
    }
    return i;
}

void mostrar(int vl[],int vs[],int t)
{
    for(int i=0;i<t;i++)
        cout<<"Legajo "<<vl[i]<<" sueldo "<<vs[i]<<endl;
}

int mayor(int v[],int t)
{
    int may=v[0];
    for(int i=1;i<t;i++)
    {
        if(v[i]>may)
            may=v[i];
    }
    return may;
}

void mostrarMS(int vl[],int vs[],int t,int m)
{
    for(int i=0;i<t;i++)
    {
        if(vs[i]==m)
            cout<<vl[i]<<endl;
    }
}
int mayor(int v[],int t,int pos[],int &j)
{
    int may;
    for(int i=0;i<t;i++)
    {
        if(i==0 || v[i]>may)
        {
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
    return may;
}

void mostrarMS(int vl[],int vp[],int t)
{
    //int pos;
    for(int i=0;i<t;i++)
    {
        //pos=vp[i];
        //cout<<vl[pos]<<endl;
        cout<<vl[vp[i]]<<endl;
    }

}
int secuencial(int v[],unsigned t,int bus)
{
    unsigned i=0;
    while(i<t && v[i]!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}
void burbujeo(int vl[],int vs[],unsigned t)
{
    unsigned i=1,j;
    int aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-i;j++)
        {
            if(vl[j]>vl[j+1])
            {
                aux=vl[j];
                vl[j]=vl[j+1];
                vl[j+1]=aux;

                aux=vs[j];
                vs[j]=vs[j+1];
                vs[j+1]=aux;

                cambio=true;
            }
        }
        i++;
    }while(i<t && cambio);
}

int binaria(int v[],unsigned t,int bus)
{
    int desde=0,hasta=t-1,medio;
   do
    {
        medio=(desde+hasta)/2;

        if(bus<v[medio])
                hasta=medio-1;
        else
                desde=medio+1;

    } while(desde<=hasta && v[medio]!=bus);
    if(v[medio]==bus)
        return medio;
    else
        return -1;
}
