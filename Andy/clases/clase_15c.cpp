#include <iostream>
using namespace std;

struct Alumno
{
    unsigned leg;
    char nombre[21];
    unsigned nota;
};

//void cargarAlumnos(Alumno*vp[], int c);
float prom(Alumno*vp[], int c);
int cargarAlumnos(Alumno*vp[], int c);

int main()
{
    Alumno *vecAlumnos[3]; // vector de punteros
    cargarAlumnos(vecAlumnos, 3);
    //prom(vecAlumnos, 3);

    return 0;
}

//void cargarAlumnos(Alumno*vp[], int c)
//{
    /*
    Alumno *p;
    for(int i=0; i<c; i++)
    {
        
        cout<<"Legajo: ";
        cin>>p->leg; 
        cout<<"Nombre: ";
        cin>>p->nombre;
        cout<<"Nota: ";
        cin>>p->nota;
        vp[i]=p; //guardo las direcciones que contiene "p" en el vector de punteros
        
    }
    */
//    for(int i=0; i<c; i++)
//    {
//        vp[i] = new Alumno;
//        cout<<"Legajo: ";
//        cin>>vp[i]->leg; 
//       cout<<"Nombre: ";
//       cin>>vp[i]->nombre;
//       cout<<"Nota: ";
//        cin>>vp[i]->nota;
//    }
//}
/*
int cargarAlumnos(Alumno *vp[], int c) //Esto no es una estructura dinamica, porque tiene un tamaño maximo
{
    int leg, i=0;
    cout<<"Legajo: ";
    cin>>leg;
    while(leg!=0 && i<c)
    {
        vp[i] = new Alumno;
        vp[i]->leg = leg;
        cout<<"Nombre: ";
        cin>>vp[i]->nombre;
        cout<<"Nota: ";
        cin>>vp[i]->nota;
        cout<<"Legajo: ";
        cin>>leg;
    }
    return i;
}
*/
float prom(Alumno*vp[], int c)
{
    int suma=0;
    for(int i=0; i<c; i++)
        suma+=vp[i]->nota;
    return suma/c;
}