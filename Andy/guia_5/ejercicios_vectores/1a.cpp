#include <iostream>
using namespace std;

struct vuelos
{
    int codV, cantPas;
};

void cargarVuelos(vuelos v[], unsigned t);
void comprarPasajes(vuelos v[], unsigned t, int noVen[]);
int validarPasajes(vuelos v[], unsigned t, int &pos);
void mostrarVuelos(vuelos v[], unsigned t, int noVen[]);
void inicializar(int v[], unsigned t);
void ordenar (vuelos v[], unsigned t);

int main()
{
    vuelos v[5];
    int noVendidos[5];
    inicializar(noVendidos, 5);
    cargarVuelos(v, 5);
    cout<<endl;
    comprarPasajes(v, 5, noVendidos);
    ordenar(v, 5);
    mostrarVuelos(v, 5, noVendidos);

    return 0;
}

void cargarVuelos(vuelos v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"Ingresar codigo de vuelo: ";
        cin>>v[i].codV;
        cout<<"Ingresar cantidad de pasajes disponibles: ";
        cin>>v[i].cantPas;
    }
}

void comprarPasajes(vuelos v[], unsigned t, int noVen[])
{
    int pos, cantPas, DNI,codV;
    string nombre;
    cout<<"Ingresar el codigo de vuelo: ";
    codV=validarPasajes(v, t, pos);
    while(codV!=0)
    {
        cout<<"Ingresar la cantidad de pasajes a comprar: ";
        cin>>cantPas;
        if(cantPas>v[pos].cantPas)
        {
            cout<<"La cantidad de pasajes pedidos supera el numero de pasajes disponibles."<<endl;
            noVen[pos]+=cantPas;
        }
        else
        {
            cout<<"Ingresar DNI: ";
            cin>>DNI;
            cout<<"Ingresar nombre y apellido: ";
            cin>>nombre;

            v[pos].cantPas-=cantPas;

            //Mostrar listado
        
            cout<<endl<<"   DNI       Apellido y nombre        Cantidad de pasajes        Codigo de vuelo    "<<endl;
            cout<<"   "<<DNI<<"            "<<nombre<<"                       "<<cantPas<<"                       "<<codV<<endl;
        }

        cout<<"Ingresar el codigo de vuelo: ";
        codV=validarPasajes(v, t, pos);
    }
}

int validarPasajes(vuelos v[], unsigned t, int &pos)
{
    int i=0, bus, r;
    cin>>bus;
    if(bus!=0)
    {
        while(i<t && v[i].codV!=bus)
            i++;
        if(i==t)   
            r=-1;
        else
        {
            r=bus;
            pos=i;
        }    
        while(r==-1)
        {
            cout<<"El codigo es incorrecto."<<endl;
            i=0;
            cin>>bus;
            while(i<t && v[i].codV!=bus)
                i++;
            if(i==t)   
                r=-1;
            else
            {
                r=bus;
                pos=i;
            }  
        }  
    }
    return bus;
}

void mostrarVuelos(vuelos v[], unsigned t, int noVen[])
{
    cout<<"   Codigo de vuelo       Pasajes Disponibles        Pasajes no vendidos     "<<endl;
    for(int i=0; i<t; i++)
        cout<<"       "<<v[i].codV<<"                     "<<v[i].cantPas<<"                         "<<noVen[i]<<endl;
}

void inicializar(int v[], unsigned t)
{
    for(int i=0; i<t; i++)
        v[i]=0;
} 

void ordenar (vuelos v[], unsigned t)
{
    int i=1, j;
    vuelos aux;
    bool cambio;
    do
    {
        cambio=false;
        for(j=0; j<t-i; j++)
        {
            if(v[j].codV>v[j+1].codV)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        i++;
    } while(i<t && cambio);
}