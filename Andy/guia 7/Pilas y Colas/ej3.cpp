#include <iostream>
#include <string.h>
using namespace std;

struct Nodo
{
    char info;
    Nodo *sig;
};

void apilar(Nodo *&pila, char letra);
char desapilar(Nodo *&pila);
bool capicua(char palabra[20]);

int main()
{
    char palabra[20];

    cout<<"Introduce una palabra: ";
    cin>>palabra;

    if(capicua(palabra))
        cout<<palabra<<" es capicua."<<endl;
    else
        cout<<palabra<<" no es capicua."<<endl;

    return 0;
}

void apilar(Nodo *&pila, char letra)
{
    Nodo *p = new Nodo;
    p->info = letra;
    p->sig = pila;
    pila = p;
}

char desapilar(Nodo *&pila)
{
    char letra;
    Nodo *p;
    p = pila;
    letra = p->info;
    pila = p->sig;
    delete p;
    return letra;
}

bool capicua(char palabra[20])
{
    char palabra_copia[20];
    Nodo *pila = NULL;
    int i;
    
    for(i=0; i<strlen(palabra); i++)
    {
        apilar(pila, palabra[i]);
    }
    
    i=0;
    while(pila != NULL)
    {
        palabra_copia[i] = desapilar(pila);
        i++;
    }

    if(strcmp(palabra, palabra_copia) == 0)
        return true;
    else
        return false;
}