#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int FILAS = 6;
const int COLUMNAS = 7;
const int BARCO1_SIZE = 2;
const int BARCO2_SIZE = 4;

// Función para mostrar el tablero
void mostrarTablero(int tablero[FILAS][COLUMNAS], bool revelado[FILAS][COLUMNAS]) {
    cout << "   ";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << (char)('A' + j) << " ";
    }
    cout << endl;
    for (int i = 0; i < FILAS; i++) {
        cout << i+1 << "  ";
        for (int j = 0; j < COLUMNAS; j++) {
            if (revelado[i][j]) {
                cout << tablero[i][j] << " ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Función para colocar los barcos en el tablero
void colocarBarcos(int tablero[FILAS][COLUMNAS]) {
    srand(time(0)); // Semilla aleatoria basada en el tiempo actual

    // Colocar barco numero 1
    int barco1Fila = rand() % FILAS;
    int barco1Columna = rand() % (COLUMNAS - BARCO1_SIZE + 1);
    for (int i = 0; i < BARCO1_SIZE; i++) {
        tablero[barco1Fila][barco1Columna + i] = 1;
    }

    // Colocar barco numero 2
    int barco2Fila, barco2Columna;
    bool posicionValida;
    do {
        barco2Fila = rand() % (FILAS - BARCO2_SIZE + 1);
        barco2Columna = rand() % COLUMNAS;
        posicionValida = true;
        for (int i = 0; i < BARCO2_SIZE; i++) {
            if (tablero[barco2Fila + i][barco2Columna] == 1) {
                posicionValida = false;
                break;
            }
        }
    } while (!posicionValida);

    for (int i = 0; i < BARCO2_SIZE; i++) {
        tablero[barco2Fila + i][barco2Columna] = 1;
    }
}

// Función para jugar
void jugar(int tablero[FILAS][COLUMNAS]) {
    int contadorTiros = 0;
    int contadorTirosPerdidos = 0;
    bool revelado[FILAS][COLUMNAS] = { false };

    bool salir = false;
    while (!salir) {
        mostrarTablero(tablero, revelado);

        int fila, columna;
        cout << "Ingrese su disparo (fila columna): ";
        cin >> fila >> columna;

        if (fila < 1 || fila > FILAS || columna < 1 || columna > COLUMNAS) {
            cout << "Posicion incorrecta. Pruebe de nuevo." << endl;
            continue;
        }

        fila--;
        columna--;

        if (revelado[fila][columna]) {
            cout << "Disparo ya hecho. Prueba otra posicion." << endl;
            continue;
        }

        contadorTiros++;
        revelado[fila][columna] = true;

        if (tablero[fila][columna] == 1) {
            cout << "¡Barco tocado!" << endl;
        } else {
            cout << "¡Agua!" << endl;
            contadorTirosPerdidos++;
        }

        mostrarTablero(tablero, revelado);

        char opcion;
        cout << "¿Quiere seguir tirando? (s/n): ";
        cin >> opcion;

        if (opcion == 'n' || opcion == 'N') {
            salir = true;
        }
    }

    cout << "Resumen de la partida:" << endl;
    cout << "Cantidad de movimientos: " << contadorTiros << endl;
    cout << "Cantidad de tiros fallados: " << contadorTirosPerdidos << endl;
}

// Función para mostrar los créditos
void mostrarCreditos() {
    cout << "Juego creado por Sebastian Aguilera" << endl;
}

// Función principal
// Función principal
int main() {
    int opcion;
    bool salir = false;
    while (!salir) {
        cout <<"--------------------------------------------------------------------------- "<< endl;
        cout <<"______________  Bienvenido al Menu de Batalla Naval"<< endl;
        cout <<"______________   1) Jugar" << endl;
        cout <<"______________   2) Creditos" << endl;
        cout <<"______________   3) Salir" << endl;
        cout <<"______________   Ingrese una opcion: ";
        cin >> opcion;
        cout <<"------------------------------------------------- "<< endl;

        switch (opcion) {
            case 1: {
                int tablero[FILAS][COLUMNAS] = { 0 };
                colocarBarcos(tablero);
                jugar(tablero);
                break;
            }
            case 2:
                mostrarCreditos();
                break;
            case 3:
                salir = true;
                break;
            default:
                cout << "Opcion incorrecta, elija opcion entre 1-3" << endl;
                break;
        }
    }

    return 0;
}
