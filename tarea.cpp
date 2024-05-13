#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string nombreArchivoEntrada = "entrada.txt";
    string nombreArchivoSalida = "salida.txt";
    
    // Abrir el archivo de entrada
    ifstream archivoEntrada(nombreArchivoEntrada);
    if (!archivoEntrada.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada: " << nombreArchivoEntrada << endl;
        return 1;
    }

    // Leer los números del archivo de entrada
    vector<int> numeros;
    int numero;
    while (archivoEntrada >> numero) {
        numeros.push_back(numero);
    }
    archivoEntrada.close();

    // Calcular el promedio
    double promedio = 0.0;
    for (int num : numeros) {
        promedio += num;
    }
    promedio /= numeros.size();

    // Abrir el archivo de salida
    ofstream archivoSalida(nombreArchivoSalida);
    if (!archivoSalida.is_open()) {
        cerr << "No se pudo abrir el archivo de salida: " << nombreArchivoSalida << endl;
        return 1;
    }

    // Escribir el promedio en el archivo de salida
    archivoSalida << "El promedio de los números en el archivo de entrada es: " << promedio << endl;

    // Cerrar el archivo de salida
    archivoSalida.close();

    cout << "Se ha calculado el promedio y guardado en el archivo de salida: " << nombreArchivoSalida << endl;

    return 0;
}

