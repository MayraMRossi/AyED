#include <iostream>
using namespace std;

struct Personas
{
    string nombre;
    int DNI;
};

struct Nodo
{
    Personas info;
    Nodo *sig;
};

void cargarCola(Nodo *&pri, Nodo *&ult);
void encolar(Nodo *&pri, Nodo *&ult, Personas per);
Personas desencolar(Nodo *&pri, Nodo *&ult);
void mostrarCola(Nodo *&pri, Nodo *&ult);
void ponerAlFinal(Nodo *&pri1, Nodo *&ult1, Nodo *&pri2, Nodo *&ult2, int DNI);

int main()
{
    Nodo *pri1 = NULL, *pri2 = NULL;
    Nodo *ult1 = NULL, *ult2 = NULL;
    int DNI;
    cargarCola(pri1, ult1);
    cout<<endl<<"Ingrese el DNI a buscar: ";
    cin>>DNI;
    ponerAlFinal(pri1, ult1, pri2, ult2, DNI);
    cout<<endl;
    mostrarCola(pri2, ult2);

}

void cargarCola(Nodo *&pri, Nodo *&ult)
{
    Personas per;
    cout<<"DNI: ";
    cin>>per.DNI;
    while(per.DNI != 0)
    {
        cout<<"Nombre: ";
        cin>>per.nombre;
        encolar(pri, ult, per);
        cout<<"DNI: ";
        cin>>per.DNI;
    }
}

void ponerAlFinal(Nodo *&pri1, Nodo *&ult1, Nodo *&pri2, Nodo *&ult2, int DNI)
{
    Personas per, aux;
    while(pri1 != NULL)
    {
        per = desencolar(pri1, ult1);
        if(per.DNI == DNI)
            aux = per;
        else
        {
            encolar(pri2, ult2, per);
        }
    }
    encolar(pri2, ult2, aux);
}

void mostrarCola(Nodo *&pri, Nodo *&ult)
{
    Personas per;
    while(pri != NULL)
    {
        per = desencolar(pri, ult);
        cout<<per.DNI<<" - "<<per.nombre<<endl;
    }
}

void encolar(Nodo *&pri, Nodo *&ult, Personas per)
{
    Nodo *p = new Nodo;
    p->info = per;
    p->sig = NULL;
    if(ult != NULL)
        ult->sig = p;
    else
        pri = p;
    ult=p;
}

Personas desencolar(Nodo *&pri, Nodo *&ult)
{
    Personas per;
    Nodo *p;
    p = pri;
    per = p->info;
    pri = p->sig;
    delete p;
    if(pri == NULL)
        ult = NULL;
    return per;
}