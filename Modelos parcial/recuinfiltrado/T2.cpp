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

struct Nodo_estudiantes
{
    Estudiantes info;
    Nodo_estudiantes *sig;
};

struct Becas
{
    unsigned Cod_beca;
    string Nombre;
    unsigned Cupo_max;
    Nodo_estudiantes *sublista;
};

struct Nodo_becas
{
    Becas info;
    Nodo_becas *sig;
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



void organizarInscriptos(Nodo_becas *listaBec)
{
    
    Estudiantes est;
    Nodo_estudiantes *listaEst = NULL;
    //armo una lista con el archivo 
    FILE*f = fopen("Solicitantes.dat", "rb");
        if(f != NULL)
        {      
            fread(&est, sizeof(Estudiantes), 1, f);  
            while(!feof(f) )
            {
                //Cargo el archivo en una lista con sublistas
                insertarSub(listaBec, est); 
                fread(&est, sizeof(Estudiantes), 1, f);
            }
            fclose(f);
        }
    
}

void insertarSub(Nodo_becas *listaBec,Estudiantes est)
{
    
    Nodo_becas *l = buscarMejor(listaBec,est.Cod_beca);//función básica buscar mejorada que me devuelve la posición de la beca con el mismo codigo de beca
    insertar(l->info.sublista, est);//función básica "insertar" ordenado de menor a mayor según el ingreso promedio con el puntero pasado por referencia
 
}




void mostrarListado (Nodo_becas *listaBec)
{

    
    while (listaBec != NULL)
    {   
        int cont=0;
        cout << "Para la beca de codigo " << listaBec->info.Cod_beca << " y nombre " << listaBec->info.Nombre << " tiene asignados los siguientes alumnos:  "<<endl;
        
        while(listaBec->info.sublista !=NULL && listaBec->info->sublista.Cod_beca == listaBec->info.Cod_beca)
        {
            if(cont<listaBec->info.Cupo_max)
                cout << "Legajo: " << listaEst->info.legajo << " Nombre y Apellido: " << listaEst->info.apellido_nombre;

            cont++;
            listaBec->info.sublista = listaBec->info->sublista.sig;
            
        }
        listaBec = listaBec->sig;
    }
}