#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Fecha
{
    unsigned dia;
    unsigned mes;
    unsigned anio;
};

struct Aplic
{
    int dni;
    int edad;
    Fecha fecha;
    char vacuna[15];
    int dosis; //1 o 2 validado con una funcion al momnto del ingreso
    int centro;
};

struct NodoAplic{
    PersonaAplic info;
    NodoPersApli sig;
}

struct Menor
{
    int dni;
    Fecha fecha_1;
    int centro_1;
    Fecha fecha_2;
    int centro_2;
}

struct NodoMenor
{
    PersonaNuevo info;
    NodoPersona sig;
}


void cargarMenores ()
{
        lis1 = cargar_lis1();
        cargar_lis2(lis1);
}

NodoAplic *cargar_lis1()
{
 FILE*f;
    f = fopen("Aplicaciones.dat", "rb");
    if(f != NULL)
    {
        Aplic pers_lis,pers_arch;

        fread(&pers_arch, sizeof(Aplic), 1, f);
        if(pers_arch.edad>18)
        {
            pers_lis=pers_arch;
            NodoAplic *lis1 = NULL;
            insertar(lis1,pers_lis);
        }       
           
        while(!feof(f))
        {
            fread(&pers_arch, sizeof(Aplic), 1, f);
            if(pers_arch.edad>18)
            {
                pers_lis=pers_arch;
                insertar(lis1,pers_lis);
            } 
        }
    }
    else  
    {
        cout<<"Error."<<endl;
    }
    fclose(f);

    return lis1;

}

void cargar_lis2(NodoAplic *lista)
{
    NodoAplic *lis1,pers;
    NodoMenor *lis2 = NULL;

    insertar2 (lis1,lis2);
    lis1=lis1->sig;

    while(lis1->sig != NULL && lis1.dosis>2)
    {
        insertar2 (lis1,lis2);
        lis1=lis1->sig;
    }
    completar(lis2);


}


void insertar(NodoAplic*&lista,Aplic pers)
{
    NodoAplic *n,*r,*ant;
    n=new NodoAplic;
    n->info=pers;
    r=lista;
    while(r!=NULL && r->info.dosis>pers.dosis) //ordeno esta nueva lista de mayor a menor (1ero dosis 2 y luego dosis 1)
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

void insertar2(NodoAplic*lista1,NodoMenor*&lista2)
{
    NodoMenor *n,*r,*ant;
    n=new NodoAplic = NULL;


        n->info->dni=lista1->info->dni;
        n->info->fecha2=lista1->info->fecha;
        n->info->centro2=lista1->info->centro;
        
        r=lista2;
        while(r!=NULL && r->info.dni<lista2->info->dni) //ordeno por DNI
        {
            ant=r;
            r=r->sig;
        }
        n->sig=r;
        if(r!=lista2)
            ant->sig=n;
        else
            lista2=n;
}

void completar (NodoMenor *&lista2)
{
    
}
