#include "Funciones.hpp"

int main()
{
    int opcion, numAyuda; // declaracion de variables de tipo entero y de tipo string
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
            cout << "\nPara jugar Jugador vs Jugador ingresa ==> 1, Para jugar Jugador vs Maquina, ingresa ==> 2: ";
            cin >> modJuego;
            bool VSmaquina = (modJuego == 2);

            if (VSmaquina) // Agregando opcion Vs maquina
            {
                cout << "\nIngrese el nombre del participante: ";
                cin >> Usuario_1;
                cout << "El participante " << Usuario_1 << " ha sido inscrito.\n";
                Usuario_2 = "Maquina";
            }
            else // Opcion Jugador vs Jugador
            {
                // Solicitando los nombres de los jugadores
                cout << "\nIngrese el nombre del primer participante: ";
                cin >> Usuario_1;
                cout << "El participante " << Usuario_1 << " ha sido inscrito.\n";
                cout << "\nIngrese el nombre del segundo participante: ";
                cin >> Usuario_2;
                cout << "El participante " << Usuario_2 << " ha sido inscrito.\n"<< "\n";
            }
            // Devuelve partidas jugadas
            RESULT = JUGAR(Usuario_1, Usuario_2, Participantes, VSmaquina);
            string JUEGOdesc = (VSmaquina) ? (Usuario_1 + " vs Maquina") : (Usuario_1 + " vs " + Usuario_2);
            JUEGOS.push_back(JUEGOdesc);
            char SEGUIR;

            do
            { // Opcion seguir jugando
                cout << " Desea seguir jugando presione: ====> Seguir jugando(a) <=== ===> Reiniciar el juego(b): ";
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
            ofstream resultarchivo("\nResultado.txt");  
            if (RESULT.first == "Empate")
            {
                //Guarda empate
                resultarchivo << "La partida termino en empate." << "\n";
            }
            else    //Guarda los ganadores
            {
                resultarchivo << "El ganador es: " << RESULT.first << "\n";
                resultarchivo << "El segundo jugador es: " << RESULT.second << "\n";
            }
            resultarchivo.close();
            break;
        } 
        
        case 4:      // mostrar las indicaciones del juego
        
            do
            {
                cout << "\n \t \t \t \t <=== AYUDA ===>\n";
                cout << "\t \t \t<===Este es un juego de X ^ O===>\n \n";
                cout << "1. Inscriba a dos participantes.\n";
                cout << "2. Seleccione 'Jugar' para comenzar una partida.\n";
                cout << "3. Cada jugador ingresa las coordenadas (Fila y Columna) Fila: De forma horizontal, Columna: De forma vertical para colocar su simbolo.\n";
                cout << "4. El primer jugador en alinear tres simbolos (Sean 'X' o 'O') en fila, columna o diagonal gana.\n";
                cout << "5. Si el tablero se llena sin que nadie gane, es un empate.\n";
                cout << "\n<===Si has entendido y estas listo para jugar ingresa el Numero 1: ===> ";
                cin >> numAyuda;

                //Verifica si la entrada no es valida
                if (cin.fail() || numAyuda != 1)
                {
                    cin.clear(); //Limpia el estado de error, para usar cin de nuevo
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignora el resto de la linea en el flujo de entrada
                    cout << "\n<====ENTRADA NO VALIDA. Por favor ingrese un valor valido====> \n";
                }
                
                
            } while (numAyuda != 1 || cin.fail());

            break;

        case 5:      // imprime los nombres y los carnets de los integrantes del proyecto
            cout << "\n            === Integrantes del Proyecto ===\n";
            cout << "1. Josue Alejandro Bran Bonilla     - Carnet => 00224824\n";
            cout << "2. Leonel Alexander Canas Rodriguez - Carnet => 00145424\n";
            cout << "3. Moises Alessandro Mencos Andrade - Carnet => 00146324\n";
            break; 
        
            
            
        case 6:      // imprime un mensaje indicando que el juego ha terminado
            cout << "Fin del Juego, Saliendo del programa...\n";
            break;

        default:     //Defaut, por si el valor ingresado es invalido
            cout << "\nLa opcion ingresada es invalida, ingresa una opcion valida";
            break;

        }
        
    }while (opcion != 6);

    return 0;
}