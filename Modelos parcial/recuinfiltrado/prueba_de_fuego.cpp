#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Estudiantes
{
    unsigned legajo;
    string nombre;
    unsigned Cod_beca;
    float Ingreso_prom;
}

struct Becas
{
    unsigned Cod_beca;
    string Nombre;
    unsigned Cupo_max;
    Nodo_estudiantes *lista_estudiantes;
}

struct Nodo_becas
{
    Becas info;
    Nodo_becas sig;
}

struct Nodo_estudiantes
{
    Estudiantes info;
    Nodo_estudiantes sig;
}

Nodo_becas ingresar_becas ();
Nodo_estudiantes organizarInscriptos();
void mostrarListado (Nodo_becas *listaBec,Nodo_estudiantes *listaEst);



int main{



    Nodo_becas lis1 = ingresar_becas();
    Nodo_estudiantes lis2 = organizarInscriptos();
    mostrarListado (lis1,lis2);
    return 0;
}




Nodo_becas ingresar_becas ()
{
    Estudiantes alu;
    Nodo_becas *listaBec = NULL;

    cout<<"Ingrese el codigo de la beca: (0 para salir)"<<endl;
    cin >> alu.Cod_beca >> endl;

    while(alu.Cod_beca!= 0)
    {
        cout << "Ingrese el nombre de la beca: " << endl;
        cin >> alu.nombre >> endl;
        cout << "Ingrese el cupo maximo: " << endl;
        cin >> alu.Cupo_max >> endl;

        insertar(listaBec,alu); //función básica "insertar" ordenado de menor a mayor según el código de beca con la lista pasada como parametro por referencia

        cout<<"Ingrese el codigo de la beca: (0 para salir)"<<endl;
        cin >> alu.Cod_beca >> endl;
    }

    return listaBec;

}



Nodo_estudiantes organizarInscriptos()
{
    Estudiantes e [10];
    for(int i = 0; i < 10; i++)
    {
        cout << "Legajo: "<<endl;
        cin>> e.legajo >> endl;
        cout << "Nombre: "<<endl;
        cin>> e.nombre >> endl;
        cout << "cod: "<<endl;
        cin>> e.Cod_beca >> endl;
        cout << "Ingreso prom: "<<endl;
        cin>> e.ingreso_prom >> endl;

            Nodo_estudiantes *listaEst = NULL;
    
     

            
            insertar(listaEst, est); //función basica "insertar" ordenado de menor a mayor según el código de beca con la lista pasada como parametro por referencia
            
        
    }

    

    
    

    return listaEst;
}




void mostrarListado (Nodo_becas *listaBec,Nodo_estudiantes *listaEst)
{
    
    while (listaBec != NULL)
    {   
        int cont=0;
        Cout << "Para la beca de código " << listaBec->info->Cod_beca << " y nombre " << listaBec->info->Nombre << " tiene asignados los siguientes alumnos:  "
        
        while(listaEst !=NULL && listaEst->info->Cod_beca == listaBec->info->Cod_beca)
        {
            if(cont<=listaBec->info->Cupo_max)
                cout << "Legajo: " << ListaEst->info->legajo << " Nombre y Apellido: " << ListaEst->info->apellido_nombre;

            cont++;
            listaEst = ListaEst->sig;
            
        }
        listaBec = listaBec->sig;
    }
}