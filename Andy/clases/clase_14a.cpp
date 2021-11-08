// Apareo y Corte de Control de Archivos

#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Parcial
{
    unsigned dni;
    char nom[21];
    unsigned nota;
};

string condicion(unsigned n1,unsigned n2);
void apareo(FILE*ap1,FILE*ap2);
void corteControl(FILE*a);

int main()
{

    FILE *p1=fopen("Parcial1.dat","rb");
    if(p1!=NULL)
    {
        FILE *p2=fopen("Parcial2.dat","rb");
        if(p2!=NULL)
        {
            cout<<endl<<"Apareo"<<endl;
            apareo(p1,p2);
            fclose(p1);
            fclose(p2);
        }
        fclose(p1);
    }


    FILE *ex=fopen("Examenes.dat","rb");
    if(ex!=NULL)
    {
        cout<<endl<<"Corte de control"<<endl;
        corteControl(ex);
        fclose(ex);

    }

    return 0;
}

string condicion(unsigned n1,unsigned n2)
{
    if(n1>7&&n2>7)
        return " Prom";
    else
    {
        if(n1>5&&n2>5)
            return " Final";
        else
            return " Recursa";
    }
}

void apareo(FILE*ap1,FILE*ap2)
{
    Parcial p1,p2;
    fread(&p1,sizeof(Parcial),1,ap1);
    fread(&p2,sizeof(Parcial),1,ap2);
    while(!feof(ap1)&&!feof(ap2))
    {
        if(p1.dni<p2.dni)
        {
            cout<<p1.dni<<" "<<p1.nom<<condicion(p1.nota,0)<<endl;
            fread(&p1,sizeof(Parcial),1,ap1);
        }
        else
        {
            if(p1.dni==p2.dni)
            {
                cout<<p1.dni<<" "<<p1.nom<<condicion(p1.nota,p2.nota)<<endl;
                fread(&p1,sizeof(Parcial),1,ap1);
                fread(&p2,sizeof(Parcial),1,ap2);
            }
            else
            {
                cout<<p2.dni<<" "<<p2.nom<<condicion(0,p2.nota)<<endl;
                fread(&p2,sizeof(Parcial),1,ap2);
            }
        }
    }
    while(!feof(ap1))
    {
        cout<<p1.dni<<" "<<p1.nom<<condicion(p1.nota,0)<<endl;
        fread(&p1,sizeof(Parcial),1,ap1);
    }
    while(!feof(ap2))
    {
        cout<<p2.dni<<" "<<p2.nom<<condicion(0,p2.nota)<<endl;
        fread(&p2,sizeof(Parcial),1,ap2);
    }
}

void corteControl(FILE*a)
{
    unsigned dniA,suma,cont;
    Parcial p;
    fread(&p,sizeof(Parcial),1,a);
    while(!feof(a))
    {
        dniA=p.dni;
        suma=0;
        cont=0;
        do
        {
            suma+=p.nota;
            cont++;
            fread(&p,sizeof(Parcial),1,a);
        }while(!feof(a)&&p.dni==dniA);
        cout<<"DNI: "<<dniA<<"  Promedio: "<<suma/cont<<endl;
    }
}
