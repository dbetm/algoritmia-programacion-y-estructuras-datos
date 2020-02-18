#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>

/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: ##/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: TAD área de un círculo
 * Grupo: 2CM1.
*/
const double PI = 3.1416;
using namespace std;

class Area {
	private:
		double radio;
	public:
		Area();
		double solicitar();
		double calcular(double);
		void mostrar(double);
		~Area();

};
Area::Area() {
	radio = 0;
}
double Area::solicitar() {
	cout << "Dame el radio del círculo: ";
	scanf("%lf", &radio);
	return radio;
}
double Area::calcular(double n) {
	return PI * (n*n);
}
void Area::mostrar(double n) {
	//cout << "El área es: " << n << endl;
	printf("El área es : %.3lf\n", n);
}
Area::~Area() {
	radio = 0;
}

int main(int argc, char **argv) {

	Area Circle;
	double res, radio;

	radio = Circle.solicitar();
	res = Circle.calcular(radio);
	Circle.mostrar(res);

	return 0;
}
