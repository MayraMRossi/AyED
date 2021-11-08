//Metodos de ordenamiento

#include <iostream>
using namespace std;

void burbujeo (int v[], unsigned t);
void mostrar(int v[], unsigned t);
void burbujeo2 (int v[], unsigned t);
void seleccion (int v[], unsigned t);
void insercion (int v[], unsigned t);
int secuencial(int v[], unsigned t, int bus);
int secuencial2(int v[], unsigned t, int bus);
int binaria(int v[] , unsigned t, int bus);

int main()
{
    int num[]={1, 2, 4, 6, 9, 25, 10};
    //burbujeo2 (num, 7); //Mal
    //seleccion(num, 7); //Mal
    insercion(num, 7);
    mostrar(num, 7);

    //Secuencial
    /*
    int pos=secuencial2(num, 7, 3);
    if(pos<0)
        cout<<"No esta el numero ingresado.";
    else
        cout<<"la posicion es: "<<pos;
    */

    //Binaria
    /*
    int pos=binaria(num, 7, 4);
    if(pos<0)
        cout<<"No esta el numero ingresado.";
    else
        cout<<"la posicion es: "<<pos;
    */

    return 0;
}

void mostrar(int v[], unsigned t)
{
    for(int i=0; i<t; i++)
        cout<<v[i]<<" ";
}

//Metodo burbujeo: comparar cada metodo con el de al lado.
//Se necesitan t-1 ciclos para que se ordene el vector, ya que
//en cada iteracion se ordena el ultimo, luego el anteultimo y asi sucesivamente.
//Para hacerlo de mayor a menor, solo hay que cambiar if(v[j]<v[j+1]).
//Para no hacer recorridos inncesarios de más, el vector recorre t-i veces, ya que
//en cada vuelta, ya se que el ultimo es el mayor.
void burbujeo (int v[], unsigned t)
{
    int i, j, aux;
    for(i=1; i<t; i++)
    {
        for(j=0; j<t-i; j++)
        {
            if(v[j]>v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void burbujeo2 (int v[], unsigned t)
{
    int i=1, j, aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0; j<t-i; j++)
        {
            if(v[j]>v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    } while(i<t && cambio);
}

//Metodo de seleccion: buscar el menor y ponerlo adelante (en la posicion 0, 1, etc)
//Compara v[i] con el resto de posiciones, cuando encuentra al menor, guarda su valor y su posicion
//para intercambiarlo con v[i].
void seleccion (int v[], unsigned t)
{
    unsigned i, j, aux;
    int menor, pos;
    for(i=0; i<t-i; i++)
    {
        menor=v[i];
        pos=i;
        for(j=i+1; j<t; j++)
        {
            if(v[j]<menor)
            {
                menor=v[j];
                pos=j;
            }
        }
        v[pos]=v[i];
        v[i]=menor;
    }
}

//Insercion: hasta la posicion i-1, el vector esta ordenado, a partir de la pos i, esta desordenado.
//Toma el primero de la parte desordenada y lo ordena y ubica en la parte ordenada.

void insercion (int v[], unsigned t)
{
    unsigned i;
    int a, j;
    for(i=1; i<t; i++)
    {
        a=v[i];
        j=i-1;
        while(j>=0 && v[j]>a)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=a;
    }
}

//Busqueda Secuencial: buscar uno por uno. bus = lo que quiero buscar

int secuencial(int v[], unsigned t, int bus)
{
    unsigned i=0;
    int pos=-1;
    while(i<t && pos==-1)
    {
        if(v[i]==bus)
            pos=i;
        i++;
    }
    return pos;
}

//Busca uno por uno hasta llegar al numero, y ahi para.
int secuencial2(int v[], unsigned t, int bus)
{
    unsigned i=0;
    while(i<t && v[i]!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}

//Busqueda Binaria: solo cuando el vector esta ordenado.
//Busca en el medio, si es menor, busca a la izquierda, si es mayor, a la derecha.
int binaria(int v[] , unsigned t, int bus)
{
    int pos=-1;
    unsigned desde=0, hasta=t-1, medio;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(v[medio]==bus)
            pos=medio;
        else 
        {
            if (bus<v[medio])
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}