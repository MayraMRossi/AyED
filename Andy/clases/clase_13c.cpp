//Funciones (para que el codigo sea modular)

#include <iostream>
#include <stdio.h>
using namespace std;

struct Productos
{
    unsigned codigo, stock;
};

int main()
{
    unsigned cod, uCompra;
    Productos prod;    
    
    FILE*f = fopen("Productos.dat", "rb");
    if(f==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        cout<<"Codigo de producto a buscar: ";
        cin>>cod;
        int pos=buscarArchivo(f, cod, prod);
        if(pos==-1)
            cout<<"Ese producto NO existe."<<endl;
        else
            /*
            fseek(f, pos*sizeof(Productos), SEEK_SET);
            fread(&prod, sizeof(Productos), 1, f);
            cout<<"El stock del producto buscado es: "<<prod.codigo;
            */
            cout<<"El stock del producto buscado es: "<<prod.codigo;
        fclose(f);
    }
    //MODIFICACION

    FILE*f = fopen("Productos.dat", "r+b"); //rb+: el "+" agrega la funcionalidad que no tiene (lectura-escritura)
    if(f==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        cout<<"Codigo de producto a buscar: ";
        cin>>cod;
        cout<<"Unidades compradas a sumar al stock: ";
        cin>>uCompra;
        int pos=buscarArchivo(f, cod, prod);
        if(pos==-1)
        {
            cout<<"Ese producto NO existe."<<endl;
            cout<<"¿Desea agregarlo? (S/N)";
            char resp;
            cin>>resp;
            if(resp=='S' || resp=='s')
            {
                prod.codigo=cod;
                prod.stock=uCompra;
                fseek(f, 0, SEEK_END);
                fwrite(&prod, sizeof(Productos), 1, f);
            }
        }
        else
        {
            prod.stock+=uCompra;
            //retroceder el puntero un lugar
            fseek(f, -sizeof(Productos),SEEK_CUR);
            fwrite(&prod, sizeof(Productos), 1, f);
        }
        fclose(f);
    }
}

int buscarArchivo(FILE* f, unsigned bus, Productos &prod)
{
    unsigned i=0;
    int pos;
    fread(&prod, sizeof(Productos), 1, f);
    while(prod.codigo!=bus && !feof(f))
        fread(&prod, sizeof(Productos), 1, f);
        i++;
    if(feof(f))
        pos==-1;
    else
        pos==i;
}

int BusquedaBinariaArchivo(FILE* f, unsigned bus, Productos &prod)
{
    unsigned desde, hasta, medio, cantRegistros;
    int pos=-1;
    desde=0;
    fseek(f, 0, SEEK_END);
    cantRegistros=ftell(f)/sizeof(Productos); //ftell: devuelve la cantidad de bytes desde el inicio del archivo hasta donde esta el puntero
    hasta=cantRegistros-1;
    while(pos==-1 && desde<=hasta)
    {
        medio=(desde+hasta)/2;
        fseek(f, medio*sizeof(Productos), SEEK_SET);
        fread(&prod, sizeof(Productos), 1, f);
        if(prod.codigo==bus)
            pos==medio;
        else
        {
            if(bus<prod.codigo)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}