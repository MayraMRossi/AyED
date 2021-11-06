#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str="de string a vector de char";
    char cadena[31];
    strcpy(cadena,str.c_str());
    cout<<cadena<<endl;
    cout<<str<<endl;

    cout<<endl;

    strcpy(cadena,"de vector de char a string");
    //str=string(cadena);
    str=cadena;
    cout<<str<<endl;
    cout<<cadena<<endl;
    return 0;
}
