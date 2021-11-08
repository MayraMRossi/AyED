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

struct ventas
{
    int numProdV[400], cantU[400];
};

int validarNumProd(int d, int h);
int validarInt(int d, int h);
float validarPrecio(int d);
float validarPorc(int d, int h);
void mostrar(productos v[], unsigned t);
int cargarProd(productos v[], unsigned t);
void cargarVentas(ventas v[], int t, productos v2[], int t2);
void inicializar(productos v[], unsigned cant);
void inicializar2(ventas v[], unsigned cant);
void agruparStock(productos v[], int t);
void actualizarStock(ventas v[], unsigned t, productos v2[], unsigned t2);
//int validarCant(ventas v[], int t, productos v2[], int t2);
void comisiones(ventas v[], unsigned t, productos v2[], unsigned t2, float com[]);
void cargarCom(float v[], int t);
void ComTotal(float v[], int t);
int validarNumProd(productos v[], int t, int &pos);
int validarCant(productos v2[], int pos);

int main()
{
    productos stock[400];
    ventas medicos[10];
    float com[10];
    inicializar(stock, 400);
    inicializar2(medicos, 10);
    int cant=cargarProd(stock, 400);
    cargarVentas(medicos, 10, stock, cant);
    actualizarStock(medicos, 10, stock, cant);
    cout<<endl<<"Stock actualizado: "<<endl;
    mostrar(stock, cant);
    comisiones(medicos, 10, stock, cant, com);
    cout<<endl;
    cargarCom(com, 10);
    cout<<endl;
    ComTotal(com, 10);

    return 0;
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

void mostrar(productos v[], unsigned t)
{
    for(int i=0; i<t; i++)
    {
        cout<<"Num prod: "<<v[i].numProd<<"  "<<"Cant stock: "<<v[i].cantStock<<"  "<<"Precio: "<<v[i].precio<<"  "<<"  "<<"Desc: "<<v[i].desc<<endl;
    }
}

void cargarVentas(ventas v[], int t, productos v2[], int t2)
{
    int i=0, num, pos;
    cout<<"Ingrese el numero de visitador: ";
    num=validarInt(0, 10);
    while(num!=0)
    {
        cout<<"Ingrese el numero de producto: ";
        v[num-1].numProdV[i]=validarNumProd(v2, t2, pos);
        cout<<"Ingrese la cantidad de unidades vendidas: ";
        v[num-1].cantU[i]=validarCant(v2, pos);
        //cout<<"POSICION: "<<pos;
        //v[num-1].cantU[i]=validarCant(v, t, v2, t2);
        
        i++;
        cout<<"Ingrese el numero de visitador: ";
        num=validarInt(0, 10);
    }
}

void agruparStock(productos v[], int t)
{
    for(int i=0; i<t; i++)
    {
        for(int j=0; i<t; j++)
        {
            if(v[i].numProd==v[j].numProd)
            {
                v[i].cantStock+=v[j].cantStock;
                v[j].numProd=0;
            }
        }
    }
}

void actualizarStock(ventas v[], unsigned t, productos v2[], unsigned t2)
{
    for(int i=0; i<t; i++)
    {
        for(int j=0; j<400; j++)
        {
            for(int k=0; k<t2; k++)
            {
                if(v[i].numProdV[j]!=0)
                {
                    if(v[i].numProdV[j]==v2[k].numProd)
                        v2[k].cantStock-=v[i].cantU[j];
                }
            }
        }
    }
}

void inicializar(productos v[], unsigned cant)
{
    for(int i=0; i<cant; i++)
        v[i].numProd=0;
}

void inicializar2(ventas v[], unsigned cant)
{
    for(int i=0; i<cant; i++)
    {
        for(int j=0; j<400; j++)
            v[i].numProdV[j]=0;
    }
}
/*
int validarCant(ventas v[], int t, productos v2[], int t2)
{
    int n;

        for(int i=0; i<t; i++)
        {
            for(int j=0; j<400; j++)
            {
                for(int k=0; k<t2; k++)
                {
                    if(v[i].numProdV[j]!=0)
                    {
                        if(v[i].numProdV[j]==v2[k].numProd)
                        {
                            cin>>n;
                            while (n>v2[k].cantStock)
                            {
                            cout<<"El numero ingresado no es valido. "<<endl;
                            cin>>n;
                            }
                        }
                    }
                }
            }
        }
    
    return n;
}
*/
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

void comisiones(ventas v[], unsigned t, productos v2[], unsigned t2, float com[])
{
    for(int i=0; i<t; i++)
    {
        for(int j=0; j<400; j++)
        {
            for(int k=0; k<t2; k++)
            {
                if(v[i].numProdV[j]!=0)
                {
                    if(v[i].numProdV[j]==v2[k].numProd)
                        com[i]+=(v2[k].precio*v2[k].porcCom/100);
                }
            }
        }
    }
}

void cargarCom(float v[], int t)
{
    for(int i=0; i<t; i++)
        cout<<"Comisiones del medico nro "<<i+1<<": "<<v[i]<<endl;
}

void ComTotal(float v[], int t)
{
    float total=0;
    for(int i=0; i<t; i++)
        total+=v[i];
    cout<<"Ventas Totales: "<<total;
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
