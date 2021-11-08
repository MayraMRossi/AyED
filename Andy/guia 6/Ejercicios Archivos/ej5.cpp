#include <iostream>
using namespace std;

struct alumno
{
    int leg, codM;
    string nombre;
};

void cargarArchivos();
void mostrarArchivos();
void apareo(FILE*f1, FILE*f2, FILE*f3);

int main()
{
    //cargarArchivos();
    mostrarArchivos();
    /*
    FILE*f1 = fopen("MAESTROSFINALES.dat", "rb");
    FILE*f2 = fopen("DIAFINALES.dat", "rb");
    FILE*f3 = fopen("FINALESACT.dat", "ab");
    if(f1 == NULL || f2 == NULL || f3 == NULL)
        cout<<"Error."<<endl;
    else
    {
        apareo(f1, f2, f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    */
    return 0;
}

void cargarArchivos()
{
    string nombreF;
    cout<<"Ingrese el nombre del archivo a crear: ";
    cin>>nombreF;
    nombreF.append(".dat");
    FILE*f = fopen(nombreF.c_str(), "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        alumno a;
        cout<<"Nro Legajo (CERO para finalizar): ";
        cin>>a.leg;
        while(a.leg!=0)
        {
            cout<<"Cod Materia: ";
            cin>>a.codM;
            cout<<"Nombre: ";
            cin>>a.nombre;
            fwrite(&a, sizeof(alumno), 1, f);
            cout<<"Nro Legajo (CERO para finalizar): ";
            cin>>a.leg;
        }
    }
    fclose(f);
}

void mostrarArchivos()
{
    string nombreF;
    cout<<"Ingrese el nombre del archivo a leer: ";
    cin>>nombreF;
    nombreF.append(".dat");
    FILE*f = fopen(nombreF.c_str(), "rb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        alumno a;
        fread(&a, sizeof(alumno), 1, f);
        while(!feof(f))
        {
            cout<<a.leg<<" "<<a.codM<<" "<<a.nombre<<endl;
            fread(&a, sizeof(alumno), 1, f);
        }
    }
    fclose(f);
}

void apareo(FILE*f1, FILE*f2, FILE*f3)
{
    alumno a1, a2;
    fread(&a1, sizeof(alumno), 1, f1);
    fread(&a2, sizeof(alumno), 1, f2);
    while(!feof(f1) && !feof(f2))
    {
        if(a1.leg<a2.leg)
        {
            fwrite(&a1, sizeof(alumno), 1, f3);
            fread(&a1, sizeof(alumno), 1, f1);
        }
        else 
        {
            if(a1.leg == a2.leg)
            {
                if(a1.codM < a2.codM)
                {
                    fwrite(&a1, sizeof(alumno), 1, f3);
                    fread(&a1, sizeof(alumno), 1, f1);
                }
                else
                {
                    if(a1.codM == a2.codM) //significa que la info esta repetida, la escribo una sola vez
                    {
                        fwrite(&a1, sizeof(alumno), 1, f3);
                        fread(&a1, sizeof(alumno), 1, f1);
                        fread(&a2, sizeof(alumno), 1, f2);
                    }
                    else
                    {
                        fwrite(&a2, sizeof(alumno), 1, f3);
                        fread(&a2, sizeof(alumno), 1, f2);
                    }
                }
            }
            else
            {
                fwrite(&a2, sizeof(alumno), 1, f3);
                fread(&a2, sizeof(alumno), 1, f2);
            }
        }
    }
    while(!feof(f1))
    {
        fwrite(&a1, sizeof(alumno), 1, f3);
        fread(&a1, sizeof(alumno), 1, f1);
    }
    while(!feof(f2))
    {
        fwrite(&a2, sizeof(alumno), 1, f3);
        fread(&a2, sizeof(alumno), 1, f2);
    }
}