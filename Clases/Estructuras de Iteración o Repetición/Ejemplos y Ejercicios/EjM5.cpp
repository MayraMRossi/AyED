#include <iostream>

using namespace std;
/*
Dado un conjunto de valores (números enteros), que finaliza con un valor nulo (cero),
determinar e imprimir (si hubo valores):
a) El valor máximo negativo
b) El valor mínimo positivo
d c) El promedio de todos los valores.
*/
int main()
{
    int nro,suma=0,cant=0,minimo,maximo;
    bool priNeg=true,priPos=true;
    cout<<"Ingresar numero"<<endl;
    cin>>nro;
    while(nro!=0)
    {
        suma+=nro;
        cant++;
        if(nro<0)
        {
            if(priNeg)
            {
                priNeg=false;
                maximo=nro;
            }
            else
            {
                if(nro>maximo)
                    maximo=nro;
            }
        }
        else
        {
            if(priPos)
            {
                priPos=false;
                minimo=nro;
            }
            else
            {
                if(nro<minimo)
                    minimo=nro;
            }
        }

        cout<<"Ingresar numero"<<endl;
        cin>>nro;
    }

    if(cant!=0)
    {
        cout<<"Promedio: "<<(float)suma/cant<<endl;
        if(!priNeg) //priNeg==false
            cout<<"Maximo de negativos: "<<maximo<<endl;
        if(!priPos)
            cout<<"Minimo de positivos: "<<minimo<<endl;
    }

    return 0;
}
