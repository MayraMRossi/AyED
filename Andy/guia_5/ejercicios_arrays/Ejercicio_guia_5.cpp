#include <iostream>
using namespace std;

void cargar(int[], unsigned);
int notaMax(int[], unsigned cant);
void mostrarInverso(int v[], unsigned cant);
int sumar(int v[], unsigned cant);
int prom(int v[], unsigned cant);
void mayoresProm (int v[], unsigned cant, int prom);
void mostrar (int[], unsigned);
int mayor (int v[], unsigned cant, int &pos);
int menor (int v[], unsigned cant, int &pos);
void inicializar(int v[], unsigned cant);
void cargarDados(int v[], unsigned cant);
void numRepe(int v[], unsigned cant);
void vectorSuma(int a[], int b[], int suma[], unsigned cant);
void vectorResta(int a[], int b[], int resta[], unsigned cant);
void cargarParalelo(int cod[], int precios[], int cant);
void mayorAmenor(int cod[], int precios[], int cant);
void informarPrecio(int cod[], int precios[], int cant);
int validarDatos(int d, int h);

int main()
{  
    //EJERCICIO 1 
    /*
    int nros[30];
    cargar(nros, 30);
    cout<<"Nota maxima: "<<notaMax(nros, 30);
    */

    //EJERCICIO 2
    /*
    int nros[40];
    cargar(nros, 40);
    mostrarInverso(nros, 40);
    */

    //EJERCICIO 3
    /*
    int edades[5], promedio;
    cargar(edades, 5);
    promedio= prom(edades, 5);
    mayoresProm(edades, 5, promedio);
    */

    //EJERCICIO 4
    /*
    int nros[5], posMayor=0, posMenor=0;
    cargar(nros, 5);
    mostrar(nros, 5);

    mayor(nros, 5, posMayor);
    menor(nros, 5, posMenor);

    cout<<"Mayor valor: "<<mayor(nros, 5, posMayor)<<"    Posicion: "<<posMayor<<endl;
    cout<<"Menor valor: "<<menor(nros, 5, posMenor)<<"    Posicion: "<<posMenor<<endl;
    */

    //EJERCICIO 5 (MAL)
    /*
    int listaA[10], listaB[10];
    bool nros[10];
    int tam=listaBool(nros, 10);
    int contA=listaAdentro(nros, listaA, tam);
    mostrar (listaA, contA);
    */

    //EJERCICIO 6 
    /*
    int dados[5];
    cargarDados(dados, 5);
    numRepe(dados, 5);
    */

    //EJERCICIO 7 
    
    int A[4], B[4], suma[5], resta[4];
    cout<<"Vector A: "<<endl;
    cargar(A, 4);
    cout<<"Vector B: "<<endl;
    cargar(B, 4);
    inicializar(suma, 5);

    vectorSuma(A, B, suma, 4);
    cout<<"Vector suma: ";
    mostrar(suma, 5);
    
    cout<<endl;
    cout<<"Vector resta: ";
    vectorResta(A, B, resta, 4);
    mostrar(resta, 4);
    

    //EJERCICIO 8
    /*
    int cod[5], precios[5];
    cargarParalelo(cod, precios, 5);
    mayorAmenor(cod, precios, 5);
    for(int i=0; i<5; i++)
        cout<<"Codigo: "<<cod[i]<<"  Precio: "<<precios[i]<<endl;
    informarPrecio(cod, precios, 5);
    */
   
    return 0;
}

void cargar(int v[], unsigned cant)
{
    for(int i=0; i<cant; i++)
    {
        cout<<"Ingrese un numero: ";
        cin>>v[i];
    }
}

int notaMax(int v[], unsigned cant)
{
    int mayor;
    for(int i=0; i<cant; i++)
    {
        if (i==0 || v[i]>mayor)
            mayor=v[i];
    }
    return mayor;
}

void mostrarInverso(int v[], unsigned cant)
{
    for(int i=cant-1; i>=0; i--)
    {
        cout<<v[i]<<" ";
    }
}

int sumar(int v[], unsigned cant)
{
    int suma=0;
    for(int i=0; i<cant; i++)
        suma+=v[i];
    return suma;
}

int prom(int v[], unsigned cant)
{
    return sumar(v, cant)/cant;
}

void mayoresProm (int v[], unsigned cant, int prom)
{
    for(int i=0; i<cant; i++)
    {
        if(v[i]>prom)
            cout<<v[i]<<" ";
    }
}

void mostrar (int v[], unsigned cant)
{
    cout<<"Contenido del vector: ";
    for(int i=0; i<cant; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int mayor (int v[], unsigned cant, int &posMa)
{
    int mayor;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || v[i]>mayor)
        {
            mayor=v[i];
            posMa=i;
        }
    }
    return mayor;
}

int menor (int v[], unsigned cant, int &posMe)
{
    int menor;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || v[i]<menor)
        {
            menor=v[i];
            posMe=i;
        }
    }
    return menor;
}

void cargarDados(int v[], unsigned cant)
{
    int dado1, dado2;
    for(int i=0; i<cant; i++)
    {
        cout<<"Tire el dado 1: ";
        dado1=validarDatos(1, 6);
        cout<<"Tire el dado 2: ";
        dado2=validarDatos(1, 6);
        v[i]=(dado1+dado2);
    }
}

void numRepe(int v[], unsigned cant)
{
    int pri, cont=0;
    for(int i=0; i<cant; i++)
    {
        if(i==0 || v[i]!=pri)
        {
            pri=v[i];
            for(int i=0; i<cant; i++)
            {
                if(v[i]==pri)
                    cont++;
            }
            cout<<pri<<" salio "<<cont<<" veces"<<endl;
            cont=0;
        }
        
    }
}

void vectorSuma(int a[], int b[], int suma[], unsigned cant)
{
    for(int i=cant-1; i>=0; i--)
    {
        suma[i+1]+=a[i]+b[i];
        if (suma[i+1]>9)
        {
            suma[i+1]-=10;
            suma[i]+=1;
        }
    }
}

void inicializar(int v[], unsigned cant)
{
    for(int i=0; i<cant; i++)
        v[i]=0;
}

void vectorResta(int a[], int b[], int resta[], unsigned cant)
{
    for(int i=cant-1; i>=0; i--)
    {
        resta[i]=a[i]-b[i];
        if(i!=0 && resta[i]<0)
        {
           resta[i]+=10;
           a[i-1]-=1;
        }
    }
}

void cargarParalelo(int cod[], int precios[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        cout<<"Ingrese el codigo del producto Nro "<<i+1<<": ";
        cin>>cod[i];
        cout<<"Ingrese el precio del producto Nro "<<i+1<<": ";
        cin>>precios[i];
    }
}

void mayorAmenor(int cod[], int precios[], int cant)
{
    int i, j, auxP, auxC;
    for(i=1; i<cant; i++)
    {
        for(j=0; j<cant-1; j++)
        {
            if(precios[j] < precios[j+1])
            {
                auxP = precios[j];
                precios[j] = precios[j+1];
                precios[j+1] = auxP;

                auxC = cod[j];
                cod[j] = cod[j+1];
                cod[j+1] = auxC;
            }
        }   
        
    }
}

void informarPrecio(int cod[], int precios[], int cant)
{
    int c;
    bool pri=true;
    cout<<"Ingrese el codigo de producto que desea buscar: ";
    cin>>c;

    for(int i=0; i<cant; i++)
    {
        if(cod[i]==c)
        {    
            cout<<"El precio es: "<<precios[i]<<endl;
            pri=false;
        }
    }
    if(pri)
        cout<<"No se encontro el producto."<<endl;
}

int validarDatos(int d, int h)
{
    int num;
    do
    {
        cin>>num;
    } while (num<d || num>h);
    return num;
}   

