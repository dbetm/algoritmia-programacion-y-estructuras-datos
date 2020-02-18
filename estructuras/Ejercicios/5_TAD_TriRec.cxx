#include <iostream>
#include <cstdio>
#include <cmath>

/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: ##/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: TAD tríangulo rectángulo, hipotenusa, área y perímetro.
 * Grupo: 2CM1.
*/

using namespace std;

class TriRec {
	private:
		float c1, c2;
	public:
		TriRec();
		float solicitar(int);
		float hipotenusa(float, float);
		float area(float, float);
		float perimetro(float, float, float);
		void mostrar(float);
		~TriRec();
}Tri;

TriRec::TriRec() {
	c1 = 0, c2 = 0;
}
float TriRec::solicitar(int opc) {
	if(opc == 1) {
		cout << "Dame cateto 1: ";
		cin >> c1;
		return c1;
	}
	else {
		cout << "Dame cateto 2: ";
		cin >> c2;
		return c2;
	}
}

float TriRec::hipotenusa(float c1, float c2) {
	float h;
	h = sqrt((c1*c1) + (c2 * c2));
	return h;
}
float TriRec::area(float c1, float c2) {
	return ((c1 * c2) / 2);
}
float TriRec::perimetro(float h, float c1, float c2) {
	return (h + c1 + c2);
}
void TriRec::mostrar(float res) {
	cout << res;
}
TriRec::~TriRec() {
	c1 = 0, c2 = 0;
}

int main(int argc, char **argv) {
	float hip, c1, c2, area, peri;
	
	c1 = Tri.solicitar(1);
	c2 = Tri.solicitar(2);
	hip = Tri.hipotenusa(c1, c2);
	area = Tri.area(c1, c2);
	peri = Tri.perimetro(hip, c1, c2);
	cout << "\nLa hipotenusa es: ";
	Tri.mostrar(hip);
	cout << "\nEl área es: ";
	Tri.mostrar(area);
	cout << "\nEl perímetro es: ";
	Tri.mostrar(peri);
	
	return 0;
}
