#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    /*
    //El "espacio" lo toma como finalizacion de ingreso de datos (cin).
    //Para solucionar esto, se usa el "getline"
    string nombre, palabra;
    getline(cin, nombre);
    //cin>>nombre; 
    cout<<nombre<<endl;

    palabra="casa"; //asignar valores
    if(palabra=="casa") //comparar 
        cout<<"si";
    */

    
    //Cadenas: un vector de char

    char nombre[20+1], palabra[15]; //Puedo  guardar n-1 caracteres + "/0"
    char nom[21]="pepe"; //Aca si se pueden asignar valores 
    cin>>nombre;

    //Si se ingresa una cadena de menor tamaño, se agrega un "/0" para determinar finalizacion de lectura
    //No se pueden asignar valores a un vector char (solo cuando se declara la variable)
    //palabra="pepe" MAL
    //palabra=nombre Mal

    cin.getline(nombre, 20); //Para ingresar vector char con espacios
    strcpy(palabra, "casa"); //Para asignar valores el char
    strcpy(palabra, nombre);

    if(palabra=="casa") //no se pueden comparar normalmente (compara las referencias de los vectores, no los contenidos)

    //Se debe usar esta funcion, que devuelve 0 si son iguales, <0 si la 1era<2da, >0 si la 1era>2da (alfabeticamente)
    //Tiene en cuenta las mayusculas y minusculas
    if(strcmp(palabra, nombre)==0) 
        cout<<"igual"<<endl;
    else
        cout<<"no igual"<<endl;

    cout<<strcmp("Alarma", "alarma")<<endl;
    
    cout<<strcmpi("Alarma", "alarma")<<endl; //ignora MAYUSCULAS

    cout<<strlen("casa")<<endl; //devuelve la logitud de la cadena (sin el "/0")

    cout<<strcat(nom, " Sanchez")<<endl; //Concatena (une) cadenas

    //Convertir de string a vector char
    string str="de string a vector de char";
    char cadena[31];
    strcpy(cadena, str.c_str());
    cout<<cadena<<endl;
    cout<<str<<endl<<endl;

    string str2="de vector de char a string";
    strcpy(cadena, str2.c_str());
    str2=cadena; //pasa de vector de char a string
    cout<<str2<<endl;
    cout<<cadena<<endl;
    

    return 0;
}