#include <iostream>
#include <string.h>
using namespace std;


struct Vehiculos
{
    char patente[6];
    char nombre[30];
    int anio_patentamiento;
};

struct Infracciones
{
    int cod_infraccion;
    char patente[6];
    int dia, mes;
    float importe;
};

struct Infracciones_act
{
    char patente[6];
    char nombre[30];
    float importe_total;
};

void cargar_vehiculos();
void cargar_infracciones();
void procesar_infracciones(FILE*vehiculos, FILE*infracciones, FILE*inf_act, Infracciones inf_vec[], int t);
void ordenar_por_patente(Infracciones v[], int t);
int cant_inf(FILE*f);
int busqueda_fecha(FILE*f, char patente[6]);
void vehiculos_por_infraccion(FILE*vehiculos, FILE*infracciones, FILE*inf_act);
void inicializar(Infracciones v[], int t);

int main()
{
    //cargar_vehiculos();
    //cargar_infracciones();

    FILE*f1= fopen("Vehiculos.dat", "rb");
    FILE*f2= fopen("Infracciones.dat", "rb");
    FILE*f3= fopen("InfracMunicipio.dat", "wb");
    if(f1 == NULL || f2 == NULL || f3 == NULL)
        cout<<"ERROR."<<endl;
    else
    {
        int tam=cant_inf(f2);
        Infracciones inf[tam];
        inicializar(inf, tam);
        ordenar_por_patente(inf, tam);
        procesar_infracciones(f1, f2, f3, inf, tam);
        vehiculos_por_infraccion(f1, f2, f3);
    }
}

void cargar_vehiculos()
{
    FILE*f = fopen("Vehiculos.dat", "wb");
    if(f == NULL)
        cout<<"ERROR."<<endl;
    else
    {
        Vehiculos v;
        cout<<"Patente (\"fin\" para finalizar): ";
        cin>>v.patente;
        while(strcmp(v.patente, "fin") != 0)
        {
            cout<<"Nombre: ";
            cin>>v.nombre;
            cout<<"Anio de patentamiento: ";
            cin>>v.anio_patentamiento;
            fwrite(&v, sizeof(Vehiculos), 1, f);
            cout<<"Patente (\"fin\" para finalizar): ";
            cin>>v.patente;
        }
    }
    fclose(f);
}

void cargar_infracciones()
{
    FILE*f = fopen("Infracciones.dat", "wb");
    if(f == NULL)
        cout<<"ERROR."<<endl;
    else
    {
        Infracciones i;
        cout<<"Codigo de infraccion: ";
        cin>>i.cod_infraccion;
        while(i.cod_infraccion != 0)
        {
            cout<<"Patente: ";
            cin>>i.patente;
            cout<<"Dia: ";
            cin>>i.dia;
            cout<<"Mes: ";
            cin>>i.mes;
            cout<<"Importe: ";
            cin>>i.importe;
            fwrite(&i, sizeof(Infracciones), 1, f);
            cout<<"Codigo de infraccion: ";
            cin>>i.cod_infraccion;
        }
    }
    fclose(f);
}

void procesar_infracciones(FILE*vehiculos, FILE*infracciones, FILE*inf_act, Infracciones inf[], int t)
{
    int i=0, j, inf_vehiculo, pos, fecha;
    Infracciones_act infrac;
    Vehiculos v;

    // Corte de control (calcula los importes de cada vehiculo por patente)
    while(i<t)
    {
        inf_vehiculo=0;
        j=i;
        do
        {
            pos = busqueda_fecha(vehiculos, inf[i].patente);
            if(pos != -1)
            {
                fseek(vehiculos, pos-1, SEEK_SET);
                fread(&v, sizeof(Vehiculos), 1, vehiculos);
                fecha = v.anio_patentamiento;
                if(2021-fecha > 20) // Descuento del importe 
                    inf[j].importe = inf[j].importe*20/100;
                inf_vehiculo+=inf[j].importe;

                strcpy(infrac.patente, v.patente);
                strcpy(infrac.nombre, v.nombre);
            }
            j++;
        } while (j<t && strcmp(inf[j].patente, inf[i].patente)==0);
        
        infrac.importe_total = inf_vehiculo;
        i=j;

        fwrite(&infrac, sizeof(Infracciones_act), 1, inf_act);
    }
}

void vehiculos_por_infraccion(FILE*vehiculos, FILE*infracciones, FILE*inf_act)
{
    // Corte de control por codigo de infraccion
    Infracciones inf;
    Vehiculos v;
    int cod, cant_veh=0, pos, fecha, i=0;
    float importe_total=0;
    string veh_sin_infracciones[1000];
    fread(&inf, sizeof(Infracciones), 1, infracciones);
    while(!feof(infracciones))
    {
        cod = inf.cod_infraccion;
        pos = busqueda_fecha(vehiculos, inf.patente);
        cout<<"Cod de Infraccion: "<<cod<<endl;
        do
        {
            if(pos != -1)
            {
                fseek(vehiculos, pos-1, SEEK_SET);
                fread(&v, sizeof(Vehiculos), 1, vehiculos);
                fecha = v.anio_patentamiento;
                if(2021-fecha > 20) // Descuento del importe 
                    inf.importe = inf.importe*20/100;
                importe_total+=inf.importe;

                cant_veh++;
            }
            else
            {
                veh_sin_infracciones[i] = v.patente;
                i++;
            }
            cout<<"Importe total: "<<importe_total<<endl<<endl;
            
        } while (!feof(infracciones) && cod == inf.cod_infraccion);
    }
    cout<<"Transportes sin Infracciones: "<<endl;
    for(int j=0; j<i; j++)
        cout<<veh_sin_infracciones[j]<<endl;
    
}

int busqueda_fecha(FILE*f, char patente[6])
{
    Vehiculos v;
    int i=0;
    fread(&v, sizeof(Vehiculos), 1, f);
    while(!feof(f) && strcmp(v.patente, patente)!=0)
    {
        fread(&v, sizeof(Vehiculos), 1, f);
        i++;
    }
    if(!feof(f))
    {
        return i;
    }
    else
        return -1;
}

void inicializar(Infracciones v[], int t)
{
    for(int i=0; i<t; i++)
        v[i].cod_infraccion=0;
}

void ordenar_por_patente(Infracciones v[], int t)
{
    int i=1, j=0;
    Infracciones aux;
    bool cambio;

    do
    {
        cambio = false;
        for(j=0; j<t-1; j++)
        {
            if(strcmp(v[j].patente, v[j+1].patente) < 0)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=v[j];
            }
        }
        i++;
    } while (i<t && cambio);
    
}

int cant_inf(FILE*f)
{
    Infracciones inf;
    int i=0;
    fread(&inf, sizeof(Infracciones), 1, f);
    while(!feof(f))
    {
        i++;
    }
    return i;
}

