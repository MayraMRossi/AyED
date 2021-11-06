#include <iostream>

using namespace std;

//Ingresar 5 números enteros y determinar e informar el mayor.


int main()
{
   int i,num,mayor;
   bool pri=true;
   //pri=true;
   for(i=1;i<=5;i++)
   {
       cout<<"Ingrese el numero de orden "<<i<<endl;
       cin>>num;
       if(pri)
       {
           mayor=num;
           pri=false;
       }
       else
       {
           if(num > mayor)
                mayor=num;
       }
       /*
       if(pri || num>mayor)
       {
           mayor=num;
           pri=false;
       }
       */

   }
   cout<<"El mayor es: "<<mayor<<endl;

    return 0;
}
