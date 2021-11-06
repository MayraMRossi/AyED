#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Libro //struct archivo Libros.dat
{
    int codLibro;
    char titulo[31];
    int cantEj;
    char ubicacion[4];
    int codEdit;
    char autor[26];
};

struct Editorial //struct archivo Editoriales.dat
{
    char nom[26];
    int codE;
};

struct Consulta //struct archivo Consultas.dat
{
    int codLibro;
    int fecha;
};

struct EditorialCons//struct archivo EditorialesCons.dat
{
    char nom[26];
    int cantCons;
};

struct LibroVecListado
{
    int codLibro;
    char titulo[31];
    char autor[26];
    int codEdit;
    int consSem[6];
};

void inicializar(FILE*ae,EditorialCons v[]);
int busquedaSecuencialV(LibroVecListado v[],int t,int bus);
int obtenerMes(int f);
int busquedaBinariaA(FILE* arch,int bus,Libro &lib);
void inicializar(int v[],int c);
int procesarConsultas(FILE*aCons,FILE*aLibros,LibroVecListado vl[],EditorialCons ve[]);
void listadoPunto1(LibroVecListado vl[],int cl,EditorialCons ve[]);
void ordenar(LibroVecListado v[],int t);
bool tieneMas20(int v[]);
void generarArchPunto2(FILE*aCE,EditorialCons ve[]);
void ordenar(EditorialCons v[],int t);

int main()
{
    LibroVecListado libros[1000];
    EditorialCons editArch[200];
    int cantLibrosCons;


    FILE *aLibros,*aEdit,*aCons,*aConsEdit;
    aLibros=fopen("Libros.dat","rb");
    aEdit=fopen("Editoriales.dat","rb");
    aCons=fopen("Consultas.dat","rb");
    aConsEdit=fopen("EditorialesCons.dat","wb");

    inicializar(aEdit,editArch);

    cantLibrosCons=procesarConsultas(aCons,aLibros,libros,editArch);

    listadoPunto1(libros,cantLibrosCons,editArch);

    generarArchPunto2(aConsEdit,editArch);


    fclose(aLibros);
    fclose(aEdit);
    fclose(aCons);
    fclose(aConsEdit);

    return 0;
}

int procesarConsultas(FILE*aCons,FILE*aLibros,LibroVecListado vl[],EditorialCons ve[])
{
    int pos,mes,cantLibros=0;
    Libro libro;
    Consulta cons;
    fread(&cons,sizeof(Consulta),1,aCons);
    while(!feof(aCons))
    {
        pos=busquedaSecuencialV(vl,cantLibros,cons.codLibro);
        if(pos==-1)
        {
            vl[cantLibros].codLibro=cons.codLibro;
            busquedaBinariaA(aLibros,cons.codLibro,libro);
            strcpy(vl[cantLibros].titulo,libro.titulo);
            strcpy(vl[cantLibros].autor,libro.autor);
            vl[cantLibros].codEdit=libro.codEdit;
            inicializar(vl[cantLibros].consSem,6);

            ve[libro.codEdit-1].cantCons++;

            pos=cantLibros;
            cantLibros++;
        }

        mes=obtenerMes(cons.fecha);
        vl[pos].consSem[mes-1]++;
        //vl[pos].consSem[obtenerMes(cons.fecha)-1]++;

        fread(&cons,sizeof(Consulta),1,aCons);
    }
    return cantLibros;
}

void listadoPunto1(LibroVecListado vl[],int cl,EditorialCons ve[])
{
    //mostrarTitulos();
    ordenar(vl,cl);
    for(int i=0;i<cl;i++)
    {
        if(tieneMas20(vl[i].consSem))
        {
                    cout<<vl[i].codLibro;
                    cout<<vl[i].titulo;
                    cout<<vl[i].autor;
                    cout<<ve[vl[i].codEdit-1].nom;
                    for(int j=0;j<6;j++)
                        cout<<vl[i].consSem[j];

                    cout<<endl;
        }
    }

}

void generarArchPunto2(FILE*aCE,EditorialCons ve[])
{
    ordenar(ve,200);
    int i=0;
    while(i<200 && ve[i].cantCons!=-1)
    {
        fwrite(&ve[i],sizeof(EditorialCons),1,aCE);
        i++;
    }

}

bool tieneMas20(int v[])
{
   int j=0;
   while(j<6 && v[j]>=20)
    j++;
   /*
   if(j==6)
    return true;
   else
    return false;
    */
    return j==6;
}

int busquedaBinariaA(FILE* arch,int bus,Libro &lib)
{
    int desde,hasta,medio,pos=-1;
    desde=0;
    fseek(arch,0,SEEK_END);
    hasta=ftell(arch)/sizeof(Libro)-1;
    while(pos==-1 && desde<=hasta)
    {
        medio=(desde+hasta)/2;
        fseek(arch,medio*sizeof(Libro),SEEK_SET);
        fread(&lib,sizeof(Libro),1,arch);
        if(lib.codLibro==bus)
            pos=medio;
        else
        {
            if(bus<lib.codLibro)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}

int busquedaSecuencialV(LibroVecListado v[],int t,int bus)
{
    int i=0;
    while(i<t && v[i].codLibro!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}

void inicializar(FILE*ae,EditorialCons v[])
{
    for(int i=0;i<200;i++)
        v[i].cantCons=-1;
    Editorial reg;
    fread(&reg,sizeof(Editorial),1,ae);
    while(!feof(ae))
    {
        strcpy(v[reg.codE-1].nom,reg.nom);
        v[reg.codE-1].cantCons=0;
        fread(&reg,sizeof(Editorial),1,ae);
    }
}

void inicializar(int v[],int c)
{
    for(int i=0;i<c;i++)

            v[i]=0;
}

int obtenerMes(int f)
{
    return f/100%100;
}


void ordenar(EditorialCons v[],int t)
{
    int i=0,j;
    EditorialCons aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-1-i;j++)
        {
            if(v[j].cantCons < v[j+1].cantCons)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    }while(i<t && cambio);
}

void ordenar(LibroVecListado v[],int t)
{
    int i=0,j;
    LibroVecListado aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-1-i;j++)
        {
            if(v[j].codLibro > v[j+1].codLibro)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    }while(i<t && cambio);
}



