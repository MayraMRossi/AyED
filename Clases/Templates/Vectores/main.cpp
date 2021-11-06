#include <iostream>

#include <string.h>
#include "funcionesVect.h"

using namespace std;

struct Dato{
   int nro;
   char nom[16];
};

struct Dato2{
   int n1;
   int n2;
};

Dato ingresarDato();
void mostrar(Dato);
int criterio(Dato,Dato);

Dato2 ingresarDato2();
void mostrar(Dato2);
int criterio(Dato2,Dato2);
int criterioBusq(int,Dato2);

int ingresarInt();
void mostrar(int);
int criterio(int,int);

int main() {
   cout<<"Vector donde cada elemento tiene un numero y una cadena"<<endl;
      Dato v[3];
      ingresar<Dato>(v,3,ingresarDato);
      cout<<endl;
      mostrarV<Dato>(v,3,mostrar);
      cout<<endl<<"Ordenado alfabeticamente"<<endl;
      ordenar<Dato>(v,3,criterio);
      mostrarV<Dato>(v,3,mostrar);
      cout<<endl;

      cout<<"Vector donde cada elemento tiene dos numeros"<<endl;
      Dato2 v2[2];
      ingresar<Dato2>(v2,2,ingresarDato2);
      cout<<endl;
      mostrarV<Dato2>(v2,2,mostrar);
      cout<<endl<<"Ordenado de menor a mayor por n1"<<endl;
      ordenar<Dato2>(v2,2,criterio);
      mostrarV<Dato2>(v2,2,mostrar);
      cout<<endl;

      int x[3];
      ingresar<int>(x,3,ingresarInt);
      mostrarV<int>(x,3,mostrar);
      cout<<endl<<"Ordenado de mayor a menor"<<endl;
      ordenar<int>(x,3,criterio);
      mostrarV<int>(x,3,mostrar);

      int buscar;
      cout<<endl<<endl<<"Vector donde cada elemento tiene dos numeros"<<endl;
      cout<<"Ingresar el numero1 que quiere buscar"<<endl;
      cin>>buscar;
      int p=busquedaBinaria<Dato2,int>(v2,2,buscar,criterioBusq);
      if(p==-1)
        cout<<"No esta"<<endl;
      else
        cout<<v2[p].n1<<" - "<<v2[p].n2<<endl;

      return 0;
   }

   Dato ingresarDato(){
      Dato d;
      cout<<"nro ";
      cin>>d.nro;
      cout<<"nom ";
      cin>>d.nom;
      return d;
   }

   void mostrar(Dato d){
      cout<<"nro "<<d.nro;
      cout<<"  nom "<<d.nom<<endl;
   }

   int criterio(Dato d1, Dato d2)
   {
      return strcmp(d1.nom,d2.nom);
   }

   Dato2 ingresarDato2(){
      Dato2 d;
      cout<<"nro 1  ";
      cin>>d.n1;
      cout<<"nro 2  ";
      cin>>d.n2;
      return d;
   }

   void mostrar(Dato2 d){
      cout<<"nro 1    "<<d.n1;
      cout<<"  nro 2   "<<d.n2<<endl;
   }

   int criterio(Dato2 d1, Dato2 d2)
   {
      return d1.n1 - d2.n1;
   }

   int criterioBusq(int x,Dato2 d)
   {
       return x - d.n1;
   }

   int ingresarInt(){
      int a;
      cout<<"Numero para vector de int"<<endl;
      cin>>a;
      return a;
   }

   void mostrar(int a){
      cout<<a;
   }

   int criterio(int a, int b)
   {
      return b - a ;
   }

