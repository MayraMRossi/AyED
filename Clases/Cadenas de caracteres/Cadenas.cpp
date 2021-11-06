#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char nombre[20+1],palabra[15];
    char nom[5]="pepe";
    cin>>nombre;
   // cin.getline(nombre,20); //Para ingresar vector de char con espacios

    //cout<<nombre<<endl;

//    palabra=nom; //MAL
    strcpy(palabra,nom);
    cout<<palabra<<endl;
    //palabra="casa"; //MAL
   // strcpy(palabra,"casa");
    //cout<<palabra<<endl;
/*
    if(palabra == nom)
        cout<<"="<<endl;
     else
        cout<<"No ="<<endl;
        */

    if(strcmp(palabra,nom)==0)
         cout<<"="<<endl;
    else
        cout<<"No ="<<endl;


    cout<<strcmpi("ancho","Ancho")<<endl;

    cout<<strlen(nom)<<endl;
    strcat(nombre," Perez");
    cout<<nombre<<endl;

    return 0;
}
