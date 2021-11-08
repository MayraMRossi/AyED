#include <iostream>
#include <string.h>
using namespace std;

struct Alumnos
{
    int leg, codPostal, anioEgreso;
    char nombre[30], domicilio[20], tel[10];
    char act;
};

void cargarAlumnos();
void cargarNovedades();
void actualizarAlumnos(FILE*fa, FILE*fn, FILE*fact);
void mostrarAlumnos();

int main()
{
    //cargarAlumnos();
    //cargarNovedades();
    mostrarAlumnos();
    /*
    FILE*fa = fopen("ALUMNOS.dat", "rb");
    FILE*fn = fopen("NOVEDADES.dat", "rb");
    FILE*fact = fopen("ALUMACTU.dat", "ab");
    if(fa == NULL || fn == NULL || fact == NULL)
        cout<<"Error."<<endl;
    else
    {
        actualizarAlumnos(fa, fn, fact);
    }
    fclose(fa);
    fclose(fn);
    fclose(fact);
    */
}

void cargarAlumnos()
{
    FILE* f = fopen("ALUMNOS.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        Alumnos a;
        cout<<"Legajo: ";
        cin>>a.leg;
        while(a.leg!=0)
        {
            cout<<"Nombre: ";
            cin.ignore();
            cin.getline(a.nombre, 30);
            cout<<"Domicilio: ";
            cin.getline(a.domicilio, 20);
            cout<<"Codigo Postal: ";
            cin>>a.codPostal;
            cout<<"Telefono: ";
            cin.ignore();
            cin.getline(a.tel, 10);
            cout<<"Anio de egreso: ";
            cin>>a.anioEgreso;
            fwrite(&a, sizeof(Alumnos), 1, f);

            cout<<"Legajo: ";
            cin>>a.leg;
        }
    }
    fclose(f);
}

void cargarNovedades()
{
    FILE*f = fopen("NOVEDADES.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        Alumnos a;
        cout<<"Legajo: ";
        cin>>a.leg;
        while(a.leg!=0)
        {
            cout<<"Nombre: ";
            cin.ignore();
            cin.getline(a.nombre, 30);
            cout<<"Domicilio: ";
            cin.getline(a.domicilio, 20);
            cout<<"Codigo Postal: ";
            cin>>a.codPostal;
            cout<<"Telefono: ";
            cin.ignore();
            cin.getline(a.tel, 10);
            cout<<"Anio de egreso: ";
            cin>>a.anioEgreso;
            cout<<"Tipo de actualizacion (A: Alta, B: Baja, M: Mod): "<<endl;
            cin>>a.act;
            fwrite(&a, sizeof(Alumnos), 1, f);
            cout<<"Legajo: ";
            cin>>a.leg;
        }
    }
    fclose(f);
}

void actualizarAlumnos(FILE*fa, FILE*fn, FILE*fact)
{
    Alumnos a, n, act;
    fread(&a, sizeof(Alumnos), 1, fa);
    fread(&n, sizeof(Alumnos), 1, fn);
    while(!feof(fa) && !feof(fn))
    {
        if(a.leg < n.leg)
        {
            fwrite(&a, sizeof(Alumnos), 1, fact);
            fread(&a, sizeof(Alumnos), 1, fa);
        }
        else if(a.leg == n.leg)
        {
            if(n.act == 'B')
            {
                fread(&a, sizeof(Alumnos), 1, fa);
                fread(&n, sizeof(Alumnos), 1, fn);
            }
            else if(n.act == 'M')
            {
                fwrite(&n, sizeof(Alumnos), 1, fact);
                fread(&a, sizeof(Alumnos), 1, fa);
                fread(&n, sizeof(Alumnos), 1, fn);
            }
        }
        else
        {
            if(n.act == 'A')
            {
                fwrite(&n, sizeof(Alumnos), 1, fact);
                fread(&n, sizeof(Alumnos), 1, fn);
            }
        }
    }
    while(!feof(fa))
    {
        fwrite(&a, sizeof(Alumnos), 1, fact);
        fread(&a, sizeof(Alumnos), 1, fa);
    }
    while(!feof(fn))
    {
        if(n.act == 'A')
        {
            fwrite(&n, sizeof(Alumnos), 1, fact);
        }
        fread(&n, sizeof(Alumnos), 1, fn);
    }
}

void mostrarAlumnos()
{
    FILE* f = fopen("ALUMACTU.dat", "rb");
    if(f != NULL)
    {
        Alumnos a;
        fread(&a, sizeof(Alumnos), 1, f);
        while(!feof(f))
        {
            cout<<a.leg<<" "<<a.nombre<<" "<<a.domicilio<<" "<<a.codPostal<<" "<<a.tel<<" "<<a.anioEgreso<<endl;
            fread(&a, sizeof(Alumnos), 1, f);
        }
    }
    fclose(f);
}