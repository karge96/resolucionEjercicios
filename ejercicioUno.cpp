#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Funcion para generar un numero aleatorio entre 0 y 99
int numeroAleatorio() {
    return rand() % 100;
}

// Funcion que verifica si un numero es primo
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

// Procedimiento para mostrar un arreglo
void mostrarArreglo(int arreglo[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Filtra los numeros primos y crea del nuevo arreglo
int filtrarPrimos(int origen[], int destino[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (esPrimo(origen[i])) {
            destino[count] = origen[i];
            count++;
        }
    }
    return count;
}

int main() {
    srand(time(0));

    int numerosAleatorios[20];
    int numerosPrimos[20]; 

    // Genera los numeros aleatorios, solo 20 numeros
    for (int i = 0; i < 20; i++) {
        numerosAleatorios[i] = numeroAleatorio();
    }

    // Filtra los numeros primos
    int sizePrimos = filtrarPrimos(numerosAleatorios, numerosPrimos, 20);

    // Mostrar los arreglos
    cout << "Numeros aleatorios: ";
    mostrarArreglo(numerosAleatorios, 20);

    cout << "Numeros primos: ";
    mostrarArreglo(numerosPrimos, sizePrimos);

    return 0;
}
