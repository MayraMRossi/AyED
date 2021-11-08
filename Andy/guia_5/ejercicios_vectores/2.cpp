//SE PARA LUEGO DE CARGAR LA MATRIZ
#include <iostream>
using namespace std;

#define COD 100
#define TALLE 5

void cargarStock(float v[][TALLE], unsigned f, unsigned c);
void compras(float v[][TALLE], unsigned f, unsigned c, int v2[][TALLE]);
int validarCod(int f);
void inicializar(int v[][TALLE], unsigned f, unsigned c);
void mostrar(int v[][TALLE], unsigned f, unsigned c);
int validarTalle(unsigned c);
int validarCant();

int main()
{
    float stock[COD][TALLE];
    int ventas[COD][TALLE];
    cargarStock(stock, COD, TALLE);
    inicializar(ventas, COD, TALLE);
    compras(stock, COD, TALLE, ventas);
    mostrar(ventas, COD, TALLE);

    return 0;
}

void cargarStock(float v[][TALLE], unsigned f, unsigned c)
{
    cout<<"Precio de stock: "<<endl;
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<"Codigo "<<i+1<<"  Talle "<<j+1<<endl;
            cin>>v[i][j];
        }
    }
}

void compras(float v[][TALLE], unsigned f, unsigned c, int v2[][TALLE])
{
    int cod, talle, cant, importe;
    cout<<"Elija el articulo que desea comprar: "<<endl;
    cout<<"Codigo de articulo: ";
    cod=validarCod(f);
    while(cod>=0)
    {
        cout<<"Talle: ";
        talle=validarTalle(c);
        cout<<"Cantidad de unidades: ";
        cant=validarCant();
        importe+=v[cod-1][talle-1]*cant;
        if(cant>3)
            importe-=importe*0,1; //descuento (10%)
        importe+=importe*0,21; //IVA (21%)

        //actualizar stock
        v2[cod-1][talle-1]+=cant;

        cout<<"Codigo de articulo: ";
        cod=validarCod(f);
    }
    cout<<"Importe total: "<<importe<<endl;
}

int validarCod(int f)
{
    int n;
    cin>>n;
    while(n==0 || n>f)
    {
        cout<<"El codigo no existe. Volver a ingresar: ";
        cin>>n;
    }
    return n;
}

int validarTalle(unsigned c)
{
    int n;
    cin>>n;
    while(n<1 || n>c)
    {
        cout<<"El talle no existe. Volver a ingresar: ";
        cin>>n;
    }
    return n;
}

int validarCant()
{
    int n;
    cin>>n;
    while(n<=0)
    {
        cout<<"La cantidad no puede ser menor a cero. Volver a ingresar: ";
        cin>>n;
    }
    return n;
}

void inicializar(int v[][TALLE], unsigned f, unsigned c)
{
    for(int i=0; i<f; i++)
    {
        for(int j=0; j<c; j++)
        {
            v[i][j]=0;
        }
    }
}

void mostrar(int v[][TALLE], unsigned f, unsigned c)
{
    int cont, total=0;
    cout<<"    Codigo de articulo    Talle    Unidades vendidas    "<<endl;
    for(int i=0; i<f; i++)
    {
        cont=0;
        for(int j=0; j<c; j++)
        {
            cout<<"             "<<i+1<<"             "<<j+1<<"              "<<v[i][j]<<endl;
            cont+=v[i][j];
            total+=v[i][j];
        }
        cout<<endl<<"Total unidades vendidas de articulo "<<i+1<<": "<<cont<<endl;
    }
    cout<<endl<<"Total general de unidades vendidas: "<<total;
}