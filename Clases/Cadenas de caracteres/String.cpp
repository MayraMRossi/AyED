#include <iostream>

using namespace std;



int main()
{
    string nombre,palabra;
    //cin>>nombre;
    getline(cin,nombre); //puede ingresar espacios
    cout<<nombre<<endl;

    palabra="casa";
    if(palabra=="casa")
        cout<<"si";

    return 0;
}





