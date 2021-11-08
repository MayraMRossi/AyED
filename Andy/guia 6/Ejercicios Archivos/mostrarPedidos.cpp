#include <iostream>
using namespace std;

struct Pedido
{
    int nroPed, cod, nroCli, cantPed;
};

int main()
{
    string fileName;
    cout<<"¿Que archivo queres leer? ";
    cin>>fileName;
    fileName.append(".dat");
    FILE*f = fopen(fileName.c_str(), "rb");
    if(f==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        cout<<"Numero de pedido    Numero de Cliente    Codigo de Producto    Cantidad pedida"<<endl;
        Pedido ped;
        fread(&ped, sizeof(Pedido), 1, f);
        while(!feof(f))
        {
            cout<<"       "<<ped.nroPed<<"                  "<<ped.nroCli<<"                     "<<ped.cod<<"                   "<<ped.cantPed<<endl;
            fread(&ped, sizeof(Pedido), 1, f);
        }
    }
}