#include <iostream>
using namespace std;

struct series
{
    int id;
    char titulo[20], genero[20];
};

void cargarSeries();
void mostrarSeries();
void apareo(FILE*f1, FILE*f2, FILE*f3);

int main()
{
    //cargarSeries();
    mostrarSeries();
    /*
    FILE*f1 = fopen("Series.dat", "rb");
    FILE*f2 = fopen("NovSeries.dat", "rb");
    FILE*f3 = fopen("ActSeries.dat", "ab");
    if(f1 == NULL || f2 == NULL)
        cout<<"ERROR"<<endl;
    else
    {
        apareo(f1, f2, f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    */
}

void cargarSeries()
{
    FILE* f = fopen("Series.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        series s;
        cout<<"ID: ";
        cin>>s.id;
        while(s.id!=0)
        {
            cout<<"Titulo: ";
            cin.ignore();
            cin.getline(s.titulo, 20);
            cout<<"Genero: ";
            cin.getline(s.genero, 20);
            fwrite(&s, sizeof(series), 1, f);

            cout<<"ID: ";
            cin>>s.id;
        }
    }
    fclose(f);
}

void mostrarSeries()
{
    string nombreF;
    cout<<"Nombre del Archivo a leer: ";
    cin>>nombreF;
    nombreF.append(".dat");
    FILE*f = fopen(nombreF.c_str(), "rb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        series s;
        fread(&s, sizeof(series), 1, f);
        while(!feof(f))
        {
            cout<<s.id<<" "<<s.titulo<<" "<<s.genero<<endl;
            fread(&s, sizeof(series), 1, f);
        }
        fclose(f);
    }

}

void apareo(FILE*f1, FILE*f2, FILE*f3)
{
    series s1, s2;
    fread(&s1, sizeof(series), 1, f1);
    fread(&s2, sizeof(series), 1, f2);
    while(!feof(f1) && !feof(f2))
    {
        if(s1.id < s2.id)
        {
            fwrite(&s1, sizeof(series), 1, f3);
            fread(&s1, sizeof(series), 1, f1);
        }
        else if(s1.id == s2.id) //Son la misma serie, por lo que la guardo una sola vez
        {
            fwrite(&s1, sizeof(series), 1, f3);
            fread(&s1, sizeof(series), 1, f1);
            fread(&s2, sizeof(series), 1, f2);
        }
        else
        {
            fwrite(&s2, sizeof(series), 1, f3);
            fread(&s2, sizeof(series), 1, f2);
        }
    }
    while(!feof(f1))
    {
        fwrite(&s1, sizeof(series), 1, f3);
        fread(&s1, sizeof(series), 1, f1);
    }
    while(!feof(f2))
    {
        fwrite(&s2, sizeof(series), 1, f3);
        fread(&s2, sizeof(series), 1, f2);
    }
}