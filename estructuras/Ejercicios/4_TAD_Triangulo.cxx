#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>

/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: ##/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: TAD área y perímetro de un triángulo equilatero
 * Grupo: 2CM1.
*/

using namespace std;

class Tri {
	private:
		float base, h, l;
	public: 
		Tri();
		float solicitar(int);
		float area(float, float);
		float perimetro(float);
		void mostrar(float, float);
		~Tri();
}Tri;

Tri::Tri() {
	base = 0;
	h = 0;
	l = 0;
}

float Tri::solicitar(int opc) {
	if(opc == 1) {
		cout << "Dame la base: ";
		cin >> base;
		return base;
	}
	else {
		cout << "Dame la altura: ";
		cin >> h;
		return h;
	}
}

float Tri::area(float b, float h) {
	return (b * h)/2;
}

float Tri::perimetro(float base) {
	return base*3;
}

void Tri::mostrar(float a, float p) {
	cout << "El área es: " << a << endl;
	cout << "El perímetro es: " << p << endl;
}

Tri::~Tri() {
	base = 0;
	h = 0;
	l = 0;
}

int main() {
	float h, b, area, per;
	
	b = Tri.solicitar(1);
	h = Tri.solicitar(2);
	area = Tri.area(b, h);
	per = Tri.perimetro(b);
	Tri.mostrar(area, per);
	
	return 0;
}
