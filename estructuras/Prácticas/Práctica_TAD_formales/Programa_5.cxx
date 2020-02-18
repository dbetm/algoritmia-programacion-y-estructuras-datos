#include <iostream>
#include <cstdlib>
#include <cstdio>
/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 15/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Práctica TAD (formales)
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/
using namespace std;
#define PI 3.1416;

class Circles {
	private:
		float radius;
		float diameter;
		float circumference;
	public:
		Circles();
		float capture(int);
		float getDiameter(float);
		float getCircun(float);
		void display(int, float, float, float);
		~Circles();
} Circles;

Circles::Circles() {
	radius = 0;
	diameter = 0;
	circumference = 0;
}

float Circles::capture(int i) {
	cout << "Radius #" << i << ": ";
	cin >> radius;
	return radius;
}

float Circles::getDiameter(float rad) {
	diameter = rad * 2;
	return diameter;
}

float Circles::getCircun(float dia) {
	circumference = dia * PI;
	return circumference;
}

void Circles::display(int i, float rad, float dia, float cir) {
	cout << endl << "Circle #" << i << ": ";
	cout << "Radius: " << rad << endl;
	cout << "Circumference: " << cir << endl;
	cout << "Diameter: " << dia << endl;
}

Circles::~Circles() {
	radius = 0;
	diameter = 0;
	circumference = 0;
}

int main(int argc, char **argv) {
	float A[5][3];
	
	cout << "Next, you will asked for five radiuses" << endl;
	for(int i = 0; i < 5; i++) {
		A[i][0] = Circles.capture(i+1);
		A[i][1] = Circles.getDiameter(A[i][0]);
		A[i][2] = Circles.getCircun(A[i][1]);
	}
	
	system("cls");
	printf("\tOUTPUT\n");
	for(int i = 0; i < 5; i++) {
		Circles.display(i+1, A[i][0], A[i][1], A[i][2]);
	}
	
	return 0;
}
