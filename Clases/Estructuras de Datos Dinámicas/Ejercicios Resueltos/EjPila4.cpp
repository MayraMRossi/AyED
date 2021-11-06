struct NodoPila
{
    int info;
    NodoPila*sig;
};



void apilar(NodoPila*&pila,int dato)
{
    NodoPila*p;
    p=new NodoPila;
    p->info=dato;
    p->sig=pila;
    pila=p;
}

int desapilar(NodoPila*&pila)
{
    int dato;
    NodoPila*p;
    p=pila;
    dato=p->info; //pila->info;
    pila=p->sig;
    delete p;
    return dato;
}

void ReemplazarValorPila(NodoPila *&pila, int valx, int valy)
{
    NodoPila *pilaAux=NULL;
    int nro;
    while(pila!=NULL)
    {
        nro=desapilar(pila);
        if(nro==valy)
            apilar(pilaAux,valx);
        else
            apilar(pilaAux,nro);

    }
    while(pilaAux!=NULL)
    {
        nro=desapilar(pilaAux);
        apilar(pila,nro);
        //apilar(pila,desapilar(pilaAux));
    }
}
