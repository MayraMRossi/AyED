#include <iostream>
#include <string.h>
using namespace std;

struct DatoArch
{
    char patente[7];
    int fecha_infraccion;
    int cod_infraccion;
};

struct Nodo 
{
    char info[7]; //patentes
    Nodo*sig;
};

int validar_dato(int desde, int hasta);
void crear_archivo();
void inicializar(Nodo*v[], int t);
void insertar(Nodo*&lista, char patente[7]);
void listar(Nodo*lista);
void listado_infracciones_repetidas(Nodo*inf[], int t);
void mostrarLista(Nodo*inf[], int t);
void archivo_a_lista(Nodo*inf[]);

int main()
{
    Nodo*inf[100];
    inicializar(inf, 100);
    archivo_a_lista(inf);
    listado_infracciones_repetidas(inf, 100);

    return 0;
}

void inicializar(Nodo*v[], int t)
{
    for(int i=0; i<t; i++)
        v[i]=NULL;
}

int validar_dato(int desde, int hasta)
{
    int n;
    cin>>n;
    while(n<desde || n>hasta)
    {
        cin>>n;
    }

    return n;
}

void crear_archivo()
{
    FILE* f = fopen("Infracciones.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        DatoArch da;
        cout<<"Cargando archivo de infracciones:"<<endl<<endl;
        cout<<"Codigo infraccion: ";
        da.cod_infraccion = validar_dato(0, 100);
        while(da.cod_infraccion != 0)
        {
            cout<<"Fecha infraccion: ";
            cin>>da.fecha_infraccion;
            cout<<"Patente: ";
            cin>>da.patente;
            fwrite(&da, sizeof(DatoArch), 1, f);

            cout<<"Codigo infraccion: ";
            da.cod_infraccion = validar_dato(0, 100);
        }
    }
    fclose(f);
}

void archivo_a_lista(Nodo*inf[])
{
    FILE*f = fopen("Infracciones.dat", "rb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        DatoArch da;
        Nodo*p;
        fread(&da, sizeof(DatoArch), 1, f);
        while(!feof(f))
        {
            insertar(inf[da.cod_infraccion-1], da.patente);

            fread(&da, sizeof(DatoArch), 1, f);
        }
    }
    fclose(f);
}

void insertar(Nodo*&lista, char patente[7])
{
    Nodo *n=new Nodo, *l=lista, *ant;
    strcpy(n->info, patente);
    while(l!=NULL && strcmp(l->info, patente)<0)
    {
        ant=l;
        l= l->sig;
    }
    n->sig = l;
    if(l!=lista)
        ant->sig = n;
    else
        lista = n;

}

void listado_infracciones_repetidas(Nodo*inf[], int t)
{
    int cont;
    char c[7];
    cout<<"Listado de infracciones cometidas mas de una vez: "<<endl<<endl;
    for(int i=0; i<t; i++)
    {
        if(inf[i]!=NULL)
        {
            strcpy(c, inf[i]->info);
            cont=0;
            cout<<"Codigo "<<i+1<<endl;
            do 
            {
                cont++;
                inf[i]=inf[i]->sig;
            } while(inf[i]!=NULL && strcmp(c, inf[i]->info)==0);

            if(cont>1)
                cout<<"Patente: "<<c<<endl;
        }
    }
}

void mostrarLista(Nodo*inf[], int t)
{
    for(int i=0; i<t; i++)
    {
        if(inf[i]!=NULL)
        {
            cout<<"Codigo infraccion: "<<i+1<<endl;
            listar(inf[i]);
            cout<<endl<<endl;
        }
    }
}

void listar(Nodo*lista)
{
    while(lista != NULL)
    {
        cout<<lista->info<<endl;
        lista = lista->sig;
    }
}