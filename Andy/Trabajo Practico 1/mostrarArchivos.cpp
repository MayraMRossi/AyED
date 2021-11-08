#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct rep
{
    unsigned dni;
    char nombre[40];
    char patente[10];
    int zona;
};

int main()
{
    for(int cant=0; cant<4; cant++)
    {
        rep repartidor;
        string vehiculo, nombreCompleto;
        int i=0;
        switch(cant)
        {
            case 0: vehiculo="Auto"; break;
            case 1: vehiculo="Moto"; break;
            case 2: vehiculo="Camioneta"; break;
            case 3: vehiculo="Camion"; break;
        }
            nombreCompleto.append("Rep");
            nombreCompleto.append(vehiculo);
            nombreCompleto.append(".dat");
        cout<<vehiculo<<": "<<endl;
        FILE*f = fopen(nombreCompleto.c_str(), "rb");
        if(f==NULL)
            cout<<"ERROR al leer archivo"<<endl<<endl;
        else
        {
            fread(&repartidor, sizeof(rep), 1, f);
            while(!feof(f))
            {
                cout<<"  DNI: "<<repartidor.dni<<endl;
                cout<<"  Nombre: "<<repartidor.nombre<<endl;
                cout<<"  Patente: "<<repartidor.patente<<endl;
                cout<<"  Zona: "<<repartidor.zona<<endl;
                cout<<endl;
                fread(&repartidor, sizeof(rep), 1, f);
            }
            cout<<endl;
        }
        fclose(f);
    }
}