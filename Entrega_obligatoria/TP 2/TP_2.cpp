#include <iostream>
#include <stdio.h>
using namespace std;

struct rep {
    unsigned dni;
    char nombre[40];
    string patente;
    int zona;
    int vehiculo;
};

void inicializar(int m[][4], unsigned f, unsigned c);
int validarZona();
void cargarRep(int zonas[][4], unsigned f, unsigned c);
void mostrarZonas(int zonas[][4], unsigned f, unsigned c);


int main()
{
    int zonas [14][4];
    inicializar(zonas, 14, 4);
    cargarRep(zonas, 14, 4);
    mostrarZonas(zonas, 14, 4);
    /*mostrarCantXZona (zonas,14,4);
    transpVacio (zonas,14,4);
    repXZona (zonas,14,4);*/
    
    
    return 0;
}

void inicializar(int m[][4], unsigned f, unsigned c)
{
    for(int i=0; i<f ;i++)
    {
        for(int j=0; j<c ;j++)
            m[i][j]=0;
    }
}

void cargarRep(int zonas[][4], unsigned f, unsigned c)
{
    rep repartidor;


    cout<<"Vehiculo (1 Auto, 2 Moto, 3 Camioneta o 4 Camion, 0 para finalizar):";
    cin>>repartidor.vehiculo;
    switch(repartidor.vehiculo)
    {
        case 1: 
        {
            FILE*f = fopen("RepAuto.dat", "ab");
            if(f==NULL)
                cout<<"ERROR al cargar"<<endl;
            else
            {
                cout<<"DNI: ";
                cin>>repartidor.dni;
                cout<<"Nombre: ";
                cin.ignore();
                cin.getline(repartidor.nombre, 40);
                cout<<"Patente: ";
                cin>>repartidor.patente;
                
                repartidor.zona = validarZona(); 

                fwrite(&repartidor, sizeof(repartidor), 1, f);


                zonas[repartidor.zona-1][0]++;
                
            }
            fclose(f);
        }
    }
    
}



int validarZona()
{
    int z;
    do{
        cout<<"Zona: (1-14)";
        cin>>z;
    }while(z<1 || z>14);   

    return z;
}

void mostrarZonas(int zonas[][4], unsigned f, unsigned c)
{
    for(int i=0; i<f ;i++)
    {
        for(int j=0; j<c ;j++)
            cout<<zonas[i][j];
        cout<<endl;
    }
}



