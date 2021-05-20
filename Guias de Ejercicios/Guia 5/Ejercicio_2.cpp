#include <iostream>

using namespace std;
// 2) Hacer un algoritmo que lea 40 números y los muestre en orden inverso.


void leerNum(int[],unsigned);
void invertirNumeros(int[],unsigned);

int main(){
int num[5];

leerNum(num,5);
invertirNumeros(num,5);

return 0;
}

//funcion que carga los numeros en el vector
void leerNum(int v[],unsigned a){

    for(int i=0;i<a;i++){
        cout<<"Ingrese el numero "<<i+1<<endl;
        cin>>v[i];
    } 
}

//Funcion que hace el orden inverso y lo muestra
void invertirNumeros(int v[],unsigned b){

    cout<<"las notas en orden inverso son: ";
    for(int i=1;i<=b;i++){ 
        cout<<v[b-i]<<" ";
    }

}