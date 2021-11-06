#include <iostream>

using namespace std;

//Confeccionar un programa para imprimir una línea con 50 asteriscos.

int main()
{
    int i;
    /*
    for(i=1;i<=50;i++)
        cout<<"*";
    cout<<endl<<endl;
    */
    /*
    i=1;
    while(i<=50)
    {
        cout<<"*";
        i++;
    }
    cout<<endl<<endl;
    */

    i=1;
    do
    {
        cout<<"*";
        i++;
    }while(i<=50);
    cout<<endl<<endl;

    return 0;
}



