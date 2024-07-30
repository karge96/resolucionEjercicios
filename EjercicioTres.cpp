#include <iostream>
using namespace std;

// Lee los numeros enteros y los almacena en un arreglo
void numero(int numeros[]) {
    for (int i = 0; i < 10; i++) {
        cout << "Ingresa el numero " << i + 1 << ": ";
        while (!(cin >> numeros[i])) {
            cout << "Entrada invalida. Ingresa un numero entero: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Calcula la media de los valores positivos
float mediaPositivos(const int numeros[]) {
    int suma = 0;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (numeros[i] > 0) {
            suma += numeros[i];
            count++;
        }
    }
    // Evitar que se genere la dicision por cero 
    if (count == 0) return 0;  
    return static_cast<float>(suma) / count;
}

// Calcula la media de los valores negativos
float mediaNegativos(const int numeros[]) {
    int suma = 0;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (numeros[i] < 0) {
            suma += numeros[i];
            count++;
        }
    }
    // Evitar que se genere la dicision por cero 
    if (count == 0) return 0;  
    return static_cast<float>(suma) / count;
}

// Procedimiento para mostrar la media de los valores positivos y negativos
void mostrarMedias(float positivos, float negativos) {
    cout << "La media de los valores positivos es: " << positivos << endl;
    cout << "La media de los valores negativos es: " << negativos << endl;
}

int main() {
    int numeros[10];

    numero(numeros);
    float positivos = mediaPositivos(numeros);
    float negativos = mediaNegativos(numeros);
    mostrarMedias(positivos, negativos);

    return 0;
}
