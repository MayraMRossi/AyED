//MÓDULOS O FUNCIONES (El codigo funciona por partes)
//Se pueden declarar antes o despues del int main.
//Si se desarrollan al principio deben seguir cierto orden, asi que se suele declarar antes (prototipo) y desarrollar despues. 
//Cuando se invoca la funcion, se llama argumento; la funcion tiene un parametro asociado.
//Cuando se invoca a la funcion, el parametro toma el valor del argumento. Despues se borra el espacio de memoria.
//Los parametros y los argumentos tienen espacios en memoria diferentes. 
//La funcion copia el contenido del argumento y lo guarda en otra variable.
//La funcion puede tener parametros (variables del principal) o variables locales(propias de la funcion).
//Return finaliza la ejecución de la funcion y devuelve la variable al programa principal.
//Cuando termina la ejecución, el contenido de todas las varibales de la función se eliminan.
//Si la función no es void, tiene que tener algo despues del return (return ... ;)
//Una función puede ser ingresada desde cualquier función.
//Si la varible se declara fuera el main, sirve para todas las funciones (variables globales)
//EJEMPLO: 
//int nota1, nota2;
//C++ tiene una funcion llamada sobrecarga  de funciones, que permite declarar 2 funciones con el mismo nombre pero que acepten distinto tipo de variables.


#include <iostream>
using namespace std;

void mensajeIngresar();
void mensajeResultado(float);
int ingresoEntero(int, int);
float promedio(int, int);
int sumar(int, int);

int main(){

int nota1, nota2;
float prom;


mensajeIngresar();
nota1=ingresoEntero(1,10);
mensajeIngresar();
nota2=ingresoEntero(1, 10);
prom=promedio(nota1, nota2);
mensajeResultado(prom);
//mensajeResultado(promedio(nota1, nota2));


return 0;
}


void mensajeIngresar ()
{
    cout<<"Ingrese la nota: "<<endl;
}

void mensajeResultado(float result)
{
    cout<<"Promedio: "<<result<<endl;
}

int ingresoEntero(int desde, int hasta)
{
    int numEnt;
    do
        cin>>numEnt;
    while(numEnt<desde || numEnt>hasta);
    return numEnt;
}

int sumar(int a, int b)
{
    //OPCION 1
    int suma;
    suma=a+b;
    return suma;

    //OPCION 2
    //return a+b; es lo mismo
}

float promedio(int n1, int n2)
{
    /*
    //OPCION 1
    int suma=sumar(n1, n2);
    float prom=(float)suma/2;
    return prom;
    */
    //OPCION 2
    /*
    int suma=suma(n1, n2);
    return (float)suma/2;
    */
    //OPCION 3
    return (float)sumar(n1, n2)/2;
    
}
