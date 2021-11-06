#include <iostream>
#include <stdio.h>


using namespace std;

struct Producto
{
    unsigned codigo; //de 1 a 10
    unsigned stock;
};



int main()
{
    FILE *aProd;
    Producto p;
    aProd=fopen("ProductosAccDir.dat","rb");
    cout<<"Codigo de producto a buscar ";
    int unCod;
    cin>>unCod;
    if(aProd!=NULL)
    {
        if(unCod>=1 && unCod<=10)
        {
            fseek(aProd,(unCod-1)*sizeof(Producto),SEEK_SET);
            fread(&p,sizeof(Producto),1,aProd);
            cout<<p.stock<<endl;
        }
        else
            cout<<"No existe producto con ese codigo"<<endl;
        fclose(aProd);
    }

    return 0;
}

