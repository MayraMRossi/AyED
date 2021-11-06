#include <iostream>

#include <stdio.h>
#include "funcionesArchhivos.h"

using namespace std;


struct Examen
{
    unsigned dni;
    char nomApe[31];
    unsigned nota;
};

int compararDni(unsigned,Examen);

int main()
{
    //dado un dni modificar la nota del examen
    unsigned unDni,nuevaNota;
    Examen ex,examen;
    int pos;
    FILE *a=fopen("Parciales.dat","rb");
    cout<<"Cantidad de registros del archivo "<<cantRegistros<Examen>(a)<<endl;;

    cout<<"un dni a buscar ";
    cin>>unDni;

    pos=busquedaSecuencial<Examen,unsigned>(a,unDni,ex,compararDni);

    if(pos!=-1)
    {

         cout<<ex.nomApe<<ex.nota;
         /*cout<<"nueva nota";
         cin>>nuevaNota;
         ex.nota=nuevaNota;
         //fseek(a,-sizeof(ex),SEEK_CUR);
         fseek(a,pos*sizeof(ex),SEEK_SET);
         fwrite(&ex,sizeof(ex),1,a);*/

    }
    else
        cout<<"no se encontro";
/*
    if(busquedaBinaria<Examen,unsigned>(a,unDni,ex,compararDni)!=-1)
        cout<<ex.nomApe<<"  "<<ex.nota<<endl;
    else
        cout<<"No esta";
*/
    fclose(a);
    return 0;
}

int compararDni(unsigned unDni,Examen ex)
{
    return unDni-ex.dni;
}
