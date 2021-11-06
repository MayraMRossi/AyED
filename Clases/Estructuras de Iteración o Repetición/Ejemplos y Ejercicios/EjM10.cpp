#include <iostream>

using namespace std;

int main()
{
    int cantVuelos,nroVuelo,capacidad,pasaporte,nroVMay;
    float importe,impPorVuelo,mayorRec;
    string destino;
    cout<<"Ingrese Cantidad de vuelos ";
    cin>>cantVuelos;
    for(int i=1;i<=cantVuelos;i++)
    {
        system("cls");
        impPorVuelo=0;
        cout<<"Ingrese Nro de vuelo ";
        cin>>nroVuelo;
        cout<<"Ingrese Destino ";
        cin>>destino;
        cout<<"Ingrese Cantidad de asientos ";
        cin>>capacidad;

        cout<<endl<<"Vuelo: "<<nroVuelo<<" Destino: "<<destino<<endl<<endl;

        cout<<"Ingrese Pasaporte del pasajero, cero para finalizar ";
        cin>>pasaporte;
        while(pasaporte!=0 && capacidad>0)
        {
            cout<<"Ingrese Importe abonado ";
            cin>>importe;
            impPorVuelo+=importe;
            capacidad--;
            cout<<endl<<"Nro Pasaporte: "<<pasaporte<<" Importe: "<<importe<<endl<<endl;

            cout<<"Ingrese Pasaporte del pasajero, cero para finalizar ";
            cin>>pasaporte;
        }
        if(pasaporte!=0)
            cout<<"Hubo sobreventa"<<endl;
        cout<<"Total recaudado del vuelo: "<<impPorVuelo<<endl;
        cout<<" Asientos libres: "<<capacidad<<endl;
        if(i==1 || impPorVuelo>mayorRec)
        {
            mayorRec=impPorVuelo;
            nroVMay=nroVuelo;
        }
    }
    cout<<"Nro de vuelo con mayor recaudacion: "<<nroVMay<<endl;

    return 0;
}
