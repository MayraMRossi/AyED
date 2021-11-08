#include <iostream>
#include <string.h>
using namespace std;

void cargarJuegos();

struct juegos
{
    int codJ, stock;
    char titulo[30], consola[10];
};

struct consolas
{
    char consola[10];
    int cantJuegos;
};

void cargarJuegos();
void listadoConsolas(FILE* f1, FILE* f2);
void mostrarListado();

int main() 
{
    //cargarJuegos();
    mostrarListado();

    FILE*f1 = fopen("JuegosPorConsola.dat", "ab");
    FILE*f2 = fopen("Juegos.dat", "rb");
    if(f1 == NULL || f2 == NULL)
        cout<<"Error."<<endl;
    else
    {
        //listadoConsolas(f1, f2);
    }
    fclose(f1);
    fclose(f2);
    
    return 0;
}

void cargarJuegos()
{
    FILE* f = fopen("Juegos.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        juegos j;
        cout<<"Codigo: ";
        cin>>j.codJ;
        while(j.codJ != 0)
        {
            cout<<"Titulo: ";
            cin.ignore();
            cin.getline(j.titulo, 30);
            cout<<"Stock: ";
            cin>>j.stock;
            cout<<"Consola: ";
            cin.ignore();
            cin.getline(j.consola, 10);
            fwrite(&j, sizeof(juegos), 1, f);

            cout<<"Codigo: ";
            cin>>j.codJ;
        }
    }
    fclose(f);
}

void listadoConsolas(FILE* f1, FILE* f2)
{
    consolas c;
    juegos j;

    fread(&j, sizeof(juegos), 1, f2);
    while(!feof(f2))
    {
        c.cantJuegos=0;
        strcpy(c.consola, j.consola);
        do
        {
            c.cantJuegos+=j.stock;
            fread(&j, sizeof(juegos), 1, f2);
        } while (!feof(f2) && strcmp(c.consola, j.consola)==0);
        
        fwrite(&c, sizeof(consolas), 1, f1);
    }
}

void mostrarListado()
{
    FILE*f = fopen("JuegosPorConsola.dat", "rb");
    if(f != NULL)
    {
        consolas c;
        fread(&c, sizeof(consolas), 1, f);
        while (!feof(f))
        {
            cout<<c.consola<<"  "<<c.cantJuegos<<endl;
            fread(&c, sizeof(consolas), 1, f);
        }
    }
    fclose(f);
}