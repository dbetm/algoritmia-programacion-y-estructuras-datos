#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Persona {
  protected:
    string nombre;
    int edad;
  public:
    Persona(int);
    void verDatos();
    ~Persona();
};

Persona::Persona(int age) {
  nombre = "Eduardo";
  edad = age;
}

void Persona::verDatos() {
  cout << "Su nombre es: " << nombre << endl;
  cout << "Su edad es: " << edad << endl;
}

Persona::~Persona() {
  nombre = "";
  edad = 0;
}

class Alumno : public Persona {
  private:
    int promedio;
  public:
    Alumno(int, int);
    void mostrarDatos();
};

Alumno::Alumno(int age, int prom) : Persona(age) {
  promedio = prom;
}

void Alumno::mostrarDatos() {
  verDatos();
  cout << "Su promedio es: " << promedio << endl;
  nombre = "Zacatecas";
  cout << "Su nombreX2 es: " << nombre << endl;
}

int main(int argc, char const *argv[]) {
  Persona menor(16), mayor(18);
  Alumno jaime(22, 9);
  menor.verDatos();
  mayor.verDatos();
  jaime.mostrarDatos();

  return 0;
}
