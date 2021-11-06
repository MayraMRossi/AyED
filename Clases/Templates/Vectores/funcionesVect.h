#include <iostream>


using namespace std;

template<typename T> void mostrarV(T v[],int t,void (*mostrarDato)(T)){
   for(int i=0;i<t;i++)
      mostrarDato(v[i]);

}

template<typename T> void ingresar(T a[], int t,T(*ingresarD)()){
   for(int i=0;i<t;i++)
      a[i]=ingresarD();
}

template<typename T> void ordenar(T v[], int t, int(*criterio)(T,T)){
   int  p=0;
   bool cambio;
   T aux;
   do
   {
      p++;
      cambio=false;
      for(int i=0;i<t-p;i++)
      {
         if(criterio(v[i],v[i+1])>0)
         {
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
            cambio=true;
         }
      }
   }while(cambio);
}

template<typename T> void inicializarV(T v[],int t,void (*inicializar)(T)){
   for(int i=0;i<t;i++)
      inicializar(v[i]);
}

template<typename T,typename K>int busquedaBinaria(T v[],int t,K dato,int (*criterio)(K,T))
{
    int pos,desde,hasta,medio;
    pos=-1;
    desde=0;
    hasta=t-1;
    while(desde<=hasta && pos==-1)
    {
        medio=(desde+hasta)/2;
        if(criterio(dato,v[medio])==0)
            pos=medio;
        else
        {
            if(criterio(dato,v[medio])<0)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}
