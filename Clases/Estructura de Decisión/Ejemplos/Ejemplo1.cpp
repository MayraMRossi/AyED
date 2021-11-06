#include <iostream>

using namespace std;

/*
Ingresar dos valores enteros en dos variables, que se llamaran a y b.
Si a es mayor a b calcular e informar la diferencia entre a y b.
*/

int main()
{
    int a,b;
    cout<<"Valor 1: ";
    cin>>a;
    cout<<"Valor 2: ";
    cin>>b;

    if(a>b)
    {
        int r;
        r=a-b;
        cout<<"resta: "<<r<<endl;
    }

    /*
    if(a>b)
        cout<<"resta: "<<a-b<<endl;
    */
    return 0;
}
