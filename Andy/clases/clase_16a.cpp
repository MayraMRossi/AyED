// Colas: es de tipo FIFO

#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sig;
};

int main()
{
    return 0;
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