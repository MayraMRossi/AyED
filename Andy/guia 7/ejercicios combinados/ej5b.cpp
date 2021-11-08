#include <iostream>
using namespace std;

struct DatoArchivo
{
    int cod, nro_cuota_pagada;
};

struct Cliente
{
    int cod;
    bool cuotas[12];
};

struct Nodo
{
    Cliente info;
    Nodo*sig;
};

void crear_arch_cobranzas();
int validar_dato(int desde, int hasta);
void mostrar_archivo();
void inicializar(bool v[], int t);
Nodo* buscarInsertar(Nodo*&lista, int cod);
void mostrar_deudas(Nodo*lista);
bool adeuda(bool v[], int t);
void archivo_a_lista(Nodo*&lista);

int main()
{
    Nodo*lista = NULL;
    archivo_a_lista(lista);
    mostrar_deudas(lista);
}

void crear_arch_cobranzas()
{
    FILE* f = fopen("Cobranzas.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        DatoArchivo da;
        cout<<"Cargando archivo de cobranzas:"<<endl<<endl;
        cout<<"Codigo de cliente: ";
        cin>>da.cod;
        while(da.cod != 0)
        {
            cout<<"Nro de cuota: ";
            da.nro_cuota_pagada = validar_dato(1, 12);
            fwrite(&da, sizeof(DatoArchivo), 1, f);
            cout<<"Codigo de cliente: ";
            cin>>da.cod;
        }
    }
    fclose(f);
}

int validar_dato(int desde, int hasta)
{
    int n;
    cin>>n;
    do
    {
        cin>>n;
    } while(n<desde || n>hasta);

    return n;
}

void mostrar_archivo()
{
    FILE*f = fopen("Cobranzas.dat", "rb");
    if(f!=NULL)
    {
        DatoArchivo da;
        fread(&da, sizeof(DatoArchivo), 1, f);
        while(!feof(f))
        {
            cout<<da.cod<<" - "<<da.nro_cuota_pagada<<endl;
            fread(&da, sizeof(DatoArchivo), 1, f);
        }
    }
    fclose(f);
}

void archivo_a_lista(Nodo*&lista)
{
    FILE* f = fopen("Cobranzas.dat", "rb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        DatoArchivo da;
        Cliente cli;
        Nodo*p;

        fread(&da, sizeof(DatoArchivo), 1, f);
        while(!feof(f))
        {
            p = buscarInsertar(lista, da.cod);

            p->info.cuotas[da.nro_cuota_pagada-1] = true;

            fread(&da, sizeof(DatoArchivo), 1, f);
        }
    }   
    fclose(f);
}

void inicializar(bool v[], int t)
{
    for(int i=0; i<t; i++)
        v[i] = false;
}

Nodo* buscarInsertar(Nodo*&lista, int cod)
{
    Nodo *l=lista, *ant;
    while(l!=NULL &&l->info.cod < cod)
    {
        ant = l;
        l = l->sig;
    }
    if(l == NULL || l->info.cod != cod)
    {
        Nodo *n = new Nodo;
        n->info.cod = cod;
        inicializar(n->info.cuotas, 12);
        n->sig = l;
        if(l!=lista)
            ant->sig = n;
        else
            lista = n;
    }
    else
        return l;
}

void mostrar_deudas(Nodo*lista)
{
    Nodo*l=lista;
    cout<<"Clientes que adeudan: "<<endl<<endl;
    while(l!=NULL)
    {
        if(adeuda(l->info.cuotas, 12))
            cout<<l->info.cod<<endl;
        l=l->sig;
    }
}

bool adeuda(bool v[], int t)
{
    bool debe=false;
    for(int i=0; i<t; i++)
    {
        if(v[i]==false)
            debe=true;
    }
    return debe;
}