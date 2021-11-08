#include <iostream>
using namespace std;

struct Alumno
{
    char nombre[30];
    int nroLeg, codMat, dia, mes, anio;
};

int main()
{
    FILE*f1 = fopen("DIAFINALES.dat", "rb");
    FILE*f2 = fopen("MATFINALES.dat", "wb");
    if(f1==NULL || f2==NULL)
        cout<<"ERROR";
    else
    {
        Alumno a;
        int bus;
        cout<<"Seleccione un codigo de materia: ";
        cin>>bus;
            
        fread(&a, sizeof(Alumno), 1, f1);
        while(!feof(f1))
        {
            if(a.codMat==bus)
                fwrite(&a, sizeof(Alumno), 1, f2);
            fread(&a, sizeof(Alumno), 1, f1);
        }
    }
    fclose(f1);
    fclose(f2);
}