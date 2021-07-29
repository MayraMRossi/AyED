#include <iostream>
#include <stdio.h>
using namespace std;
#define ZN 14

struct rep
{
    unsigned dni;
    char nombre[40];
    string patente;
    int zona;
    int vehiculo;
};

void inicializar(int m[][4], unsigned f, unsigned c);
void inicializarVector(int v[], unsigned t);
int validarZona();
void cargarRep(int zonas[][4], unsigned f, unsigned c);
void mostrarCantXZona(int zonas[][4], unsigned f, unsigned c, int repTotal[]);
void transpVacio(int zonas[][4], unsigned f, unsigned c);
void repXZona(int repTotal[], unsigned t);

int main()
{
    int zonas[ZN][4];
    int repTotal[ZN];
    inicializar(zonas, ZN, 4);
    inicializarVector(repTotal, ZN);
    cargarRep(zonas, ZN, 4);
    cout << endl;
    mostrarCantXZona(zonas, ZN, 4, repTotal);
    cout << endl;
    transpVacio(zonas, ZN, 4);
    cout << endl;
    repXZona(repTotal, ZN);

    return 0;
}

void inicializar(int m[][4], unsigned f, unsigned c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            m[i][j] = 0;
    }
}

void inicializarVector(int v[], unsigned t)
{
    for (int i = 0; i < t; i++)
    {
        v[i] = 0;
    }
}

void cargarRep(int zonas[][4], unsigned f, unsigned c)
{
    rep repartidor;

    cout << "Vehiculo (1 Auto, 2 Moto, 3 Camioneta o 4 Camion, 0 para finalizar):";
    cin >> repartidor.vehiculo;
    while (repartidor.vehiculo != 0)
    {
        switch (repartidor.vehiculo)
        {
        case 1:
        {
            FILE *f = fopen("RepAuto.dat", "ab");
            if (f == NULL)
                cout << "ERROR al cargar" << endl;
            else
            {
                cout << "DNI: ";
                cin >> repartidor.dni;
                cout << "Nombre: ";
                cin.ignore();
                cin.getline(repartidor.nombre, 40);
                cout << "Patente: ";
                cin >> repartidor.patente;

                repartidor.zona = validarZona();

                fwrite(&repartidor, sizeof(repartidor), 1, f);

                zonas[repartidor.zona - 1][0]++;
            }
            fclose(f);
        }
        break;

        case 2:
        {
            FILE *f = fopen("RepMoto.dat", "ab");
            if (f == NULL)
                cout << "ERROR al cargar" << endl;
            else
            {
                cout << "DNI: ";
                cin >> repartidor.dni;
                cout << "Nombre: ";
                cin.ignore();
                cin.getline(repartidor.nombre, 40);
                cout << "Patente: ";
                cin >> repartidor.patente;

                repartidor.zona = validarZona();

                fwrite(&repartidor, sizeof(repartidor), 1, f);

                zonas[repartidor.zona - 1][1]++;
            }
            fclose(f);
        }
        break;

        case 3:
        {
            FILE *f = fopen("RepCamioneta.dat", "ab");
            if (f == NULL)
                cout << "ERROR al cargar" << endl;
            else
            {
                cout << "DNI: ";
                cin >> repartidor.dni;
                cout << "Nombre: ";
                cin.ignore();
                cin.getline(repartidor.nombre, 40);
                cout << "Patente: ";
                cin >> repartidor.patente;

                repartidor.zona = validarZona();

                fwrite(&repartidor, sizeof(repartidor), 1, f);

                zonas[repartidor.zona - 1][2]++;
            }
            fclose(f);
        }
        break;

        case 4:
        {
            FILE *f = fopen("RepCamion.dat", "ab");
            if (f == NULL)
                cout << "ERROR al cargar" << endl;
            else
            {
                cout << "DNI: ";
                cin >> repartidor.dni;
                cout << "Nombre: ";
                cin.ignore();
                cin.getline(repartidor.nombre, 40);
                cout << "Patente: ";
                cin >> repartidor.patente;

                repartidor.zona = validarZona();

                fwrite(&repartidor, sizeof(repartidor), 1, f);

                zonas[repartidor.zona - 1][3]++;
            }
            fclose(f);
        }
        break;

        default:
            cout << "El numero no se encuentra dentro del rango aceptado. Por favor vuelva a ingresar: ";
            break;
        }
        cout << "Vehiculo (1 Auto, 2 Moto, 3 Camioneta o 4 Camion, 0 para finalizar):";
        cin >> repartidor.vehiculo;
    }
}

int validarZona()
{
    int z;
    do
    {
        cout << "Zona: ";
        cin >> z;
    } while (z < 1 || z > ZN);

    return z;
}

void mostrarCantXZona(int zonas[][4], unsigned f, unsigned c, int repTotal[])
{
    cout << "Cantidad de repartidores por zona: " << endl;
    for (int i = 0; i < f; i++)
    {
        cout << "Zona " << i + 1 << endl;
        for (int j = 0; j < c; j++)
        {
            switch (j)
            {
            case 0:
                cout << "Auto: " << zonas[i][j] << "  ";
                break;
            case 1:
                cout << "Moto: " << zonas[i][j] << "  ";
                break;
            case 2:
                cout << "Camioneta: " << zonas[i][j] << "  ";
                break;
            case 3:
                cout << "Camion: " << zonas[i][j] << "  ";
                break;
            }
            repTotal[i] += zonas[i][j];
        }
        cout << endl;
    }
}

void transpVacio(int zonas[][4], unsigned f, unsigned c)
{
    int suma;
    cout << "Vehiculos no disponibles: " << endl;
    for (int j = 0; j < c; j++)
    {
        suma = 0;
        for (int i = 0; i < f; i++)
        {
            suma += zonas[i][j];
        }
        if (suma == 0)
        {
            switch (j)
            {
            case 0:
                cout << "Auto" << endl;
                break;
            case 1:
                cout << "Moto" << endl;
                break;
            case 2:
                cout << "Camioneta" << endl;
                break;
            case 3:
                cout << "Camion" << endl;
                break;
            }
        }
    }
}

void repXZona(int repTotal[], unsigned t)
{
    int mayorRep, mayorZona;
    for (int i = 0; i < t; i++)
    {
        if (i == 0 || repTotal[i] > mayorRep)
        {
            mayorRep = repTotal[i];
            mayorZona = i + 1;
        }
    }
    cout << "La zona con mas repartidores es: " << mayorZona << endl;
}
