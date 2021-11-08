#include <iostream>
using namespace std;



int MCD(int, int);
int factorial(int);
bool multip(int, int);
float porcentaje(int, int);
unsigned edadAGrupoEtario(unsigned);
int fecha(int, int, int);
void fechaInversa(int);
void sumaHoras(int, int);
int restaMenor(int, int);
float combinatorio(int, int);
char vieja(int, int, int, int, char); 

int main()
{
    //EJERCICIO 1
    /*
    int num1, num2, Resto;

    cout<<"Ingrese el 1er numero: ";
    cin>>num1;
    cout<<"Ingrese el 2do numero: ";
    cin>>num2;
    cout<<"El MCD es: "<<MCD(num1, num2);
    */
    
    //EJERCICIO 2
    /*
    int num;

    cout<<"Ingrese un numero: ";
    cin>>num;
    cout<<"Factorial de "<<num<<": "<<factorial(num);
    */

    //EJERCICIO 3
    /*
    int num1, num2;

    cout<<"Ingrese el 1er numero: ";
    cin>>num1;
    cout<<"Ingrese el 2do numero: ";
    cin>>num2;
    if(multip(num1, num2))
        cout<<"verdadero";
    else
        cout<<"falso";
    */
    

    //EJERCICIO 4
    /*
    int num, cont1=0, cont2=0, cont3=0;
    
    cout<<"Ingrese un numero positivo, para finalizar ingrese 0: ";
    cin>>num;
    while(num!=0)
    {
        cout<<"Factorial: "<<factorial(num)<<endl;
        if(multip(num, 3))
            cont1++;
        if(multip(num, 5))
            cont2++;
        if(multip(num, 3) && multip(num, 5))
            cont3++;
        cout<<"Ingrese un numero positivo, para finalizar ingrese 0: ";
        cin>>num;
    }
    
    cout<<"Multiplos de 3: "<<cont1<<endl;
    cout<<"Multiplos de 5: "<<cont2<<endl;
    cout<<"Multiplos de 3 y 5: "<<cont3<<endl;
    */

    //EJERCICIO 5
    /*
    int dado1, dado2;
    
    cout<<"Ingrese el valor del dado 1: ";
    cin>>dado1;
    cout<<"Ingrese el valor del dado 2: ";
    cin>>dado2;
    if(dado2>dado1)
        cout<<"El valor es invalido";
    else
        cout<<"Combinatorio: "<<combinatorio(dado1, dado2);
    */

    //EJERCICIO 6
    /*
    int num1, num2;
    
    cout<<"Ingrese el 1er numero: ";
    cin>>num1;
    cout<<"Ingrese el 2do numero: ";
    cin>>num2;
    
    cout<<num1<<" es el %"<<porcentaje(num1, num2)<<" de "<<num2;
    */

    //EJERCICIO 7
    /*
    unsigned edad;

    cout<<"Ingrese su edad: ";
    cin>>edad;
    if(edadAGrupoEtario(edad)==0)
        cout<<"El valor ingresado es invalido";
    else
        cout<<"Grupo etario: "<<edadAGrupoEtario(edad);
    */

    //EJERCICIO 8
    /*
    int dia, mes, anio;

    cout<<"Ingrese el dia ";
    cin>>dia;
    cout<<"Ingrese el mes ";
    cin>>mes;
    cout<<"Ingrese el anio ";
    cin>>anio;

    cout<<"La fecha es: "<<fecha(dia, mes, anio);
    */

    //EJERCICIO 9
    /*
    int fecha;

    cout<<"Ingrese la fecha: ";
    cin>>fecha;

    fechaInversa(fecha);
    */

    //EJERCICIO 10
    /*
    int hora, tiempo;

    cout<<"Ingrese la hora: ";
    cin>>hora;
    cout<<"Ingrese el tiempo: ";
    cin>>tiempo;

    sumaHoras(hora, tiempo);
    */

    //EJERCICIO 11 
    /*
    int num1, num2, opcion;

    cout<<"Ingrese el 1er numero: ";
    cin>>num1;
    cout<<"Ingrese el 2do numero: ";
    cin>>num2;

    cout<<"Ingrese:"<<endl<<"1. Suma de los numeros."<<endl<<"2. Resta del menor de los numeros al mayor."<<endl<<"3. Que porcentaje representa el menor de los numeros sobre el mayor."<<endl<<"4. Maximo comun divisor de ambos numeros."<<endl<<"5. Numero combinatorio del mayor de los numeros sobre el menor."<<endl<<"6. Cambiar los numeros."<<endl;
    cin>>opcion;
    
    
        switch(opcion)
        {
            case 1: cout<<num1+num2; break;
            case 2: restaMenor(num1, num2); break;
            case 3:
                if(num1>num2)
                    cout<<"%"<<porcentaje(num2, num1);
                else if(num2>num1)
                    cout<<"%"<<porcentaje(num1, num2);
                else
                    cout<<"Los numeros son iguales"<<endl;
                break;
            case 4: cout<<MCD(num1, num2); break;
            case 5: 
                if(num1>num2)
                    cout<<combinatorio(num2, num1);
                else if(num2>num1)
                    cout<<combinatorio(num1, num2);
                else
                    cout<<"Los numeros son iguales"<<endl;
                break;
            default: cout<<"El numero ingresado es invalido"; break;
    
    

    }
    */

    //EJERCICIO 12
    /*
    int diaNacimiento, mes, anio, cont1=0, cont2=0, cont3=0, cont4=0, cont5=0, cont6=0, cont7=0, cont8=0, contOctubre=0, contAntes=0, contPrimavera=0, contVueltas=0;
    char sexo, sexoMayor;

    cout<<"Ingrese el dia de nacimiento, para finalizar ingrese cero: ";
    cin>>diaNacimiento;
    while(diaNacimiento!=0)
    {
        contVueltas++;
        cout<<"Ingrese el mes: ";
        cin>>mes;
        cout<<"Ingrese el anio: ";
        cin>>anio;
        cout<<"Ingrese el sexo (M/F): ";
        cin>>sexo;

        if(edadAGrupoEtario(2021-anio)==1)
            cont1++;
        if(edadAGrupoEtario(2021-anio)==2)
            cont2++;
        if(edadAGrupoEtario(2021-anio)==3)
            cont3++;
        if(edadAGrupoEtario(2021-anio)==4)
            cont4++;
        if(edadAGrupoEtario(2021-anio)==5)
            cont5++;
        if(edadAGrupoEtario(2021-anio)==6)
            cont6++;
        if(edadAGrupoEtario(2021-anio)==7)
            cont7++;
        if(edadAGrupoEtario(2021-anio)==8)
            cont8++;

        if(mes==10)
            contOctubre++;
        
        if(fecha(diaNacimiento, mes, anio)<19900709)
            contAntes++;
        
        if(sexo=='F' && fecha(diaNacimiento, mes, anio)>=19820922 && fecha(diaNacimiento, mes, anio)<=19821221)
            contPrimavera++;

        sexoMayor=vieja(diaNacimiento, mes, anio, contVueltas, sexo);
        
        
        cout<<"Ingrese el dia de nacimiento, para finalizar ingrese cero: ";
        cin>>diaNacimiento;
    }
    cout<<"Grupo etario 1: "<<cont1<<endl;
    cout<<"Grupo etario 2: "<<cont2<<endl;
    cout<<"Grupo etario 3: "<<cont3<<endl;
    cout<<"Grupo etario 4: "<<cont4<<endl;
    cout<<"Grupo etario 5: "<<cont5<<endl;
    cout<<"Grupo etario 6: "<<cont6<<endl;
    cout<<"Grupo etario 7: "<<cont7<<endl;
    cout<<"Grupo etario 8: "<<cont8<<endl;

    cout<<"Nacimientos en octubre: "<<contOctubre<<endl;
    cout<<"Nacimientos antes del 9/07/1990: "<<contAntes<<endl;
    cout<<"Cantidad de mujeres nacidas en la primavera del 1982: "<<contPrimavera<<endl;
    cout<<"Sexo de la persona mayor: "<<sexoMayor<<endl;
    */

    return 0;
}

int MCD(int a, int b)
{
    int r, MCD;

    r=a%b;
    while(r != 0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    MCD=b;
    
    return MCD;
}

int factorial(int num)
{
    int fact=1;
    for (int i=1; i<=num; i++)
    {
        fact*=i;
    }
    return fact;
}

bool multip(int n1, int n2)
{
    bool m=true;
    if(n1%n2 != 0)
        m=false;
    
    return m;
}

float porcentaje(int a, int b)
{
    return (float)a*100/b;
}

unsigned edadAGrupoEtario(unsigned edad)
{
    unsigned grupoEdad=0;
    if(edad>0 && edad<=14)
        grupoEdad=1;
    else if(edad>=15 && edad<=21)
        grupoEdad=2;
    else if(edad>=22 && edad<=28)
        grupoEdad=3;
    else if(edad>=29 && edad<=35)
        grupoEdad=4;
    else if(edad>=36 && edad<=42)
        grupoEdad=5;
    else if(edad>=43 && edad<=49)
        grupoEdad=6;
    else if(edad>=50 && edad<=63)
        grupoEdad=7;
    else if(edad>=64)
        grupoEdad=8; 
    return grupoEdad;
}

int fecha(int dia, int mes, int anio)
{
    return anio*10000 + mes*100 + dia;
}

void fechaInversa(int fecha)
{
    int dia, mes, anio;

    anio = fecha/10000;
    mes = (fecha-anio*10000)/100;
    dia = (fecha-anio*10000-mes*100);
    cout<<"Anio: "<<anio<<endl<<"Mes: "<<mes<<endl<<"Dia: "<<dia;

    
}

void sumaHoras(int h, int t)
{
    int horas1, minutos1, segundos1, horas2, minutos2, segundos2, horasF=0, minutosF=0, segundosF=0, dias=0;

    //La hora inicial
    horas1 = h/10000;
    minutos1 = (h-horas1*10000)/100;
    segundos1 = (h-horas1*10000-minutos1*100);
    //Tiempo que se suma
    horas2 = t/10000;
    minutos2 = (t-horas2*10000)/100;
    segundos2 = (t-horas2*10000-minutos2*100);

    segundosF=segundos1+segundos2;
    if(segundosF>=60)
    {
        minutosF++;
        segundosF-=60;
    }
    minutosF+=minutos1+minutos2;
    if(minutosF>=60)
    {
        horasF++;
        minutosF-=60;
    }
    horasF+=horas1+horas2;
    if(horasF>=24)
    {
        dias++;
        horasF-=24;
    }

    
    cout<<"La hora resultante es: "<<horasF<<":"<<minutosF<<":"<<segundosF<<endl;
    if(dias==1)
        cout<<"Hubo un cambio de dia";
}

int restaMenor(int a, int b)
{
    int result;
    if(a<b)
        result=b-a;
    else
        result=a-b;
    
    return result;
}

float combinatorio(int a, int b)
{
    return (float)factorial(a)/(factorial(b)*factorial(a-b));
}

char vieja(int dia, int mes, int anio, int vueltas, char sexo)
{
    int mayor;
    char sexoMayor;
    if(vueltas==1 || fecha(dia, mes, anio)<mayor)
    {
        mayor=fecha(dia, mes, anio);
        sexoMayor=sexo;
    }
    return sexoMayor;
    
}
