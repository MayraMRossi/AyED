#include <iostream>

//1) Hacer un algoritmo que lea 5 notas las cargue un vector y luego muestre la nota máxima

using namespace std;

void leerNotas(int[],unsigned);
void compararNotas(int[],unsigned);

int main(){
int notas[5];

leerNotas(notas,5);
compararNotas(notas,5);

return 0;
}

//funcion que carga las notas en el vector
void leerNotas(int v[],unsigned a){

    for(int i=0;i<a;i++){
        cout<<"ingrese la nota numero "<<i+1<<endl;
        cin>>v[i];
    } 
}

//Funcion que determina cual es la nota mayor y mostrarla
void compararNotas(int v[],unsigned b){
    int notaMax=v[0];
    
    for(int i=1;i<b;i++){
        if(v[i]>notaMax){
            notaMax = v[i];
        }  
    }
    cout<<"la nota mas alta es: "<<notaMax;
}