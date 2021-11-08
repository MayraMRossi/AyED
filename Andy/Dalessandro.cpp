#include <iostream>
using namespace std;

char cuadrante(int, int);
int puntaje (char);

int main()
{
    int ID, result, puntajeTotal=0, contDis=0, IDganador, puntajeGanador, ContCentro=0, X, Y, cont1=0, cont2=0, cont3=0, cont4=0, cont0=0, cont0Total=0, contParticipantes=0;
    
    cout<<"Ingrese el numero de participante: ";
    cin>>ID;
    while (ID>0)
    {
        contParticipantes++;
        for(int i=1; i<=5; i++)
        {
            cout<<"Ingrese la coordenada en X de orden "<<i<<": ";
            cin>>X;
            cout<<"Ingrese la coordenada en Y de orden "<<i<<": ";
            cin>>Y;
            
        
            puntajeTotal+=puntaje(cuadrante(X, Y));

            switch(cuadrante(X, Y))
            {
                case '1': cont1++; break;
                case '2': cont2++; break;
                case '3': cont3++; break;
                case '4': cont4++; break;
                case '0': cont0++; cont0Total++; break;
            }
        }
        cout<<"Puntaje Total: "<<puntajeTotal<<endl;
        cout<<"Disparos en el Cuadrante 1: "<<cont1<<endl;
        cout<<"Disparos en el Cuadrante 2: "<<cont2<<endl;
        cout<<"Disparos en el Cuadrante 3: "<<cont3<<endl;
        cout<<"Disparos en el Cuadrante 4: "<<cont4<<endl;
        cout<<"Disparos en el Cuadrante 0: "<<cont0<<endl;

        if(contParticipantes==1 || puntajeTotal>puntajeGanador)
        {
            puntajeGanador=puntajeTotal;
            IDganador=ID;
        }

        cont1=0;
        cont2=0; 
        cont3=0; 
        cont4=0; 
        cont0=0;
        puntajeTotal=0;

        cout<<"Ingrese el numero de participante: ";
        cin>>ID;
    }
    if(contParticipantes==0)
            cout<<"No se ingreso ningun participante.";
    else
    {
        cout<<"El participante numero "<<IDganador<<" gano con "<<puntajeGanador<<" puntos!"<<endl;
        cout<<"Cantidad Total de Disparos en el centro: "<<cont0Total<<endl;
    }
    
    
    
    return 0;
}

char cuadrante(int X, int Y)
{
    char cuadrantes;

    if(X>0 && Y>0)
        cuadrantes='1';
    if(X>0 && Y==0)
        cuadrantes='1';
    if(X==0 && Y>0)
        cuadrantes='1';
    if(X<0 && Y>0)
        cuadrantes='2';
    if(X<0 && Y==0)
        cuadrantes='2';
    if(X<0 && Y<0)
        cuadrantes='3';
    if(X>0 && Y<0)
        cuadrantes='4';
    if(X==0 && Y<0)
        cuadrantes='4';
    if(X==0 && Y==0)
        cuadrantes='0';

    return cuadrantes;
}

int puntaje(char cuadrantes)
{
    int puntaje;
    switch(cuadrantes)
            {
                case '1': 
                case '2': 
                    puntaje=50; break;
                case '3': 
                case '4': 
                    puntaje=40; break;
                case '0': puntaje=100; break;
            }
    return puntaje;
}