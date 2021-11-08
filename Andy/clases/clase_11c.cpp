//Archivos de Datos (binarios): almacena datos en memoria auxiliar, para mantener esos datos

//Cargar archivo
#include <iostream>
#include <stdio.h>
using namespace std;

struct Parcial
{
    int legajo;
    char nombre[36];
    int nota;
};

int main()
{
    //Tres tipos de apertura: wb (write o escribir), rb (read o leer), ab (append o agregar)
    FILE*file=fopen("Parcial.dat","wb");
    if(file==NULL)
        cout<<"Error al crear el archivo"<<endl;
    else
    {
        Parcial parcial;
        cout<<"Legajo (cero para finalizar) ";
        cin>>parcial.legajo;
        while(parcial.legajo!=0)
        {
            cout<<"Nombre ";
            cin.ignore();
            cin.getline(parcial.nombre, 35);
            cout<<"Nota: ";
            cin>>parcial.nota;

            fwrite(&parcial, sizeof(Parcial), 1, file);

            cout<<"Legajo (cero para finalizar) ";
            cin>>parcial.legajo;
        }
        fclose(file);
    }
    
    return 0;
}