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
    arch=fopen("Productos.dat","r+b");
    if(arch==NULL)
        cout<<"ERROR";
    else
    {
        unsigned unCod,uCompra;
        Producto prod;
        cout<<"Codigo a buscar ";
        cin>>unCod;
        cout<<"Unidades compradas para sumar al stock ";
        cin>>uCompra;
        fread(&prod,sizeof(Producto),1,arch);
        while(!feof(arch) && prod.codigo!=unCod)
            fread(&prod,sizeof(Producto),1,arch);
        if(feof(arch))
        {
            cout<<"no hay un producto con ese codigo"<<endl;
            cout<<"quiere agregarlo? (S/N)";
            char resp;
            cin>>resp;
            if(resp=='S')
            {
                prod.codigo=unCod;
                prod.stock=uCompra;
                fwrite(&prod,sizeof(Producto),1,arch);
            }
        }
        else
        {
           prod.stock+=uCompra;
           //correr el puntero un Producto para atras
           fseek(arch,-sizeof(Producto),SEEK_CUR);
           fwrite(&prod,sizeof(Producto),1,arch);
        }

        fclose(arch);
    }
    return 0;
}

