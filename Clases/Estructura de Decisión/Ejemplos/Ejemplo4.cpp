#include <iostream>

using namespace std;

/*
Confeccionar un programa que solicite el medio de transporte
para llegar a un determinado lugar,
mostrando en pantalla el tiempo estimado de viaje para cada medio de transporte.
El medio de transporte se ingresa con una letra siendo:
•	T: tren, tiempo estimado de viaje 90 min.
•	A: auto, tiempo estimado de viaje, 90 min.
•	C: colectivo, tiempo estimado de viaje 180min
•	H: helicóptero, tiempo estimado de viaje, 20 min.

*/

int main()
{
    char transp;
    cout<<"Ingrese medio de transporte (T C H) ";
    cin>>transp;
    switch(transp)
    {
        case 'T':
        case 'A':
        case 't':
        case 'a':
            cout<<"tiempo estimado de viaje 90 min"<<endl;
            break;
        case 'C':
        case 'c':
            cout<<"tiempo estimado de viaje 180 min"<<endl;
            break;
        case 'H':
        case 'h':
            cout<<"tiempo estimado de viaje 20 min"<<endl;
            break;
        default:
            cout<<"Error. Medio de transporte inexistente"<<endl;
   }

    return 0;
}
