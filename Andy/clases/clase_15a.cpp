//Estructuras dinamicas (de tamaño variable)

#include <iostream>
using namespace std;

int main()
{
    //Manejo dinamico de memoria
    /*
    int a;
    int*p; // p es un puntero, que almacena la direccion de memoria de alguna variable
    a=5;
    p=&a; 
    cout<<a<<endl;
    cout<<*p<<endl; //muestra lo apuntado por "P"
    a=8;
    cout<<*p<<endl; //Aun si "a" cambia de valor, p va a mostrar el nuevo valor de "a" sin necesidad de actualizarlo
    cout<<p<<endl; //muestra el propio contenido de p (la direccion en memoria de "a")
    */

    int *p, *q;
    p = new int; // new = busca un espacio de memoria para guardar un entero y devuelve esa direccion de memoria
    *p = 5;
    /*
    delete p; // borra el espacio de memoria apuntado por "p" para que no quede al pedo en memoria si no se va a usar
    p = NULL; // "p" no apunta a nada
    */
    //q = p; // le asigno el contenido de "p" en "q", es decir, la direccion en memoria del espacio al que apunta "p"
    q = new int;
    *q = *p; // guarda el contenido de la direccion en memoria de "p" en el contenido de la direccion de memoeria de "q"
    
    return 0;
}