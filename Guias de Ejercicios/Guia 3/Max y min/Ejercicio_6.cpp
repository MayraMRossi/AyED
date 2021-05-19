/*6) Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un
Nombre = ‘FIN’, informar el nombre de la persona con mayor edad y el de la más joven.*/

#include <iostream>

using namespace std;

main(){
    int a,mes,dia,a_mayor,a_menor,mes_mayor,mes_menor,dia_mayor,dia_menor;
    bool flag = true;
    string nombre = "No informado",nom_mayor="No informado",nom_joven="No informado";
    unsigned fecha=00000000;

    while(nombre!="FIN"||nombre!="fin"||nombre!="Fin"){

        //AREA DE INGRESO DE DATOS
        cout<<"Ingrese un nombre"<<endl;
        cin>>nombre;
        cout<<"Ingrese la fecha de nacimiento (AAAAMMDD)"<<endl;
        cin>>fecha;

        //DIVISION DE LA FECHA
        dia=fecha%100;
        fecha=fecha/100;
        mes=fecha%100;
        a=fecha/100;

        //DETERMINACION DEL PRIMER VALOR
        if(flag==true){
            a_mayor=a;
            a_menor=a;
            mes_mayor=mes;
            mes_menor=mes;
            dia_mayor=dia;
            dia_menor=dia;
            nom_mayor = nombre;
            nom_joven = nombre;
            flag = false;
        }else{
            if(a>a_mayor){
                a_mayor=a;
                mes_mayor=mes;
                dia_mayor=dia;
                nom_mayor = nombre;
            }
            if(a<a_menor){
                a_menor=a;
                mes_menor=mes;
                dia_menor=dia;
                nom_menor=nom;
            }
            if(a=a_mayor){
                if(mes>mes_mayor){
                    mes_mayor=mes;
                    dia_mayor=dia;
                    nom_mayor = nombre;
                }
                if (mes=mes_mayor){
                    if(dia>dia_mayor){
                        dia_mayor=dia;
                        nom_mayor = nombre;
                    
                    }

                }


            }
            if(año=año_menor){
                if(mesmenormes_menor){
                    mes_menor=mes;
                    dia_menor=dia;
                    nom_menor = nombre;
                }
                if (mes=mes_menor){
                    if(dia<dia_menor){
                        dia_menor=dia;
                        nom_menor = nombre;
                    
                    }

                }


            }






         }

    }
    cout << "el mayor es "<<nom_mayor<<endl;
    cout << "el menor es "<<nom_menor<<endl;


    return 0;
}
