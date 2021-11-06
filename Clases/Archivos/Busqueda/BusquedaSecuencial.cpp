#include <iostream>
#include <stdio.h>


using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

int main()
{
    FILE *arch;
    arch=fopen("Productos.dat","rb");
    if(arch==NULL)
        cout<<"ERROR";
    else
    {
        unsigned unCod;
        Producto prod;
        cout<<"Codigo de producto a buscar ";
        cin>>unCod;
        fread(&prod,sizeof(Producto),1,arch);
        while(!feof(arch) && prod.codigo!=unCod)
            fread(&prod,sizeof(Producto),1,arch);
        if(feof(arch))
            cout<<"no hay un producto con ese codigo"<<endl;
        else
            cout<<"el stock del producto buscado es "<<prod.stock<<endl;
        fclose(arch);
    }
    return 0;
}
