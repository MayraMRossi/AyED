#include <iostream>

using namespace std;

int main()
{
    char letra;
    cout<<"ingrese un caracter ";
    cin>>letra;
    if(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u')
        cout<<"es vocal";

    string nombre;
    cout<<"Nombre: ";
    cin>>nombre;
    if(nombre=="pepe")
        cout<<"sos vos pepe!   ";
    cout<<"hola "<<nombre<<"!";
    return 0;
}
