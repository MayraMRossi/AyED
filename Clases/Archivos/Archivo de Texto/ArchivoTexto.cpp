
#include <iostream>
#include <stdio.h>
#include<string.h>

using namespace std;
/*
LeerCaracter c = fgetc(f)
LeerCadena fgets(s,n,f)
LeerConFormato fscanf(f,”%c%f%s”,&c,&r,s)
GrabarCaracter fputc(c,f)
GrabarCadena fputs(s,f)
GrabarConFormato fprintf(f,”%c %f %s \n”, c,r,s)
*/
void armar();
void mostrar();
void armarT();
void mostrarT();
void mostrarT2();

int main()
{
    //armarT();
    //mostrarT();
    //mostrarT2();
    //armar();
    mostrar();
    return 0;
}

void armarT()
{
    FILE *archivo;
    char s[20];
    archivo = fopen("texto.txt","w");
    if(archivo==NULL)
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

void mostrarT()
{
    FILE *archivo;
    char c;
    archivo = fopen("texto.txt","r");
    if(archivo==NULL)
        cout<<"error";
    else
    {
        while(!feof(archivo))
        {
            c=fgetc(archivo);
            cout<<c<<endl;
        }
        fclose(archivo);
    }
}

void mostrarT2()
{
    FILE *archivo;
    char s[20];
    archivo = fopen("texto.txt","r");
    if(archivo==NULL)
        cout<<"error";
    else
    {
        while(!feof(archivo))
        {
            fgets(s,20,archivo);
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
