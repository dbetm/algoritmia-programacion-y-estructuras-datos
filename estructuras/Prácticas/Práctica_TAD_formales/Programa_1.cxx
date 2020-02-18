#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

class Nums {
	private:
		float num;
	public:
		Nums();
		float solicitar(int);
		float suma(float, float, float);
		float producto(float, float, float);
		float menor(float, float, float);
		float prom(float);
		void mostrar(float);
		~Nums();
}Nums;

Nums::Nums() {
	num = 0;
}

float Nums::solicitar(int pos) {
	cout << pos << ". Escribe el numero: ";
	cin >> num;
	return num;
}

float Nums::suma(float a, float b, float c) {
	return (a + b + c);
}

float Nums::producto(float a, float b, float c) {
	return (a * b * c);
}

float Nums::menor(float a, float b, float c) {
	if(a < b && a < c)  return a;
	else if (b < a && b < c)  return b;
	else return c;
}

float Nums::prom(float suma) {
	return (suma / 3);
}

void Nums::mostrar(float res) {
	cout << res << endl;
}

Nums::~Nums() {
	num = 0;
}

int main(int argc, char **argv) {
	float a, b, c;
	float suma, prod, menor, prom;
	
	a = Nums.solicitar(1);
	b = Nums.solicitar(2);
	c = Nums.solicitar(3);
	
	suma = Nums.suma(a, b, c);
	cout << "La suma es: ";
	Nums.mostrar(suma);
	
	prod = Nums.producto(a, b, c);
	cout << "El producto es: ";
	Nums.mostrar(prod);
	
	menor = Nums.menor(a, b, c);
	cout << "El menor es: ";
	Nums.mostrar(menor);
	
	prom = Nums.prom(suma);
	cout << "El promedio es: ";
	Nums.mostrar(prom);
	
	printf("\n\n");
	
	return 0;
}
