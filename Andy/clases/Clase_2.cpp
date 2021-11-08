#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    /*
    // La división de 2 numeros enteros siempre dan un número entero, aunque la variable "división" sea float.
    // Si pongo div = (float)num1/num2, da con coma, se llama casteo. 
    int num1, num2, resto;
    float div;
    */
    
    /*
    //Definir constantes
    const float PI = 3.14; //Ocupa espacio en memoria.
    #define PI 3.14; //Esta es para todo el código, no ocupa espacio.
    //Usar potenciación y radicación
    float superficie, radio, perimetro;
    cin >> radio;
    superficie = PI * pow(radio,2);
    perimetro = 2 * PI * radio;
    cout << perimetro;
    cout << superficie;
    */
    
    /*
    // Uso de condicionales
    int a, b;
    cout << "Ingrese el primer valor ";
    cin >> a;
    cout << "Ingrese el segundo valor";
    cin >> b;

    if(a>b)
    {
        int resta;
        resta = a-b;
        cout << "La resta es: " << resta << endl;
    }
    */
    
    /*
    //EJEMPLO 1
    int v1, v2;
    cout << "Ingrese valor 1:";
    cin >> v1;
    cout << "Ingrese valor 2: ";
    cin >> v2;
    if (v1==v2)
        cout << "Los numeros son iguales ";
    else
    {
        if (v1>v2)
            cout << v1 << endl;
        else
            cout << v2 << endl;
    }
    */

    /*
    Operadores logicos
    ^ = &&
    v = ||
    ~ = !
    */
    
    /*
    //EJEMPLO 2
    int n1, n2;
    cout << "Ingrese un numero: ";
    cin >> n1;
    cout << "Ingrese otro numero: ";
    cin >> n2;

    if (n1>0 && n2>0)
        cout << "POSITIVOS";
    else 
    {
        if(n1<0 && n2<0)
            cout << "NEGATIVOS";
        else
            cout << "SON DE DISTINTO SIGNO O CERO";
    }
    */
    
    /*
    //EJEMPLO 3 (seleccion multiple)
    //char = representan un caracter pero son enteros.
    //'' = determinar una constante caracter.

    char transp;
    cout << "Ingrese medio de transporte: " << endl << "T: tren" << endl << "A: auto" << endl << "C: colectivo" << endl << "H: helicoptero" << endl;
    cin >> transp;
    switch (transp)
    {
        case 'T':
        case 't':
        case 'A':
        case 'a':
            cout << "El tiempo estimado de viaje es de 90 min";
            break;
        case 'C':
        case 'c':
            cout << "El tiempo estimado de viaje es de 180 min";
            break;
        case 'H':
        case 'h':
            cout << "El tiempo estimado de viaje es de 20 min";
            break;
        default:
            cout << "Error. Medio de transporte inexistente.";
    }
    */

   /*
    //EJEMPLO 4
    char letra;
    cout << "Ingrese una letra: ";
    cin >> letra;
    switch (letra)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "Es una vocal " << endl;
        default:
            cout << "Es una consonante " << endl;
    }

    string nombre;
    cout << "Nombre: ";
    cin >> nombre;
    if (nombre == "pepe")
        cout << "Sos vos Pepe!";
    else
        cout << "No sos Pepe, raja de aca ";
    

    return 0;
    */

}