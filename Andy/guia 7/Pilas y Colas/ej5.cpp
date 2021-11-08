#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sig;
};

void cargarCola(Nodo *&pri, Nodo *&ult);
void encolar(Nodo *&pri, Nodo *&ult, int nro);
int desencolar(Nodo *&pri, Nodo *&ult);
bool eliminar4(Nodo *&pri, Nodo *&ult);

int main()
{
    Nodo *pri=NULL;
    Nodo *ult=NULL;
    cargarCola(pri, ult);
    bool ask = eliminar4(pri, ult);
    if(ask)
        cout<<"SI pudo eliminar 4."<<endl;
    else
        cout<<"NO pudo eliminar 4."<<endl;
}

void cargarCola(Nodo *&pri, Nodo *&ult)
{
    int nro;
    cout<<"Ingresa un nro: ";
    cin>>nro;
    while(nro != 0)
    {
        encolar(pri, ult, nro);
        cout<<"Ingresa un nro: ";
        cin>>nro;
    }
}

void encolar(Nodo *&pri, Nodo *&ult, int nro)
{
    Nodo *p = new Nodo;
    p->info = nro;
    p->sig = NULL;
    if(ult != NULL)
        ult->sig = p;
    else
        pri = p;
    ult=p;
}

int desencolar(Nodo *&pri, Nodo *&ult)
{
    int nro;
    Nodo *p;
    p = pri;
    nro = p->info;
    pri = p->sig;
    delete p;
    if(pri == NULL)
        ult = NULL;
    return nro;
}

bool eliminar4(Nodo *&pri, Nodo *&ult)
{
    int cont=0;
    while(pri != NULL && cont<4)
    {
        desencolar(pri, ult);
        cont++;
    }
    
    return cont == 4;
}