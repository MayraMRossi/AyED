#include <iostream>
#include <string.h>
using namespace std;

struct series
{
    int id, numTemp, numEp, cantDes, fechaDes;
    char titulo[20];
};

void cargarSeries();
void mostrarListado(FILE*f);
void mostrarFecha(int fecha);

int main()
{
    //cargarSeries();
    
    FILE* f = fopen("Episodios.dat", "rb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        mostrarListado(f);
    }
    fclose(f);
}

void cargarSeries()
{
    FILE*f = fopen("Episodios.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        series s;
        cout<<"Id: ";
        cin>>s.id;
        while(s.id!=0)
        {
            cout<<"Titulo: ";
            cin.ignore();
            cin.getline(s.titulo, 20);
            cout<<"Nro Temporada: ";
            cin>>s.numTemp;
            cout<<"Nro Episodio: ";
            cin>>s.numEp;
            cout<<"Cantidad de descargas: ";
            cin>>s.cantDes;
            cout<<"Fecha de ultima descarga: ";
            cin>>s.fechaDes;
            fwrite(&s, sizeof(series), 1, f);
            cout<<"Id: ";
            cin>>s.id;
        }
    }
    fclose(f);
}

void mostrarListado(FILE*f)
{
    int id, temp, cantEpTemp, totalDesTemp, cantEpSerie, totalDesSerie, totalSeries=0;
    series s;
    cout<<"                         Listado de Descargas de Series"<<endl;
    fread(&s, sizeof(series), 1, f);
    while(!feof(f))
    {
        id=s.id;
        cout<<"Serie: "<<id<<endl;
        cantEpSerie=0;
        totalDesSerie=0;
        do
        {
            temp=s.numTemp;
            cout<<"  Temporada: "<<temp<<endl;
            cantEpTemp=0;
            totalDesTemp=0;
            cout<<"     N. de Episodio          Titulo del Episodio          Cant. descargas        Fecha de ultima descarga   "<<endl;
            do
            {
                cout<<"            "<<s.numEp<<"                     "<<s.titulo<<"                         "<<s.cantDes<<"                      "; mostrarFecha(s.fechaDes); cout<<endl;
                cantEpTemp++;
                cantEpSerie++;
                totalDesTemp+=s.cantDes;
                totalDesSerie+=s.cantDes;
                fread(&s, sizeof(series), 1, f);
            } while (!feof(f) && temp==s.numTemp);
            
            cout<<endl<<"*Cant. Total de Episodios de la Temporada: "<<cantEpTemp<<endl;
            cout<<"*Total descargas de la Temporada: "<<totalDesTemp<<endl<<endl;
        } while(!feof(f) && s.id==id);

        cout<<"**Cant. Total de Episodios de la Serie: "<<cantEpSerie<<endl;
        cout<<"**Total descargas de la Serie: "<<totalDesSerie<<endl<<endl;
        totalSeries++;
    }
    cout<<endl<<"TOTAL GENERAL DE SERIES: "<<totalSeries<<endl;
}

void mostrarFecha(int fecha)
{
    int dia, mes, anio;
    string fechaMod;

    dia = fecha/1000000;
    mes = (fecha-dia*1000000)/10000;
    anio = fecha%10000;

    cout<<dia<<"/"<<mes<<"/"<<anio;
}