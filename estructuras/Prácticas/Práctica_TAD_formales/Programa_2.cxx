#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 14/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Práctica TAD (formales)
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/
using namespace std;

class Figuras {
	private:
		float n;
	public:
		Figuras();
		float solicitar();
		float triangulo(float, float);
		float rectangulo(float, float);
		float trapecio(float, float, float);
		void mostrar(float);
		~Figuras();
		
}Figuras;

Figuras::Figuras() {
	n = 0;
}

float Figuras::solicitar() {
	cin >> n;
	return n;
}

float Figuras::triangulo(float b, float h) {
	return ((b*h)/2);
}

float Figuras::rectangulo(float b, float h) {
	return (b * h);
}

float Figuras::trapecio(float a, float b, float h) {
	return (0.5)*((a + b) * h);
}

void Figuras::mostrar(float res) {
	cout << res << endl;
}

Figuras::~Figuras() {
	n = 0;
}

int main(int argc, char **argv) {
	float b, h, a;
	float area;
	
	cout << "AREA DEL TRIANGULO" << endl;
	cout << "Dame la base: ";
	b = Figuras.solicitar();
	cout << "Dame la altura: ";
	h = Figuras.solicitar();
	area = Figuras.triangulo(b, h);
	cout << "---El area es: ";
	Figuras.mostrar(area);
	
	cout << "\nAREA DEL RECTANGULO" << endl;
	cout << "Dame la base: ";
	b = Figuras.solicitar();
	cout << "Dame la altura: ";
	h = Figuras.solicitar();
	area = Figuras.rectangulo(b, h);
	cout << "---El area es: ";
	Figuras.mostrar(area);
	
	cout << "\nAREA DEL TRAPECIO" << endl;
	cout << "Dame la base menor: ";
	a = Figuras.solicitar();
	cout << "Dame la base mayor: ";
	b = Figuras.solicitar();
	cout << "Dame la altura: ";
	h = Figuras.solicitar();
	area = Figuras.trapecio(a, b, h);
	cout << "---El area es: ";
	Figuras.mostrar(area);
	
	return 0;
}
