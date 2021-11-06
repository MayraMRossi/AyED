#include <iostream>

using namespace std;

//Ingresar 5 números enteros y determinar e informar el mayor.
//7	-3	10	8	-2

int main()
{
    int num,mayor;
    cout<<"Ingrese el numero de orden "<<1<<endl;
    cin>>mayor;
    for(int i=2;i<=5;i++)
    {
        cout<<"Ingrese el numero de orden "<<i<<endl;
        cin>>num;
        if(num>mayor)
            mayor=num;
    }

    cout<<"El mayor es "<<mayor<<endl;

    return 0;
}
