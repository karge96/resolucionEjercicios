#include <iostream>
#include <iomanip>
using namespace std;

// Lee los nombres de los estudiantes que se ingresan 
void nombre(string nombres[]) {
    for (int i = 0; i < 10; i++) {
        cout << "Ingresa el nombre del estudiante " << i + 1 << ": ";
        cin >> ws;
        getline(cin, nombres[i]);
    }
}

// Lee las notas de los estudiantes ingresados 
void leerNotas(float notas[][3]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Ingresa la nota del " << j + 1 << "er corte del estudiante " << i + 1 << ": ";
            while (!(cin >> notas[i][j]) || notas[i][j] < 0 || notas[i][j] > 20) {
                cout << "Entrada invalida. Ingresa una nota entre 0-20: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }
}

// Calcula las notas finales de los estudiantes
void notaFinal(const float notas[][3], float notasFinales[]) {
    for (int i = 0; i < 10; i++) {
        notasFinales[i] = 0;
        for (int j = 0; j < 3; j++) {
            notasFinales[i] += notas[i][j];
        }
        notasFinales[i] /= 3;
    }
}

// Ordena los datos en forma de tabla
void resultados(const string nombres[], const float notas[][3], const float notasFinales[]) {
    cout << left << setw(15) << "Estudiante" 
        << setw(15) << "Nota 1er Corte" 
        << setw(15) << "Nota 2do Corte" 
        << setw(15) << "Nota 3er Corte" 
        << setw(15) << "Nota Final" << endl;

    for (int i = 0; i < 10; i++) {
        cout << left << setw(15) << nombres[i] 
            << setw(15) << notas[i][0] 
            << setw(15) << notas[i][1] 
            << setw(15) << notas[i][2] 
            << setw(15) << notasFinales[i] << endl;
    }
}

int main() {
    string nombres[10];
    float notas[10][3];
    float notasFinales[10];

    nombre(nombres);
    leerNotas(notas);
    notaFinal(notas, notasFinales);
    resultados(nombres, notas, notasFinales);

    return 0;
}