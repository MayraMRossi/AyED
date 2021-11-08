//Modificar archivos (sobreescribir):

#include <iostream>
#include <stdio.h>
using namespace std;

struct Productos
{
    unsigned codigo, stock;
};

int main()
{
    FILE*f = fopen("Productos.dat", "r+b"); //rb+: el "+" agrega la funcionalidad que no tiene (lectura-escritura)
    if(f==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        unsigned cod, uCompra;
        Productos prod;

        cout<<"Codigo de producto a buscar: ";
        cin>>cod;
        cout<<"Unidades compradas a sumar al stock: ";
        cin>>uCompra;
        fread(&prod, sizeof(Productos), 1, f);
            while(prod.codigo!=cod && !feof(f))
                fread(&prod, sizeof(Productos), 1, f);
        if(feof(f))
        {
            cout<<"Ese producto NO existe."<<endl;
            cout<<"¿Desea agregarlo? (S/N)";
            char resp;
            cin>>resp;
            if(resp=='S' || resp=='s')
            {
                //El puntero ya esta en el final del archivo, asi que no hace falta usar un append.
                prod.codigo=cod;
                prod.stock=uCompra;
                fwrite(&prod, sizeof(Productos), 1, f);
            }
        }
        else
        {
            //Modificacion

            prod.stock+=uCompra;
            //retroceder el puntero un lugar
            fseek(f, -sizeof(Productos),SEEK_CUR);
            fwrite(&prod, sizeof(Productos), 1, f);
        }
        fclose(f);
    }
    return 0;
}

/*
fseek: 
SEEK_SET (posicion 0)
SEEK_CUR (posicion actual)
SEEK_END (posicion final)
*/