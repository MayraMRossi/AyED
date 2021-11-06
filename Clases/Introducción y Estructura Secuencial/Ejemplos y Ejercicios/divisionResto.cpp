#include <iostream>


//operador / %

using namespace std;


int main()
{
    int nro1, nro2, resto;
    float div;
    cin>>nro1;
    cin>>nro2;
    div=(float)nro1/nro2;  //casteo
    resto=nro1%nro2;
    cout<<"division "<<div<<endl;
    cout<<"resto "<<resto<<endl;

    return 0;
}
