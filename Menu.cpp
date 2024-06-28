#include <Funciones.hpp>

int main()
{
    int opcion; // declaracion de variables de tipo entero y de tipo string
    string Usuario_1, Usuario_2;
    pair<string, string> RESULT;
    vector<Participant> Participantes;
    vector<string> JUEGOS;

    do // opciones del menu
    {
        cout << "\n                    <====JUEGO X ^ O====>\n";
        cout << "\n       ====OPCIONES DEL JUEGO====\n\n";
        cout << "1. Listas de Puntuaciones de 'jugadores' en archivo.txt\n";
        cout << "2. Jugar\n";
        cout << "3. Mostrar Ganador o Empate y guardar en .txt\n";
        cout << "4. Ayuda\n";
        cout << "5. Integrantes del Proyecto\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1: // creacion del archivo txt
        {
            cout << "\n=== Puntuaciones ===\n";
            ofstream Puntuacionarchivo;
            Puntuacionarchivo.open("Puntuaciones.txt", ios::out);
            if (Puntuacionarchivo.fail()) // verificando posible error de apertura
            {

                cout << "No se pudo abrir el archivo puntuacion. ";
                exit(1);
            }
            for (const auto &p : Participantes) // recorre cada participante del contenedor participantes
            {
                // para cada participante se imprime su nombre y puntuacion
                cout << p.Name << " - Puntuacion: " << p.SCORE << "\n";

                // se guarda en el archivo .txt
                Puntuacionarchivo << p.Name << " - Puntuacion: " << p.SCORE << "\n";
            }
            Puntuacionarchivo.close(); // se cierra el archivo .txt

            // declara un objeto de tipo ofstream
            ofstream Partidas;

            // intenta abrir el archivo "partidas.txt"
            Partidas.open("Partidas.txt", ios::out);

            // comprueba si la apertura del archivo ha fallado
            if (Partidas.fail())
            {
                cout << "No se pudo abrir el archivo puntuacion. ";
                exit(1);
            }
            for (const auto &p : Participantes)
            {
                cout << p.Name << " Vs " << p.Name << "\n"; // imprime el nombre de los jugadores
                Partidas << p.Name << " Vs " << "maquina" << "\n";
            }
            Partidas.close();

            // imprime las partidas guardadas
            cout << "\n====> Partidas guardadas <====\n";
            for (const auto &juego : JUEGOS)
            {
                cout << juego << "\n";
            }
            break;
        }

        case 2:
        {
            int modJuego;
            // Opcion que pregunta modo de juego
            cout << "Elige el modo que deseas jugar '(|1|) Jugador vs Jugador' |/| '(|2|). Jugador vs la maquina': ";
            cin >> modJuego;
            bool VSmaquina = (modJuego == 2);

            if (VSmaquina) // Agregando opcion Vs maquina
            {
                cout << "\nIngrese el nombre del participante: ";
                cin >> Usuario_1;
                cout << "El participante " << Usuario_1 << " A sido inscrito.\n";
                Usuario_2 = "Maquina";
            }
            else // Opcion Jugador vs Jugador
            {
                // Solicitando los nombres de los jugadores
                cout << "\nIngrese el nombre del primer participante: ";
                cin >> Usuario_1;
                cout << "El participante " << Usuario_1 << " A sido inscrito.\n";
                cout << "\nIngrese el nombre del segundo participante: ";
                cin >> Usuario_2;
                cout << "El participante " << Usuario_1 << " A sido inscrito.\n"
                     << "\n";
            }
            // Devuelve partidas jugadas
            RESULT = JUGAR(Usuario_1, Usuario_2, Participantes, VSmaquina);
            string JUEGOdesc = (VSmaquina) ? (Usuario_1 + " vs Maquina") : (Usuario_1 + " vs " + Usuario_2);
            JUEGOS.push_back(JUEGOdesc);
            char SEGUIR;

            char SEGUIR;
            do
            { // Opcion seguir jugando
                cout << " Desea seguir jugando ====> Seguir jugando= (a) <=||=> Reiniciar el juego(b): ";
                cin >> SEGUIR;
                if (SEGUIR == 'n' || SEGUIR == 'N')
                {
                    Usuario_1 = "";
                    Usuario_2 = "";
                    Participantes.clear();
                    JUEGOS.clear();
                    cout << "| El juego se ha reiniciado |.\n";
                }

            } while (SEGUIR != 'A' && SEGUIR != 'B' && SEGUIR != 'a' && SEGUIR != 'b');
        }
        break;

        case 3:
        { 
            if (RESULT.first.empty())  //Si no hay datos imprimir esto:   
            {
                cout << "Aun no hay un ganador o no se ha jugado la partida.\n";
            }
            else if (RESULT.first == "Empate")   //Si hay empate imprimir esto:  
            {
                cout << "\nLa partida termino en empate.\n";
            }
            else    //Imprime los ganadores
            {
                cout << "El ganador es: " << RESULT.first << "\n";
                cout << "El segundo jugador es: " << RESULT.second << "\n";
            }
            //Crea archivo txt(Resultado) mostrando los resultados
            ofstream resultarchivo("\n" <<"Resultado.txt");  
            if (RESULT.first == "Empate")
            {
                //Guarda empate
                resultarchivo << "La partida termino en empate." << "\n";
            }
        break;
        } 

        }
        
    }while (opcion != 6);

    return 0;
}