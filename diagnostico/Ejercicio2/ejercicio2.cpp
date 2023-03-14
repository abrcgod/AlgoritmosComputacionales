/* Solicita al usuario 20 numeors enteros y almacena en un arreglo los pares y
 * en otro los nones*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  if (argc < 21) {
    cout << "Error:Falta de argumentos, Ingresa 20 numeros enteros" << endl;
    return EXIT_FAILURE;
  }

  vector<int> pares;
  vector<int> impares;

  for (int i = 1; i < 20; i++) {
    int numero;
    try {
      numero = stoi(argv[i]);
    } catch (invalid_argument) {
      cout << "Error: Ingresa solo numeros enteros" << endl;
      return EXIT_FAILURE;
    }
    if (numero % 2 == 0) {
      pares.push_back(numero);
    } else {
      impares.push_back(numero);
    }
  }

  cout << "Numeros pares ingresados: " << endl;
  cout << "[ ";
  for (auto i = pares.begin(); i != pares.end(); i++) {
    cout << *i << " ";
  }
  cout << "]" << endl;

  cout << "Numeros impares ingresados: " << endl;
  cout << "[ ";
  for (auto i = impares.begin(); i != impares.end(); i++) {
    cout << *i << " ";
  }
  cout << "]" << endl;

  return EXIT_SUCCESS;
}
