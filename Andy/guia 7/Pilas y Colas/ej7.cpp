#include <iostream>
using namespace std;

struct Pasajeros
{
    char nombre[30];
    int DNI;
};

struct Nodo 
{
    Pasajeros info;
    Nodo *sig;
};

void ingresarPasajero(Nodo *&pri_monte, Nodo *&ult_monte, Nodo *&pri_punta, Nodo *&ult_punta, Nodo *&pri_mar, Nodo *&ult_mar, Pasajeros pas, int destino);
void actualizarCola(Nodo *&pri_monte, Nodo *&ult_monte, Nodo *&pri_punta, Nodo *&ult_punta, Nodo *&pri_mar, Nodo *&ult_mar, int destino, int cantAsientos);
void encolar(Nodo *&pri, Nodo *&ult, Pasajeros pas);
Pasajeros desencolar(Nodo *&pri, Nodo *&ult);

int main()
{
    Nodo *pri_monte=NULL, *pri_punta=NULL, *pri_mar=NULL;
    Nodo *ult_monte=NULL, *ult_punta=NULL, *ult_mar=NULL;
    int destino;
    Pasajeros pas;
    int cantAsientos;

    cout<<"DNI: ";
    cin>>pas.DNI;
    while(pas.DNI != 0)
    {
        cout<<"Nombre: ";
        cin>>pas.nombre;
        cout<<"Destino (1: Montevideo, 2: Punta del Este, 3: Mar del Plata): "<<endl;
        cin>>destino;
        ingresarPasajero(pri_monte, ult_monte, pri_punta, ult_punta, pri_mar, ult_mar, pas, destino);
        cout<<endl<<"DNI: ";
        cin>>pas.DNI;
    }

    cout<<endl<<"Actualizacion de la Cola: "<<endl;
    cout<<"Destino: ";
    cin>>destino;
    cout<<"Cant asientos libres: ";
    cin>>cantAsientos;
    actualizarCola(pri_monte, ult_monte, pri_punta, ult_punta, pri_mar, ult_mar, destino, cantAsientos);
}

void ingresarPasajero(Nodo *&pri_monte, Nodo *&ult_monte, Nodo *&pri_punta, Nodo *&ult_punta, Nodo *&pri_mar, Nodo *&ult_mar, Pasajeros pas, int destino)
{
    switch(destino)
    {
        case 1:
            encolar(pri_monte, ult_monte, pas); break;
        case 2:
            encolar(pri_punta, ult_punta, pas); break;
        case 3:
            encolar(pri_mar, ult_mar, pas); break;
        default:
            cout<<"El destino es incorrecto."<<endl;
    }
}

void actualizarCola(Nodo *&pri_monte, Nodo *&ult_monte, Nodo *&pri_punta, Nodo *&ult_punta, Nodo *&pri_mar, Nodo *&ult_mar, int destino, int cantAsientos)
{
    int i;
    Pasajeros pas;
    switch(destino)
    {
        case 1:
        {
            for(i=0; i<cantAsientos; i++)
            {
                pas = desencolar(pri_monte, ult_monte);
                cout<<pas.DNI<<" - "<<pas.nombre<<endl;
            }   
            break;
        }
        case 2:
            for(i=0; i<cantAsientos; i++)
            {
                pas = desencolar(pri_punta, ult_punta);
                cout<<pas.DNI<<" - "<<pas.nombre<<endl;
            } 
            break;
        case 3:
            for(i=0; i<cantAsientos; i++)
            {
                pas = desencolar(pri_mar, ult_mar);
                cout<<pas.DNI<<" - "<<pas.nombre<<endl;
            } 
            break;
        default:
            cout<<"El destino es incorrecto."<<endl;
    }
}

void encolar(Nodo *&pri, Nodo *&ult, Pasajeros pas)
{
    Nodo *p = new Nodo;
    p->info = pas;
    p->sig = NULL;
    if(ult != NULL)
        ult->sig = p;
    else
        pri = p;
    ult=p;
}

Pasajeros desencolar(Nodo *&pri, Nodo *&ult)
{
    Pasajeros pas;
    Nodo *p;
    p = pri;
    pas = p->info;
    pri = p->sig;
    delete p;
    if(pri == NULL)
        ult = NULL;
    return pas;
}