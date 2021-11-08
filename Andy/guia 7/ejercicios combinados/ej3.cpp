#include <iostream>
using namespace std;

struct DatoArch
{
    int nro_fac;
    int cod_ven;
    float importe;
};

struct Ventas
{
    int nro_fac;
    float importe;
};

struct Nodo
{
    Ventas info;
    Nodo*sig;
};

struct DatoArchivoVendedor
{
    int cod_ven;
    float importeTotal;
};

void cargarVector(Nodo* ven[]);
void insertar(Nodo*&lista, Ventas v);
void mostrarLista(Nodo*ven[]);
void mostrarArchivo();
void inicializar(Nodo* ven[]);
void crear_ventas();

int main()
{
    Nodo* ven[10];
    inicializar(ven);
    crear_ventas();
    cargarVector(ven);
    mostrarLista(ven);
    mostrarArchivo();
}

void crear_ventas()
{
    FILE* f = fopen("VENTAS.dat", "wb");
    if(f != NULL)
    {
        DatoArch d;
        cout<<"Nro Factura: ";
        cin>>d.nro_fac;
        while(d.nro_fac != 0)
        {
            cout<<"Cod Vendedor: ";
            cin>>d.cod_ven;
            cout<<"Importe: ";
            cin>>d.importe;
            fwrite(&d, sizeof(DatoArch), 1, f);
            cout<<"Nro Factura: ";
            cin>>d.nro_fac;
        }
    }
    fclose(f);
}

void cargarVector(Nodo* ven[])
{
    FILE*f = fopen("VENTAS.dat", "rb");
    if(f != NULL)
    {
        DatoArch d;
        Ventas v;
        fread(&d, sizeof(DatoArch), 1, f);
        while(!feof(f))
        {
            v.nro_fac = d.nro_fac;
            v.importe = d.importe;
            insertar(ven[d.cod_ven-1], v);
            fread(&d, sizeof(DatoArch), 1, f);
        }  
    }
    fclose(f);
}

void insertar(Nodo*&lista, Ventas v)
{
    Nodo *n, *l, *ant;
    l=lista;
    n = new Nodo;
    n->info = v;
    while(l!=NULL && l->info.importe > v.importe)
    {
        ant=l;
        l=l->sig;
    }
    n->sig=l;
    if(l!=lista)
        ant->sig=n;
    else
        lista=n;
}

void mostrarLista(Nodo*ven[])
{
    Nodo*p;
    FILE*f = fopen("VentasVendedor.dat", "wb");
    if(f!=NULL)
    {
        DatoArchivoVendedor d;
        float suma;
        for(int i=0; i<10; i++)
        {
            suma=0;
            p=ven[i];
            while(p != NULL)
            {
                cout<<"Cod vendedor: "<<i+1<<"  Nro Factura: "<<p->info.nro_fac<<"  Importe: "<<p->info.importe<<endl;
                suma+=p->info.importe;
                p=p->sig;
            }

            d.cod_ven = i+1;
            d.importeTotal = suma;
            fwrite(&d, sizeof(DatoArchivoVendedor), 1, f);
        }
    }
    fclose(f);
}

void inicializar(Nodo* ven[])
{
    for(int i=0; i<10; i++)
        ven[i]=NULL;
}

void mostrarArchivo()
{
    FILE*f = fopen("VentasVendedor.dat", "rb");
    if(f==NULL)
        cout<<"Error."<<endl;
    else
    {
        DatoArchivoVendedor d;
        fread(&d, sizeof(DatoArchivoVendedor), 1, f);
        while(!feof(f))
        {
            cout<<"Cod vendedor: "<<d.cod_ven<<"  Importe: "<<d.importeTotal<<endl;
            fread(&d, sizeof(DatoArchivoVendedor), 1, f);
        }
    }
    fclose(f);
}