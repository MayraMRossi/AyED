#include <iostream>
#include <math.h>

#define PI 3.1416

using namespace std;


/*dado el radio de un circulo
calcular perimetro y superficie*/



int main()
{
    //const float PI=3.14;
    float radio, perim, sup;
    cout<<"Ingrese el radio :";
    cin>>radio;
    perim=2 * PI * radio;
    //sup=PI * radio * radio;
    sup=PI * pow(radio,2);
    cout<<"Perimetro "<<perim<<endl;
    cout<<"Superficie "<<sup<<endl;
    //cout<<sqrt(radio); //raiz cuadrada
    return 0;
}
