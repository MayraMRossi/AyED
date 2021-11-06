#include <iostream>
#include <stdio.h>


using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

struct Pedido
{
    unsigned nroPed;
    unsigned nroCli;
    unsigned codProd;
    unsigned cant;
};

void procesarPedidos(FILE*aProd,FILE*aPedidos,FILE*aPedNoS);
bool actualizarStock(FILE*ap,unsigned unCodigo,unsigned unaCant);

int main()
{
    FILE *aProd,*aPedidos,*aPedNoS;
    aProd=fopen("Productos.dat","rb+");
    if(aProd!=NULL)
    {
        aPedidos=fopen("Pedidos.dat","rb");
        if(aPedidos!=NULL)
        {
            aPedNoS=fopen("PedNoS.dat","wb");
            if(aPedNoS!=NULL)
            {
                procesarPedidos(aProd,aPedidos,aPedNoS);
               fclose(aPedNoS);
            }
           fclose(aPedidos);
        }
        fclose(aProd);
    }

    return 0;
}

void procesarPedidos(FILE*aProd,FILE*aPedidos,FILE*aPedNoS)
{
    Pedido pedido;
    mostrarTitulos();
    fread(&pedido,sizeof(Pedido),1,aPedidos);
    while(!feof(aPedidos))
    {
        if(actualizarStock(aProd,pedido.codProd,pedido.cant))
            mostrar(pedido);
        else
            fwrite(&pedido,sizeof(Pedido),1,aPedNoS);
        fread(&pedido,sizeof(Pedido),1,aPedidos);
    }
}

bool actualizarStock(FILE*ap,unsigned unCodigo,unsigned unaCant)
{
    Producto prod;
    fseek(ap,(unCodigo-1)*sizeof(Producto),SEEK_SET);
    fread(&prod,sizeof(Producto),1,ap);
    if(prod.stock>=unaCant)
    {
        prod.stock-=unaCant;
        fseek(ap,-sizeof(Producto),SEEK_CUR);
        fwrite(&prod,sizeof(Producto),1,ap);
        return true;
    }
    else
        return false;
}


