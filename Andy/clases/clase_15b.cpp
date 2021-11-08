#include <iostream>
using namespace std;

struct Alumno
{
    unsigned leg;
    char nombre[21];
    unsigned nota;
};

int main()
{
    Alumno alu;
    Alumno *p;
    /*
    p=&alu;
    cout<<"Legajo: ";
    cin>>alu.leg;
    cout<<"Nombre: ";
    cin>>alu.nombre;
    cout<<"Nota: ";
    cin>>alu.nota;
    */

    p = new Alumno;
    /*
    cout<<"Legajo: ";
    cin>>(*p).leg; // el "." tiene un orden de prioridad mayor a "*", por lo que hay que poner parentesis "()"
    cout<<"Nombre: ";
    cin>>(*p).nombre;
    cout<<"Nota: ";
    cin>>(*p).nota;
    */
    cin>>p->leg; //hace lo mismo que "(*p).leg"
    cin>>p->nombre;
    cin>>p->nota;

    return 0;
}