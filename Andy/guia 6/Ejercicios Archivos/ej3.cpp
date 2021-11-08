#include <iostream>
using namespace std;

struct Alumno
{
    char nombre[30];
    int nroLeg, codMat, dia, mes, anio;
};

void cargarFinales();
void actualizarIncripciones();

int main()
{
    //cargarFinales();
    actualizarIncripciones();
}

void cargarFinales()
{
    Alumno a;
    FILE*f = fopen("FINALES.dat", "wb");
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

void actualizarIncripciones()
{
    FILE*f1 = fopen("DIAFINALES.dat", "rb");
    FILE*f2 = fopen("FINALES.dat", "ab");
    if(f1 == NULL || f2 == NULL)
        cout<<"ERROR"<<endl;
    else
    {
        Alumno a;
        fread(&a, sizeof(Alumno), 1, f1);
        while(!feof(f1))
        {
            fwrite(&a, sizeof(Alumno), 1, f2);
            fread(&a, sizeof(Alumno), 1, f1);
        }
    }
    fclose(f1);
    fclose(f2);
}