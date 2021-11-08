//Listas:

#include <iostream>
using namespace std;

struct Alumno
{
    unsigned leg;
    string nombre;
    unsigned nota;
};

struct Nodo
{
    Alumno info;
    Nodo *sig;
};

Nodo* buscar(Nodo* lista, unsigned leg);
Nodo* buscarMejorada(Nodo* lista, unsigned leg) ;
void modificarNota(Nodo* lista, unsigned leg, unsigned nuevaNota);
void insertar(Nodo* &lista, Alumno a);
void listar(Nodo *lista);
Nodo *buscarInsertar(Nodo* &lista, Alumno a);

int main()
{
    Nodo *lista = NULL;
    Alumno a;
    cout<<"Leg: ";
    cin>>a.leg;
    while(a.leg!=0)
    {
        cout<<"Nota: ";
        cin>>a.nota;
        insertar(lista, a);
        cout<<"Leg: ";
        cin>>a.leg;
    }
    listar(lista);
    cout<<"Nuevo leg: ";
    cin>>a.leg;
    cout<<"Nuevo nombre: ";
    cin>>a.nombre;
    Nodo *p = buscarInsertar(lista, a);
    cout<<"Nueva Nota: ";
    cin>>a.nota;
    p->info.nota = a.nota;
}

Nodo* buscar(Nodo* lista, unsigned leg) //devuelve el puntero al elemento de la lista a buscar
{
    Nodo *l = lista;
    while(l != NULL && l->info.leg != leg)
        l = l->sig;
    return l;
}

Nodo* buscarMejorada(Nodo* lista, unsigned leg) //Solo sirve con listas ordenadas, si me paso de lo que quiero buscar, dejo de buscar
{
    Nodo *l = lista;
    while(l != NULL && l->info.leg < leg)
        l = l->sig;
    if(l!=NULL && l->info.leg == leg)
        return l;
    else
        return NULL;
}

void modificarNota(Nodo* lista, unsigned leg, unsigned nuevaNota)
{
    Nodo *l = buscar(lista, leg);
    if(l != NULL)
        l->info.nota = nuevaNota;
}

void insertar(Nodo* &lista, Alumno a) //inserta de manera ordenada
{
    Nodo *n, *l, *ant;
    n = new Nodo;
    n->info = a;
    l = lista;
    while(l != NULL && l->info.leg < a.leg)
    {
        ant = l; //antecesor de n
        l = l->sig; //sucesor de n
    }
    n->sig = l;
    if(l != lista)
        ant->sig = n;
    else
        lista = n;
}

Nodo *buscarInsertar(Nodo* &lista, Alumno a) //Si el nuevo alumno está, lo modifica. De lo contrario, lo agrega
{
    Nodo *l, *ant;
    l = lista;
    while(l != NULL && l->info.leg < a.leg)
    {
        ant = l;
        l = l->sig;
    }
    if(l == NULL || l->info.leg!=a.leg) //si no está
    {
        Nodo *n = new Nodo;
        n->info = a;
        n->sig = l;
        if(l != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
    else
        return l;
}

bool eliminar(Nodo* &lista, unsigned leg)
{
    Nodo *l, *ant;
    l = lista;
    while(l != NULL && l->info.leg < leg)
    {
        ant = l; 
        l = l->sig; 
    }
    if(l == NULL || l->info.leg!=leg)
        //cout<<"No esta en la lista."<<endl;
        return false;
    else
    {
        if(l==lista)
        {
            lista = l->sig;
        }
        else
            ant->sig = l->sig;
        delete l;
        return true;
    }
}

void listar(Nodo *lista)
{
    Nodo *l;
    l = lista;
    while(l != NULL)
    {
        cout<<l->info.leg<<" "<<l->info.nombre<<" "<<l->info.nota<<endl;
        l = l->sig;
    }
}
