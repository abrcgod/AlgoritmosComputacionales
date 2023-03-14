/* Busca dentro de un arreglo de numeros naturales diferentes un mnumero
 * solicitado por el usuario. Indica la posicion donde se encuentra ese numero*/

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <strings.h>

using namespace std;

// Opciones
auto rango = "-r";
auto limite = "-l";
auto guess = "-g";

// Valores default;
const int INICIAL_DEFAULT = 0;
const int FINAL_DEFAULT = 100;
const int LIMITE_DEFAULT = 100;

bool repetido(int cantidad, int *arr, int clave) {
  for (int i = 0; i < cantidad; i++) {
    if (arr[i] == clave) {
      return true;
    }
  }
  return false;
}

int *generar_numeros(int offset, int range, int limite) {
  if (range < limite) {
    cout << "Error:  Los numeros generados no deben repetirse, por lo que la "
            "cantidad a generar no puede ser mayor al valor del limite "
            "superior del rango"
         << endl;
    return nullptr;
  }
  int *numeros = (int *)malloc(sizeof(int) * limite);
  srand(time(NULL));
  for (int i = 0; i < limite; i++) {
    do {
      numeros[i] = offset + (rand() % range);
    } while (i != 0 && repetido(i, numeros, numeros[i]));
  }

  return numeros;
}

int main(int argc, char *argv[]) {
  int guess_number;
  int *numeros;
  int cantidad;
  if (argc == 2) {
    // Se toma el unico argumento como numero a buscar, no necesita flag
    numeros = generar_numeros(INICIAL_DEFAULT, FINAL_DEFAULT, LIMITE_DEFAULT);
    cantidad = LIMITE_DEFAULT;
    try {
      guess_number = atoi(argv[1]);
    } catch (...) {
      cout << "Error: Argumentos invalidos" << endl;
      return EXIT_FAILURE;
    }
  } else if (argc > 2) {
    int rango_index = 0;
    int limite_index = 0;
    int guess_index = 0;
    for (int i = 0; i < argc; i++) {
      if (strcasecmp(argv[i], rango) == 0) {
        rango_index = i;
      } else if (strcasecmp(argv[i], limite) == 0) {
        limite_index = i;
      } else if (strcasecmp(argv[i], guess) == 0) {
        guess_index = i;
      }
    }
    // al incluir opciones hay que proporcionar flag de numero a buscar, se
    // verifica que exista y que su argumento sea valido
    if (guess_index != 0) {
      try {
        guess_number = atoi(argv[guess_index + 1]);
      } catch (...) {
        cout << "Error: Argumentos invalidos" << endl;
        return EXIT_FAILURE;
      }
    } else {
      cout << "Error: Argumentos invalidos: No se incluyo flag de numero a "
              "buscar"
           << endl;
      return EXIT_FAILURE;
    }

    // Se procesan las opciones para generar los numeros indicados por el
    // usuario
    int lim_inf;
    int lim_sup;
    int limite;
    if (rango_index != 0 && limite_index != 0) {
      try {
        limite = atoi(argv[limite_index + 1]);
        lim_inf = atoi(argv[rango_index + 1]);
        lim_sup = atoi(argv[rango_index + 2]);
      } catch (...) {
        cout << "Error: Argumentos invalidos" << endl;
        return EXIT_FAILURE;
      }
      numeros = generar_numeros(lim_inf, lim_sup, limite);
      cantidad = limite;
    } else if (rango_index != 0) {
      try {
        lim_inf = atoi(argv[rango_index + 1]);
        lim_sup = atoi(argv[rango_index + 2]);
      } catch (...) {
        cout << "Error: Argumentos invalidos" << endl;
        return EXIT_FAILURE;
      }
      numeros = generar_numeros(lim_inf, lim_sup, LIMITE_DEFAULT);
      cantidad = LIMITE_DEFAULT;
    } else if (limite_index != 0) {
      try {
        limite = atoi(argv[limite_index + 1]);
      } catch (...) {
        cout << "Error: Argumentos invalidos" << endl;
        return EXIT_FAILURE;
      }
      numeros = generar_numeros(INICIAL_DEFAULT, FINAL_DEFAULT, limite);
      cantidad = limite;
    }
  }

  if (numeros != nullptr) {
    for (int i = 0; i < cantidad; i++) {
      cout << numeros[i] << endl;
      if (numeros[i] == guess_number) {
        cout << "Numero: " << guess_number << " encontrado en posicion " << i
             << endl;
        return EXIT_SUCCESS;
      }
    }
    cout << "Numero: " << guess_number << " No encontrado" << endl;
  } else {
    return EXIT_FAILURE;
  }
  return 0;
}
