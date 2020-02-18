#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cctype>
/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 06/03/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Ejericio TAD Cola (estática) con enteros
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/
using namespace std;
#define MAX 3

void menu();

class CCola {
	private:
		int Cola[MAX];
		int frente;
		int finl;
	public:
		CCola();
		int LeerDato();
		void Agregar(int);
		void Eliminar();
		void Imprimir();
		bool Vacia();
		bool Llena();
		void eleFrt();
		void eleFn();
		~CCola();
};

CCola::CCola() {
	for (int i = 0; i < MAX ; i++) {
		Cola[i] = 0;
	}
	frente = finl = 0;

}

int CCola::LeerDato() {
	int dato;
	cout << "Dato a ingresar: ";
	cin >> dato;
	return dato;
}

void CCola::Agregar(int dat) {
	if (Llena() == true) cout << "La cola está llena" << endl;
	else {
		Cola[finl] = dat;
		finl++;
		cout << "Se agregó correctamente" << endl;
	}
}

void CCola::Eliminar() {
	if(Vacia() == true) {
		cout << "La cola está vacía" << endl;
	}
	else {
		cout << "Se sacó: " << Cola[frente] << endl;
		Cola[frente] = 0;
		frente++;
	}
}

void CCola::Imprimir() {
	if(Vacia() == true) cout << "La cola está vacía" << endl;
	else {
		for (int i = frente; i < finl ; i++) {
			cout << " " << Cola[i];
		}
		cout << endl;
	}
}

bool CCola::Llena() {
	if(finl == MAX) return true;
	else return false;
}

bool CCola::Vacia() {
	if(finl == 0 || finl == frente) return true;
	else return false;
}

void CCola::eleFn() {
	if(Vacia() == true) cout << "La cola está vacía" << endl;
	else {
		cout << "El último elemento de la cola es: " << Cola[finl-1] << endl;
	}
}

void CCola::eleFrt() {
	if(Vacia() == true) cout << "La cola está vacía" << endl;
	else {
		cout << "El elemento en frente es: " << Cola[frente] << endl;
	}
}

CCola::~CCola() {
	for (int i = 0; i < MAX ; i++) {
		Cola[i] = 0;
	}
	frente = finl = 0;

}

int main() {
	CCola Cola;
	int dat, opc, numE;
	char continuar;
	bool estado;

	do {
		system("clear");
		menu();
		cin >> opc;

		switch(opc) {
			case 0:
				cout << "¿Cuántos elementos desea ingresar? ";
				cin >> numE;
				for (int i = 0; i < numE; i++) {
					dat = Cola.LeerDato();
					Cola.Agregar(dat);
				}
				break;
			case 1: //Agregar un nuevo número entero
				dat = Cola.LeerDato();
				Cola.Agregar(dat);
				break;
			case 2: //Eliminar elemento del frente
				Cola.Eliminar();
				break;
			case 3: //Saber que dato se encuentra al frente
				Cola.eleFrt();
				break;
			case 4: //Saber que dato se encuentra al final
				Cola.eleFn();
				break;
			case 5: //Mostrar elementos de la cola
				Cola.Imprimir();
				break;
			case 6: //Verificar si está vacía
				estado = Cola.Vacia();
				if(estado == true) cout << "La cola está vacía" << endl;
				else cout << "La cola no está vacía" << endl;
				break;
			case 7: //Verificar si está llena
				estado = Cola.Llena();
				if(estado == true) cout << "La cola está llena" << endl;
				else cout << "La pila no está llena" << endl;
				break;
			default:
				cout << "Opción no válida" << endl;
				break;
		}

		cout << "¿Otra opción? (S/N) --> ";
		cin >> continuar;
		continuar = toupper(continuar);
	} while(continuar == 'S');

	return 0;
}

void menu() {
	cout << "\tElija una operación" << endl;
	cout << "0. Agregar n elementos" << endl;
	cout << "1. Agregar nuevo dato" << endl;
	cout << "2. Eliminar" << endl;
	cout << "3. Ver elemento que está al frente" << endl;
	cout << "4. Ver último elemento de la cola" << endl;
	cout << "5. Mostrar elementos de la cola" << endl;
	cout << "6. Saber si está vacía" << endl;
	cout << "7. Saber si está llena" << endl;
	cout << "---> ";
}
