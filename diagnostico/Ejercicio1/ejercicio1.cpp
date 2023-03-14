#include <cstdlib>
#include <cstring>
#include <iostream>
#include <strings.h>

using namespace std;

// Operaciones
auto conversion_temperatura = "--Ctemp";
auto calculo_perimetro = "--Perimetro";
auto calcul_areas = "--Area";

// Opciones
auto farenheit = "-F";
auto kelvin = "-K";
auto circulo = "-C";
auto rectangulo = "-R";
auto triangulo = "-T";

// Operaciones para convertir temperatura
typedef double (*conversor_temperatura)(double);

double celcius_a_farenheit(double celcius) {
  return ((9.0 / 5.0) * celcius) + 32.0;
}

double celcius_a_kelvin(double celcius) { return celcius + 273.15; }

conversor_temperatura to_farenheit = celcius_a_farenheit;
conversor_temperatura to_kelvin = celcius_a_kelvin;

void convertir_temperatura(char *argumento, string unidad_salida,
                           conversor_temperatura conversor) {
  double celcius = strtod(argumento, nullptr);
  if (celcius == 0.0 && strcmp(argumento, "0.0") != 0) {
    cout << "Error: ingresa un factor de temperatura valido";
    return;
  } else {
    double valor_convertido = conversor(celcius);
    cout << celcius << " Celcius son " << valor_convertido << " "
         << unidad_salida << endl;
  }
}

// Operaciones para calcular perimetros
const double PI = 3.1416;
typedef double (*calculador_perimetro)(double, double);

double perimetro_circulo(double radio, double _pi = PI) {
  return PI * (2 * radio);
}

double perimetro_rectangulo(double base, double altura) {
  return (2 * base) + (2 * altura);
}

const calculador_perimetro p_circulo = perimetro_circulo;
const calculador_perimetro p_rectangulo = perimetro_rectangulo;

void calcular_perimetro(string figura, char *factor1, char *factor2,
                        calculador_perimetro formula) {
  double factor1_d = strtod(factor1, nullptr);
  if (factor1_d == 0.0 && strcmp(factor1, "0.0") != 0) {
    cout << "Error: ingresa valores validos" << endl;
    return;
  }
  double factor2_d;
  if (factor2 != nullptr) {
    factor2_d = strtod(factor2, nullptr);
    if (factor2_d == 0.0 && strcmp(factor2, "0.0") != 0) {
      cout << "Error: ingresa valores validos" << endl;
      return;
    }
  }
  double perimetro = formula(factor1_d, factor2_d);
  cout << "El perimetro del " << figura << " es " << perimetro << " unidades"
       << endl;
}

// Operaciones para calcular areas
typedef double (*calculador_areas)(double, double);

double area_circulo(double radio, double pi) { return PI * (radio * radio); }

double area_triangulo(double base, double altura) {
  return (base * altura) / 2;
}

const calculador_areas a_circulo = area_circulo;
const calculador_areas a_triangulo = area_triangulo;

void calcular_area(string figura, char *factor1, char *factor2,
                   calculador_areas formula) {
  double factor1_d = strtod(factor1, nullptr);
  if (factor1_d == 0.0 && strcmp(factor1, "0.0") != 0) {
    cout << "Error: ingresa valores validos" << endl;
    return;
  }
  double factor2_d;
  if (factor2 != nullptr) {
    factor2_d = strtod(factor2, nullptr);
    if (factor2_d == 0.0 && strcmp(factor2, "0.0") != 0) {
      cout << "Error: ingresa valores validos" << endl;
      return;
    }
  }
  double area = formula(factor1_d, factor2_d);
  cout << "El area del " << figura << " es " << area << " unidades cuadradas"
       << endl;
}

/*Uso: ejercicio1 --[Operaciopn] -[Opcion] [Factores]*/
int main(int argc, char **argv) {
  if (strcasecmp(argv[1], conversion_temperatura) == 0) {
    if (strcasecmp(argv[2], farenheit) == 0) {
      convertir_temperatura(argv[3], "Farenheit", to_farenheit);
    } else if (strcasecmp(argv[2], kelvin) == 0) {
      convertir_temperatura(argv[3], "Kelvin", to_kelvin);
    } else {
      cout << "Error: Opcion invalida" << endl;
    }
  } else if (strcasecmp(argv[1], calculo_perimetro) == 0) {
    if (strcasecmp(argv[2], circulo) == 0) {
      calcular_perimetro("Circulo", argv[3], nullptr, p_circulo);
    } else if (strcasecmp(argv[2], rectangulo) == 0) {
      calcular_perimetro("Rectangulo", argv[3], argv[4], p_rectangulo);
    } else {
      cout << "Error: Opcion invalida" << endl;
    }
  } else if (strcasecmp(argv[1], calcul_areas) == 0) {
    if (strcasecmp(argv[2], circulo) == 0) {
      calcular_area("Circulo", argv[3], nullptr, a_circulo);
    } else if (strcasecmp(argv[2], triangulo) == 0) {
      calcular_area("Triangulo", argv[3], argv[4], a_triangulo);
    } else {
      cout << "Error: Opcion invalida" << endl;
    }
  } else {
    cout << "Error: Operacion no valida" << endl;
  }
}
