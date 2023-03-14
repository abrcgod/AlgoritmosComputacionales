/*Una nutriologa desea llevar el control de  sus pacientes. Calcular el IMC e
 * indicar a estos si tienen bajo peso , peso normal, sobrepeso u obesidad
 */
#include <iostream>
#include <string>

using namespace std;

class Paciente {
public:
  Paciente(string _nombre, int _edad, string _sexo, double _peso,
           double _estatura) {
    nombre = _nombre;
    edad = _edad;
    sexo = _sexo;
    peso = _peso;
    estatura = _estatura;
    imc = calcular_imc();
    rango_peso = calcular_rango();
  }

  string &getNombre() { return nombre; }

  int getEdad() { return edad; }

  string &getSexo() { return sexo; }

  double getPeso() { return peso; }

  double getEstatura() { return estatura; }

  double getImc() { return imc; }

private:
  double calcular_imc() { return (peso) / (estatura * estatura); }

  string calcular_rango() {
    if (imc < 18.5) {
      return "Bajo Peso";
    } else if (imc > 18.5 && imc < 24.9) {
      return "Peso Normal";
    } else if (imc > 25 && imc < 29.0) {
      return "Sobrepeso";
    } else {
      return "Obesidad";
    }
  }

private:
  string nombre;
  int edad;
  string sexo;
  double peso;
  double estatura;
  double imc;
};
