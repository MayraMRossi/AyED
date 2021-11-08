// Una funcion recursiva es aquella que se llama a si misma

#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
    int nro;
    cout<<"Nro: ";
    cin>>nro;
    cout<<"El factorial de "<<nro<<" es "<<factorial(nro)<<endl;

    return 0;
}

//En el caso del factorial, la podemos definir con ciclos o con recursividad
// n! = n*(n-1)*(n-2)*1 
// n! = n*(n-1)!
int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}