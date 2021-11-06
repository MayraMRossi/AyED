#include <iostream>

using namespace std;

struct Alumno
{
    unsigned legajo;
    char nombre[21];
    unsigned nota;
};

int main()
{
    Alumno*p,*q;
    /*
    Alumno alu;
    p=&alu;
    cin>>alu.legajo;
    cin>>alu.nombre;
    cin>>alu.nota;
    */
    //Alumno alu;

    p=new Alumno;
    //alu=*p;
    /*
    cin>>(*p).legajo;
    cin>>(*p).nombre;
    cin>>(*p).nota;
    */
    cin>>p->legajo;
    cin>>p->nombre;
    cin>>p->nota;

    p=new Alumno;

    q=new Alumno;
    cin>>q->legajo;
    cin>>q->nombre;
    cin>>q->nota;

    return 0;
}
