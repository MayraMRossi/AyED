#include <iostream>
using namespace std;

struct Producto
{
    int cod, stock;
};

struct Pedido
{
    int nroPed, cod, nroCli, cantPed;
};

void cargarProductos();
void cargarCliPed();
void realizarPedidos();

int main()
{
    //cargarProductos();
    //cargarCliPed();
    realizarPedidos();
}

void cargarProductos()
{
    FILE* f = fopen("productos.dat", "wb");
    if(f == NULL)
        cout<<"ERROR"<<endl;
    else
    {
        Producto p;
        cout<<"Cod de producto: ";
        cin>>p.cod;
        while(p.cod != 0)
        {
            cout<<"Stock: ";
            cin>>p.stock;
            fwrite(&p, sizeof(Producto), 1, f);

            cout<<"Cod de producto: ";
            cin>>p.cod;
        }
    }
    fclose(f);
}

void cargarCliPed()
{
    FILE* f = fopen("pedidos.dat", "wb");
    if(f == NULL)
        cout<<"ERROR"<<endl;
    else
    {
        Pedido p;
        cout<<"Nro de Pedido: ";
        cin>>p.nroPed;
        while(p.nroPed != 0)
        {
            cout<<"Nro Cliente: ";
            cin>>p.nroCli;
            cout<<"Cod de producto: ";
            cin>>p.cod;
            cout<<"Cant pedida: ";
            cin>>p.cantPed;
            fwrite(&p, sizeof(Pedido), 1, f);

            cout<<"Nro de Pedido: ";
            cin>>p.nroPed;
        }
    }
    fclose(f);
}

void realizarPedidos()
{
    FILE* pr = fopen("productos.dat", "rb+");
    FILE* pe = fopen("pedidos.dat", "rb");
    if(pr == NULL || pe == NULL)
        cout<<"ERROR"<<endl;
    else
    {
        cout<<"              **************** PEDIDOS SATISFECHOS ****************"<<endl;
            cout<<"Numero de pedido    Numero de Cliente    Codigo de Producto    Cantidad pedida"<<endl;
        Pedido ped;
        Producto prod;
        fread(&ped, sizeof(Pedido), 1, pe);
        while(!feof(pe))
        {
            fseek(pr, (ped.cod-1)*sizeof(Producto), SEEK_SET);
            fread(&prod, sizeof(Producto), 1, pr);
            if(ped.cod>=1 && ped.cod<=5)
            {
                if(ped.cantPed>prod.stock)
                {
                    FILE*pedNO = fopen("Pedidos_rechazados.dat", "ab");
                    if(pedNO == NULL)
                        cout<<"ERROR"<<endl;
                    else
                        fwrite(&ped, sizeof(Pedido), 1, pedNO);
                    fclose(pedNO);
                }
                else
                {
                    cout<<"       "<<ped.nroPed<<"                 "<<ped.nroCli<<"                   "<<ped.cod<<"                     "<<ped.cantPed<<endl;
                    
                    prod.stock-=ped.cantPed;
                    fseek(pr, (ped.cod-1)*sizeof(Producto), SEEK_SET);
                    fwrite(&prod, sizeof(Producto), 1, pr);
                }
            }
            else
                cout<<"No existe el codigo de producto"<<endl;
            
            fread(&ped, sizeof(Pedido), 1, pe);
        }
    }
    fclose(pr);
    fclose(pe);
}