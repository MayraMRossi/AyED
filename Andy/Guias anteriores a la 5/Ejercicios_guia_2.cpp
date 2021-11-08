#include <iostream>
using namespace std;

int main()
{
    /*
    //EJERCICIO 1
    
    int num1, num2;
    cout << "Ingrese un numero: ";
    cin >> num1;
    cout << "Ingrese otro numero: ";
    cin >> num2;
    if (num1 < num2)
        cout << "El numero menor es: " << num1;
    else 
    {
        if(num2 < num1)
            cout << "El numero menor es: " << num2;
        else
            cout << "Los numeros son iguales";
    }
    */
    
    /*
    //EJERCICIO 2

    int num1, num2, resto;
    cout << "Ingrese un numero: ";
    cin >> num1;
    resto = num1 % 2;
    if (resto == 0)
        cout << "El numero es par ";
    else
        cout << "El numero es impar ";
    */
    
    /*
    //EJERCICIO 3
    int num1, num2;
    cout << "Ingrese un numero: ";
    cin >> num1;
    cout << "Ingrese otro numero: ";
    cin >> num2;
    if(num1 >num2)
        cout << "La resta es " << num1-num2 << endl;
    else    
        cout << "La suma es " << num1+num2 << endl;
    
    */
    
    /*
    //EJERCICIO 4
    float base, altura, superficie;
    cout << "Ingrese el valor de la base en cm "<<endl;
    cin >>base;
    cout << "Ingrese el valor de la altura en cm "<<endl;
    cin >> altura;
    superficie = (base * altura)/2;
    if(superficie<100)
        cout << "La superficie es de "<<superficie*100<<" mm cuadrados";
    else
        cout << "La superficie es de "<<superficie/10000<<" m cuadrados";

    */

    /*
    //EJERCICIO 5
    int num1, num2, num3;
    cout << "Ingrese un numero: ";
    cin >> num1;
    cout << "Ingrese otro numero: ";
    cin >> num2;
    cout << "Ingrese otro numero: ";
    cin >> num3;
    if (num1>num2 && num1>num3)
        cout << "El numero mayor es "<<num1;
    else
        if(num2>num1 && num2>num3)
            cout << "El numero mayor es "<<num2;
        else
            cout << "El numero mayor es "<<num3;

    */
    
    /*
    //EJERCICIO 6
    int anios1, meses1, dias1, anios2, meses2, dias2 ;
    cout << "Ingrese los anios de la 1era fecha ";
    cin >> anios1;
    cout << "Ingrese los meses de la 1era fecha ";
    cin >> meses1;
    cout << "Ingrese los dias de la 1era fecha ";
    cin >> dias1;
    cout << "Ingrese los anios de la 2da fecha ";
    cin >> anios2;
    cout << "Ingrese los meses de la 2da fecha ";
    cin >> meses2;
    cout << "Ingrese los dias de la 2da fecha ";
    cin >> dias2;

    if (anios1>anios2)
        cout << "La primera fecha es la mas reciente ";
    else 
        if(anios2>anios1)
            cout << "La segunda fecha es la mas reciente ";
        else
            if(meses1>meses2)
                cout << "La primera fecha es la mas reciente ";
            else
                if(meses2>meses1)
                    cout << "La segunda fecha es la mas reciente ";
                else
                    if(dias1>dias2)
                    cout << "La primera fecha es la mas reciente ";
                    else
                        if(dias2>dias1)
                            cout << "La segunda fecha es la mas reciente ";
                        else
                            cout << "Las fechas son identicas ";

    */

    /*
    //EJERCICIO 7
    int lado1, lado2, lado3;
    cout << "Ingrese el valor del primer lado ";
    cin >> lado1;
    cout << "Ingrese el valor del segundo lado ";
    cin >> lado2;
    cout << "Ingrese el valor del tercer lado ";
    cin >> lado3;
    if(lado1+lado2>lado3)
        cout << "Forman triangulo ";
    else
        cout << "No forman triangulo";

    */
    
    /*
    //EJERCIO 8
    int lado1, lado2, lado3;
    cout << "Ingrese el valor del primer lado ";
    cin >> lado1;
    cout << "Ingrese el valor del segundo lado ";
    cin >> lado2;
    cout << "Ingrese el valor del tercer lado ";
    cin >> lado3;
    if(lado1==lado2==lado3)
        cout << "Es un triangulo equilatero ";
    else
        if(lado1==lado2 || lado1==lado3 || lado2==lado3)
            cout << "Es un triangulo isosceles ";
        else
            cout << "Es un triangulo escaleno ";
    */
    
    /*
    //EJERCICIO 9
    int num;
    cout << "Ingrese un numero de 5 cifras ";
    cin >> num;
    if(num/10000 == num % 10)
        cout << "El numero es capicua ";
    else 
        cout << "El numero no es capicua ";
    */
    
    /*
    //EJERCICIO 10
    int mes, anio;
    cout << "Ingrese el anio ";
    cin >> anio;
    cout << "Ingrese el mes ";
    cin >> mes;
    if((anio/4)==0)
        if(mes == 1||3||5||7||8||10||12) 
            cout << "El mes tiene 31 dias ";
        else 
            if (mes == 4||6||9||11)
                cout << "El mes tiene 30 dias ";
            else
                if (mes == 2)
                    cout << "El mes tiene 29 dias ";
                else
                    cout << "El numero del mes es invalido ";
    else
        if(mes == 1||3||5||7||8||10||12) 
            cout << "El mes tiene 31 dias ";
        else 
            if (mes == 4||6||9||11)
                cout << "El mes tiene 30 dias ";
            else
                if (mes == 2)
                    cout << "El mes tiene 28 dias ";
                else
                    cout << "El numero del mes es invalido ";
    */

    /*
    //EJERCICIO 11
    int cod, cant;
    cout << "Ingrese el codigo del articulo: ";
    cin >> cod;
    cout << "Ingrese la cantidad ";
    cin >> cant;
    switch(cod)
    {
        case 1:
        case 10:
        case 100:
            cout << "Importe a pagar: $" << cant*10;
            break;
        case 2:
        case 22:
        case 222:
            if((cant%10)==0)
                cout << "Importe a pagar: $" << (float)cant*6.5;
            else
                cout << "Importe a pagar: $" << cant*7;
            break;
        case 3:
        case 33:
            if(cant>10)
                cout << "Importe a pagar: $" << (cant*3)-((float)cant*3*10/100); 
            else
                cout << "Importe a pagar: $" << cant*3;
            break;
        case 4:
        case 44:
            cout << "Importe a pagar: $" << cant*2;
            break;
        default:
            cout << "El codigo ingresado no corresponde a ningun articulo existente ";

    }
    */
    
    /*
    //EJERCICIO 12
    int hist, precio;
    char cod;
    cout << "Ingrese su numero de historia de paciente: ";
    cin >> hist;
    cout << "Ingrese el codigo de prestacion: ";
    cin >> cod;
    switch (cod)
    {
        case 'A':
            precio = 200;
            break;
        case 'D':
            precio = 400;
            break;
        case 'F':
            precio = 600;
            break;
        case 'M':
        case 'T':
            precio = 1500;
            break;
    }
    cout << "Numero de historia de paciente: " << hist << endl;
    cout << "Codigo de la prestacion: " << cod << endl;
    cout << "Importe a pagar: $" << precio;
    */
    return 0;
}