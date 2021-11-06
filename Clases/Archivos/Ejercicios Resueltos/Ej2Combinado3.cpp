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

struct LibVec
{
    int codLib;
    char titulo[31];
    char autor[26];
    int codEdi;
    int cantCons[6];
};

void inicializar(int m[][6],int cf,int cc);
void inicializar(FILE*ae,EditorialCons v[]);
int obtenerMes(int f);
bool tieneMas20(int m[]);
void grabarArchPto2(FILE*aConsEdit,EditorialCons vecEdit[]);
void ordenar(EditorialCons v[],unsigned t);
int busquedaBinariaA(FILE* arch,unsigned bus,Libro &lib);

int busquedaSecuencialV(LibVec v[],unsigned t,int bus);
int procesarConsultas(FILE*aCons,FILE*aLibros,LibVec vL[],EditorialCons vecEdit[]);
void listadoPto1(LibVec vl[],int cl,FILE*aLibros,EditorialCons ve[]);

void inicializar(int v[],int c);

int main()
{

    LibVec codLibrosConsult[1000];


    FILE *aLibros,*aEdit,*aCons,*aConsEdit;
    aLibros=fopen("Libros.dat","rb");
    aEdit=fopen("Editoriales.dat","rb");
    aCons=fopen("Consultas.dat","rb");
    aConsEdit=fopen("EditorialesCons.dat","wb");


    EditorialCons vecEdit[200]; //para punto2 acceso directo por codigo
    inicializar(aEdit,vecEdit);

    int cantlibrosCons=procesarConsultas(aCons,aLibros,codLibrosConsult,vecEdit);
    listadoPto1(codLibrosConsult,cantlibrosCons,aLibros,vecEdit);
    grabarArchPto2(aConsEdit,vecEdit);

    fclose(aLibros);
    fclose(aEdit);
    fclose(aCons);
    fclose(aConsEdit);
    return 0;
}


int procesarConsultas(FILE*aCons,FILE*aLibros,LibVec vL[],EditorialCons vecEdit[])
{
    int cantLibCons=0,pos,mes;
    Libro lib;
    Consulta regCons;
    fread(&regCons,sizeof(Consulta),1,aCons);
    while(!feof(aCons))
    {

        pos=busquedaSecuencialV(vL,cantLibCons,regCons.codLibro);
        if(pos==-1)
        {
            pos=cantLibCons;
            vL[pos].codLib=regCons.codLibro;
            busquedaBinariaA(aLibros,regCons.codLibro,lib);
            vL[pos].codEdi=lib.codEdit;
            strcpy(vL[pos].titulo,lib.titulo);
            strcpy(vL[pos].autor,lib.autor);
            inicializar(vL[pos].cantCons,6);
            cantLibCons++;
        }
        mes=obtenerMes(regCons.fecha);
        vL[pos].cantCons[mes-1]++;

        vecEdit[vL[pos].codEdi-1].cantCons++;

        fread(&regCons,sizeof(Consulta),1,aCons);
    }
    return cantLibCons;
}



void listadoPto1(LibVec vl[],int cl,FILE*aLibros,EditorialCons ve[])
{
    //mostrarTitulo();
    for(int i=0;i<cl;i++)
    {
        if(tieneMas20(vl[i].cantCons))
        {
            cout<<vl[i].codLib;
            cout<<vl[i].titulo<<vl[i].autor<<ve[vl[i].codEdi-1].nom;
            for(int j=0;j<6;j++)
                cout<<vl[i].cantCons[j];
            cout<<endl;

        }
    }
}


void grabarArchPto2(FILE*aConsEdit,EditorialCons vecEdit[])
{
    ordenar(vecEdit,200);
    int i=0;
    while(i<200 && vecEdit[i].cantCons!=-1)
    {
        fwrite(&vecEdit[i],sizeof(EditorialCons),1,aConsEdit);
        i++;
    }

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

bool tieneMas20(int v[])
{
   int j=0;
   while(j<6 && v[j]>20)
    j++;
   /*
   if(j==6)
    return true;
   else
    return false;
    */
    return j==6;
}

int busquedaBinariaA(FILE* arch,unsigned bus,Libro &lib)
{
    unsigned desde,hasta,medio;
    int pos=-1;
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

int busquedaSecuencialV(int v[],unsigned t,int bus)
{
    unsigned i=0;
    while(i<t && v[i]!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}
int busquedaSecuencialV(LibVec v[],unsigned t,int bus)
{
    unsigned i=0;
    while(i<t && v[i].codLib!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
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


void ordenar(EditorialCons v[],unsigned t)
{
    unsigned i=0,j;
    EditorialCons aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0;j<t-1-i;j++)
        {
            if(v[j].cantCons<v[j+1].cantCons)
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

