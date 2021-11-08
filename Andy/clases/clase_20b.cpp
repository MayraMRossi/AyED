// Arboles binarios: de la raiz dependen dos arboles (uno a izq y otro a der)
//Hay 3 formas de recorrerlo:
// Preorden (RID): empieza en la raiz, luego por el arbol izq y luego el derecho
// Postorden(IDR): va por la raiz, luego por el arbol de la izq. Cuando llega a un NULL, 
//imprime ese arbol. Luego va al arbol de la derecha, y se repite el proceso 
// Entreorden/Inorden/Orden simetrico/abb:arbol binario de busqueda (IRD): primero imprime el izquierdo, luego la raiz y finalmente el derecho

#include <iostream>
using namespace std;

struct Nodo // del arbol
{
    int info;
    Nodo*izq;
    Nodo*der;
};

void listarIn(Nodo*raiz);
void listarPre(Nodo*raiz);
void listarPost(Nodo*raiz);
Nodo* buscar(Nodo*raiz, int n);
void insertar(Nodo*&raiz, int n);

int main()
{
    Nodo*raizArbol=NULL;
    int nro;
    cout<<"Agregar nro: ";
    cin>>nro;
    while(nro!=0)
    {
        insertar(raizArbol, nro);
        cout<<"Agregar nro: ";
        cin>>nro;
    }
    cout<<endl<<"Inorden"
    listarIn(raizArbol);
    cout<<"Preorden"<<endl;
    listarPre(raizArbol);
    cout<<"Postorden"<<endl;
    listarPost(raizArbol);
    return 0;
}

void listarIn(Nodo*raiz) // Arbol Inorden
{
    if(raiz!=NULL)
    {
        listarIn(raiz->izq);
        cout<<raiz->info<<endl;
        listarIn(raiz->der);
    }
}

void listarPre(Nodo*raiz) // Arbol Preorden
{
    if(raiz!=NULL)
    {
        cout<<raiz->info<<endl;
        listarPre(raiz->izq);
        listarPre(raiz->der);
    }
}

void listarPost(Nodo*raiz) // Arbol Postorden
{
    if(raiz!=NULL)
    {
        listarPost(raiz->izq);
        listarPost(raiz->der);
        cout<<raiz->info<<endl;
    }
}

Nodo* buscar(Nodo*raiz, int n) //sirve para arboles inorden, hace una busqueda binariado
{
    Nodo *r = raiz;
    while(r!=NULL && r->info!=n)
    {
        if(r->info<n)
            r = r->izq;
        else
            r = r->der;
    }
    return r;
}

//Al agregar un nodo, siempre se agregan abajo de todo (en las hojas)
//La raiz solo se modifica si el arbol es NULL
void insertar(Nodo*&raiz, int n) // para Inorden
{
    Nodo*n= new Nodo;
    n->info=n;
    n->izq=n->der=NULL;
    if(raiz==NULL)
        raiz=n;
    else
    {
        Nodo *ant, *r=raiz;
        do
        {
            ant=r;
            if(nro < r->info)
                r = r->izq;
            else
                r = r->der;
        } while(r!=NULL);
        if(nro < ant->info)
            ant->izq = n;
        else
            ant->der = n;
    }
}