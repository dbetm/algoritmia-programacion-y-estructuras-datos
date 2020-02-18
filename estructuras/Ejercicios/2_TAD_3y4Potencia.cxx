#include <iostream>
#include <cstdio>
#include <cmath>
/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 08/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: 
 * Grupo: 2CM1.
*/
using namespace std;

class Potencias {
	private:
		int num;
	public:
		Potencias();
		void Solicitar();
		int Leer();
		int Elevar3(int);
		int Elevar4(int);
		void Mostrar(int);
		~Potencias();
};
//IMPLEMENTACIÓN
Potencias::Potencias() { //Constructor
	num = 0;
}
void Potencias::Solicitar() {
	cout << "Número: ";
}
int Potencias::Leer() {
	cin >> num;
	return num;
}
int Potencias::Elevar3(int num) {
	return pow(num, 3);
}
int Potencias::Elevar4(int num) {
	return pow(num, 4);
}
void Potencias::Mostrar(int res) {
	cout << "El resultado es: " << res << endl;
}

Potencias::~Potencias() { //Destructor
	num = 0;
}

int main(int argc, char **argv) {
	Potencias Nuevo;
	int res, a;
	
	cout << "Número elevado a la 3" << endl;
	Nuevo.Solicitar();
	a = Nuevo.Leer();
	res = Nuevo.Elevar3(a);
	Nuevo.Mostrar(res);
	cout << "\nNúmero elevado a la 4" << endl;
	Nuevo.Solicitar();
	a = Nuevo.Leer();
	res = Nuevo.Elevar4(a);
	Nuevo.Mostrar(res);
	
	return 0;
}

