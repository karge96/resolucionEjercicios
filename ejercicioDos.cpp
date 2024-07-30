#include <iostream>
#include <cstdlib>
#include <ctime>

//imprime el array 4x5 y la suma de los numeros 
void arrayDeSuma(int arregloGenerado[4][5]);

int main() {
    // Genera los numeros aleatorios
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Inicializa el array
    int arregloGenerado[4][5];

    // Rellena el array con los datos 
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            arregloGenerado[i][j] = std::rand() % 10;
        }
    }

    //imprime el array y la suma de los numeros 
    arrayDeSuma(arregloGenerado);

    return 0;
}
//imprime el array y la suma de los numeros 
void arrayDeSuma(int arregloGenerado[4][5]) {
    int sumaFila[4] = {0};
    int sumaColumna[5] = {0};
    int sumaTotal = 0;

    // Imprime y calcula las sumas parciales
    std::cout << "Matriz:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << arregloGenerado[i][j] << "   ";
            sumaFila[i] += arregloGenerado[i][j];
            sumaColumna[j] += arregloGenerado[i][j];
            sumaTotal += arregloGenerado[i][j];
        }
        std::cout << "| " << sumaFila[i] << "\n";
    }

    // Imprime la suma de las columnas
    std::cout << "--------------------\n";
    for (int j = 0; j < 5; ++j) {
        std::cout << sumaColumna[j] << "  ";
    }
    std::cout << "| " << sumaTotal << "\n";
}
