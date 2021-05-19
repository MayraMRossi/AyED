#include <iostream>

using namespace std;

/*
Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número que lo
identifica y el resultado de los disparos efectuados. El ingreso finaliza con un número de
participante negativo. Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de
cada disparo.
Para determinar el cuadrante utilizar la función cuadrante que reciba las dos coordenadas y
retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un tiro en el centro.
Para calcular el puntaje utilizar la función puntaje que reciba 5 parámetros que representan la
cantidad disparos en cada cuadrante y en el centro. La función debe retornar el puntaje obtenido
según la siguiente escala:
✓ Cuadrantes 1 y 2: 50 puntos
✓ Cuadrantes 3 y 4: 40 puntos
✓ Centro: 100 puntos
Determinar:
a. El puntaje obtenido por cada participante, detallando cuantos disparos realizó en cada
cuadrante.
b. Mostrar el número del participante ganador y el puntaje obtenido.
c. Calcular y mostrar la cantidad total de disparos en el centro (de todos los participantes)
Los disparos sobre el eje X, o sea para y=0, considerarlo en los cuadrantes 1 y 2
Los disparos sobre el eje Y, o sea para x=0, considerarlo en los cuadrantes 1 y 4
*/
//hola probando github

int cuadrante(int, int);
int puntaje(int, int, int, int, int);

int main()
{
    int nPart = 1, puntos = 0, cuad = 0, flag = true;
    int nPartGanador = 0, puntosGanador = 0, totCentro = 0;
    float x = 0, y = 0;

    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl;
    cout << "Ingrese el numero de participante (un numero negativo para salir): " << endl;
    cin >> nPart;

    while (nPart > 0)
    {

        int sumCero = 0, sumUno = 0, sumDos = 0, sumTres = 0, sumCuatro = 0, puntos = 0;

        for (int i = 1; i <= 5; i++)
        {
            cout << "Ingrese la coordenada x del tiro " << i << endl;
            cin >> x;
            cout << "Ingrese la coordenada y del tiro " << i << endl;
            cin >> y;
            cuad = cuadrante(x, y);

            if (cuad == 0)
            {
                sumCero++;
                totCentro++;
            }
            if (cuad == 1)
            {
                sumUno++;
            }
            if (cuad == 2)
            {
                sumDos++;
            }
            if (cuad == 3)
            {
                sumTres++;
            }
            if (cuad == 4)
            {
                sumCuatro++;
            }
        }

        puntos += puntaje(sumCero, sumUno, sumDos, sumTres, sumCuatro);

        cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl
             << endl;
        cout << "El puntaje obtenido por el participante " << nPart << " es: " << puntos << endl
             << endl
             << endl;
        cout << "Disparo " << sumUno << " veces en el cuadrante 1, ";
        cout << sumDos << " veces en el cuadrante 2, ";
        cout << sumTres << " veces en el cuadrante 3, ";
        cout << sumCuatro << " veces en el cuadrante 4 y " << endl;
        cout << sumCero << " veces en el centro" << endl
             << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

        if (flag == true)
        {
            nPartGanador = nPart;
            puntosGanador = puntos;
            flag = false;
        }
        else
        {
            if (puntosGanador < puntos)
            {
                puntosGanador = puntos;
                nPartGanador = nPart;
            }
            //se considera ganador al primero que obtuvo los puntos
        }

        cout << "Ingrese el numero de participante (un numero negativo para salir): " << endl;
        cin >> nPart;
    }

    cout << "******************************************************************" << endl
         << endl;
    cout << "Gano el participante " << nPartGanador << " con " << puntosGanador << " puntos" << endl
         << endl;
    cout << "Se anoto en el centro " << totCentro << " veces en total " << endl
         << endl;
    cout << "******************************************************************" << endl
         << endl;

    return 0;
}

int cuadrante(int x, int y)
{
    int cuadrante = 0;
    if (x == 0 && y == 0)
    {
        cuadrante = 0;
    }
    else
    {
        if (x >= 0 && y >= 0)
        {
            cuadrante = 1;
        }
        if (x < 0 && y >= 0)
        {
            cuadrante = 2;
        }
        if (x < 0 && y < 0)
        {
            cuadrante = 3;
        }
        if (x >= 0 && y < 0)
        {
            cuadrante = 4;
        }
    }
    return cuadrante;
}

int puntaje(int c0, int c1, int c2, int c3, int c4)
{
    int puntos = ((c1 + c2) * 50) + ((c2 + c3) * 40) + (c0 * 100);

    return puntos;
}