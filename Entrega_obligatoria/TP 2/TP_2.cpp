#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define ZN 14

struct rep
{
    unsigned dni;
    char nombre[40];
    char patente[10];
    int zona;
};

void inicializar(int m[][4], unsigned f, unsigned c);
void inicializarVector(int v[], unsigned t);
int validarZona();
void cargarRep(int zonas[][4], unsigned f, unsigned c);
void mostrarCantXZona(int zonas[][4], unsigned f, unsigned c, int repTotal[]);
void transpVacio(int zonas[][4], unsigned f, unsigned c);
void repXZona(int repTotal[], unsigned t);
int cant_de_rep_por_veh(int zonas[][4], unsigned f, unsigned c, unsigned vehiculo);
void pasar_a_vector(int zonas[][4], unsigned f, unsigned c);
void ordenar(rep v[], unsigned t);
void cargar_ordenado(rep vecOrdenado[], unsigned t, string vehiculo);
void mostrarArchivos();

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
    cout << endl;
    pasar_a_vector(zonas, ZN, 4);

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
    int vehiculo;
    rep repartidor;

    cout << "Vehiculo (1 Auto, 2 Moto, 3 Camioneta o 4 Camion, 0 para finalizar):";
    cin >> vehiculo;
    while (vehiculo != 0)
    {
        switch (vehiculo)
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
                cout << endl;

                if (zonas[repartidor.zona - 1][0] <= 20)
                {
                    fwrite(&repartidor, sizeof(rep), 1, f);
                    zonas[repartidor.zona - 1][0]++;
                }
                else
                    cout << "Se alcanzo el numero maximo de repartidores por zona y vehiculo" << endl;
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
                cout << endl;

                if (zonas[repartidor.zona - 1][1] <= 20)
                {
                    fwrite(&repartidor, sizeof(rep), 1, f);
                    zonas[repartidor.zona - 1][1]++;
                }
                else
                    cout << "Se alcanzo el numero maximo de repartidores por zona y vehiculo";
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
                cout << endl;

                if (zonas[repartidor.zona - 1][2] <= 20)
                {
                    fwrite(&repartidor, sizeof(rep), 1, f);
                    zonas[repartidor.zona - 1][2]++;
                }
                else
                    cout << "Se alcanzo el numero maximo de repartidores por zona y vehiculo";
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
                cout << endl;

                if (zonas[repartidor.zona - 1][2] <= 20)
                {
                    fwrite(&repartidor, sizeof(rep), 1, f);
                    zonas[repartidor.zona - 1][3]++;
                }
                else
                    cout << "Se alcanzo el numero maximo de repartidores por zona y vehiculo";
            }
            fclose(f);
        }
        break;

        default:
            cout << "El numero no se encuentra dentro del rango aceptado. Por favor vuelva a ingresar: ";
            break;
        }
        cout << "Vehiculo (1 Auto, 2 Moto, 3 Camioneta o 4 Camion, 0 para finalizar):";
        cin >> vehiculo;
    }
}

int validarZona()
{
    int z;
    do
    {
        cout << "Zona: (1 a " << ZN << ")";
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
    bool flag = true;
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
            flag = false;
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
        if (flag)
            cout << "Todos los vehiculos estan disponibles" << endl;
    }
}

void repXZona(int repTotal[], unsigned t)
{
    int mayorRep, mayorZona[14], pos = 0;
    for (int i = 0; i < t; i++)
    {
        if (i == 0 || repTotal[i] > mayorRep)
        {
            mayorRep = repTotal[i];
            mayorZona[0] = i + 1;
            pos = 0;
        }
        else
        {
            if (repTotal[i] == mayorRep)
            {
                pos++;
                mayorRep = repTotal[i];
                mayorZona[pos] = i + 1;
            }
        }
    }
    cout << "La/s zona/s con mas repartidores: " << endl;
    for (int j = 0; j <= pos; j++)
    {
        cout << mayorZona[j] << endl;
    }
}

int cant_de_rep_por_veh(int zonas[][4], unsigned f, unsigned c, unsigned vehiculo) //dice la cantidad de repartidores dado el vehiculo
{
    int cant[4];
    inicializarVector(cant, 4);
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < f; i++)
        {
            cant[j] += zonas[i][j];
        }
    }
    return cant[vehiculo];
}

void pasar_a_vector(int zonas[][4], unsigned f, unsigned c) //pasa los datos del archivo a un vector con n posiciones, siendo n la cantidad de repartidores por zona (de todos los vehiculos)
{
    for (int nro_veh = 0; nro_veh < c; nro_veh++)
    {

        string vehiculo, nombreCompleto;
        switch (nro_veh)
        {
        case 0:
            vehiculo = "Auto";
            break;
        case 1:
            vehiculo = "Moto";
            break;
        case 2:
            vehiculo = "Camioneta";
            break;
        case 3:
            vehiculo = "Camion";
            break;
        }
        nombreCompleto.append("Rep");
        nombreCompleto.append(vehiculo);
        nombreCompleto.append(".dat");
        int cant = cant_de_rep_por_veh(zonas, f, c, nro_veh);
        rep vecOrdenado[cant];
        FILE *f = fopen(nombreCompleto.c_str(), "rb");
        if (f == NULL)
            cout << "ERROR al leer archivo" << endl;
        else
        {
            for (int i = 0; i < cant; i++)
            {
                fread(&vecOrdenado[i], sizeof(rep), 1, f);
            }
        }
        fclose(f);
        ordenar(vecOrdenado, cant);
        cargar_ordenado(vecOrdenado, cant, vehiculo);
    }
}

void ordenar(rep v[], unsigned t) //ordena el vector
{
    int i = 1, j;
    rep aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].dni > v[j + 1].dni)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void cargar_ordenado(rep vecOrdenado[], unsigned t, string vehiculo) //carga el vector ordenado devuelta al archivo con un "wb"
{
    string nombreCompleto;
    nombreCompleto.append("Rep");
    nombreCompleto.append(vehiculo);
    nombreCompleto.append(".dat");
    FILE *f = fopen(nombreCompleto.c_str(), "wb");
    if (f == NULL)
        cout << "ERROR al escribir el archivo" << endl;
    else
    {
        for (int i = 0; i < t; i++)
        {
            fwrite(&vecOrdenado[i], sizeof(rep), 1, f);
        }
    }
    fclose(f);
}

void mostrarArchivos()
{
    for (int cant = 0; cant < 4; cant++)
    {
        rep repartidor;
        string vehiculo, nombreCompleto;
        int i = 0;
        switch (cant)
        {
        case 0:
            vehiculo = "Auto";
            break;
        case 1:
            vehiculo = "Moto";
            break;
        case 2:
            vehiculo = "Camioneta";
            break;
        case 3:
            vehiculo = "Camion";
            break;
        }
        nombreCompleto.append("Rep");
        nombreCompleto.append(vehiculo);
        nombreCompleto.append(".dat");
        FILE *f = fopen(nombreCompleto.c_str(), "rb");
        if (f == NULL)
            cout << "ERROR al leer archivo" << endl;
        else
        {
            fread(&repartidor, sizeof(rep), 1, f);
            cout << vehiculo << ": " << endl;
            while (!feof(f))
            {
                cout << "  DNI: " << repartidor.dni << endl;
                cout << "  Nombre: " << repartidor.nombre << endl;
                cout << "  Patente: " << repartidor.patente << endl;
                cout << "  Zona: " << repartidor.zona << endl;
                cout << endl;
                fread(&repartidor, sizeof(rep), 1, f);
            }
            cout << endl;
        }
        fclose(f);
    }
}