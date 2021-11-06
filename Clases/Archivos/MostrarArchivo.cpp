#include <iostream>
#include <stdio.h>


using namespace std;

struct Examen
{
    int leg;
    char nom[36];
    int nota;
};

int main()
{
    FILE *a=fopen("Parcial.dat","rb");
    if(a==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        Examen ex;
        fread(&ex,sizeof(Examen),1,a);
        while(!feof(a))
        {
            cout<<ex.leg<<ex.nom<<ex.nota<<endl;
            fread(&ex,sizeof(Examen),1,a);
        }
        fclose(a);
    }
    return 0;


}
