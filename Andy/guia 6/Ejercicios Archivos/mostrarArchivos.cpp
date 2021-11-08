#include <iostream>
#include <string.h>
using namespace std;

struct Alumno
{
    char nombre[30];
    int nroLeg, codMat, dia, mes, anio;
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
        Alumno a;
        fread(&a, sizeof(Alumno), 1, f);
        while(!feof(f))
        {
            cout<<"Nro Legajo: "<<a.nroLeg<<endl
            <<"Cod Materia: "<<a.codMat<<endl
            <<"Dia: "<<a.dia<<endl
            <<"Mes: "<<a.mes<<endl
            <<"Anio: "<<a.anio<<endl
            <<"Nombre: "<<a.nombre<<endl<<endl;

            fread(&a, sizeof(Alumno), 1, f);
        }
    }
    fclose(f);
}