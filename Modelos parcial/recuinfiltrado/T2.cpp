#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Estudiantes
{
    unsigned legajo;
    char apellido_nombre[20];
    unsigned Cod_beca;
    float Ingreso_prom;
};

struct Becas
{
    unsigned Cod_beca;
    string Nombre;
    unsigned Cupo_max;
};

struct Nodo_becas
{
    Becas info;
    Nodo_becas *sig;
};

struct Nodo_estudiantes
{
    Estudiantes info;
    Nodo_estudiantes *sig;
};


Nodo_becas *ingresar_becas ()
{
    Becas b;
    Nodo_becas *listaBec = NULL;

    cout<<"Ingrese el codigo de la beca: (0 para salir)"<<endl;
    cin >> b.Cod_beca >> endl;

    while(b.Cod_beca!= 0)
    {
        cout << "Ingrese el nombre de la beca: " << endl;
        cin >> b.nombre >> endl;
        cout << "Ingrese el cupo maximo: " << endl;
        cin >> b.Cupo_max >> endl;

        insertar(listaBec,b); //función básica "insertar" ordenado de menor a mayor según el código de beca con la lista pasada como parametro por referencia

        cout<<"Ingrese el codigo de la beca: (0 para salir)"<<endl;
        cin >> b.Cod_beca >> endl;
    }

    return listaBec;

}



Nodo_estudiantes *organizarInscriptos()
{
    
    Estudiantes est;
    Nodo_estudiantes *listaEst = NULL;
    //Cargo el archivo en una lista simple
    FILE*f = fopen("Solicitantes.dat", "rb");
    if(f != NULL)
    {      
        fread(&est, sizeof(Estudiantes), 1, f);  
        while(!feof(f))
        {
            
            insertar(listaEst, est); //función basica "insertar" ordenado de menor a mayor según el código de beca con la lista pasada como parametro por referencia
            fread(&est, sizeof(Estudiantes), 1, f);
        }
        fclose(f);
    }

    return listaEst;
}




void mostrarListado (Nodo_becas *listaBec,Nodo_estudiantes *listaEst)
{
    
    while (listaBec != NULL)
    {   
        int cont=0;
        cout << "Para la beca de código " << listaBec->info.Cod_beca << " y nombre " << listaBec->info.Nombre << " tiene asignados los siguientes alumnos:  "
        
        while(listaEst !=NULL && listaEst->info.Cod_beca == listaBec->info.Cod_beca)
        {
            if(cont<=listaBec->info->Cupo_max)
                cout << "Legajo: " << ListaEst->info.legajo << " Nombre y Apellido: " << ListaEst->info.apellido_nombre;

            cont++;
            listaEst = ListaEst->sig;
            
        }
        listaBec = listaBec->sig;
    }
}