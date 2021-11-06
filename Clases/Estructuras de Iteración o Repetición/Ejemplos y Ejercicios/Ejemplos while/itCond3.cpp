#include <iostream>

using namespace std;

//Ingresar las 3 notas de un alumno, calcular e informar el promedio del alumno
//(con validación)

int main()
{
    int i,nota,suma=0,prom;
    for(i=1;i<=3;i++)
    {
        cout<<"Ingrese nota "<<i<<endl;
        do
        {
            cin>>nota;
        }while(nota<1 || nota>10);
        suma+=nota;
    }
    prom=suma/3;
    cout<<"El promedio de notas es: "<<prom<<endl;

    return 0;
}
