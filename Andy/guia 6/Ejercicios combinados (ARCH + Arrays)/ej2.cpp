#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Libros
{
    int codL, cantL, codEd;
    char titulo[30], ubicacion[3], autor[25];
};

struct Editorial
{
    char nombreEd[25];
    int codEd;
};

struct Consultas
{
    int codL, fechaCon;
};

struct EditorialCon
{
    char nombreEd[25];
    int cantLibrosConsultados;
};

void cargarLibros();
void cargarEditorial();
void cargarConsultas();
int mes(int fecha);
void inicializar(int m[][6], unsigned f, unsigned c);
string busquedaCodEd(FILE*f, int bus);
bool muyConsultado(int m[][6], int cod);
int validarCodEd();
void ordenarConsultas(Consultas v[], unsigned t);
void listadoConsultas(int cantCon[][6], FILE*libros, FILE*editorial, EditorialCon editoriales[]);
void inicializarVector(EditorialCon v[], unsigned t);
void inicializarConsultas(Consultas v[], unsigned t);
void ordenarEditoriales(EditorialCon v[]);
void listado2(EditorialCon editoriales[], FILE*editorial);
void mostrarEditoriales();
void mostrarConsultas();
int cantLibrosPorCod(int m[][6], int cod);
void mostrarVec(EditorialCon v[], int t);
void cargarCantCon(int cantCon[][6]);

int main()
{
    //cargarLibros();
    //cargarEditorial();
    //cargarConsultas();
    
    int cantConsultas[1000][6];
    EditorialCon editoriales[200];

    inicializar(cantConsultas, 1000, 6);
    inicializarVector(editoriales, 200);

    cargarCantCon(cantConsultas);

    FILE* libros = fopen("Libros.dat", "rb");
    FILE* editorial = fopen("Editoriales.dat", "rb");
    if(libros == NULL || editorial == NULL)
        cout<<"Error."<<endl;
    else
    {
        listadoConsultas(cantConsultas, libros, editorial, editoriales);
        cout<<endl<<"Muestra del vector (es de prueba): "<<endl;
        mostrarVec(editoriales, 200);
        cout<<endl;
        listado2(editoriales, editorial);
    }
    fclose(libros);
    fclose(editorial);
    
    //mostrarEditoriales(); 
    //mostrarConsultas();
}

void cargarLibros()
{
    FILE* f = fopen("Libros.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        Libros l;
        cout<<"Cod libro: ";
        cin>>l.codL;
        while(l.codL!=0)
        {
            cout<<"Titulo libro: ";
            cin.ignore();
            cin.getline(l.titulo, 30);
            cout<<"Cant ejemplares: ";
            cin>>l.cantL;
            cout<<"Ubicacion: ";
            cin.ignore();
            cin.getline(l.ubicacion, 4);
            cout<<"Cod editorial: ";
            l.codEd = validarCodEd();
            cout<<"Autor: ";
            cin.ignore();
            cin.getline(l.autor, 25);
            fwrite(&l, sizeof(Libros), 1, f);
            cout<<"Cod libro: ";
            cin>>l.codL;
        }
    }
    fclose(f);
}

void cargarEditorial()
{
    FILE* f = fopen("Editoriales.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        Editorial e;
        cout<<"Cod Editorial: ";
        e.codEd = validarCodEd();
        while(e.codEd != 0)
        {
            cout<<"Nombre Editorial: ";
            cin.ignore();
            cin.getline(e.nombreEd, 25);
            fwrite(&e, sizeof(Editorial), 1, f);
            cout<<"Cod Editorial: ";
            cin>>e.codEd;
        }
    }
    fclose(f);
}

void cargarConsultas()
{
    FILE* f = fopen("Consultas.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        int i=0;
        Consultas c;
        cout<<"Cod libro: ";
        cin>>c.codL;
        while(c.codL != 0 && i<1000)
        {
            cout<<"Fecha de consulta: ";
            cin>>c.fechaCon;
            fwrite(&c, sizeof(Consultas), 1, f);
            i++;
            cout<<"Cod libro: ";
            cin>>c.codL;
        }
    }
    fclose(f);
}

void cargarCantCon(int cantCon[][6])
{
    FILE* f = fopen("Consultas.dat", "rb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        int m;
        Consultas c;
        fread(&c, sizeof(Consultas), 1, f);
        while(!feof(f))
        {
            m = mes(c.fechaCon);
            cantCon[c.codL-1][m-1]++;
            fread(&c, sizeof(Consultas), 1, f);
        }
    }
    fclose(f);
}

void inicializarConsultas(Consultas v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        v[i].codL = 0;
    }
}

void ordenarConsultas(Consultas v[], unsigned t)
{
    int i=1, j=0;
    Consultas aux;
    bool cambio;
    do
    {
        cambio = false;
        for(j=0; j<t-1; j++)
        {
            if(v[j].codL>v[j+1].codL)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    } while(i<t && cambio);
}

int mes(int fecha)
{
    int dia, mes, anio;

    anio = fecha/10000;
    dia = fecha%100;
    mes = ((fecha-anio*10000)-dia)/100;

    return mes;
}

void inicializar(int m[][6], unsigned f, unsigned c)
{
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
            m[i][j] = 0;
    }
}

string busquedaCodEd(FILE*f, int bus)
{
    Editorial e;
    int pos=0;
    fread(&e.codEd, sizeof(Editorial), 1, f);
    while(e.codEd != bus && !feof(f))
    {
        pos++;
        fread(&e.codEd, sizeof(Editorial), 1, f);
    }
    if(feof(f))
        return " ";
    else
        return e.nombreEd;
}

bool muyConsultado(int m[][6], int cod, int &sumaL)
{
    bool ret=true;

    for(int i=0; i<6; i++)
    {
        if(m[cod-1][i]<2)
            ret=false;
        sumaL+=m[cod-1][i];
    }
    return ret;
}

int validarCodEd()
{
    int n;
    do
    {
        cin>>n;
    } while (n<0 || n>200);
    return n;
}

void listadoConsultas(int cantCon[][6], FILE*libros, FILE*editorial, EditorialCon editoriales[])
{
    cout<<"   Codigo del Libro       Titulo      Autor      Editoral        Consultas en el Semestre   "<<endl;
    cout<<"                                                                1    2    3    4    5    6     "<<endl;
    Libros libro;
    int sumaL;
    fread(&libro, sizeof(Libros), 1, libros);
    while(!feof(libros))
    {
        sumaL=0;
        if(muyConsultado(cantCon, libro.codL, sumaL))
        {
            cout<<"         "<<libro.codL<<"             "<<libro.titulo<<"    "<<libro.autor<<"     "<<libro.codEd<<"           ";
            for(int i=0; i<6; i++)
            {
                cout<<cantCon[libro.codL-1][i]<<"    ";
            }
        }

        editoriales[libro.codEd-1].cantLibrosConsultados+=cantLibrosPorCod(cantCon, libro.codL);
        //strcpy(editoriales[libro.codEd-1].nombreEd, busquedaCodEd(editorial, j).c_str()); // Mejor inicializo el vector con los titulos directamente en vez de ir a buscarlos
        fread(&libro, sizeof(Libros), 1, libros);
    }
}

void mostrarVec(EditorialCon v[], int t)
{
    for(int i=0; i<t; i++)
    {
        if(v[i].cantLibrosConsultados!=0)
            cout<<v[i].nombreEd<<" "<<v[i].cantLibrosConsultados<<endl;
    }
}

void inicializarVector(EditorialCon v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        v[i].cantLibrosConsultados=0;
    }
    FILE* editorial = fopen("Editoriales.dat", "rb");
    if(editorial == NULL)
        cout<<"Error editorial."<<endl;
    else
    {
        Editorial e;
        fread(&e, sizeof(Editorial), 1, editorial);
        while(!feof(editorial))
        {
            strcpy(v[e.codEd-1].nombreEd, e.nombreEd);
            fread(&e, sizeof(Editorial), 1, editorial);
        }
    }
    fclose(editorial);
}

void listado2(EditorialCon editoriales[], FILE*editorial) //cambie el vector a struct, pero sigue sin cargarse
{
    ordenarEditoriales(editoriales);
    FILE*f = fopen("Libros por editorial.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        int i=0;
        while(i<200)
        {
            if(editoriales[i].cantLibrosConsultados!=0)
                fwrite(&editoriales[i], sizeof(EditorialCon), 1, f);
            i++;
        }
    }
    fclose(f);
}

void ordenarEditoriales(EditorialCon v[])
{
    int i=1, j=0;
    EditorialCon aux;
    bool cambio;
    do
    {
        cambio = false;
        for(j=0; j<200-1; j++)
        {
            if(v[j].cantLibrosConsultados<v[j+1].cantLibrosConsultados)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    } while(i<200 && cambio);
}

void mostrarEditoriales()
{
    FILE* f = fopen("Libros por editorial.dat", "rb");
    if(f != NULL)
    {
        EditorialCon e;
        fread(&e, sizeof(EditorialCon), 1, f);
        while(!feof(f))
        {
            cout<<e.nombreEd<<"   "<<e.cantLibrosConsultados<<endl;
            fread(&e, sizeof(EditorialCon), 1, f);
        }
    }
    fclose(f);
}

void mostrarConsultas()
{
    FILE* f = fopen("Consultas.dat", "rb");
    if(f != NULL)
    {
        Consultas e;
        fread(&e, sizeof(Consultas), 1, f);
        while(!feof(f))
        {
            cout<<e.codL<<"   "<<e.fechaCon<<endl;
            fread(&e, sizeof(Consultas), 1, f);
        }
    }
    fclose(f);
}

int cantLibrosPorCod(int m[][6], int cod)
{
    int suma=0;

    for(int i=0; i<6; i++)
    {
        suma+=m[cod-1][i];
    }
    return suma;
}