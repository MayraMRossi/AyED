// Lista Simple:

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

int main()
{
    return 0;
}

void listar(Nodo *lista) //muestra los elementos de la lista
{
    Nodo *l;
    l = lista;
    while(l != NULL)
    {
        cout<<l->info.leg<<" "<<l->info.nombre<<" "<<l->info.nota<<endl;
        l = l->sig;
    }
}

void listarAprobados(Nodo *lista)
{
    Nodo *l;
    l = lista;
    while(l != NULL)
    {
        if(lista->info.nota>=6)
            cout<<l->info.leg<<" "<<l->info.nombre<<" "<<l->info.nota<<endl;
        l = l->sig;
    }
}

float promedio(Nodo *lista)
{
    int i=0;
    float suma=0;
    Nodo *l;
    l = lista;
    while(l != NULL)
    {
        suma += l->info.nota;
        i++;
        l = l->sig;
    }
    if(i == 0)
        return 0;
    else
        return suma/i;
}