// Rehacer usando sublistas

#include <iostream>
using namespace std;

struct Ventas
{
    int nro_fac;
    int cod_ven;
    float importe;
};

struct Nodo
{
    Ventas info;
    Nodo*sig;
};

void crear_ventas();
void insertar(Nodo*&lista, Ventas v);
void cargar_archivo(Nodo*&lista);
void generar_nuevo(Nodo*lista);

int main()
{
    crear_ventas();
    Nodo* lista_ventas = NULL;
    cargar_archivo(lista_ventas);
    generar_nuevo(lista_ventas);
}

void crear_ventas()
{
    FILE* f = fopen("VENTAS.dat", "wb");
    if(f != NULL)
    {
        Ventas v;
        cout<<"Nro Factura: ";
        cin>>v.nro_fac;
        while(v.nro_fac != 0)
        {
            cout<<"Cod Vendedor: ";
            cin>>v.cod_ven;
            cout<<"Importe: ";
            cin>>v.importe;
            fwrite(&v, sizeof(Ventas), 1, f);
            cout<<"Nro Factura: ";
            cin>>v.nro_fac;
        }
    }
    fclose(f);
}

void insertar(Nodo*&lista, Ventas v)
{
    Nodo*n, *l, *ant;
    n = new Nodo;
    l = lista;
    while(l!=NULL && l->info.nro_fac < v.nro_fac)
    {
        ant = l;
        l = l->sig;
    }
    while(l!=NULL && l->info.nro_fac == v.nro_fac && l->info.importe > v.importe)
    {
        ant = l;
        l = l->sig;
    }
    n->sig = l;
    if(l != lista)
        ant->sig = n;
    else
        lista = n;
}

void cargar_archivo(Nodo*&lista)
{
    FILE* f = fopen("VENTAS.dat", "rb");
    if(f != NULL)
    {
        Ventas v;
        fread(&v, sizeof(Ventas), 1, f);
        while(!feof(f))
        {
            insertar(lista, v);
            fread(&v, sizeof(Ventas), 1, f);
        }
    }
    fclose(f);
}

void generar_nuevo(Nodo*lista) //ERROR
{
    FILE* f = fopen("VentasVendedor.dat", "wb");
    if(f != NULL)
    {
        while(lista != NULL)
        {
            fwrite(&lista->info, sizeof(Ventas), 1, f);
            cout<<"Nro Factura: "<<lista->info.nro_fac<<"  Cod ven: "<<lista->info.cod_ven<<"  Importe: "<<lista->info.importe<<endl;
            lista = lista->sig;
        }
    }
}