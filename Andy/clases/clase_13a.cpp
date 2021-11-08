//Busqueda secuencial en ARCHIVOS de datos:

#include <iostream>
using namespace std;

struct Productos
{
    unsigned codigo, stock;
};

int main()
{
    FILE*f = fopen("Productos.dat", "rb");
    if(f==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        unsigned cod;
        Productos prod;
        cout<<"Codigo de producto a buscar: ";
        cin>>cod;
        fread(&prod, sizeof(Productos), 1, f);
            while(prod.codigo!=cod && !feof(f))
                fread(&prod, sizeof(Productos), 1, f);
        if(feof(f))
            cout<<"Ese producto NO existe."<<endl;
        else
            cout<<"El stock del producto buscado es: "<<prod.codigo;
        fclose(f);
    }
    return 0;
}