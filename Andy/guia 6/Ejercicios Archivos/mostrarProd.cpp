#include <iostream>
using namespace std;

struct Producto
{
    int cod, stock;
};

int main()
{
    string fileName;
    cout<<"¿Que archivo queres leer? ";
    cin>>fileName;
    fileName.append(".dat");
    FILE*f = fopen(fileName.c_str(), "rb");
    if(f==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        Producto prod;
        fread(&prod, sizeof(Producto), 1, f);
        while(!feof(f))
        {
            cout<<"Cod Producto: "<<prod.cod<<"   Stock: "<<prod.stock<<endl;
            fread(&prod, sizeof(Producto), 1, f);
        }
    }
}