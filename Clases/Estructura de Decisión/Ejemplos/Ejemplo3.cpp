#include <iostream>

using namespace std;

/*
Ingresar dos números.
Indicar si ambos son positivos, ambos son negativos, o son distinto signo o cero.
*/

int main()
{
    int n1,n2;
    cout<<"Valor 1: ";
    cin>>n1;
    cout<<"Valor 2: ";
    cin>>n2;
    if(n1>0 && n2>0)
        cout<<"positivos"<<endl;
    else
    {
        if(n1<0 && n2<0)
            cout<<"negativos"<<endl;
        else
            cout<<"son de distinto signo o cero"<<endl;
    }

    return 0;
}
