//Agregar nuevos elementos a archivos
//ab: agrega nuevos elementos en un archivo existente, sino crea el archivo

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Parcial
{
    int legajo;
    char nombre[36];
    int nota;
};

int main()
{
    char nombArch[21];
    cout<<"Ingrese el nombre del archivo: ";
    cin>>nombArch;
    strcat(nombArch, ".dat");

    FILE*archParcial=fopen(nombArch, "ab");
    if(archParcial==NULL)
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

            fwrite(&parcial, sizeof(Parcial), 1, archParcial);

            cout<<"Legajo (cero para finalizar) ";
            cin>>parcial.legajo;
        }
        fclose(archParcial);
    }
}
