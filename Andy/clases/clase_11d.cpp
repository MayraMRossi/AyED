//Mostrar Archivo

#include <iostream>
#include <stdio.h>
using namespace std;

struct Examen
{
    int leg;
    char nom[36];
    int nota;
};

int main()
{
    FILE*file2=fopen("Parcial.dat","rb");
    if(file2==NULL)
        cout<<"Error al crear el archivo"<<endl;
    else
    {
        Examen ex;
        fread(&ex, sizeof(ex), 1, file2); //Trae del archivo a memoria la cantidad de bits indicados
        //feof: indica verdadero si al leer detecto la marca de fin de archivo, sino es falsa
        while(!feof(file2))
        {
            cout<<ex.leg<<" "<<" "<<ex.nom<<" "<<ex.nota<<endl;
            fread(&ex, sizeof(ex), 1, file2);
        }
        fclose(file2);
    }


    return 0;
}