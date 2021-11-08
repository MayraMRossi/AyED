#include <iostream>
using namespace std;

void cargar(int v[], int t);
void pagos(int pat[], unsigned t, float importe[][12]);
int validarDatos(int d, int h);
void inicializar(float v[][12], unsigned f, unsigned c);
void importeTotal(float m[][12], unsigned f, unsigned c, int pat[]);
int buscarPatente(int v[], unsigned t);
void deudas(float m[][12], unsigned f, unsigned c, int pat[]);
void mesSinDeudas(float m[][12], unsigned f, unsigned c);

int main()
{
    int cant;
    cout<<"Cantidad de vehiculos: ";
    cin>>cant;
    int patentes[cant];
    float importe[cant][12];

    inicializar(importe, cant, 12);
    cargar(patentes, cant);
    cout<<endl;
    pagos(patentes, cant, importe);
    cout<<endl;
    importeTotal(importe, cant, 12, patentes);
    cout<<endl;
    deudas(importe, cant, 12, patentes);
    cout<<endl;
    mesSinDeudas(importe, cant, 12);

    return 0;
}

void cargar(int v[], int t)
{
    cout<<"Cargar las patentes: "<<endl;
    for(int i=0; i<t; i++)
    {
        cout<<"Posicion "<<i+1<<": ";
        cin>>v[i];
    }
}

void pagos(int pat[], unsigned t, float importe[][12])
{
    int i=0, mes, posPat;
    
    cout<<"Mes abonado: ";
    mes=validarDatos(0, 12);
    while(mes!=0)
    {
        cout<<"Patente: ";
        posPat=buscarPatente(pat, t);
        if(posPat!=-1)
        {
            cout<<"Importe: ";
            cin>>importe[posPat][mes-1];


        }
        else
            cout<<"El nro de patente no existe."<<endl;
        
        cout<<"Mes abonado: ";
        mes=validarDatos(0, 12);
    }
}

int validarDatos(int d, int h)
{
    int n;
    do
    {
        cin>>n;
    } while (n<d || n>h);
    return n;
}

void inicializar(float v[][12], unsigned f, unsigned c)
{
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
            v[i][j]=0;
    }
}

void importeTotal(float m[][12], unsigned f, unsigned c, int pat[])
{
    float suma;
    for(int i=0; i<f; i++)
    {
        suma=0;
        for(int j=0; j<c; j++)
            suma+=m[i][j];
        cout<<"Importe total del vehiculo de patente "<<pat[i]<<": "<<suma;
    }
}

int buscarPatente(int v[], unsigned t)
{
    int i=0, bus;
    cin>>bus;
    while(i<t && v[i]!=bus)
        i++;
    if(i==t)
        return -1;
    else
        return i;
}

void deudas(float m[][12], unsigned f, unsigned c, int pat[])
{
    for(int i=0; i<f; i++)
    {
        cout<<"Patente "<<pat[i]<<" adeuda los meses: "<<endl;
        for(int j=0; j<c; j++)
        {
            if(m[i][j]==0)
                cout<<j+1<<", ";
        }
        cout<<endl;
    }
}

void mesSinDeudas(float m[][12], unsigned f, unsigned c)
{
    int cont;
    cout<<"Meses en los que se abono por todos los vehiculos: "<<endl;
    for(int j=0; j<c; j++)
    {
        cont=0;
        for(int i=0; i<f; i++)
        {
            if(m[i][j]==0)
              cont++;  
        }
        if(cont==0)
            cout<<j+1<<", ";
    }
}