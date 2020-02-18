#include <iostream>
#include <cstdlib>
#include <cstdio>
/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 18/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Práctica TAD (formales)
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/
using namespace std;

class Conv {
	private: 
		int opcion;
		float num;
		float res;
	public:
		Conv();
		int menu();
		float leer();
		float conv(int);
		void resultado(float, int);
		~Conv();
};

Conv::Conv() {
	opcion = 0;
	res = 0;
}

int Conv::menu() {
	cout << "\tMenu de conversiones" << endl;
	cout << "1. Pulgadas a cm" << endl;
	cout << "2. Pies a cm" << endl;
	cout << "3. Calorias a joules" << endl;
	cout << "4. Onzas a gramos" << endl;
	cout << "5. Caballos de fuerza a Watts" << endl;
	cout << "--> ";
	cin >> opcion;
	return opcion;
}

float Conv::leer() {
	cin >> num;
	return num;
}

float Conv::conv(int opc) {
	switch(opc) {
		case 1:
			cout << "Ingresa el valor en pulgadas: ";
			res = Conv::leer();
			res = res * 2.54;
			return res;
		case 2:
			cout << "Ingresa el valor en pies: ";
			res = Conv::leer();
			res = res * 30.48;
			return res;
		case 3:
			cout << "Ingresa el valor en calorias: ";
			res = Conv::leer();
			res = res * 4.184;
			return res;
		case 4:
			cout << "Ingresa el valor en Onzas: ";
			res = Conv::leer();
			res = res * 28.3495;
			return res;
		case 5:
			cout << "Ingresa el valor en caballos de fuerza: ";
			res = Conv::leer();
			res = res * 745.7;
			return res;
		default:
			cout << "Valor incorrecto" << endl;
			break;
	}
	return EXIT_SUCCESS;
}

void Conv::resultado(float result, int opc) {
	switch(opc) {
		case 1:
			cout << "Cm: " << res << endl;
			break;
		case 2:
			cout << "Cm: " << res << endl;
			break;
		case 3:
			cout << "Joules: " << res << endl;
			break;
		case 4:
			cout << "Gramos: " << res << endl;
			break;
		case 5:
			cout << "Watts: " << res << endl;
			break;
		default:
			break;
	}
}

Conv::~Conv() {
	opcion = 0;
	res = 0;
}

int main(int argc, char **argv) {
	Conv Nuevo;
	float res;
	int opc;
	char a;
	
	do {
		system("cls");
		opc = Nuevo.menu();
		res = Nuevo.conv(opc);
		Nuevo.resultado(res, opc);
		cout << "Otra vez? (s/n) ";
		cin >> a;
	} while(a == 's');
	
	return 0;
}
