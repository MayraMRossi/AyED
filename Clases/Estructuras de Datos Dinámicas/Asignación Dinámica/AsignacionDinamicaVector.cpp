#include <iostream>

using namespace std;

struct Alumno
{
    unsigned legajo;
    char nombre[21];
    unsigned nota;

};

//void cargarAlumnos(Alumno*vp[],int c);
float prom(Alumno *v[],int c);
int cargarAlumnos(Alumno *vp[],int c)

int main()
{
    Alumno *vecAlumnos[5];
    int cant=cargarAlumnos(vecAlumnos,3);
    cout<<prom(vecAlumnos,cant);
    return 0;
}

//void cargarAlumnos(Alumno*vp[],int c)
//{
    /*
    Alumno*p;
    for(int i=0;i<c;i++)
    {
        p=new Alumno;
        cin>>p->legajo;
        cin>>p->nombre;
        cin>>p->nota;
        vp[i]=p;
    }
    */
//    for(int i=0;i<c;i++)
//    {
//        vp[i]=new Alumno;
//        cin>>vp[i]->legajo;
//        cin>>vp[i]->nombre;
//        cin>>vp[i]->nota;
//    }
//
//}

int cargarAlumnos(Alumno *vp[],int c)
{
    int leg,i=0;
    cin>>leg;
    while(leg!=0 && i<c)
    {
        vp[i]=new Alumno;
        vp[i]->legajo=leg;
        cin>>vp[i]->nombre;
        cin>>vp[i]->nota;
        i++;
        cin>>leg;
    }
    return i;
}

float prom(Alumno *v[],int c)
{
    int s=0;
    for(int i=0;i<c;i++)
        s+=v[i]->nota;
    return s/c;
}









