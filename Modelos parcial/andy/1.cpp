/*
Voy a utilizar una lista de creditos  que contenga  el codigo, la descripcion y el cupo del credito correspondiente,
asi como una sublista de personas que solicitan ese credito. 
Utilizo esta estructura de datos ya que no tengo una cantidad fija de creditos, y tampoco de personas que solicitan los creditos.
*/

#include <iostream>
#include <string.h>
using namespace std;

struct DatoArch
{
    int dni;
    char nombre[20];
    int cod_credito;
    float ingreso_prom;
};

struct Solicitante
{
    int dni;
    char nombre[20];
    float ingreso_prom;
};

struct NodoSub
{
    Solicitante info;
    NodoSub *sig;
};

struct Credito
{
    int cod_credito;
    char desc[30];
    int cupo; //cant max de creditos a otorgar
    NodoSub *lista_solicitantes;
};

struct Nodo
{
    Credito info;
    Nodo *sig;
};

void ingresarCreditos(Nodo*&lista);
void organizarInscriptos(Nodo*&lista);
void mostrarListado(Nodo*lista);
void insertar(Nodo*&lista, Credito c);
Nodo* buscar(Nodo*lista, int cod);
void insertarSub(NodoSub*&lista, Solicitante Sol);
void cargarArch();
void leerArch();

int main()
{
    //cargarArch();
    //leerArch();
    
    Nodo *lista_creditos = NULL;
    ingresarCreditos(lista_creditos);
    cout<<endl;
    organizarInscriptos(lista_creditos);
    cout<<endl;
    mostrarListado(lista_creditos);
    

    return 0;
}

void ingresarCreditos(Nodo*&lista)
{
    Credito c;
    cout<<"Codigo de credito: ";
    cin>>c.cod_credito;
    while(c.cod_credito!=0)
    {
        cout<<"Descripcion: ";
        cin>>c.desc;
        cout<<"Cupo: ";
        cin>>c.cupo;
        insertar(lista, c); //ordenado por cod_credito
        cout<<"Codigo de credito: ";
        cin>>c.cod_credito;
    }
}

void organizarInscriptos(Nodo*&lista)
{
    FILE*f = fopen("Inscriptos.dat", "rb");
    if(f!=NULL)
    {
        DatoArch da;
        Solicitante sol;
        fread(&da, sizeof(DatoArch), 1, f);
        while(!feof(f))
        {
            Nodo *p = buscar(lista, da.cod_credito); //busca por cod_credito
            if(p!=NULL) //si lo encontro
            {
                sol.dni = da.dni;
                strcpy(sol.nombre, da.nombre);
                sol.ingreso_prom = da.ingreso_prom;
                insertarSub(p->info.lista_solicitantes, sol); //ordenado de mayor a menor sueldo
            }
            fread(&da, sizeof(DatoArch), 1, f);
        }
    }
    fclose(f);
}

void mostrarListado(Nodo*lista)
{
    while(lista!=NULL)
    {
        cout<<"Credito: "<<lista->info.cod_credito<<endl;
        cout<<"Solicitantes: "<<endl<<endl;
        int i=0;
        NodoSub *p = lista->info.lista_solicitantes;
        while(p!=NULL && i<lista->info.cupo)
        {
            cout<<"Dni: "<<p->info.dni<<endl<<
            "Nombre: "<<p->info.nombre<<endl<<endl;
            i++;
            p=p->sig;
        }
        lista=lista->sig;
    }
}

void insertar(Nodo*&lista, Credito c)
{
    Nodo *l=lista, *ant, *n=new Nodo;
    while(l!=NULL && l->info.cod_credito<c.cod_credito)
    {
        ant=l;
        l=l->sig;
    }
    n->info=c;
    n->sig=l;
    if(l!=lista)
        ant->sig=n;
    else
        lista=n;
}

Nodo* buscar(Nodo*lista, int cod)
{
    Nodo *l=lista, *ant;
    while(l!=NULL && l->info.cod_credito!=cod)
        l=l->sig;
    return l;
}

void insertarSub(NodoSub*&lista, Solicitante sol)
{
    NodoSub *l=lista, *ant, *n=new NodoSub;
    while(l!=NULL && l->info.ingreso_prom > sol.ingreso_prom)
    {
        ant=l;
        l=l->sig;
    }
    n->info=sol;
    n->sig=l;
    if(l!=lista)
        ant->sig=n;
    else
        lista=n;
}

void cargarArch()
{
    FILE*f = fopen("Inscriptos.dat", "wb");
    if(f!=NULL)
    {
        DatoArch da;
        cout<<"Dni: ";
        cin>>da.dni;
        while(da.dni!=0)
        {
            cout<<"Nombre: ";
            cin>>da.nombre;
            cout<<"Cod_Credito: ";
            cin>>da.cod_credito;
            cout<<"Ingreso promedio: ";
            cin>>da.ingreso_prom;
            fwrite(&da, sizeof(DatoArch), 1, f);
            cout<<"Dni: ";
            cin>>da.dni;
        }
    }
    fclose(f);
}

void leerArch()
{
    FILE*f = fopen("Inscriptos.dat","rb");
    if(f!=NULL)
    {
        DatoArch da;
        fread(&da, sizeof(DatoArch), 1, f);
        while(!feof(f))
        {
            cout<<"Dni: "<<da.dni<<" - Nombre: "<<da.nombre<<" - Cod: "<<da.cod_credito<<" - Ingreso prom: "<<da.ingreso_prom<<endl;
            fread(&da, sizeof(DatoArch), 1, f);
        }
    }
    fclose(f);
}