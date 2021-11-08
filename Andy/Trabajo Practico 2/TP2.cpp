#include <iostream>
using namespace std;

struct Pedido
{
    string domicilio;
    int zona_entrega;
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
};

struct NodoSubLista
{
    Pedidos info;
    NodoSubLista *sig;
};

struct NodoLista
{
    int info; //dni
    NodoLista *sig;
};

int indicar_vehiculo(float vol);
int validar_zona();
void cargar_pedidos(int m[][4]);
void inicializar(Cola m[][4], unsigned f, unsigned c);
void encolar(NodoCola *&pri, NodoCola *&ult, Pedido ped);
Pedido desencolar(NodoCola *&pri, NodoCola *&ult);
bool buscar_repartidor(int zona, int nro_vehiculo);
bool leer_archivo(FILE*, int zona);
void asignar_pedidos(Cola m[][4]);
Repartidor buscar_dni(int dni);
Repartidor leer_archivo2(FILE*f, int dni, int nro_vehiculo);

int main()
{
    Cola*repartidores[14][4];

    inicializar(repartidores, 14, 4);
    cout<<endl<<"CARGAR PEDIDOS: "<<endl;
    cargar_pedidos(repartidores);
    cout<<endl<<"ASIGNAR PEDIDOS:"<<endl;
    asignar_pedidos(repartidores);

    return 0;
}

int indicar_vehiculo(float vol) //Asigna u nro del 0 al 3 en base al volumen para determinar el tipo de vehiculo
{
    if(vol<0,005)
        return 0; // Moto
    else if(vol<0,02)
        return 1; // Auto
    else if(vol<8)
        return 2; // Camioneta
    else 
        return 3; // Camion 
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

void insertar(NodoLista* &lista, int dni)
{
    Nodo *n, *l, *ant;
    n = new NodoLista;
    n->info = dni;
    l = lista;
    while(l != NULL && l->info < dni)
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

Nodo *buscarInsertar(NodoSubLista* &lista, Pedido ped) 
{
    Nodo *l, *ant;
    l = lista;
    while(l != NULL && l->info.importe > ped.importe)
    {
        ant = l;
        l = l->sig;
    }
    if(l == NULL || l->info.importe!=ped.importe) 
    {
        NodoSubLista *n = new NodoSubLista;
        n->info = ped;
        n->sig = l;
        if(l != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
    else
        return l;
}

void cargar_pedidos(int m[][4])
{
    Pedido p;
    cout<<"Zona de entrega: ";
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
        
        cout<<"Zona de entrega: ";
        p.zona = validar_zona();
    }
}

bool buscar_repartidor(int zona, int nro_vehiculo) // Verifica que haya por lo menos un repartidor en la zona y vehiculo pedido
{
    switch (nro_vehiculo)
    {
        case 0:
            FILE*f = fopen("RepMoto.dat", "rb");
            break;
        
        case 1:
            FILE*f = fopen("RepAuto.dat", "rb");
            break;
        
        case 2:
            FILE*f = fopen("RepCamioneta.dat", "rb");
            break;
        
        case 3:
            FILE*f = fopen("RepCamion.dat", "rb");
            break;
    }
    if(f == NULL)
        cout<<"Error."<<endl;
    else
        return leer_archivo(f, zona);
    fclose(f);
}

bool leer_archivo(FILE*, int zona)
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

void asignar_pedidos(Cola m[][4]) //vericar que el repartidor este en esa zona y vehiculo y en base a eso asignarle un pedido de la cola
{
    int dni;
    cout<<"Dni: "
    cin>>dni;
    Repartidor rep;
    Pedido ped;
    while(dni != 0)
    {
        rep = buscar_dni;
        if(rep.nro_vehiculo == -1)
            cout<<"El repartidor no existe."<<endl;
        else
        {
            ped = deseconlar(m[rep.zona-1][rep.nro_vehiculo-1].pri, m[rep.zona-1][rep.nro_vehiculo-1].ult);

        }
    }
}

Repartidor buscar_dni(int dni) //Funcion que se me occurrio, no estoy seguro si esta bien 
{
    FILE* f = fopen("RepMoto.dat", "rb");
    Repartidor rep;
    int i=0;
    rep = leer_archivo2(f, dni, i);
    i++;
    if (rep.nro_vehiculo == -1)
    {
        FILE* f = fopen("RepAuto.dat", "rb");
        rep = leer_archivo2(f, dni, i);
        i++;
    }
    else if(rep.nro_vehiculo == -1)
    {
        FILE* f = fopen("RepCamioneta.dat", "rb");
        rep = leer_archivo2(f, dni, i);
        i++; 
    }
    else if(rep.nro_vehiculo == -1)
    {
        FILE* f = fopen("RepCamion.dat", "rb");
        rep = leer_archivo2(f, dni, i);
        i++; 
    }
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
        while(!feof(f) && r.dni != dni);
        {
            fread(&r, sizeof(Arch_rep), 1, f);
        }
        rep.dni = r.dni;
        rep.zona = r.zona;
        if(!feof(f))
            rep.nro_vehiculo = nro_vehiculo;
        else
            rep.nro_vehiculo = -1; // si no lo encontro
        return rep;
    }
    fclose(f);
}
