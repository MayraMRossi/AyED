//Archivos de Texto:

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void armarT();
void mostrarT();
void mostrarT2();

int main()
{
    armarT();
    mostrarT2();

}

void armarT() 
{
    FILE*archivo;
    char s[20];
    //Tres tipos de apertura: w (write o escribir), r (read o leer), a (append o agregar)
    archivo=fopen("texto2.txt","w"); //devulve un puntero al archivo
    if (archivo==NULL)
        cout<<"error";
    else
    {
        cin.getline(s,20);
        while(strcmp(s,"fin")!=0)
        {
            fputs(s, archivo);
            cin.getline(s,20);
        }
        fclose(archivo);
    }
}

void mostrarT()  //muestra caracter a caracter
{
    FILE*archivo;
    char c;
    archivo=fopen("texto2.txt","r"); //devulve un puntero al archivo
    if (archivo==NULL)
        cout<<"error";
    else
    {
        while(!feof(archivo));
        {
            c = fgetc(archivo);
            cout<<c<<endl;
        }
        fclose(archivo);
    }
}

void mostrarT2() //muestra por cada 20 caracteres
{
    FILE*archivo;
    char s[20];
    archivo=fopen("texto2.txt","r");
    if (archivo==NULL)
        cout<<"error";
    else
    {
        while(!feof(archivo))
        {
            fgets(s, 20, archivo);
            cout<<s<<endl;
        }
        fclose(archivo);
    }
}

void armar()
{
   FILE *f;
      char nom[31];
      int legajo;
      int nota;
      f = fopen("Alumnos.txt","w");
      if(f==NULL)
         cout<<"error";
      else
      {
         cout<<"Ingrese legajo (0 para finalizar) ";
         cin>>legajo;
         while(legajo!=0)
         {
            cout<<"Nombre: ";
            cin.ignore();
            //cin>>nom;
            cin.getline(nom,31);
            cout<<"Nota: ";
            cin>>nota;
            fprintf(f,"%d %s %d\n",legajo,nom,nota);
            cout<<"Ingrese legajo (0 para finalizar) ";
            cin>>legajo;
         }
         fclose(f);
      }
}

void mostrar()
{
   FILE *archivo;
      char nom[31];
      int legajo;
      int nota;
      archivo = fopen("Alumnos.txt","r");
      if(archivo==NULL)
         cout<<"error";
      else
      {
        fscanf(archivo,"%d %s %d",&legajo,nom,&nota); //El string no tiene que tener espacio

         while(!feof(archivo))
         {

            cout<<nom<<" con legajo "<<legajo<<" con nota "<<nota<<endl;
            fscanf(archivo,"%d %s %d",&legajo,nom,&nota);
         }
         fclose(archivo);
      }
}