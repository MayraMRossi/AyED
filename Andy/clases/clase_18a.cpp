// Apareo y Corte de Control

#include <iostream>
using namespace std;

struct Alumno
{
    unsigned leg, nota;
    string nombre;
};

struct Nodo
{
    Alumno info;
    Nodo* sig;
};

int main()
{

}

void apareo(Nodo* lista1, Nodo* lista2)
{
    Nodo *p1, *p2;
    p1=lista1;
    p2=lista2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->info.leg < p2->info.leg)
        {
            cout<<p1->info.leg<<" "<<p1->info.nombre<<" "<<p1->info.nota<<endl;
            p1 = p1->sig;
        }
        else
        {
            if(p1->info.leg == p2->info.leg)
            {
                cout<<p1->info.leg<<" "<<p1->info.nombre<<" ";
                if(p1->info.nota > p2->info.nota)
                    cout<<p1->info.nota<<endl;
                else
                    cout<<p2->info.nota<<endl;
                p1 = p1->sig;
                p2 = p2->sig;
            }
            else
            {
                cout<<p2->info.leg<<" "<<p2->info.nombre<<" "<<p2->info.nota<<endl;
                p2 = p2->sig;
            }
        }
    }
    while(p1!=NULL)
    {
        cout<<p1->info.leg<<" "<<p1->info.nombre<<" "<<p1->info.nota<<endl;
        p1 = p1->sig;
    }
    while(p2!=NULL)
    {
        cout<<p2->info.leg<<" "<<p2->info.nombre<<" "<<p2->info.nota<<endl;
        p2 = p2->sig;
    }
}

void corteControl(Nodo* lista)
{
    Nodo *p = lista;
    int suma, leg, cont;
    string nom;
    while(p != NULL)
    {
        leg=p->info.leg;
        nom=p->info.nombre;
        suma=0;
        cont=0;
        do
        {
            suma+=p->info.nota;
            cont++;
            p = p->sig;
        } while (p!=NULL && p->info.leg == leg);
        cout<<leg<<" "<<nom<<" "<<suma/cont<<endl;
    }
}

void corteControl2(Nodo* lista) //usa dos punteros
{
    Nodo *p, *q;
    int suma, cont;
    p=q=lista;
    while(p != NULL)
    {
        suma=0;
        cont=0;
        do
        {
            suma+=q->info.nota;
            cont++;
            q=q->sig;
        } while (q!=NULL && q->info.leg == p->info.leg);
        cout<<p->info.leg<<" "<<p->info.nombre<<" "<<suma/cont<<endl;
        p=q;
    } 
}