#include <iostream>
#include <stdio.h>
using namespace std;

struct Fecha
{
    unsigned dia;
    unsigned mes;
    unsigned anio;
};
struct DatoArchivo
{
    unsigned codAct;
    unsigned nroSocio;
    Fecha fecha;
    unsigned resul;
};
struct DatoLista
{
    unsigned nroSocio;
    unsigned resul;
};
struct Nodo
{
    DatoLista info;
    Nodo*sig;
};

void inicMatriz(Nodo*m[][12]);
void insertar(Nodo*&lista,DatoLista dato);
void listar(Nodo*lista);
void cargarMatriz(FILE*a,Nodo*m[][12]);
void puntoA(Nodo*m[][12]);
void puntoB(Nodo*m[][12]);
void puntoC(Nodo*m[][12]);
int cantidad(Nodo*lista);
int cantPuesto1(Nodo*lista);

int main()
{
    FILE *arch=fopen("Competidores.dat","rb");
    if(arch!=NULL)
    {
        Nodo*matriz[15][12];
        inicMatriz(matriz);
        cargarMatriz(arch,matriz);
        fclose(arch);
        puntoA(matriz);
        puntoB(matriz);
        puntoC(matriz);

    }

    return 0;
}

void inicMatriz(Nodo*m[][12])
{
    for(int i=0;i<15;i++)
        for(int j=0;j<12;j++)
            m[i][j]=NULL;
}

void cargarMatriz(FILE*a,Nodo*m[][12])
{
    DatoArchivo reg;
    DatoLista d;
    fread(&reg,sizeof(DatoArchivo),1,a);
    while(!feof(a))
    {
        //unsigned fila=reg.codAct-1;
        //unsigned col=reg.fecha.mes-1;
        d.nroSocio=reg.nroSocio;
        d.resul=reg.resul;
        //insertar(m[fila][col],d);
        insertar(m[reg.codAct-1][reg.fecha.mes-1],d);
        fread(&reg,sizeof(DatoArchivo),1,a);
    }
}

void puntoA(Nodo*m[][12])
{
    for(int i=0;i<15;i++)
    {
        cout<<"Actividad: "<<i+1<<endl;
        for(int j=0;j<12;j++)
        {
            cout<<"Mes: "<<j+1<<endl;
            listar(m[i][j]);
        }
    }
}

void puntoB(Nodo*m[][12])
{
    for(int j=0;j<12;j++)
    {
        cout<<"Mes: "<<j+1<<endl;
        for(int i=0;i<15;i++)
        {
            cout<<"Actividad: "<<i+1<<" compitienron "<<cantidad(m[i][j])<<endl;
        }
    }
}
/*
void puntoC(Nodo*m[][12])
{
    int s;
    for(int i=0;i<15;i++)
    {
        s=0;
        for(int j=0;j<12;j++)
            s+=cantPuesto1(m[i][j]);
        if(s>1)
            cout<<i+1<<endl;
    }
}
*/

void puntoC(Nodo*m[][12])
{
    int s,j;
    for(int i=0;i<15;i++)
    {
        s=0;
        j=0;
        while(j<12 && s+cantPuesto1(m[i][j])<1)
        {
            s+=cantPuesto1(m[i][j]);
            j++;
        }
        if(j<12)
            cout<<i+1;
    }
}

void insertar(Nodo*&lista,DatoLista dato)
{
    Nodo*ant,*r=lista,*p=new Nodo;
    p->info=dato;
    while(r!=NULL && r->info.nroSocio<dato.nroSocio)
    {
        ant=r;
        r=r->sig;
    }
    if(r==lista)
        lista=p;
    else
        ant->sig=p;
    p->sig=r;
}

void listar(Nodo*lista)
{
    Nodo*r=lista;
    while(r!=NULL)
    {
        cout<<r->info.nroSocio<<"   "<<r->info.resul<<endl;
        r=r->sig;
    }
}

int cantidad(Nodo*lista)
{
    Nodo*r=lista;
    int c=0;
    while(r!=NULL)
    {
        c++;
        r=r->sig;
    }
    return c;
}

int cantPuesto1(Nodo*lista)
{
    Nodo*r=lista;
    int c=0;
    while(r!=NULL)
    {
        if(r->info.resul==1)
            c++;
        r=r->sig;
    }
    return c;
}