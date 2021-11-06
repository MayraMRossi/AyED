#include <iostream>
#include <stdio.h>


using namespace std;

struct NodoCola
{
    int info;
    NodoCola*sig;
};

void encolar(NodoCola*&pri,NodoCola*&ult,int nro)
{
    NodoCola*p;
    p=new NodoCola;
    p->info=nro;
    p->sig=NULL;
    if(ult!=NULL)
        ult->sig=p;
    else
        pri=p;
   ult=p;
}

int desencolar(NodoCola*&pri,NodoCola*&ult)
{
    int dato;
    NodoCola *p;
    p=pri;
    dato=p->info; //pri->info;
    pri=p->sig;  //pri->sig;
    delete p;
    if(pri==NULL)
        ult=NULL;
    return dato;
}















