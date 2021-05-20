#include <iostream>

//1) Hacer un algoritmo que lea 5 notas las cargue un vector y luego muestre la nota máxima

using namespace std;

void leerNotas(int,unsigned);
int compararNotas();

int main(){
int notas[5], notaMax=0;

leerNotas(notas,5);
compararNotas();

return 0;
}

//funcion que carga las notas en el vector
void leerNotas(int v[],unsigned a){

    for(int i=0;i<a;i++){
        cout<<"ingrese la nota n° "<<i+1;
        cin>>v[i]
    }
    
}


//Funcion que 
int compararNotas(){


}