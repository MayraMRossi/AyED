#include <iostream>
using namespace std;

//Ingresar 5 numeros enteros e informar cuantos de ellos son mayores a su promedio.

int main()
{
    //Los arreglos son espacios de memoria con un solo nombre que puede guardar varios datos (Van de 0 en adelante).
    //Vector: arreglo unidimensional.
    //Se pueden asignar los valores adentro: vector[]={20, 5, 10, 3, 1} 

    int nums[5], /*num*/ suma=0, prom, i, cont=0; 
    for(i=0; i<5; i++)
    {
        cout<<"Ingrese el numero de orden "<<i+1<<": "<<endl;
        cin>>nums[i];
        /*
        //Es lo mismo que:
        cin>>num;
        nums[i]=num;
        */
    }
    for(i=0; i<5; i++)
        suma+=nums[i];
    prom=suma/5;

    for(i=0; i<5; i++)
    {
        if(nums[i]>prom)
            cont++;
    }
    
    cout<<"Hay "<<cont<<" numeros mayores al promedio "<<prom<<endl;

    return 0;
}