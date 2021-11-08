// ERROR: termina de cargar los datos del primer archivo y se cierra

#include <iostream>
using namespace std;

struct Ventas
{
    int nro_fac;
    float importe;
};

struct NodoSub
{
    Ventas info;
    NodoSub*sig;
};

struct Vendedor
{
    int cod_ven;
    NodoSub*listaVentas;
};

struct Nodo
{
    Vendedor info; 
    Nodo*sig;
};

struct DatoArchivo
{
    int nro_fac;
    float importe;
    int cod_ven;
};

struct DatoArchivoVendedor
{
    int cod_ven;
    float importeTotal;
};

void crear_ventas();
Nodo*buscarInsertar(Nodo*&lista, int cod_ven);
void insertar(NodoSub*&lista, Ventas v);
void mostrarArchivo();
void crearListaOrdenada(Nodo*&lista);
void mostrarLista(Nodo*lista);

int main()
{
    Nodo*lista = NULL;
    //crear_ventas();
    crearListaOrdenada(lista);
    mostrarLista(lista);
    mostrarArchivo();
}

void crear_ventas()
{
    FILE* f = fopen("VENTAS.dat", "wb");
    if(f != NULL)
    {
        DatoArchivo v;
        cout<<"Nro Factura: ";
        cin>>v.nro_fac;
        while(v.nro_fac != 0)
        {
            cout<<"Cod Vendedor: ";
            cin>>v.cod_ven;
            cout<<"Importe: ";
            cin>>v.importe;
            fwrite(&v, sizeof(DatoArchivo), 1, f);
            cout<<"Nro Factura: ";
            cin>>v.nro_fac;
        }
    }
    fclose(f);
}

Nodo*buscarInsertar(Nodo*&lista, int cod_ven)
{
    Nodo *l, *ant;
    l = lista;
    while(l!=NULL && l->info.cod_ven < cod_ven)
    {
        ant = l;
        l = l->sig;
    }
    if(l==NULL || l->info.cod_ven != cod_ven)
    {
        Nodo *n = new Nodo;
        n->info.cod_ven = cod_ven;
        n->sig = l;
        n->info.listaVentas = NULL;
        if(l!=lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
    else
        return l;
}

void insertar(NodoSub*&lista, Ventas v)
{
    NodoSub *n, *l,*ant;
    n = new NodoSub;
    n->info = v;
    l = lista;
    while(l!=NULL && l->info.importe > v.importe)
    {
        ant = l;
        l = l->sig;
    }
    n->sig = l;
    if(l!=lista)
        ant->sig = n;
    else
        lista = n;
}

void crearListaOrdenada(Nodo*&lista)
{
    FILE*f = fopen("VENTAS.dat", "rb");
    if(f==NULL)
        cout<<"Error."<<endl;
    else
    {
        DatoArchivo d;
        Vendedor vende;
        Ventas v;
        Nodo*p;
        fread(&d, sizeof(DatoArchivo), 1, f);
        while(!feof(f))
        {
            vende.listaVentas = NULL;
            p = buscarInsertar(lista, d.cod_ven);

            v.nro_fac = d.nro_fac;
            v.importe = d.importe;

            insertar(p->info.listaVentas, v);

            fread(&d, sizeof(DatoArchivo), 1, f);
        }
    }
    fclose(f);
}

void mostrarLista(Nodo*lista)
{
    NodoSub*p;
    FILE*f = fopen("VentasVendedor.dat", "wb");
    if(f!=NULL)
    {
        DatoArchivoVendedor d;
        float suma;
        while(lista!=NULL)
        {
            suma=0;
            p = lista->info.listaVentas;
            while(p != NULL)
            {
                cout<<"Cod vendedor: "<<lista->info.cod_ven<<"  Nro Factura: "<<p->info.nro_fac<<"  Importe: "<<p->info.importe<<endl;
                suma+=p->info.importe;
                p=p->sig;
            }

            d.cod_ven = lista->info.cod_ven;
            d.importeTotal = suma;
            fwrite(&d, sizeof(DatoArchivoVendedor), 1, f);

            lista = lista->sig;
        }
    }
    fclose(f);
}

void mostrarArchivo() // no anda
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