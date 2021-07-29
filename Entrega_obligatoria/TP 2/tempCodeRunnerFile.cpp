
                    cin>>repartidor.dni;
                    cout<<"Nombre: ";
                    cin.ignore();
                    cin.getline(repartidor.nombre, 40);
                    cout<<"Patente: ";
                    cin>>repartidor.patente;
                    
                    repartidor.zona = validarZona(); 
