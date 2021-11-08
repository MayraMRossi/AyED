/*
Una empresa que se dedica a la fabricación de equipos e instrumentos médicos desea controlar las ventas que realizan sus visitadores médicos. 
Cuenta con 10 visitadores médicos y cuenta también con casi 400 productos hasta el momento. Para ello se tienen los siguientes datos de cada 
producto (estos datos se ingresan por teclado y finalizan cuando se ingresa un Cero en Número de Producto):
− Número de Producto (entre 3.000 y 15.000).
− Descripción de Producto 
− Cantidad de unidades en Stock (entre 1 y 2000).
− Precio de Producto (float, mayor a 0).
− Porcentaje de comisión por su venta (float, entre 5 y 20 %).
Además cuenta con los datos de las ventas que realizan sus 10 visitadores médicos que son los siguientes (estos datos se ingresan por teclado 
y finalizan cuando se ingresa un Cero en Número de Visitador):
− Número de Visitador Médico (entre 1 y 10).
− Número de Producto (entre 3.000 y 15.000).
− Cantidad de unidades vendidas.
NOTA: Rechazar los pedidos de aquellos productos cuyo stock es inferior al pedido.
Determinar e informar:
a) Informar el Stock de todos los productos luego de procesar las ventas de sus visitadores médicos.
b) Informar las comisiones que van a recibir cada uno de sus visitadores luego de haber procesado todas las ventas.
c) Informar el total de la facturación que realizó la empresa de cada uno de los productos vendidos luego de haber procesado todas las ventas.
*/

#include <iostream>
using namespace std;

struct productos
{
    int numProd, cantStock, precio;
    string desc;
    float porcCom;
};

int cargarProd(productos v[], unsigned t);
void inicializar(productos v[], unsigned cant);
int validarNumProd(int d, int h);
int validarInt(int d, int h);
float validarPrecio(int d);
float validarPorc(int d, int h);
void cargarVentas(productos v2[], int t2, float com[]);
int validarNumProd(productos v[], int t, int &pos);
int validarCant(productos v2[], int pos);
void mostrarComisiones(float com[], unsigned t);
void mostrarStock(productos v[], unsigned t);


int main()
{
    productos stock[400];
    float comisiones[10];
    inicializar(stock, 400);
    int cant=cargarProd(stock, 400);
    cout<<endl<<"Ventas: "<<endl;
    cargarVentas(stock, cant, comisiones);
    cout<<endl<<"Stock actualizado: "<<endl;
    mostrarStock(stock, cant);
    cout<<endl;
    mostrarComisiones(comisiones, 10);
}

void inicializar(productos v[], unsigned cant)
{
    for(int i=0; i<cant; i++)
        v[i].numProd=0;
}

int cargarProd(productos v[], unsigned t)
{
    int cont=0, i=0;

    cout<<"Ingrese el Numero de Producto, cero para finalizar (3000 a 15000): ";
    v[i].numProd=validarNumProd(3000, 15000);
    while(v[i].numProd!=0)
    {
        cout<<"Ingrese la Descripcion del Producto: ";
        cin>>v[i].desc;
        cout<<"Ingrese la Cantidad de Unidades en Stock(1 a 2000): ";
        v[i].cantStock=validarInt(1, 2000);
        cout<<"Ingrese el Precio del Producto: ";
        v[i].precio=validarPrecio(0);
        cout<<"Ingrese el procentaje de comision (5 a 20%): ";
        v[i].porcCom=validarPorc(5, 20);

        i++;

        cout<<"Ingrese el Numero de Producto, cero para finalizar (3000 a 15000): ";
        v[i].numProd=validarNumProd(3000, 15000);
    }
    return i;
}

int validarNumProd(int d, int h)
{
    int n;
    cin>>n;
    if(n!=0)
    {
        while (n<d || n>h)
        {
            cout<<"El numero ingresado no es valido. ";
            cin>>n;
        }
    }
    return n;
}

int validarInt(int d, int h)
{
    int n;
    cin>>n;
    while (n<d || n>h)
    {
        cout<<"El numero ingresado no es valido. ";
        cin>>n;
    }
    return n;
}

float validarPrecio(int d)
{
    int n;
    cin>>n;
    while (n<d)
    {
        cout<<"El numero ingresado no es valido. ";
        cin>>n;
    }
    return n;
}

float validarPorc(int d, int h)
{
    int n;
    cin>>n;
    while (n<d || n>h)
    {
        cout<<"El numero ingresado no es valido. ";
        cin>>n;
    }
    return n;
}

void cargarVentas(productos v2[], int t2, float com[])
{
    int i=0, numV, pos, numP, cant;
    cout<<"Ingrese el numero de visitador: ";
    numV=validarInt(0, 10);
    while(numV!=0)
    {
        cout<<"Ingrese el numero de producto: ";
        numP=validarNumProd(v2, t2, pos);
        cout<<"Ingrese la cantidad de unidades vendidas: ";
        cant=validarCant(v2, pos);

        com[numV]+=(v2[pos].precio*v2[pos].porcCom)/100;

        v2[pos].cantStock-=cant;
        
        cout<<"Ingrese el numero de visitador: ";
        numV=validarInt(0, 10);
    }
}

int validarNumProd(productos v[], int t, int &pos)
{
    unsigned i=0;
    int bus, r;
    cin>>bus;
    while(i<t && v[i].numProd!=bus)
    {
        i++;
    }
    if(t==i)
        r=-1;
    while(r==-1)
    {
        cout<<"El numero ingresado no es valido. "<<endl;
        cin>>bus;
        while(i<t && v[i].numProd!=bus)
        {
            i++;
        }
        if(t==i)
            r=-1;
    }
    pos=i;
    return bus;
}

int validarCant(productos v2[], int pos)
{
    int n;
    cin>>n;
    while(n>v2[pos].cantStock)
    {
        cout<<"El numero ingresado no es valido. "<<endl;
        cin>>n;
    }
    return n;
}

void mostrarComisiones(float com[], unsigned t)
{
    float total=0;
    for(int i=0; i<t; i++)
    {
        cout<<"Comisiones del medico nro "<<i+1<<": "<<com[i]<<endl;
        total+=com[i];
    }
    cout<<endl<<"Ventas Totales: "<<total;
}

void mostrarStock(productos v[], unsigned t)
{
    for(int i=0; i<t; i++)
        cout<<"Num prod: "<<v[i].numProd<<"  "<<"Cant stock: "<<v[i].cantStock<<"  "<<"Precio: "<<v[i].precio<<"  "<<"  "<<"Desc: "<<v[i].desc<<endl;
}