#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Pedido
{
    string domicilio;
    int zona;
    float volumen;
    float importe;
    int cod_comercio;
    int nro_vehiculo;
};

struct NodoCola
{
    Pedido info;
    NodoCola*sig;
};

struct Cola
{
    NodoCola *pri, *ult;
};

struct Arch_rep
{
    unsigned dni;
    char nombre[40];
    char patente[10];
    int zona;
};

struct Repartidor
{
    unsigned dni;
    int zona;
    int nro_vehiculo;
    char nombre[40];
};

struct NodoSubLista
{
    Pedido info;
    NodoSubLista *sig;
};

struct Lista
{
    int dni;
    char nombre[40];
    NodoSubLista *lista_pedidos;
};

struct NodoLista
{
    Lista info;
    NodoLista *sig;
};

struct Arbol
{
    int cod_comercio;
    int cant_entregas;
};

struct NodoArbol
{
    Arbol info;
    NodoArbol *izq;
    NodoArbol *der;
};

int indicar_vehiculo(float vol);
int validar_zona();
void cargar_pedidos(Cola m[][4]);
void inicializar(Cola m[][4], unsigned f, unsigned c);
void encolar(NodoCola *&pri, NodoCola *&ult, Pedido ped);
Pedido desencolar(NodoCola *&pri, NodoCola *&ult);
bool buscar_repartidor(int zona, int nro_vehiculo);
bool leer_archivo(FILE*f, int zona);
void asignar_pedidos(Cola m[][4], NodoLista *&lista, NodoArbol *&arbol);
Repartidor buscar_dni(int dni);
Repartidor leer_archivo2(FILE*f, int dni, int nro_vehiculo);
void insertar(NodoSubLista* &lista, Pedido ped);
NodoLista *buscarInsertar(NodoLista* &lista, Lista lis);
string traducir_nro_veh(int nro_vehiculo);
void mostrar_lista(NodoLista*lista);
void buscar_insertar_arbol(NodoArbol*&raiz, int cod_comercio);
void listar_arbol(NodoArbol*raiz);

int main()
{
    Cola repartidores[14][4];
    NodoLista* lista_repartidores = NULL;
    NodoArbol* arbol_comercios = NULL;
    inicializar(repartidores, 14, 4);
   
    

    // MENU
    int opcion;

    do
    {
        cout<<"****************************************************************MENU****************************************************************"<<endl<<endl;
        cout<<"Seleccione una opcion: "<<endl<<"1: Cargar pedido."<<endl<<"2: Asignar Pedido."<<endl<<"3: Mostrar pedidos. "<<endl<<"4: Salir."<<endl;
        cin>>opcion;
        switch(opcion)
        {
            case 1: 
                cargar_pedidos(repartidores);
                break;
            case 2: 
                asignar_pedidos(repartidores, lista_repartidores, arbol_comercios);
                break;
            case 3: 
                mostrar_lista(lista_repartidores);
                break;
            case 4:
                cout<<endl;
                listar_arbol(arbol_comercios);
                break;
            default:
                cout<<"La opcion no existe. Volver a ingresar: "<<endl;
        }
        cout<<endl<<endl;
    } while(opcion!=4);


    return 0;
}

int indicar_vehiculo(float vol) //Asigna un nro del 0 al 3 en base al volumen para determinar el tipo de vehiculo
{
    int n;
    if(vol<0.005)
        n = 0; // Moto
    else if(vol<0.02)
        n = 1; // Auto
    else if(vol<8)
        n = 2; // Camioneta
    else 
        n = 3; // Camion 

    return n;
}

void inicializar(Cola m[][4], unsigned f, unsigned c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j].pri=NULL;
            m[i][j].ult=NULL;
        }
    }
}

int validar_zona()
{
    int z;
    do
    {
        cout << "Zona: (1 a 14)";
        cin >> z;
    } while (z < 0 || z > 14);

    return z;
}

void encolar(NodoCola *&pri, NodoCola *&ult, Pedido ped)
{
    NodoCola *p = new NodoCola;
    p->info = ped;
    p->sig = NULL;
    if(ult != NULL)
        ult->sig = p;
    else
        pri = p;
    ult=p;
}

Pedido desencolar(NodoCola *&pri, NodoCola *&ult)
{
    Pedido ped;
    NodoCola *p;
    p = pri;
    ped = p->info;
    pri = p->sig;
    delete p;
    if(pri == NULL)
        ult = NULL;
    return ped;
}

void insertar(NodoSubLista* &lista, Pedido ped)
{
    NodoSubLista *n, *l, *ant;
    n = new NodoSubLista;
    n->info = ped;
    l = lista;
    while(l != NULL && l->info.importe > ped.importe)
    {
        ant = l; 
        l = l->sig; 
    }
    n->sig = l;
    if(l != lista)
        ant->sig = n;
    else
        lista = n;
}

NodoLista *buscarInsertar(NodoLista* &lista, Lista lis)
{
    NodoLista *l, *ant;
    l = lista;
    while(l != NULL && l->info.dni < lis.dni)
    {
        ant = l;
        l = l->sig;
    }
    if(l == NULL || l->info.dni!=lis.dni) 
    {
        NodoLista *n = new NodoLista;
        n->info = lis;
        n->sig = l;
        n->info.lista_pedidos = NULL;
        if(l != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
    else
        return l;
}

void cargar_pedidos(Cola m[][4])
{
    Pedido p;
    cout<<endl<<"Zona de entrega: ";
    p.zona = validar_zona();
    while(p.zona != 0)
    {
        cout<<"Volumen del paquete: ";
        cin>>p.volumen;
        p.nro_vehiculo = indicar_vehiculo(p.volumen);
        if(buscar_repartidor(p.zona, p.nro_vehiculo))
        {
            cout<<"Domicio de entrega: ";
            cin>>p.domicilio; 
            cout<<"Importe del pedido: ";
            cin>>p.importe;
            cout<<"Codigo del comercio: ";
            cin>>p.cod_comercio;

            // Cargar matriz de colas
            encolar(m[p.zona-1][p.nro_vehiculo-1].pri, m[p.zona-1][p.nro_vehiculo-1].ult, p);
        }
        else
            cout<<"No hay repartidores disponibles."<<endl;
        
        cout<<endl<<"Zona de entrega: ";
        p.zona = validar_zona();
    }
}

bool buscar_repartidor(int zona, int nro_vehiculo) // Verifica que haya por lo menos un repartidor en la zona y vehiculo pedido
{
    FILE*f;
    switch (nro_vehiculo)
    {
        case 0:
            f = fopen("RepMoto.dat", "rb");
            break;
        
        case 1:
            f = fopen("RepAuto.dat", "rb");
            break;
        
        case 2:
            f = fopen("RepCamioneta.dat", "rb");
            break;
        
        case 3:
            f = fopen("RepCamion.dat", "rb");
            break;
    }
    if(f == NULL)
        cout<<"Error."<<endl;
    else
        return leer_archivo(f, zona);
    fclose(f);
}

bool leer_archivo(FILE*f, int zona)
{
    Arch_rep r;
    fread(&r, sizeof(Arch_rep), 1, f);
    while(!feof(f) && r.zona != zona)
    {
        fread(&r, sizeof(Arch_rep), 1, f);
    }
    if(feof(f))
        return false;
    else
        return true;
}

void asignar_pedidos(Cola m[][4], NodoLista *&lista, NodoArbol *&arbol) //vericar que el repartidor este en esa zona y vehiculo y en base a eso asignarle un pedido de la cola
{
    Repartidor rep;
    Pedido ped;
    int cont;
    cout<<endl<<"Dni (0 para salir): ";
    cin>>rep.dni;
    while(rep.dni != 0)
    {
        rep = buscar_dni(rep.dni);
        if(rep.nro_vehiculo == -1)
            cout<<"El repartidor no existe."<<endl;
        else
        {
            NodoLista *l;
            Lista lis;
            Arbol a;
            if(m[rep.zona-1][rep.nro_vehiculo-1].pri == NULL)
                cout<<"No hay mas pedidos para la zona "<<rep.zona<<" y el vehiculo "<<traducir_nro_veh(rep.nro_vehiculo)<<endl;
            else
            {
                ped = desencolar(m[rep.zona-1][rep.nro_vehiculo-1].pri, m[rep.zona-1][rep.nro_vehiculo-1].ult);
                //crear lista
                lis.dni = rep.dni;
                strcpy(lis.nombre, rep.nombre);
                l = buscarInsertar(lista, lis);
                insertar(l->info.lista_pedidos, ped);

                //Insertar en el arbol
                buscar_insertar_arbol(arbol, ped.cod_comercio);

            }
        }
        cout<<endl<<"Dni: ";
        cin>>rep.dni;
    }
}

Repartidor buscar_dni(int dni) 
{
    FILE*f1 = fopen("RepMoto.dat", "rb");
    FILE*f2 = fopen("RepAuto.dat", "rb");
    FILE*f3 = fopen("RepCamioneta.dat", "rb");
    FILE*f4 = fopen("RepCamion.dat", "rb");
    Repartidor rep;
    
    rep = leer_archivo2(f1, dni, 0);
    if (rep.nro_vehiculo == -1)
    {
        rep = leer_archivo2(f2, dni,1);

        if (rep.nro_vehiculo == -1)
        {
            rep = leer_archivo2(f3, dni, 2);

            if (rep.nro_vehiculo == -1)
            {
                rep = leer_archivo2(f4, dni, 3);
            }
        }
    }
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);

    return rep;
}


Repartidor leer_archivo2(FILE*f, int dni, int nro_vehiculo)
{
    if(f == NULL)
        cout<<"Error."<<endl;
    else
    {
        Arch_rep r;
        Repartidor rep;
        fread(&r, sizeof(Arch_rep), 1, f);
        while(!feof(f) && r.dni != dni)
            fread(&r, sizeof(Arch_rep), 1, f);

        rep.dni = r.dni;
        rep.zona = r.zona;
        strcpy(rep.nombre, r.nombre);

        if(!feof(f))
            rep.nro_vehiculo = nro_vehiculo;
        else
            rep.nro_vehiculo = -1; // si no lo encontro
        return rep;
    }
}

string traducir_nro_veh(int nro_vehiculo)
{
    string n;
    switch(nro_vehiculo)
    {
        case 0: n="Moto"; break;
        case 1: n="Auto"; break;
        case 2: n="Camioneta"; break;
        case 3: n="Camion"; break;
    }
    return n;
}

void mostrar_lista(NodoLista*lista)
{
    NodoSubLista* p;
    while(lista!=NULL)
    {
        cout<<endl<<"Dni: "<<lista->info.dni<<endl;
        cout<<"Nombre: "<<lista->info.nombre<<endl<<endl;
        cout<<"PEDIDOS: "<<endl<<endl;
        p = lista->info.lista_pedidos;
        while(p!=NULL)
        {
            cout<<"Importe "<<p->info.importe<<endl
            <<"Domicilio: "<<p->info.domicilio<<endl
            <<"Zona: "<<p->info.zona<<endl
            <<"Volumen: "<<p->info.volumen<<endl
            <<"Codigo Comercio: "<<p->info.cod_comercio<<endl<<endl;
            p = p->sig;
        }
        lista = lista->sig;
    }
}

void listar_arbol(NodoArbol*raiz)
{
    if(raiz!=NULL)
    {
        listar_arbol(raiz->izq);
        cout<<"Cod comercio: "<<raiz->info.cod_comercio<<endl;
        cout<<"Cantidad de entregas: "<<raiz->info.cant_entregas<<endl<<endl;
        listar_arbol(raiz->der);
    }
}

void buscar_insertar_arbol(NodoArbol*&raiz, int cod_comercio)
{
    NodoArbol *r = raiz;
    while(r!=NULL && r->info.cod_comercio != cod_comercio)
    {
        if(r->info.cod_comercio > cod_comercio)
            r = r->izq;
        else
            r = r->der;
    }
    
    if(r==NULL || r->info.cod_comercio != cod_comercio) //si no lo encuentro
    {
        NodoArbol*n= new NodoArbol;
        n->info.cod_comercio=cod_comercio;
        n->izq=n->der=NULL;
        n->info.cant_entregas = 1;

        if(raiz==NULL)
            raiz=n;
            
        else
        {
            NodoArbol *ant, *r=raiz;
            do
            {
                ant=r;
                if(cod_comercio < r->info.cod_comercio)
                    r = r->izq;
                else
                    r = r->der;
            } while(r!=NULL);
            if(cod_comercio < ant->info.cod_comercio)
                ant->izq = n;
            else
                ant->der = n;
        }
    }
    else
        r->info.cant_entregas++;
}

