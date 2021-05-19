#include <iostream>
#include <math.h>
using namespace std;


int main(){

    float num1=0,num2=0, res=0,i;

    cout<<"Ingrese un numero "<<endl;
    cin>>num1;
    cout<<"Ingrese otro numero "<<endl;
    cin>>num2;

    if(num1>num2){
        cout<<"El numero 1 es mayor que el numero 2";
    }else{
        if(num1<num2){
            cout<<"El numero 2 es mayor que el numero 1";
        }else{
            cout<<"Los numeros son iguales";
        }
    }


return 0;
}
