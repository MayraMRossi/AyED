#include <iostream>

//Ingresar la cantidad de alumnos del curso
//Ingresar nombre y nota de cada uno de los alumnos del curso,
//informar por cada uno el nombre y
//la leyenda “APROBADO” o “DESAPROBADO” si la nota es mayor o igual a 6 o no.

using namespace std;

int main()
{
    unsigned nota,i,cant;
    string nombre;
    cout<<"Ingrese la cantidad de alumnos del curso ";
    cin>>cant;
    for(i=1;i<=cant;i++)
    {
        cout<<"nombre del alumno de orden "<<i<<endl;
        cin>>nombre;
        cout<<"nota del alumno de orden "<<i<<endl;
        cin>>nota;
        if(nota>=6)
            cout<<nombre<<" aprobo"<<endl<<endl;
        else
            cout<<nombre<<" desaprobo"<<endl<<endl;
    }
    return 0;
}
