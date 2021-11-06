
#include <iostream>
#include <stdio.h>


using namespace std;

struct Parcial
{
    int legajo;
    char nombre[36];
    int nota;
};

int main()
{
    FILE *arch=fopen("Parcial.dat","wb");
    if(arch==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        Parcial parcial;
        cout<<"Legajo (cero fin) ";
        cin>>parcial.legajo;
        while(parcial.legajo!=0)
        {
            cout<<"Nombre ";
            cin.ignore();
            cin.getline(parcial.nombre,35);
            cout<<"Nota ";
            cin>>parcial.nota;
            fwrite(&parcial,sizeof(Parcial),1,arch);
            cout<<"Legajo (cero fin) ";
            cin>>parcial.legajo;
        }
        fclose(arch);
    }
    return 0;
}
