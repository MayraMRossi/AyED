
template<typename T>unsigned cantRegistros(FILE *archivo)
{
    fseek(archivo,0,SEEK_END);
    return ftell(archivo)/sizeof(T);
}

template<typename T,typename K>int busquedaSecuencial(FILE *archivo,K abuscar,T &dato,int (*criterio)(K,T))
{
    int c=0;
    fread(&dato,sizeof(dato),1,archivo);
    while(!feof(archivo) && criterio(abuscar,dato)!=0)
    {
        c++;
        fread(&dato,sizeof(dato),1,archivo);
    }

    if(!feof(archivo))
        return c;
    else
        return -1;
}

template<typename T,typename K>int busquedaBinaria(FILE *archivo,unsigned aBuscar,T &dato,int (*criterio)(K,T))
{
    int pos=-1;
    unsigned desde,hasta,medio;
    //fseek(archivo,0,SEEK_END);
    //hasta=ftell(archivo)/sizeof(dato)-1;
    hasta=cantRegistros<T>(archivo)-1;
    desde=0;
    while(pos==-1 && desde<=hasta)
    {
        medio=(desde+hasta)/2;
        fseek(archivo,medio*sizeof(dato),SEEK_SET);
        fread(&dato,sizeof(dato),1,archivo);
        if(criterio(aBuscar,dato)==0)
            pos=medio;
        else
        {
            if(criterio(aBuscar,dato)<0)
                hasta=medio-1;
            else
                desde=medio+1;
        }
    }
    return pos;
}

