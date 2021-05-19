/*5) Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo
valores):
a) El valor máximo negativo
b) El valor mínimo positivo
d) El promedio de todos los valores
*/

#include <iostream>

using namespace std;

main(){
    int max_neg,min_pos,sum=0,numero=1,cont=0;
    bool flag_neg=true,flag_pos=true;
    float prom=0;


    while(numero>0||numero<0){

        //SOLICITO EL NUMERO AL USUARIO
        cout<<"ingrese un numero"<<endl;
        cin>>numero;

        //SUMAR PARA SACAR EL PROMEDIO AL FINAL
        sum+=numero;
        //cout<<"El sum vale"<<sum<<endl;
        cont ++;
        //cout<<"El cont vale"<<cont<<endl;
        
        //DIVIDO INCIALMENTE EN MAYORES Y MENORES QUE CERO
        if(numero>0){
            //EVALUO EL PRIMER MAYOR QUE 0 PARA ASIGNARLO
            if(flag_pos==true){
                min_pos = numero;
                flag_pos=false;
                cout<<"Cambie el flag_pos"<<endl;
                cout<<"el min_pos vale "<<min_pos<<endl;
            }else{
                //SINO COMPARO SI ES EL MENOR DE LOS POSITIVOS
                if(min_pos>numero){
                    min_pos = numero;
                    cout<<"el min_pos vale "<<min_pos<<endl;
                }
            } 
        }else{
            //EVALUO EL PRIMER MAYOR QUE 0 PARA ASIGNARLO
            if(flag_neg==true){
                max_neg = numero;
                flag_neg = false;
                cout<<"Cambie el flag_neg"<<endl;
                cout<<"el max_neg vale"<<max_neg<<endl;
            }else{
                //SINO COMPARO SI ES EL MENOR DE LOS POSITIVOS
                if(max_neg<numero&&numero<0){
                    max_neg = numero;
                    cout<<"el max_neg vale"<<max_neg<<endl;
                }
            } 
        }
    }
    cout<<max_neg<<endl;

    //Calculo el promedio
    prom = float(sum)/cont;
    cout<<"El promedio es"<<prom<<endl;

    //si existe..muestro el max negativo y el minimo positivo
    if(flag_neg==false){
        cout<<"El maximo negativo"<< max_neg<<endl;   
    }

    if(flag_pos==false){
        cout<<"El minimo positivo"<< min_pos<<endl; 
    }

    return 0;
}