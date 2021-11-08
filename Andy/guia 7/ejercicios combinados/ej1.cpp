#include <iostream>
using namespace std;

struct Construccion
{
    int cod_obra, fecha;
    float importe;
};

struct Nodo
{
    Construccion info;
    Nodo *sig;
};

void insertar(Nodo*&lista, Construccion con);
void mostrar_archivo();

int main()
{
    Nodo*lista_obra = NULL;
    Construccion con;
    cout<<"Codigo obra: ";
    cin>>con.cod_obra;
    while(con.cod_obra != 0)
    {
        cout<<"Fecha: ";
        cin>>con.fecha;
        cout<<"Importe: ";
        cin>>con.importe;
        insertar(lista_obra, con);
        cout<<"Codigo obra: ";
        cin>>con.cod_obra;
    }

    FILE*f = fopen("Construccion.dat", "wb");
    if(f!=NULL)
    {
        while(lista_obra != NULL)
        {
            con = lista_obra->info;
            fwrite(&con, sizeof(Construccion), 1, f);
            lista_obra = lista_obra->sig;
        }
    }
    fclose(f);

    mostrar_archivo();
}

void insertar(Nodo*&lista, Construccion con)
{
    Nodo*n, *l, *ant;
    n = new Nodo;
    n->info = con;
    l = lista;
    while(l != NULL && l->info.cod_obra < con.cod_obra)
    {
        ant = l;
        l = l->sig;
    }
    while(l != NULL && l->info.cod_obra == con.cod_obra && l->info.fecha < con.fecha)
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

void mostrar_archivo()
{
    FILE* f = fopen("Construccion.dat", "rb");
    if(f!=NULL)
    {
        Construccion con;
        fread(&con, sizeof(Construccion), 1, f);
        while(!feof(f))
        {
            cout<<"Cod: "<<con.cod_obra<<" | "<<"Fecha: "<<con.fecha<<" | "<<"Importe: " << con.importe<<endl;
            fread(&con, sizeof(Construccion), 1, f);
        }
    }
    fclose(f);
}

