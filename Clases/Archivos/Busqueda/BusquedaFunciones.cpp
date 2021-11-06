#include <iostream>
#include <stdio.h>


using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};


int busquedaSecuencial(FILE* arch,unsigned bus,Producto &prod);
int busquedaBinaria(FILE* arch,unsigned bus,Producto &prod);
int cantRegistros(FILE * a);

int main()
{
    /*
    unsigned unCod,uCompra;
    Producto prod;
    FILE *arch;
    //CONSULTA

    arch=fopen("Productos.dat","rb");
    if(arch==NULL)
        cout<<"ERROR";
    else
    {

        cout<<"Codigo de producto a buscar ";
        cin>>unCod;
        int pos=busquedaSecuencial(arch,unCod,prod);
        if(pos==-1)
            cout<<"no hay un producto con ese codigo"<<endl;
        else
        {
           cout<<"el stock del producto buscado es "<<prod.stock<<endl;
        }

        fclose(arch);
    }
    //MODIFICACIÓN
    arch=fopen("Productos.dat","r+b");
    if(arch==NULL)
        cout<<"ERROR";
    else
    {
        cout<<"Codigo a buscar ";
        cin>>unCod;
        cout<<"Unidades compradas para sumar al stock ";
        cin>>uCompra;
        int pos=busquedaSecuencial(arch,unCod,prod);
        if(pos==-1)
        {
            cout<<"no hay un producto con ese codigo"<<endl;
            cout<<"quiere agregarlo? (S/N)";
            char resp;
            cin>>resp;
            if(resp=='S')
            {
                prod.codigo=unCod;
                prod.stock=uCompra;
                fseek(arch,0,SEEK_END);
                fwrite(&prod,sizeof(Producto),1,arch);
            }
        }
        else
        {
           prod.stock+=uCompra;
           //correr el puntero un Producto para atras
           fseek(arch,pos*sizeof(Producto),SEEK_SET);
           fwrite(&prod,sizeof(Producto),1,arch);
        }

        fclose(arch);
    }
    */
    /*
    FILE* arch=fopen("ProductosOrd.dat","rb");
    if(arch==NULL)
        cout<<"ERROR";
    else
    {
        cout<<cantRegistros(arch)<<endl;
        fclose(arch);
    }
    */
    unsigned unCod,uCompra;
    Producto prod;
    FILE *arch;
    //CONSULTA

    arch=fopen("ProductosOrd.dat","rb");
    if(arch==NULL)
        cout<<"ERROR";
    else
    {

        cout<<"Codigo de producto a buscar ";
        cin>>unCod;
        int pos=busquedaBinaria(arch,unCod,prod);
        if(pos==-1)
            cout<<"no hay un producto con ese codigo"<<endl;
        else
        {
           cout<<"el stock del producto buscado es "<<prod.stock<<endl;
        }

        fclose(arch);
    }
    //MODIFICACIÓN
    arch=fopen("ProductosOrd.dat","r+b");
    if(arch==NULL)
        cout<<"ERROR";
    else
    {
        cout<<"Codigo a buscar ";
        cin>>unCod;
        cout<<"Unidades compradas para sumar al stock ";
        cin>>uCompra;
        int pos=busquedaBinaria(arch,unCod,prod);
        if(pos==-1)
        {
            cout<<"no hay un producto con ese codigo"<<endl;

        }
        else
        {
           prod.stock+=uCompra;
           //correr el puntero un Producto para atras
           fseek(arch,pos*sizeof(Producto),SEEK_SET);
           fwrite(&prod,sizeof(Producto),1,arch);
        }

        fclose(arch);
    }

    return 0;
}

int busquedaSecuencial(FILE* arch,unsigned bus,Producto&prod)
{
    unsigned i=0;
    fread(&prod,sizeof(Producto),1,arch);
    while(!feof(arch)&&prod.codigo!=bus)
    {
        fread(&prod,sizeof(Producto),1,arch);
        i++;
    }
    if(feof(arch))
        return -1;
    else
        return i;
}

int busquedaBinaria(FILE* arch,unsigned bus,Producto &prod)
{
    unsigned desde,hasta,medio,cantReg;
    int pos=-1;
    desde=0;
    /*
    fseek(arch,0,SEEK_END);
    cantReg=ftell(arch)/sizeof(Producto);
    hasta=cantRegistros-1;
    */
    hasta=cantRegistros(arch)-1;
    //hasta=ftell(arch)/sizeof(Producto)-1;
    while(pos==-1 && desde<=hasta)
    {
        medio=(desde+hasta)/2;
        fseek(arch,medio*sizeof(Producto),SEEK_SET);
        fread(&prod,sizeof(Producto),1,arch);
        if(prod.codigo==bus)
            pos=medio;
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

int cantRegistros(FILE * a)
{
    fseek(a,0,SEEK_END);
    return ftell(a)/sizeof(Producto);
}
