//Se tiene un vector de productos (cada elemento tiene código, descripción y stock) y otro vector 
//con los productos recibidos de los proveedores (código, cantidad recibida), ambos ordenados por código de producto.
//Se pide actualizar el stock del vector de productos.

#include <iostream>
using namespace std;

void cargarParalelo(string desc[], int cod[], int stock[], unsigned t);
void burbujeo (string nombre[], int n1[], int n2[], unsigned t);
int secuencial(string v[], unsigned t, string bus);
void actualizarStock(int cod1[], int cod2[], string desc1[], string desc2[], int stock1[], int stock2[], unsigned t);
void mostrar(string desc[], int cod[], int stock[], unsigned t);

int main()
{
    //Vector de productos
    int cod1[5], stock1[5];
    string desc1[5];
    //Vector de productos recibidos
    int cod2[5], stock2[5];
    string desc2[5];

    cout<<"Productos: "<<endl;
    cargarParalelo(desc1, cod1, stock1, 5);
    cout<<"Productos recibidos: "<<endl;
    cargarParalelo(desc2, cod2, stock2, 5);

    //Ordenar Vector 1
    burbujeo(desc1, cod1, stock1, 5);

    //Ordenar Vector 2
    burbujeo(desc2, cod2, stock2, 5);

    actualizarStock(cod1, cod2, desc1, desc2, stock1, stock2, 5);
    
    cout<<"Stock actualizado: "<<endl;
    mostrar(desc1, cod1, stock1, 5);

    return 0;
}

void cargarParalelo(string desc[], int cod[], int stock[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"Producto "<<i+1<<": "<<endl;
        cout<<"Ingrese la descripcion: ";
        cin>>desc[i];
        cout<<"Ingrese el codigo: ";
        cin>>cod[i];
        cout<<"Ingrese el stock: ";
        cin>>stock[i];
        cout<<endl;
    }
    
}

void mostrar(string desc[], int cod[], int stock[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"Producto "<<i+1<<": "<<endl;
        cout<<"Descripcion: "<<desc[i]<<endl;
        cout<<"Codigo: "<<cod[i]<<endl;
        cout<<"Stock: "<<stock[i]<<endl<<endl;
    }
}

void burbujeo (string nombre[], int n1[], int n2[], unsigned t)
{
    int i, j, aux1;
    string aux2;
    for(i=1; i<t; i++)
    {
        for(j=0; j<t-i; j++)
        {
            if(n1[j]>n1[j+1])
            {
                aux2=nombre[j];
                nombre[j]=nombre[j+1];
                nombre[j+1]=aux2;

                aux1=n1[j];
                n1[j]=n1[j+1];
                n1[j+1]=aux1;

                aux1=n2[j];
                n2[j]=n2[j+1];
                n2[j+1]=aux1;
            }
        }
    }
}

void actualizarStock(int cod1[], int cod2[], string desc1[], string desc2[], int stock1[], int stock2[], unsigned t)
{
    int pos;
    for(int i=0; i<t; i++)
    {
        pos=secuencial(desc2, 5, desc1[i]);
        if(pos!=-1)
            stock1[i]+=stock2[pos];
    }
}

int secuencial(string v[], unsigned t, string bus)
{
    unsigned i=0;
    while(i<t && v[i]!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}