#include <iostream>
using namespace std;

int main()
{
    //EJERCICIO 1
    /*
    for(int i=1; i<=10; i++)
    {
        int num;
        cout << "Ingrese un numero: ";
        cin >> num;
        if(num>=0)
            cout << num << " "<<endl;
    }
    */

    //EJERCICIO 2
    /*
    int cant, nota1, nota2;
    string nombre;
    cout<<"Ingrese la cantidad de alumnos ";
    cin >> cant;
    for(int i=1; i<=cant; i++)
    {
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese la 1era nota: ";
        cin >> nota1;
        cout << "Ingrese la 2da nota: ";
        cin >> nota2;
        
        float prom = ((float)nota1+nota2)/2;
        cout << nombre << " tiene un promedio de: " << prom << endl;
    }
    */

    //EJERCICIO 3
    /*
    int num, cant, par;
    par = 0;
    cout << "Ingrese la cantidad de numeros que desea evaluar: ";
    cin >> cant;
    for(int i=1; i<=cant; i++)
    {
        par+=2;
        cout << par << " ";
 
    }
    */

    //EJERCICIO 4
    /*
    int num, cont=0, i;
    for(i=1; i<=20; i++)
    {
        cout << "Ingrese un numero de orden "<<i<<": ";
        cin >> num;
        if(num<0)
            cont++;
    }
    cout << "La cantidad de numeros negativos es: "<<cont;
    */
    
    //EJERCICIO 5
    /*
    int num, suma=0;
    for(int i=1; i<=10; i++)
    {
        cout << "Ingrese un numero de orden "<<i<<": ";
        cin >> num;
        suma+=num;
    }
    cout << "La sumatoria es: " << suma;
    */
    
    //EJERCICIO 6
    /*
    int cant, num, suma=0;
    cout << "Ingrese la cantidad de numeros que desea evaluar: ";
    cin >> cant;
    for(int i=1; i<=cant; i++)
    {
        cout << "Ingrese un numero de orden "<<i<<": ";
        cin >> num;
        suma+=num;
    }
    int prom = suma/cant;
    cout << "El promedio es: " << prom;
    */

    //EJERCICIO 7
    /*
    int cant, nota, cont1=0, cont2=0;
    string nombre;
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> cant;
    for (int i=1; i<=cant; i++)
    {
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese la nota: ";
        cin >> nota;
        if(nota>=6)
        {
            cout << nombre << " aprobado"<<endl;
            cont1++;
        }
        else
        {
            cout << nombre << " desaprobado"<<endl;
            cont2++;
        }
    }
    float porc1 = (float)cont1/cant*100;
    float porc2 = (float)cont2/cant*100;
    cout << "El porcentaje de alumnos aprobados es: % "<<porc1<<endl;
    cout << "El porcentaje de alumnos desaprobados es: % "<<porc2<<endl;
    */

    //EJECICIO 8
    /*
    int num, M, C, D, U;
    cout << "Ingrese el numero: ";
    cin >> num;

    M = num/1000;
    C = (num/100) - (M*10);
    D = (num/10) - (M*100) - (C*10);
    U = num%10;
    
    switch(M)
    {
        case 1:
            cout<<"M";
            break;
        case 2:
            cout<<"MM";
            break;
        case 3:
            cout<<"MMM";
            break;
    }

    switch(C)
    {
        case 1: 
            cout<<"C";
            break;
        case 2: 
            cout<<"CC";
            break;
        case 3: 
            cout<<"CCC";
            break;
        case 4: 
            cout<<"CD";
            break;
        case 5: 
            cout<<"D";
            break;
        case 6: 
            cout<<"DC";
            break;
        case 7: 
            cout<<"DCC";
            break;
        case 8: 
            cout<<"DCCC";
            break;
        case 9: 
            cout<<"CM";
            break;
    }
    switch(D)
    {
        case 1: 
            cout<<"X";
            break;
        case 2: 
            cout<<"XX";
            break;
        case 3: 
            cout<<"XXX";
            break;
        case 4: 
            cout<<"XL";
            break;
        case 5: 
            cout<<"L";
            break;
        case 6: 
            cout<<"LX";
            break;
        case 7: 
            cout<<"LXX";
            break;
        case 8: 
            cout<<"LXXX";
            break;
        case 9: 
            cout<<"XC";
            break;
    }
    switch(U)
    {
        case 1: 
            cout<<"I";
            break;
        case 2: 
            cout<<"II";
            break;
        case 3: 
            cout<<"III";
            break;
        case 4: 
            cout<<"IV";
            break;
        case 5: 
            cout<<"V";
            break;
        case 6: 
            cout<<"VI";
            break;
        case 7: 
            cout<<"VII";
            break;
        case 8: 
            cout<<"VIII";
            break;
        case 9: 
            cout<<"IX";
            break;        
    }
    */

    //EJERCICIO 9
    /*
    int num, acum=0, suma=0, prom, cont=0;
    for(int i=1; i<=50; i++)
    {
        cout<<"Ingrese un numero ";
        cin>>num;
        if(num>100)
        {
            acum+=num;
            cont++;
        }
        else if (num < -10)
            suma+=num;
    }
    prom=acum/cont;
    cout<<"El promedio de los numeros mayores que 100 es: "<<prom<<endl;
    cout<<"La suma de los numeros menores que -10 es: "<<suma<<endl; 
    */
    
    //EJERCICIO 10
    /*
    int equipo, puntaje=0;
    string nombre;
    char cod;
    cout<<"Ingrese la cantidad de equipos: ";
    cin>>equipo;
    int cant_partidos=equipo-1;
    for(int i=1; i<=equipo; i++)
    {
        cout<<"Ingrese el nombre del equipo: ";
        cin>>nombre;
        for(int j=0; j<cant_partidos; j++)
        {
            cout<<"Ingrese el codigo del resultado: "<<endl<<"P: Perdido"<<endl<<"E: Empatado"<<endl<<"G: Ganado"<<endl;
            cin>>cod;
            switch(cod)
            {
                case 'E': 
                    puntaje++;
                    break;
                case 'G':
                    puntaje+=3;
                    break;
            }
        }
        cout<<"Equipo: "<<nombre<<endl<<"Puntaje: "<<puntaje<<endl;
        puntaje=0;
    }
    */

    //EJERCICIO 11
    /*
    int num1, num2, suma=0;
    cout<<"Ingrese un numero: ";
    cin>>num1;
    cout<<"Ingrese otro numero: ";
    cin>>num2;
    cout<<num1*num2<<" = ";
    for(int i=1; i<=num2; i++)
    {
        cout<<num1<<" ";
    }
    */

    //EJERCICIO 12
    /*
    int num, factorial=1;
    cout<<"Ingrese un numero entero positivo: ";
    cin>>num;
    for(int i=1; i<=num; i++)
    {
        factorial*=i;
    }
    cout<<"El factorial del numero es: "<<factorial;
    */
    
    //EJERCICIO 13
    /*
    int num, suma=0, cont=0, prom;
    cout<<"Ingrese un numero. Ingrese cero para finalizar: ";
    cin>>num;
    while(num!=0)
    {
        suma+=num;
        cont++;
        cout<<"Ingrese un numero. Ingrese cero para finalizar: ";
        cin>>num;
    }
    if(cont==0)
        cout<<"No se ingresaron datos"<<endl;
    else
    {
        prom=suma/cont;
        cout<<"El promedio es: "<<prom<<endl;
    }
    */

    //EJERCICIO 14
    /*
    int sueldo, cont1=0, cont2=0, cont3=0, cont4=0;
    cout<<"Ingrese el sueldo, para finalizar ingrese cero: ";
    cin>>sueldo;
    while(sueldo!=0)
    {
        if(sueldo<900)
            cont1++;
        else if(sueldo>900 && sueldo<1200)
            cont2++;
                else if(sueldo>1200 && sueldo<2000)
                    cont3++;
                        else if(sueldo>2000)
                            cont4++;
        cout<<"Ingrese el sueldo: ";
        cin>>sueldo;
    }    
    cout<<"Cantidad de empleados que ganan menos de $900: "<<cont1<<endl;
    cout<<"Cantidad de empleados que ganan entre $900 y $1200: "<<cont2<<endl;
    cout<<"Cantidad de empleados que ganan entre $1200 y $2000: "<<cont3<<endl;
    cout<<"Cantidad de empleados que ganan mas de $2000: "<<cont4<<endl;
    */
    
    //EJERCICIO 15
    /*
    int edad, cont1=0, cont2=0, cont3=0, cont4=0, cont5=0;
    cout<<"Ingrese la edad, para finalizar ingrese cero: ";
    cin>>edad;
    while(edad!=0)
    {
        switch(edad)
        {
            case 18: cont1++; break;
            case 19: cont2++; break;
            case 20: cont3++; break;
            case 21: cont4++; break;
            case 22: cont5++; break;
            default: cout<<"La edad no se encuentra en el rango permitido"<<endl; break;
        }
        cout<<"Ingrese la edad, para finalizar ingrese cero: ";
        cin>>edad;
    }
    cout<<"Personas con 18 anios: "<<cont1<<endl;
    cout<<"Personas con 19 anios: "<<cont2<<endl;
    cout<<"Personas con 20 anios: "<<cont3<<endl;
    cout<<"Personas con 21 anios: "<<cont4<<endl;
    cout<<"Personas con 22 anios: "<<cont5<<endl;
    */
    
    //EJERCICIO 16
    /*
    int num, factorial=1;
    cout<<"Ingrese un numero entero positivo, para finalizar ingrese cero ";
    cin>>num;
    while(num!=0)
    {
        for(int i=1; i<=num; i++)
            factorial*=i;
        cout<<"El factorial de "<<num<<": "<<factorial<<endl;
        factorial=1;
        cout<<"Ingrese un numero entero positivo: ";
        cin>>num;
    }
    */
    
    //EJERCICIO 17
    /*
    int lado1, lado2, lado3;
    cout << "Ingrese el valor del primer lado, para finalizar ingrese cero: ";
    cin >> lado1;
    cout << "Ingrese el valor del segundo lado, para finalizar ingrese cero: ";
    cin >> lado2;
    cout << "Ingrese el valor del tercer lado, para finalizar ingrese cero: ";
    cin >> lado3;
    while(lado1!=0 && lado2!=0 && lado3!=0)
    {
        if(lado1==lado2==lado3)
            cout << "Es un triangulo equilatero "<<endl;
        else
            if(lado1==lado2 || lado1==lado3 || lado2==lado3)
                cout << "Es un triangulo isosceles "<<endl;
            else
                cout << "Es un triangulo escaleno "<<endl;
        cout << "Ingrese el valor del primer lado, para finalizar ingrese cero: ";
        cin >> lado1;
        cout << "Ingrese el valor del segundo lado, para finalizar ingrese cero: ";
        cin >> lado2;
        cout << "Ingrese el valor del tercer lado, para finalizar ingrese cero: ";
        cin >> lado3;
    }
    */
    
    //EJERCICIO 18
    /*
    int nota, cont=0, suma=0, prom;
    string nombre;
    for(int i=1;i<=25;i++)
    {
        cout<<"Ingrese el nombre del alumno: ";
        cin>>nombre;
        cout<<"Ingrese la nota: ";
        cin>>nota;
        while(nota!=0)
        {
            suma+=nota;
            cont++;
            cout<<"Ingrese la nota: ";
            cin>>nota;
        }
        prom=suma/cont;
        cout<<"El promedio de "<<nombre<<" es: "<<prom<<endl;
        cont=0;
        suma=0;
    }
    */

    //EJERCICIO 19
    /*
    int num, saldo, cont_A=0, cont_D=0, cont_N=0;
    string nombre;
    cout<<"Ingrese el numero de cuenta, para finalizar ingrese un numero negativo: ";
    cin>>num;
    while(num>=0)
    {
        cout<<"Ingrese el nombre del cliente: ";
        cin>>nombre;
        cout<<"Ingrese el saldo actual del cliente: ";
        cin>>saldo;
        if(saldo<0)
        {
            cout<<"Estado de la cuenta numero "<<num<<": "<<"DEUDOR"<<endl;
            cont_D++;
        }
        else
            if(saldo==0)
                cont_N++;
            else
            {
            cout<<"Estado de la cuenta numero "<<num<<": "<<"ACREEDOR"<<endl;
            cont_A++;
            }
        cout<<"Ingrese el numero de cuenta, para finalizar ingrese un numero negativo: ";
        cin>>num;
    }
    if(cont_D!=0 && cont_N!=0 && cont_A!=0)
    {
        cout<<"Cantidad de cuentas con saldo DEUDOR: "<<cont_D<<endl;
        cout<<"Cantidad de cuentas con saldo ACREEDOR: "<<cont_A<<endl;
        cout<<"Cantidad de cuentas con saldo NULO: "<<cont_N<<endl;
    }
    else
        cout<<"No se ingresaron numeros";
    */
    
    //MAXIMOS Y MINIMOS
    
    //EJERCICIO 1
    /*
    int num, menor;
    cout<<"Ingrese un numero: ";
    cin>>menor;
    for(int i=1; i<50; i++)
    {
        cout<<"Ingrese un numero: ";
        cin>>num;
        if(num<menor)
            menor=num;
    }
    cout<<"El menor numero es: "<<menor;
    */

    //EJERCICIO 2
    /*
    int num, mayor, posicion=1;
    cout<<"Ingrese un numero: ";
    cin>>mayor;
    for(int i=2; i<=50; i++)
    {
        cout<<"Ingrese un numero: ";
        cin>>num;
        if(num>mayor)
        {
            mayor=num;
            posicion=i;
        }
    }
    cout<<"La posicion del mayor numero es: "<<posicion;
    */

    //EJERCICIO 3
    /*
    int num, mayor, cont=1;
    cout<<"Ingrese un numero: ";
    cin>>mayor;
    for(int i=2; i<=50; i++)
    {
        cout<<"Ingrese un numero: ";
        cin>>num;
        if(num>mayor)
        {
            mayor=num;
            cont=1;
        }
        else
        {
            if(num == mayor)
                cont++;
        }
    }
    cout<<"El numero mayor se ingreso "<<cont<<" veces";
    */

    //EJERCICIO 4
    /*
    int num, mayor1, mayor2=0, i;
    bool bandera=true;
    for(i=1;i<=50;i++)
    {
        cout<<"Ingrese el numero de orden "<<i<<":";
        cin>>num;
        if(i == 1)
            mayor1=num;
        else 
            if(num>mayor1)
            {
                mayor2=mayor1;
                mayor1=num; 
            }
            if(bandera)
                if (num<mayor1)
                {
                    bandera=false;
                    mayor2=num;
                }     
            else
            {
                if(num<mayor1 && num>mayor2)
                    mayor2=num;
            }
                
    }
    cout<<"El primer numero mayor es: "<<mayor1<<endl;
    cout<<"El segundo numero mayor es: "<<mayor2<<endl;
    */
    
    //EJERCICIO 5
    /*
    int num, min, max, suma=0, cont=0;
    float prom;
    bool priNeg=true, priPos=true;
    cout<<"Ingrese un numero: ";
    cin>>num;
    while(num!=0)
    {
        suma+=num;
        cont++;
        if(num<0)
        {
            if(priNeg)
            {
                max=num;
                priNeg=false;  
            }
            else
            {
                if(num>max)
                    max=num;
            }
            
        }
        else
        {
            if(priPos)
            {
                min=num;
                priPos=false;
            }
            else
                if(num<min)
                    min=num;
        }
        cout<<"Ingrese un numero: ";
        cin>>num;
    }
    prom=(float)suma/cont;
    if(cont!=0)
    {   
        cout<<"El promedio es: "<<prom<<endl;
        if(!priNeg)
            cout<<"El valor maximo negativo es: "<<max<<endl;
        if(!priPos)
            cout<<"El valor minimo positivo es: "<<min<<endl;
    }
    else
        cout<<"No se ingresaron valores";
    */
    
    //EJERCICIO 6
    /*
    int edad1, edad2;
    string nombre1, nombre2, FIN;
    cout<<"Ingrese el primer nombre, para finalizar ingrese FIN: ";
    cin>>nombre1;
    cout<<"Ingrese el segundo nombre, para finalizar ingrese FIN: ";
    cin>>nombre2;
    while(nombre1!="FIN" && nombre2!="FIN")
    {
        cout<<"Ingrese la primer fecha de nacimiento: ";
        cin>>edad1;
        cout<<"Ingrese la segunda fecha de nacimiento: ";
        cin>>edad2;
        if((edad1-edad2)>0)
            cout<<nombre2<<" es mayor"<<endl;
        else if((edad1-edad2)<0)
            cout<<nombre1<<" es mayor"<<endl;
        else
            cout<<"Tienen la misma edad"<<endl;

        cout<<"Ingrese el primer nombre, para finalizar ingrese FIN: ";
        cin>>nombre1;
        cout<<"Ingrese el segundo nombre, para finalizar ingrese FIN:: ";
        cin>>nombre2;
    }
    */

    //EJERCICIO 7
    /*
    int num, mayor1, mayor2=0, i, contTiros=0, puntajeTotal, puntajeMax=0, puntajeSuma=0;
    bool bandera=true;
    char continuar;
    float puntajeProm;

    do
    {
        for(i=1;i<=5;i++)
        {
            cout<<"Ingrese el valor del dado "<<i<<": ";
            cin>>num;

            if(i == 1)
                mayor1=num;
            else 
                if(num>mayor1)
                {
                    mayor2=mayor1;
                    mayor1=num; 
                }
                if(bandera)
                    if (num<mayor1)
                    {
                        bandera=false;
                        mayor2=num;
                    }     
                else
                {
                    if(num<mayor1 && num>mayor2)
                        mayor2=num;
                }
        }
        puntajeTotal=mayor1+mayor2;

        if(i == 1)
            puntajeMax=puntajeTotal;
        else if (puntajeTotal>puntajeMax)
            puntajeMax=puntajeTotal;

        contTiros++;
        puntajeSuma+=puntajeTotal;
        cout<<"Continua? S/N "<<endl;
        cin>>continuar;
    }
    while(continuar=='S');

    puntajeProm=(float)puntajeSuma/contTiros;
    cout<<"Cantidad de tiros: "<<contTiros<<endl;
    cout<<"Puntaje maximo: "<<puntajeMax<<endl;
    cout<<"Puntaje promedio: "<<puntajeProm<<endl;
    */


    //EJERCICIO 8 Mal hecho
    /*
    int cant, edad, cont_P=0, cont_A=0,j=0, familias, cont_Pob=0, mayor, cont_D;
    string nombre, apellido, dom, dom_M;
    char viv, sexo, ind, estudios;
    float porc;

    cout<<"Ingrese la cantidad de familias a encuestar: ";
    cin>>familias;
    for(int i=1; i<=familias; i++)
    {
        cout<<"Ingrese el domicilio: ";
        cin>>dom;
        cout<<"Ingrese el tipo de vivienda: "<<endl<<"Casa: C"<<endl<<"Departamento: D"<<endl;
        cin>>viv;
        cout<<"Ingrese la cantidad de integrantes, para finalizar ingrese cero: ";
        cin>>cant;
        cont_Pob+=cant;
        if(viv=='D')
            cont_D++;
        while(cant!=0)
        {
            j=1;
            cout<<"Ingresar el nombre de orden "<<j<<": ";
            cin>>nombre;
            cout<<"Ingresar el apellido de orden "<<j<<": ";
            cin>>apellido;
            cout<<"Ingresar la edad de orden "<<j<<": ";
            cin>>edad;
            cout<<"Ingresar el sexo de orden "<<j<<": "<<endl<<"M o F"<<endl;
            cin>>sexo;
            cout<<"Ingresar el nivel de estudios alcanzado de orden "<<j<<": "<<endl<<"N: No posee"<<endl<<"P: Primario"<<endl<<"S: Secundario"<<endl;
            cin>>estudios;
            cout<<"Ingresar el indicador de orden "<<j<<": "<<endl<<"I: Incompleto"<<endl<<"C: Completo"<<endl;
            cin>>ind;

            //if(estudios=='P' && ind=='C' || estudios='S')
                //cont_P++;
            if(edad>10 && estudios=='N')
                cont_A++;


            j++;
            cout<<"Ingrese la cantidad de integrantes, para finalizar ingrese cero";
            cin>>cant;
            cont_Pob+=cant;
        }
        if(viv=='D')
            {
                if(cont_D==1)
                {
                    mayor=cant;
                    dom_M=dom;
                }
                else if(cant>mayor)
                    {
                        mayor=cant;
                        dom_M=dom;
                    }
            }
    }
    
    if(j=0)
        cout<<"Fin del proceso";
    else
    {
        cout<<"Cantidad de encuestados con estudios primarios: "<<cont_P<<endl;
        porc=(float)cont_A*100/cont_Pob;
        cout<<"Porcentaje de analfabetismo: "<<porc<<endl;
        cout<<"Domicilio de la familia con la mayor cantidad de integrantes: "<<dom_M<<endl;



    }
    */
    
    //EJERCICIO 8 de MAR
    
    /*
    int edad, numint, sumatotal=0, i, primaria=0, analfabetismo=0, mayornumint=0, sumaedades=0, edadpromedio, secuinc=0, femtercom=0, suma_edad_familia=0, promediofammayor=0, numerodom;
    float porcentajeanalfa, promedio_edad_familia, porcentajefem;
    string domicilio, nombre, domimasint;
    char sexo, tvivienda, estudios, indicador;

    cout << "Lo invitamos a realizar la siguiente encuesta sobre el grupo familiar. Para comenzar, ingrese la cantidad de integrantes del mismo, para finalizar, ingrese 0." << endl;
    cin >> numint;

    while (numint != 0)
    {
      sumatotal += numint; //cantidad total de habitantes
      cout << "Ingrese la direccion de su domicilio" << endl;
      cin >> domicilio >> numerodom;
      cout << "Ingrese el tipo de vivienda donde reside. 'C': casa, 'D': departamento" << endl;
      cin >> tvivienda;

      cout << "A continuacion se realizaran preguntas sobre cada integrante del grupo familiar" << endl;

       for (i=1; i<=numint;i++)
       {
           cout << "Indique el nombre y apellido de la persona." << endl;
           cin >> nombre;
           cout << "Edad" << endl;
           cin >> edad;
            sumaedades +=edad; // suma total de las edades
           cout << "Sexo.'F': femenino, 'M': masculino" << endl;
           cin >> sexo;
           cout << "Nivel de estudios alcanzados.'N': no posee, 'P': primario, 'S': secundario, 'T': terciario " << endl;
           cin >> estudios;
           if (estudios != 'N')
           {
               cout << "Indique 'C': completo o 'I': incompleto referente al nivel de estudio" << endl;
               cin >> indicador;
           }

           if (estudios == 'P' && indicador == 'C') //primaria completa
                primaria++;

           if (edad > 10 && estudios == 'N') //cantidad de analfabetos
                analfabetismo++;

           if (estudios == 'S' && indicador == 'I') // cant secundario incompleto
                secuinc++;

           if (sexo == 'F' && estudios == 'T' && indicador == 'C') //cant femenino terciario completo 
                femtercom++;

           suma_edad_familia += edad;

       }
        if ( tvivienda == 'D' && numint > mayornumint) //domicilio con la mayor cantidad de integrantes en un depto
        domimasint = domicilio;

       promedio_edad_familia = (float)suma_edad_familia / numint;

       if (promedio_edad_familia > promediofammayor) //mayor edad promedio de las familias
             promediofammayor = promedio_edad_familia;

     cout << "Lo invitamos a realizar la siguiente encuesta sobre el grupo familiar. Para comenzar, ingrese la cantidad de integrantes del mismo, para finalizar, ingrese 0." << endl;
     cin >> numint;

        suma_edad_familia = 0; //para reestablecer el contador para sacar el mayor porcentaje 
    }
    
    porcentajeanalfa = (float)analfabetismo * 100 / sumatotal;
    edadpromedio = (float)sumaedades / sumatotal;
    porcentajefem= (float)femtercom *100 / sumatotal;

    cout << "Cantidad de encuestados que completaron sus estudios primarios: " << primaria << endl;
    cout << "Porcentaje de analfabetismo en la ciudad: " << porcentajeanalfa << endl;
    cout << "Domicilio de la familia con mayor cantidad de integrantes en un depto.: " << domimasint <<endl;
    cout << "Edad promedio: " << edadpromedio << endl;
    cout << "Mayor edad promedio de las familias: " << promediofammayor << endl;
    cout << "Cantidad de encuestados con estudios secundarios incompletos: " << secuinc << endl;
    cout << "Porcentaje de encuestados de sexo femenino con estudios terciarios incompletos: " << porcentajefem <<  endl;
    */

    //EJERCICIO 8 (mi version)
    /*
    int cant, edad, cont_P=0, cont_A=0,j=0, familias, cont_Pob=0, mayor, cont_D=0, sumaEdad=0, cont_SI=0, cont_T=0, cont_F=0, sumaEdad2=0;
    string nombre, apellido, dom, dom_M;
    char viv, sexo, ind, estudios;
    float porc;

    cout<<"Ingrese la cantidad de familias a encuestar: ";
    cin>>familias;
    for(int i=1; i<=familias; i++)
    {
        cout<<"Ingrese el domicilio de orden " <<i<<" :";
        cin>>dom;
        cout<<"Ingrese el tipo de viviendade orden "<<i<<" :"<<endl<<"Casa: C"<<endl<<"Departamento: D"<<endl;
        cin>>viv;
        cout<<"Ingrese la cantidad de integrantes de orden " <<i<<", para finalizar ingrese cero: ";
        cin>>cant;
        
        cont_Pob+=cant;
        if(viv=='D')
            cont_D++;
        for(j=1; j<=cant; j++)
        {
            cout<<"Ingresar el nombre de orden "<<j<<": ";
            cin>>nombre;
            cout<<"Ingresar el apellido de orden "<<j<<": ";
            cin>>apellido;
            cout<<"Ingresar la edad de orden "<<j<<": ";
            cin>>edad;
            sumaEdad+=edad;
            sumaEdad2+=edad;
            cout<<"Ingresar el sexo de orden "<<j<<": "<<endl<<"M o F"<<endl;
            cin>>sexo;
            cout<<"Ingresar el nivel de estudios alcanzado de orden "<<j<<": "<<endl<<"N: No posee"<<endl<<"P: Primario"<<endl<<"S: Secundario"<<endl<<"T: Terciario"<<endl;
            cin>>estudios;
            if(estudios=='P' || estudios=='S' || estudios=='T')
            {
                cout<<"Ingresar el indicador de orden "<<j<<": "<<endl<<"I: Incompleto"<<endl<<"C: Completo"<<endl;
                cin>>ind;
            }

            if(estudios=='P' && ind=='C')
                cont_P++;
            if(estudios=='S' || estudios=='T')
                cont_P++;
            if(edad>10 && estudios=='N')
                cont_A++;
            if(estudios=='S' && ind=='I')
                cont_SI++;
            if(estudios=='P')
                cont_SI++;
            if(sexo=='F' && estudios=='T' && ind=='C')
                cont_T++;
            if(sexo=='F')
                cont_F++;
        }
        if(viv=='D')
            {
                if(cont_D==1)
                {
                    mayor=cant;
                    dom_M=dom;
                }
                else if(cant>mayor)
                    {
                        mayor=cant;
                        dom_M=dom;
                    }
            }
        cout<<"Edad promedio de la familia de orden "<<i<<" :"<<sumaEdad2/cant<<endl;
        sumaEdad2=0;
    }
    
    if(j=0)
        cout<<"Fin del proceso";
    else
    {
        cout<<"Cantidad de encuestados con estudios primarios: "<<cont_P<<endl;
        porc=(float)cont_A*100/cont_Pob;
        cout<<"Porcentaje de analfabetismo: "<<porc<<endl;
        cout<<"Domicilio de la familia con la mayor cantidad de integrantes que viven en un departamento: "<<dom_M<<endl;
        cout<<"Edad promedio de los habitantes: "<<sumaEdad/cont_Pob<<endl;
        cout<<"Cantidad de encuestados con secundario incompleto: "<<cont_SI<<endl;
        cout<<"Porcentaje de mujeres con terciario completo: "<<cont_T*100/cont_F;
    }
    */

    //EJERCICIO 9
    /*
    int ID, peso, puerto, sumaPeso=0, mayorPeso, cant1=0, cant2=0, cant3=0, vueltas=0, IDmayor;

    cout<<"Ingrese la identificacion del contenedor, para finalizar ingrese cero: ";
    cin>>ID;
    while(ID!=0)
    {
        cout<<"Ingrese el peso del contenedor en Kg: ";
        cin>>peso;
        cout<<"Ingrese el puerto de arribo: ";
        cin>>puerto;

        sumaPeso+=peso;
        vueltas++;

        if(vueltas==1)
        {
            IDmayor=ID;
            mayorPeso=peso;
        }
        else if(peso>mayorPeso)
        {
            IDmayor=ID;
            mayorPeso=peso;
        }
        
        switch(puerto)
        {
            case 1: cant1++; break;
            case 2: cant2++; break;
            case 3: cant3++; break;
            default: cout<<"El puerto solo se identifica con numeros del 1 al 3"<<endl; break;
        }

        cout<<"Ingrese la identificacion del contenedor, para finalizar ingrese cero: ";
        cin>>ID;
    }

    cout<<"Peso total a trasladar: "<<sumaPeso<<endl;
    cout<<"ID del contenedor de mayor peso: "<<IDmayor<<endl;
    cout<<"Cantidad de contenedores a trasladar al puerto 1: "<<cant1<<endl;
    cout<<"Cantidad de contenedores a trasladar al puerto 2: "<<cant2<<endl;
    cout<<"Cantidad de contenedores a trasladar al puerto 3: "<<cant3<<endl;
    */

    //EJERCICIO 10
    /*
    int cantV, numV, cantAsientos, numPas, precio, cont_Pas=0, precioTotal=0, precioMayor, numVMayor;
    string destino;

    cout<<"Ingrese la cantidad de vuelos realizados: ";
    cin>>cantV;
    for(int i=1; i<=cantV; i++)
    {
        precioTotal=0;
        cont_Pas=0;
        cout<<"Ingrese el numero de vuelo: ";
        cin>>numV;
        cout<<"Ingrese el destino: ";
        cin>>destino;
        cout<<"Ingrese la cantidad de asientos: ";
        cin>>cantAsientos;

        cout<<"Ingrese el numero de pasaporte de orden 1, para finalizar ingrese cero: ";
        cin>>numPas;
        while(numPas!=0)
        {
            cont_Pas++;
            cout<<"Ingrese el importe del pasaje en dolares: ";
            cin>>precio;
            precioTotal+=precio;

            cout<<"Nro de Pasaporte: "<<numPas<<endl;
            cout<<"Importe en u$s: "<<precio<<endl<<endl; 

            cout<<"Ingrese el numero de pasaporte de orden "<<cont_Pas+1<<": ";
            cin>>numPas;

        }

        if(i == 1 || precioTotal>precioMayor)
        {
            precioMayor=precioTotal;
            numVMayor=numV;
        }    
        
        cout<<"Numero de vuelo: "<<numV<<endl;
        cout<<"Destino: "<<destino<<endl;
        cout<<"Total recaudado del vuelo: "<<precioTotal<<endl;
        cout<<"Cantidad de asientos libres: "<<cantAsientos-cont_Pas<<endl;

    }
    cout<<"Nro de vuelo que mas recaudo: "<<numVMayor;
    */
   
    return 0;
} 