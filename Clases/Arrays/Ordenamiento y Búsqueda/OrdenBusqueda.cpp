#include <iostream>


using namespace std;

void ingresar(int[],unsigned);
void mostrar(int[],unsigned);
void burbujeo(int[],unsigned); //ordenamiento
void seleccion(int[],unsigned);  //ordenamiento
void insercion(int[],unsigned); //ordenamiento
int secuencial(int[],unsigned,int);  //búsqueda
int binaria(int[],unsigned,int);  //búsqueda

int main()
{
    int v[]={20,40,10,90,100,60,70,30,50,80};
    int pos;
    //int v[10];
    //ingresar(v,10);
    cout<<"Numeros desordenados"<<endl;
    mostrar(v,10);


    pos=secuencial(v,10,15);

    if(pos==-1)
        cout<<endl<<"No esta"<<endl<<endl;
    else
        cout<<endl<<"Esta en la posicion "<<pos<<endl<<endl;


    //burbujeo(v,10);
    //seleccion(v,10);
    insercion(v,10);

    cout<<"Numeros ordenados"<<endl;
    mostrar(v,10);


    pos=binaria(v,10,15);
    if(pos==-1)
        cout<<endl<<"No esta"<<endl<<endl;
    else
        cout<<endl<<"Esta en la posicion "<<pos<<endl<<endl;


    return 0;
}

void ingresar(int v[],unsigned t)
{
    for(unsigned i=0;i<t;i++)
        cin>>v[i];
}

void mostrar(int v[],unsigned t)
{
    for(unsigned i=0;i<t;i++)
        cout<<v[i]<<"    "<<endl;
}

/*
void burbujeo(int v[], unsigned t)
{
    int i , j, aux;
    for(i = 1; i < t; i++)
    {
       for(j = 0; j < t-i; j++)
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

*/

void burbujeo(int v[],unsigned t)
{
    unsigned i=1,j;
    int aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-i;j++)
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
    }while(i<t && cambio);
}

void seleccion(int v[],unsigned t)
{
    unsigned i,j;
    int menor, pos;
    for(i=0;i<t-1;i++)
    {
        menor=v[i];
        pos=i;
        for(j=i+1;j<t;j++)
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

void insercion(int v[],unsigned t)
{
    unsigned i;
    int a,j;
    for(i=1;i<t;i++)
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

int secuencial(int v[],unsigned t,int bus)
{
    unsigned i=0;
    while(i<t && v[i]!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}
/*
int secuencial(int v[],unsigned t,int bus)
{
    unsigned i=0;
    int pos=-1
    while(i<t && pos==-1)
    {
        if(v[i]==bus)
            pos=i;
        i++;
    }
    return pos;
}
*/
/*
int binaria(int v[],unsigned t,int bus)
{
    int pos=-1,desde=0,hasta=t-1,medio;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(v[medio]==bus)
            pos=medio;
        else
        {
            if(bus<v[medio])
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}
*/
int binaria(int v[],unsigned t,int bus)
{
    int desde=0,hasta=t-1,medio;
   do
    {
        medio=(desde+hasta)/2;

        if(bus<v[medio])
                hasta=medio-1;
        else
                desde=medio+1;

    } while(desde<=hasta && v[medio]!=bus);
    if(v[medio]==bus)
        return medio;
    else
        return -1;
}
