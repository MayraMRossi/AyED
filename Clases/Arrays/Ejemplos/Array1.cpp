#include <iostream>

using namespace std;

//Ingresar 5 números  enteros e
//informar cuántos de ellos son mayores a su promedio


int main()
{
    int nros[5],n,suma=0,prom,i,cont=0;
    for(i=0;i<5;i++)
    {
        cout<<"nro de orden "<<i+1<<endl;
        cin>>nros[i];
    }
    for(i=0;i<5;i++)
        suma+=nros[i];
    prom=suma/5;
    for(i=0;i<5;i++)
    {
        if(nros[i]>prom)
            cont++;
    }
    cout<<"hay "<<cont<<" nros mayores al promedio "<<prom<<endl;

    return 0;
}





