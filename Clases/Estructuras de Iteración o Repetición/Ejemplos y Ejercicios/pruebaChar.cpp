#include <iostream>

//Ingresar 5 números enteros, informar la cantidad de números negativos
//y la sumatoria de los positivos.

using namespace std;

int main()
{
    int  num, cont, suma;
    char c1,c2;
    cont=0;
    suma=0;
    for(int i=1;i<=5;i++)
    {
        cout<<"Ingrese el numero de orden "<<i<<endl;
        cin>>num;
        cout<<"char 1 ";
        cin>>c1;
        cout<<"char 2 ";
        cin>>c2;
        if(num<0)
            //cont=cont+1;
            //cont+=1;
            cont++; //--
        else
            //suma=suma+num;
            suma+=num; //-=  *=  /=   %=
    }
    cout<<"Cantidad de negativos: "<<cont<<endl;
    cout<<"Sumatoria de positivos: "<<suma<<endl;

    return 0;
}
