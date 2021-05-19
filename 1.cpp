
//EJERCICIO SUMA DE DOS NUMEROS

/*#include <iostream>

using namespace std;

main(){

int num1,num2,suma;
cout<<"inserte el primer numero: "<<endl;
cin>>num1;
cout<<"inserte el segundo numero: "<<endl;
cin>>num2;
suma = num1 + num2;
cout<<"La suma es: "<<suma<<endl;
return 0;

}
*/

//EJERCICIO SUMA , resta y multiplicacion de 3 num positivos

/*
#include <iostream>

using namespace std;

main(){

int num1,num2,num3,operacion;
cout<<"inserte el primer numero: "<<endl;
cin>>num1;
cout<<"inserte el segundo numero: "<<endl;
cin>>num2;
cout<<"inserte el tercer numero: "<<endl;
cin>>num3;

//Suma
operacion = num1 + num2 + num3;
cout<<"La suma es: "<<operacion<<endl;

//Resta
operacion = num1 - num2 - num3;
cout<<"La resta es: "<<operacion<<endl;

//Multiplicacion
operacion = num1 * num2 * num3;
cout<<"La multiplicacion es: "<<operacion<<endl;

return 0;

}

*/

//Ejercicio 2 leer dos numeros y encontrar a. la sma del doble del primero mas el cuadrado del segundo b. promedio de sus cubos
/*
#include <iostream>

using namespace std;

main(){

float num1,num2,operacion;
cout<<"inserte el primer numero: "<<endl;
cin>>num1;
cout<<"inserte el segundo numero: "<<endl;
cin>>num2;
//a
operacion = num1*2 + num2*num2;
cout<<"La suma es: "<<operacion<<endl;
//b
operacion = (num1*num1*num1)/3;
cout<<"El promedio del cubo de "<<num1;
cout<<" es: "<<operacion<<endl;

operacion = (num2*num2*num2)/3;
cout<<"El promedio del cubo de "<<num2;
cout<<" es: "<<operacion<<endl;
return 0;

}
*/

//EJERCICIO 3 Determinar la suma de las cifras de un numero entero positivo de 4 cifras

/*
#include <iostream>

using namespace std;

main(){

int num = 0,operacion = 0;
cout<<"inserte un numero de 4 cifras: "<<endl;
cin>>num;

//opcion 1

operacion = num/1000;
num = num%1000;
operacion = operacion + num/100;
num = num%100;
operacion = operacion + num/10;
num = num%10;
operacion = operacion + num/1;
cout<<"La suma es: "<<operacion<<endl;



//opcion 2
while (num>0){
    operacion = operacion + num%10;
    num = num/10;
}
cout<<"La suma es: "<<operacion<<endl;

return 0;

}
*/

//EJERCICIO 4 elabore un programa que calcule la edad de una persona
//prueba

#include <iostream>

using namespace std;

main()
{

    float operacion = 0, ano = 0, mes = 0;
    cout << "Ingrese el a�o de nacimiento";
    cin >> ano;
    cout << "ingrese el mes de nacimiento en numero/";
    cin >> mes;
    if (mes >= 4)
    {
        operacion = 2021 - ano - 1;
    }
    else
        operacion = 2021 - ano;

    cout << "Tu edad es: " << operacion;
    return 0;
}
