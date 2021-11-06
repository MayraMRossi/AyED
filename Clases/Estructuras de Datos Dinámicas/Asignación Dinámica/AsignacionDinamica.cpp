#include <iostream>

using namespace std;


int main()
{
    /*
    int a;
    int*p;
    a=5;
    p=&a;
    cout<<a<<endl;
    cout<<*p<<endl;
    a=8;
    cout<<*p<<endl;
    cout<<p<<endl;
    */
    int *p,*q;
    p=new int;
    *p=5;
    cout<<*p<<endl;
    cout<<p<<endl;
    //delete p;

    //p=NULL;

    //q=p;
    q=new int;
    *q=*p;
    *p=8;
    cout<<*q<<endl;
    cout<<q<<endl;

    return 0;
}


