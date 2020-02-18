#include <iostream>
#include <cstdlib>
#include <cstdio>

/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 08/03/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Práctica #3 TAD Cola circular
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/
using namespace std;
#define MAX 10

void menu();

class Colac {
	private:
		int Cola[MAX];
		int frente;
		int finl;
		bool flag; //una variable bandera para saber si algun apuntador ya dio una "vuelta"
	public:
		Colac();
		int LeerDato();
		void Insertar(int);
		void Sacar();
		void Mostrar_frente();
		void Imprimir();
		bool Vacia();
		bool Llena();
		~Colac();
};

Colac::Colac() {
	for (int i = 0; i < MAX ; i++) {
		Cola[i] = 0;
	}
	frente = finl = 0;
	flag = false;
}

int Colac::LeerDato() {
	int dato;
	cout << "Dato a ingresar: ";
	cin >> dato;
	return dato;
}

void Colac::Insertar(int dat) {
	if (Llena() == true) cout << "La cola está llena" << endl;
	else {
		Cola[finl] = dat;
		finl++;
		if(finl == MAX) {
			finl = 0;
			flag = true;
		}
		cout << "Se insertó correctamente" << endl;
	}
}

void Colac::Sacar() {
	if(Vacia() == true) {
		cout << "No hay elementos en la cola" << endl;
	}
	else {
		cout << "Se sacó: " << Cola[frente] << endl;
		Cola[frente] = 0; //0 representa un lugar vacío
		frente++;
		if(frente == MAX) {
			frente = 0;
			flag = false;
		}
	}
}
void Colac::Imprimir() {
	if(Vacia() == true) cout << "No hay elementos en la cola" << endl;
	
	else if(frente < finl) {
		for (int i = frente; i < finl; i++) {
				cout << " " << Cola[i];
			}
	}
	else {
		for (int i = frente; i < MAX; i++) {
			cout << " " << Cola[i];
		}
		for (int i = 0; i < finl; i++) {
			cout << " " << Cola[i];
		}
	}
	cout << endl;
}

void Colac::Mostrar_frente() {
	if(Vacia() == true) cout << "No hay elementos en la cola" << endl;
	else {
		cout << "El elemento en frente es: " << Cola[frente] << endl;
	}
}

bool Colac::Llena() {
	if(flag == true) {
		if(finl == frente) return true;
		else return false;
	}
	else if(frente == 0 && finl == MAX) return true;
	else return false;
}

bool Colac::Vacia() {
	if(finl == frente && flag == false) return true;
	else return false;
}

Colac::~Colac() {
	for (int i = 0; i < MAX ; i++) {
		Cola[i] = 0;
	}
	frente = finl = 0;
	flag = 0;
}

int main() {
	Colac Cola;
	int dat, opc, numE;
	
	do {
		system("clear");
		menu();
		fflush(stdin);
		cin >> opc;
		
		switch(opc) {
			case 0:
				cout << "¿Cuántos elementos desea ingresar? ";
				cin >> numE;
				for (int i = 0; i < numE; i++) {
					dat = Cola.LeerDato();
					Cola.Insertar(dat);
					if(Cola.Llena()) {
						cout << endl << "Ups! La cola se ha llenado" << endl;
						 break;
					}
				}
				break;
			case 1: //Agregar un nuevo elemento
				dat = Cola.LeerDato();
				Cola.Insertar(dat);
				break;
			case 2:
			cout << "¿Cuántos elementos desea eliminar? ";
			cin >> numE;
			for (int i = 0; i < numE; i++) {
				Cola.Sacar();
				if(Cola.Vacia()) {
					cout << endl << "Ups! Ya no hay elementos en la cola" << endl;
					 break;
				}
			}
			break;
			case 3: //Eliminar elemento del frente
				Cola.Sacar();
				break;
			case 4: //Saber que dato se encuentra al frente
				Cola.Mostrar_frente();
				break;
			case 5: //Mostrar elementos de la cola
				Cola.Imprimir();
				break;
			case 6:
				cout << "¡Adiós!" << endl;
				return 0;
			default:
				cout << "Opción no válida" << endl;
				break;
		}
		cout << "Presione una tecla para continuar...";
		cin.ignore().get();
	} while(true);
	
	return 0;
}

void menu() {
	cout << "\tElija una acción" << endl;
	cout << "0. Insertar N cantidad de elementos" << endl;
	cout << "1. Insertar un nuevo elemento" << endl;
	cout << "2. Sacar N cantidad de elementos" << endl;
	cout << "3. Sacar un elemento" << endl;
	cout << "4. Mostrar elemento que está al frente" << endl;
	cout << "5. Imprimir datos" << endl;
	cout << "6. Salir" << endl;
 	cout << "---> ";
}
