#include <iostream>
#include <stdio.h>


using namespace std;

struct Alumno
{
    unsigned leg;
    char nom[21];
    unsigned nota;
};

struct Nodo
{
    Alumno info;
    Nodo*sig;
};

void listar(Nodo*lista);
void insertar(Nodo*&lista,Alumno alu);
Nodo*buscarInsertar(Nodo*&lista,Alumno alu);

int main()
{
    Nodo*listaK1021=NULL;
    Alumno a;
    cin>>a.leg;
    while(a.leg!=0)
    {
        cin>>a.nom;
        cin>>a.nota;
        insertar(listaK1021,a);
        cin>>a.leg;
    }
    listar(listaK1021);
    cout<<"Leg del recuperatorio ";
    cin>>a.leg;
    cout<<"nombre ";
    cin>>a.nom;
    Nodo*p=buscarInsertar(listaK1021,alu);
    int nota;
    cout<<"nota ";
    cin>>unaNota;
    p->info.nota=unaNota;
}

void listar(Nodo*lista)
{
    Nodo*r;
    r=lista;
    while(r!=NULL)
    {
        cout<<r->info.leg<<r->info.nom<<r->info.nota<<endl;
        r=r->sig;
    }
}
//buscar, insertar, buscarInsertar y eliminar.

Nodo* buscar(Nodo*lista,unsigned unLeg)
{
    Nodo*r=lista;
    while(r!=NULL && r->info.leg!=unLeg)
        r=r->sig;
    return r;
}

Nodo* buscarMejor(Nodo*lista,unsigned unLeg)
{
    Nodo*r=lista;
    while(r!=NULL && r->info.leg<unLeg)
        r=r->sig;
    if(r!=NULL && r->info.leg==unLeg)
        return r;
    else
        return NULL;
}

void insertar(Nodo*&lista,Alumno alu)
{
    Nodo *n,*r,*ant;
    n=new Nodo;
    n->info=alu;
    r=lista;
    while(r!=NULL && r->info.leg<alu.leg)
    {
        ant=r;
        r=r->sig;
    }
    n->sig=r;
    if(r!=lista)
        ant->sig=n;
    else
        lista=n;
}

Nodo*buscarInsertar(Nodo*&lista,Alumno alu)
{
    Nodo*r,*ant;
    r=lista;
    while(r!=NULL && r->info.leg<alu.leg)
    {
        ant=r;
        r=r->sig;
    }
    if(r==NULL || r->info.leg!=alu.leg)
    {
        Nodo*n=new Nodo;
        n->info=alu;
        n->sig=r;
        if(r!=lista)
            ant->sig=n;
        else
            lista=n;
        return n;
    }
    else
        return r;
}


bool eliminar(Nodo*&lista,unsigned unLeg)
{
    Nodo*r,*ant;
    r=lista;
    while(r!=NULL && r->info.leg<unLeg)
    {
        ant=r;
        r=r->sig;
    }
     if(r==NULL || r->info.leg!=unLeg)
        //cout<<"no esta ";
        return false;
     else
     {
         if(r==lista)
            lista=r->sig;
         else
            ant->sig=r->sig;
         delete r;
         return true;
     }

}

void mostrarAprobados(Nodo*lista)
{
    Nodo*r;
    r=lista;
    while(r!=NULL)
    {
        if(r->info.nota>=6)
            cout<<r->info.leg<<r->info.nom<<r->info.nota<<endl;
        r=r->sig;
    }
}

float promedioCurso(Nodo*lista)
{
    unsigned cont=0,suma=0;
    Nodo*r;
    r=lista;
    while(r!=NULL)
    {
        suma+=r->info.nota;
        cont++;
        r=r->sig;
    }
    if(cont>0)
        return (float)suma/cont;
    else
        return 0;
}

void modificarNota(Nodo*lista,unsigned unLeg,unsigned nuevaNota)
{
    Nodo*p=buscarMejor(lista,unLeg);
    if(p!=NULL)
        p->info.nota=nuevaNota;
}








