#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
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

class Trans {
	private:
		float monto;
	public:
		Trans();
		float solicitar();
		float depositar(float);
		float retirar(float);
		void sfinal(float);
		~Trans();
}Trans;

Trans::Trans() {
	monto = 0;
}

float Trans::solicitar() {
	cout << "Ingresa el monto: $";
	cin >> monto;
	return monto;
}

float Trans::depositar(float saldo) {
	saldo += Trans::solicitar();
	return saldo;
}

float Trans::retirar(float saldo) {
	monto = Trans::solicitar();
	if(saldo < monto) {
		cout << "Saldo insuficiente" << endl;
		return saldo;
	}
	else {
		return saldo-monto;
	}
}

void Trans::sfinal(float saldo) {
	cout << "Su saldo final es: $" << saldo << endl;
}

Trans::~Trans() {
	monto = 0;
}

int main() {
	float saldo = 0;
	int opc;
	char aux;
	
	do {
		system("cls");
		cout << "Elija una opcion:" << endl;
		cout << "1. Retirar" << endl;
		cout << "2. Depositar" << endl;
		cout << "---> ";
		cin >> opc;
		switch(opc) {
			case 1:
				saldo = Trans.retirar(saldo);
				break;
			case 2:
				saldo = Trans.depositar(saldo);
				break;
			default:
				break;
		}
		cout << "Desea hacer otra operacion? (s/n) ";
		cin >> aux;
	} while(aux == 's');
	Trans.sfinal(saldo);
	
	return 0;
}
