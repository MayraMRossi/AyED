#include <iostream>

using namespace std;

//Ingresar 5 números enteros y determinar e informar el mayor.


int main()
{
    int num,mayor;
    for(int i=1;i<=5;i++)
    {
        cout<<"Ingrese el numero de orden "<<i<<endl;
        cin>>num;
        if(i==1)
            mayor=num;
        else
        {
            if(num > mayor)
                mayor=num;
        }
        /*
        if(i==1 || num > mayor)
            mayor=num;
        */
    }
    cout<<"El mayor es "<<mayor<<endl;

    return 0;
}
