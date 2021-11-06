#include <iostream>

//Realizar un programa para mostrar los números pares entre 30 y 10 en forma descendente.

using namespace std;

int main()
{
    int i;
    for(i=30;i>=10;i-=2)//i=i-2
        cout<<i<<"  ";
    cout<<endl;
    return 0;
}
