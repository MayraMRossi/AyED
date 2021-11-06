#include <iostream>

//Ingresar 5 números enteros, informar la cantidad de números negativos
//y la sumatoria de los positivos.

using namespace std;

int main()
{
    int cont=0,suma=0,num;
    //cont=0;
    //suma=0;
    for(int i=1;i<=5;i++)
    {
        cout<<"Ingrese el numero de orden "<<i<<endl;
        cin>>num;
        if(num<0)
            //cont=cont+1;
            //cont+=1;
            cont++;
        else
            //suma=suma+num;
            suma+=num;
    }
    cout<<"Cantidad de negativos: "<<cont<<endl;
    cout<<"Sumatoria de positivos: "<<suma<<endl;

    return 0;
}
//+= -= *= /= %=
//++  --
