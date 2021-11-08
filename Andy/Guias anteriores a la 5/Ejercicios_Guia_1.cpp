#include <iostream>
#include <math.h>

using namespace std; 

int main() 
{
	
	//EJERCICIO 1
	
	
	/*
	int num1, num2, num3, suma, resta, multiplicacion;
	cout<<"Insertar un numero ";
	cin>>num1;
	cout<<"Insertar otro numero ";
	cin>>num2;
	cout<<"Insertar otro numero ";
	cin>>num3;
	
	suma=num1+num2+num3;
	cout<<"La suma entre los numeros es " << suma<<endl;
	resta=-num1-num2-num3;
	cout<<"La resta entre los numeros es " << resta<<endl;
	multiplicacion=num1*num2*num3;
	cout<<"La multiplicacion entre los numeros es " << multiplicacion<<endl;
	*/
	
	
	//EJERCICIO 2
	
	
	/*
	int num1, num2, resultado1, resultado2;
    cout<<"Ingresar el primer numero"<<endl;
    cin>>num1;
    cout<<"Ingresar el segundo numero"<<endl;
    cin>>num2;
	
	resultado1=2*num1+num2*num2
    cout<<"El doble producto del primero mas el cuadrado del segundo es"<<resultado1<<endl:
    resultado2=(num1*num1*num1+num2*num2*num2)/2
    cout<<"El promedio de sus cubos es "<<resultado2<<endl;
	*/
	
	//EJERCICIO 3
	
	
	/*
	int num4c;
	cout << "Ingrese un numero de 4 cifras " << endl;
	cin >> num4c;
	int cifra1 = num4c/1000;
	int cifra2 = num4c/100 - cifra1*10;
	int cifra3 = num4c/10 - cifra1*100 - cifra2*10;
	int cifra4 = num4c - cifra1 * 1000 - cifra2*100 - cifra3*10;
	int suma = cifra1 + cifra2 + cifra3 + cifra4;
	cout << "La suma entre las cifras del numero es " << suma << endl;
	*/
	
	
	//EJERCICIO 4
	
	
	/*
	unsigned ano_de_nacimiento, ano_actual, edad;
	cout<<"Ingrese su ano de nacimiento ";
	cin>>ano_de_nacimiento;
	cout<<"Ingrese el ano actual ";
	cin>>ano_actual;
	
	edad= ano_actual-ano_de_nacimiento;
	cout<<"Su edad es "<<edad<<endl;
	*/
	
	
	//EJERCICIO 5
	
	
	/*
	unsigned anos, meses, meses_total;
	cout<<"Ingrese su edad en anos "<<endl;
	cin>>anos;
	cout<<"Ingrese su edad en meses desde su ultimo cumpleanos "<<endl;
	cin>>meses;
	
	meses_total=anos*12+meses;
	cout<<"Su edad total en meses es "<<meses_total<<endl;
	*/
	
	
	//EJERCICIO 6
	
	
	/*
	unsigned nota1, nota2, nota3, nota4, promedio;
	cout<<"Ingrese la primera nota "<<endl;
	cin>>nota1;
	cout<<"Ingrese la segunda nota "<<endl;
	cin>>nota2;
	cout<<"Ingrese la tercera nota "<<endl;
	cin>>nota3;
	cout<<"Ingrese la cuarta nota "<<endl;
	cin>>nota4;
	
	promedio=(nota1+nota2+nota3+nota4)/4;
	cout<<"Tu promedio es de "<<promedio<<endl;
	*/
	
	
	//EJERCICIO 7
	
	
	/*
	double radio, diametro, perimetro, superficie;
	cout<<"Ingrese el valor del radio en centimetros "<<endl;
	cin>>radio;
	diametro=radio*2;
	perimetro=2*3.14*radio;
	superficie=3.14*radio*radio;
	
	cout<<"El diametro es de "<<diametro<<" cm"<<endl;
	cout<<"El perimetro es de "<<perimetro<<" cm"<<endl;
	cout<<"La superficie es de "<<superficie<<" cm cuadrados"<<endl;
	*/
	
	
	//EJERCICIO 8
	
	
	/*
	double base, altura, area, perimetro;
	cout<<"Ingrese la base del rectangulo en cm: ";
	cin>>base;
	cout<<"Ingrese altura del rectangulo en cm: ";
	cin>>altura;
	
	area=base*altura;
	perimetro=2*base+2*altura;
	cout<<"El area es de "<<area<<" cm cuadrados"<<endl;
	cout<<"El perimetro de "<<perimetro<<" cm"<<endl;
	*/
	
	
	//EJERCICIO 9
	
	
	/*
	int aprobados, desaprobados, ausentes, total;
	float porc_aprob, porc_desaprob, porc_ausentes;
	cout<<"Ingrese la cantidad de alumnos aprobados ";
	cin>>aprobados;
	cout<<"Ingrese la cantidad de alumnos desaprobados ";
	cin>>desaprobados;
	cout<<"Ingrese la cantidad de alumnos ausentes ";
	cin>>ausentes;
	
	total=aprobados+desaprobados+ausentes;
	porc_aprob=aprobados*100/total;
	porc_desaprob=desaprobados*100/total;
	porc_ausentes=ausentes*100/total;
	cout<<"El porcentaje de alumnos aprobados es "<<porc_aprob<<endl;
	cout<<"El porcentaje de alumnos desaprobados es "<<porc_desaprob<<endl;
	cout<<"El porcentaje de alumnos ausentes es "<<porc_ausentes<<endl;
	
	*/
	
	
	//EJERCICIO 10
	
	
	/*
	float a, b, c;
	
	cout<<"Ingresar el valor del primer cateto "<<endl;
	cin>>a;
	cout<<"Ingresar el valor del segundo cateto "<<endl;
	cin>>b;
	
	c= sqrt(a*a+b*b);
	
	cout<<"La hipotenusa vale "<<c<<endl;
	*/
	
	
	//EJERCICIO 11
	
	
	/*
	float metros, precio_unit, precio;
	cout<<"Ingrese el largo del alambre en metros ";
	cin>>metros;
	
	precio_unit=10.50;
	precio=precio_unit*metros;
	
	cout<<"El precio total es de "<<precio<<" pesos"<<endl;
	*/
	
	
	//EJERCICIO 12
	
	
	/*
	float pesos, euros, dolares, cambio_D, cambio_E;
	cout<<"Ingrese la cantidad en pesos ";
	cin>>pesos;
	cout<<"Indique cuantos pesos son un euro ";
	cin>>cambio_E;
	cout<<"Indique cuantos pesos son un dolar ";
	cin>>cambio_D;
	euros=pesos/cambio_E;
	dolares=pesos/cambio_D;
	
	cout<<pesos<<" pesos son "<<euros<<" euros"<<endl;
	cout<<pesos<<" pesos son "<<dolares<<" dolares"<<endl;
	*/
	
	
	//EJERCICIO 13
	
	
	/*
	float ensambladora, pintura, electrica, presupuesto;
	cout<<"Ingrese el monto presupuestal ";
	cin>>presupuesto;
	
	ensambladora=37*100/presupuesto;
	pintura=42*100/presupuesto;
	electrica=21*100/presupuesto;
	
	cout<<"Ensambladora recibe el monto de "<<ensambladora<<endl;
	cout<<"Pintrua recibe el monto de "<<pintura<<endl;
	cout<<"Electrica recibe el monto de "<<electrica<<endl;
	
	*/
	
	
	//EJERCICIO 14
	
	
	/*
	float largo, alto, arena;
	
	cout<<"Ingrese el largo de la pared en metros ";
	cin>>largo;
	cout<<"Ingrese el alto de la pared en metros ";
	cin>>alto;
	
	arena=largo*alto*0.5;
	
	cout<<"La cantidad de arena necesaria es "<<arena<<" metros cubicos"<<endl;
	
	*/
	
	return 0;	
}
