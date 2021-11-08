#include <iostream>
using namespace std;

struct Alumno
{
    char nombre[30];
    int nroLeg, codMat, dia, mes, anio;
};

int main()
{
    Alumno a;
    FILE*f = fopen("DIAFINALES.dat", "wb");
    if(f == NULL)
        cout<<"ERROR"<<endl;
    else
    {
        cout<<"Nro de legajo: ";
        cin>>a.nroLeg;
        while(a.nroLeg!=0)
        {
            cout<<"Codigo de materia: ";
            cin>>a.codMat;
            cout<<"Dia del examen: ";
            cin>>a.dia;
            cout<<"Mes de examen: ";
            cin>>a.mes;
            cout<<"Anio del examen: ";
            cin>>a.anio;
            cout<<"Nombre y Apellido: ";
            cin.ignore();
            cin.getline(a.nombre, 30);

            fwrite(&a, sizeof(Alumno), 1, f);

            cout<<"Nro de legajo: ";
            cin>>a.nroLeg;
        }
    }
    fclose(f);
}