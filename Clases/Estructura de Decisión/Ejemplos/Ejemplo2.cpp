#include <iostream>

using namespace std;

/*
Confeccionar un programa que ingrese dos valores numéricos y
determine e informe al mayor de ellos si son distintos,
o un mensaje que diga IGUALES en caso de serlo.
*/

int main()
{
    int v1,v2;
    cout<<"Valor 1: ";
    cin>>v1;
    cout<<"Valor 2: ";
    cin>>v2;
    if(v1!=v2)
    {
        if(v1>v2)
        {
            cout<<v1<<endl;
        }
        else
        {
            cout<<v2<<endl;
        }

    }
    else
    {
       cout<<"iguales"<<endl;
    }

    return 0;
}
