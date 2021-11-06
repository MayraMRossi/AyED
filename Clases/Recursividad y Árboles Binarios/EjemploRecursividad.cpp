#include <iostream>

using namespace std;

int factorial(int n);

int main()
{
    int nro;
    cout<<"nro: ";
    cin>>nro;
    cout<<"El factorial de "<<nro<<" es "<<factorial(nro)<<endl;

    return 0;
}

int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
