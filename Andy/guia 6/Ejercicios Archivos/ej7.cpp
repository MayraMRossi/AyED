#include <iostream>
using namespace std;

struct stock
{
    int cod;
    char titulo[30], autor[20], editorial[20], genero[10];
    bool enLocal, enDep;
};

bool validar();
void cargarStockLocal();
void cargarStockDep();
void apareo(FILE*f1, FILE*f2);
void mostrarStockLocal();
void mostrarStockDep();

int main()
{
    //cargarStockLocal();
    //cargarStockDep();
    /*
    FILE*f1 = fopen("StockEnLocal.dat", "rb");
    FILE*f2 = fopen("StockEnDeposito.dat", "rb");
    if(f1 == NULL || f2 == NULL)
        cout<<"ERROR"<<endl;
    else
    {
        apareo(f1, f2);
    }
    fclose(f1);
    fclose(f2);
    */
    mostrarStockLocal();
    cout<<endl;
    mostrarStockDep();
}

void cargarStockLocal()
{
    FILE*f = fopen("StockEnLocal.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        stock s;
        cout<<"Cod: ";
        cin>>s.cod;
        while(s.cod!=0)
        {
            cout<<"Titulo: ";
            cin.ignore();
            cin.getline(s.titulo, 30);
            cout<<"Autor: ";
            cin.getline(s.autor, 20);
            cout<<"Editorial: ";
            cin.getline(s.editorial, 20);
            cout<<"Genero: ";
            cin.getline(s.genero, 10);
            cout<<"Esta en el Local? (Y/N): ";
            s.enLocal=validar();
            fwrite(&s, sizeof(stock), 1, f);

            cout<<"Cod: ";
            cin>>s.cod;
        }
    }
    fclose(f);
}

void cargarStockDep()
{
    FILE*f = fopen("StockEnDeposito.dat", "wb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        stock s;
        cout<<"Cod: ";
        cin>>s.cod;
        while(s.cod!=0)
        {
            
            s.enDep=validar();
            fwrite(&s, sizeof(stock), 1, f);

            cout<<"Cod: ";
            cin>>s.cod;
        }
    }
    fclose(f);
}

bool validar()
{
    char r;
    cin>>r;
    if(r == 'Y' || r == 'y')
      return 1;
    else
        return 0;
}

void apareo(FILE*f1, FILE*f2)
{
    stock s1, s2;
    fread(&s1, sizeof(stock), 1, f1);
    fread(&s2, sizeof(stock), 1, f2);
    while(!feof(f1) && !feof(f2))
    {
        if(s1.cod < s2.cod && !s1.enLocal)
        {
            if(!s1.enLocal)
                cout<<s1.cod<<" "<<"Falta en local"<<endl;
            fread(&s1, sizeof(stock), 1, f1);
        }
        else if(s1.cod == s2.cod)
        {
            if(!s1.enLocal && !s2.enDep)
                cout<<s1.cod<<" "<<"Falta en local y en deposito"<<endl;
            else if(!s1.enLocal)
                cout<<s1.cod<<" "<<"Falta en local"<<endl;
            else if(!s2.enDep)
                cout<<s1.cod<<" "<<"Falta en deposito"<<endl;
            fread(&s1, sizeof(stock), 1, f1);
            fread(&s2, sizeof(stock), 1, f2);
        }
        else
        {
            if(!s2.enDep)
                cout<<s2.cod<<" "<<"Falta en deposito"<<endl;
            fread(&s2, sizeof(stock), 1, f2);
        }
    }
    while(!feof(f1))
    {
        if(!s1.enLocal)
            cout<<s1.cod<<" "<<"Falta en local"<<endl;
        fread(&s1, sizeof(stock), 1, f1);
    }
    while(!feof(f2))
    {
        if(!s2.enDep)
            cout<<s2.cod<<" "<<"Falta en deposito"<<endl;
        fread(&s2, sizeof(stock), 1, f2);
    }
}

void mostrarStockLocal()
{
    FILE*f = fopen("StockEnLocal.dat", "rb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        stock s;
        fread(&s, sizeof(stock), 1, f);
        while(!feof(f))
        {
            cout<<s.cod<<" "<<s.enLocal<<endl;
            fread(&s, sizeof(stock), 1, f);
        }
    }
    fclose(f);
}

void mostrarStockDep()
{
    FILE*f = fopen("StockEnDeposito.dat", "rb");
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        stock s;
        fread(&s, sizeof(stock), 1, f);
        while(!feof(f))
        {
            cout<<s.cod<<" "<<s.enDep<<endl;
            fread(&s, sizeof(stock), 1, f);
        }
    }
    fclose(f);
}