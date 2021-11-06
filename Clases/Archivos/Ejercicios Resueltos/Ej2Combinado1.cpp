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

void inicializar(int m[][6],int cf,int cc);
void inicializar(FILE*ae,EditorialCons v[]);
int busquedaSecuencialV(int v[],unsigned t,int bus);
int obtenerMes(int f);
int procesarConsultas(FILE*aCons,FILE*aLibros,int vL[],int mc[][6],EditorialCons vecEdit[]);
void listadoPto1(int vl[],int mConsul[][6],int cl,FILE*aLibros,EditorialCons ve[]);
bool tieneMas20(int m[][6],int x);
void grabarArchPto2(FILE*aConsEdit,EditorialCons vecEdit[]);
void ordenar(EditorialCons v[],unsigned t);
int busquedaBinariaA(FILE* arch,unsigned bus,Libro &lib);



int main()
{
    int codLibrosConsult[1000],cantConsul[1000][6]; //para punto1
    inicializar(cantConsul,1000,6);

    FILE *aLibros,*aEdit,*aCons,*aConsEdit;
    aLibros=fopen("Libros.dat","rb");
    aEdit=fopen("Editoriales.dat","rb");
    aCons=fopen("Consultas.dat","rb");
    aConsEdit=fopen("EditorialesCons.dat","wb");


    EditorialCons vecEdit[200]; //para punto2 acceso directo por codigo
    inicializar(aEdit,vecEdit);

    int cantlibrosCons=procesarConsultas(aCons,aLibros,codLibrosConsult,cantConsul,vecEdit);
    listadoPto1(codLibrosConsult,cantConsul,cantlibrosCons,aLibros,vecEdit);
    grabarArchPto2(aConsEdit,vecEdit);

    fclose(aLibros);
    fclose(aEdit);
    fclose(aCons);
    fclose(aConsEdit);
    return 0;
}

int procesarConsultas(FILE*aCons,FILE*aLibros,int vL[],int mc[][6],EditorialCons vecEdit[])
{
    int cantLibCons=0,pos,mes;
    Consulta regCons;
    fread(&regCons,sizeof(Consulta),1,aCons);
    while(!feof(aCons))
    {

        //pto1
        pos=busquedaSecuencialV(vL,cantLibCons,regCons.codLibro);
        if(pos==-1)
        {
            pos=cantLibCons;
            vL[pos]=regCons.codLibro;
            cantLibCons++;
        }
        mes=obtenerMes(regCons.fecha);
        mc[pos][mes-1]++;
        //pto1
        //pto2
        Libro lib;
        busquedaBinariaA(aLibros,regCons.codLibro,lib);
        vecEdit[lib.codEdit-1].cantCons++;
        //pto2

        fread(&regCons,sizeof(Consulta),1,aCons);
    }
    return cantLibCons;
}

void listadoPto1(int vl[],int mConsul[][6],int cl,FILE*aLibros,EditorialCons ve[])
{
    //mostrarTitulo();
    for(int i=0;i<cl;i++)
    {
        if(tieneMas20(mConsul,i))
        {
            cout<<vl[i];
            Libro lib;
            busquedaBinariaA(aLibros,vl[i],lib);
            cout<<lib.titulo<<lib.autor<<ve[lib.codEdit-1].nom;
            for(int j=0;j<6;j++)
                cout<<mConsul[i][j];
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

bool tieneMas20(int m[][6],int x)
{
   int j=0;
   while(j<6 && m[x][j]>20)
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



void inicializar(int m[][6],int cf,int cc)
{
    for(int i=0;i<cf;i++)
        for(int j=0;j<cc;j++)
            m[i][j]=0;
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

