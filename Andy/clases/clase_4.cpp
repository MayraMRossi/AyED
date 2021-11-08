#include <iostream>
using namespace std;
int main()
{
    //Iteración condicionada (se repite segun una condicion)
    /*
    int i=1;
    while(i<=50)
    {
        cout<<"*";
        i++;
    }
    */
    
    /*
    int suma=0, cont=0, temp, prom;
    cout<<"Ingrese la temperatura, para finalizar ingrese 999: ";
    cin>>temp;
    while(temp!=999)
    {
        suma+=temp;
        cont++;
        cout<<"Ingrese la temperatura, para finalizar ingrese 999: ";
        cin>>temp;
    }
    if(cont>0)
    {
        prom=suma/cont;
        cout<<"El promedio de temperaturas es: "<<prom<<endl;
    }
    else
        cout<<"No se ingresaron datos"<<endl;
    */
    
    //El do while es un while que primero hace el proceso y despues evalua la condicion
    /*
    int suma=0, prom=0;
    for(int i=1;i<=3;i++)

    */
    
    //Obtener el numero maximo
    //Opcion 1
    /*
    int mayor, num;
    cout<<"Ingrese el numero de orden 1: "<<endl;
    cin>>mayor;
    for(int i=2; i<=5;i++)
    {
        cout<<"Ingrese el numero de orden"<<i<<" :"<<endl;
        cin>>num;
        if(num>mayor)
            mayor=num;
    }
    cout<<"El mayor es "<<mayor<<endl;
    */

    //Opcion 2
    /*
    int num, mayor, i;
    for(i=1;i<=5;i++)
    {
        cout<<"Ingrese el numero de orden "<<i<<":";
        cin>>num;
        if(i == 1)
            mayor=num;
        else if(num>mayor)
            mayor=num;
    }
    cout<<"El numero mayor es: "<<mayor<<endl;
    */
    
    //Opcion 3 (con banderas, variables con 2 estados: true y false)
    /*
    int num, mayor, i;
    bool pri;
    pri = true;
    for(i=1;i<=5;i++)
    {
        cout<<"Ingrese el numero de orden "<<i<<":";
        cin>>num;
        if(pri)
        {
            pri = false;
            mayor=num;
        }   
        else if(num>mayor)
            mayor=num;
    }
    cout<<"El numero mayor es: "<<mayor<<endl;
    */
    
    //En las 2 ultimas opciones, se pueden abreviar los 2 if en uno solo, usando || "or")
    /*
    int num, mayor, i;
    bool pri;
    pri = true;
    for(i=1;i<=5;i++)
    {
        cout<<"Ingrese el numero de orden "<<i<<":";
        cin>>num;
        if(pri || num>mayor)
        {
            pri = false;
            mayor=num;
        }
    }
    cout<<"El numero mayor es: "<<mayor<<endl;
    */
    
    
    return 0;
}