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