/*
Voy a usar una lista que contenga:
- Dni
- Dosis
- Fecha
Uso esta estructura de datos ya que necesito tener a la gente ordenada por dni y no tengo un limite de personas.
Luego, para armar el archivo, hago un corte de control en la lista por persona.
*/
#include <iostream>
using namespace std;

struct Fecha
{
    int dia, mes, anio;
};

struct DatoArch
{
    int nro_doc;
    int edad;
    Fecha fecha;
    char vacuna[15];
    int dosis; //1 o 2
    int centro_vacunacion; //de 1 a 30
};

struct Vacunado
{
    int dni;
    int dosis;
    Fecha fecha;
    int centro_vacunacion;
    int edad;
};

struct Nodo
{
    Vacunado info;
    Nodo *sig;
};

struct DatoArch2
{
    int dni;
    Fecha fecha_dosis1;
    Fecha fecha_dosis2;
    int centro1;
    int centro2;
}

int main()
{
    Nodo lista_vacunados = NULL;
}

void de_arch_a_lista(Nodo*&lista)
{
    FILE*f = fopen("Inscriptos.dat", "rb");
    if(f!=NULL);
    {
        DatoArch da;
        Vacunado vac;
        Nodo*p;
        fread(&da, sizeof(DatoArch), 1, f);
        while(!feof(f))
        {
            vac.dni = da.dni;
            vac.fecha = da.fecha;
            vac.dosis = da.dosis;
            vac.centro_vacunacion = da.centro_vacunacion;
            vac.edad = da.edad;
            insertar(lista, vac);
            fread(&da, sizeof(DatoArch), 1, f);
        }
    }
    fclose(f);
}

void insertar(Nodo*&lista, Vacunado vac)
{
    Nodo *n=new Nodo, *l=lista, *ant;
    n->info = dni;
    while(l!=NULL && l->info.dni < dni)
    {
        ant=l;
        l=l->sig;
    }
    n->sig=l;
    if(lista!=l)
        ant->sig=n;
    else
        lista=n;
}

void corte_control(Nodo*lista)
{
    FILE*f = fopen("Menores.dat", "wb");
    if(f!=NULL)
    {
        bool dosis1, dosis2;
        int dni;
        DatoArch2 da;
        while(lista!=NULL)
        {
            dosis1=dosis2=false;
            dni=lista->info.dni;
            do
            {
                if(lista->info.dosis==1)
                {
                    da.fecha_dosis1 = lista->info.fecha;
                    da.centro1 = lista->info.centro_vacunacion;
                    dosis1=true;
                }
                else
                {
                    da.fecha_dosis2 = lista->info.fecha;
                    da.centro2 = lista->info.centro_vacunacion;
                    dosis2=true
                }
                lista=lista->sig;
            } while(lista!=NULL && lista->info.dni==dni);
            if(lista->info.edad<18 && dosis1 && dosis2)
                fwrite(&da,sizeof(DatoArch), 1, f);
        }
    }
}