#include <iostream>

using namespace std;

//Dados 10 valores que se ingresan por teclado, mostrar el mayor y 
//la cantidad de veces que fue ingresado

int main(){
    int numero=0, mayor=0,cont=0;

    for (int i=1; i<=10;i++)
    {
        cout<<"ingrese el numero de orden "<<i<<endl;
        cin>>numero;

        if (i==1){
           mayor = numero;
           cont = 1;
        }else{
            if(mayor==numero){
                cont++;
            }
						if(mayor<numero){
                cont = 1;
                mayor = numero;
            }
        }
    }
    cout<<"La cantidad de veces que se mostro el "<<mayor<<"es: "<<cont<<endl;

return 0;
}