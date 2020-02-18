#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cctype>

/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 22/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Ejericio TAD Pila (estática) con enteros
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/

void menu();

using namespace std;
const int MAX = 10;

class CPila {
	private:
		int Pila[MAX];
		int Cima;
	public:
		CPila();
		int LeerDato();
		void Agregar(int);
		void Sacar();
		void Imprimir();
		bool Vacia();
		bool Llena();
		void EleCima();
		~CPila();
};

CPila::CPila() {
	for (int i = 0; i < MAX; i++) {
		Pila[i] = 0;
	}
	Cima = -1; //para que mi pila siga siendo de 10 elementos
	//-1 para saber si está vacía, ya que no es ningun índice de mi arreglo	
}

int CPila::LeerDato() {
	int Dato;
	cout << "Dato a ingresar: ";
	cin >> Dato;
	return Dato;
}

bool CPila::Llena() {
	if(Cima == MAX - 1) return true;
	else return false;
}

bool CPila::Vacia() {
	if(Cima == -1) return true;
	else return false;
}

void CPila::Agregar(int Dat) {
	if (Llena() == true) cout << "La pila está llena" << endl;
	else {
		Cima++;
		Pila[Cima] = Dat;
		cout << "El dato se guardó correctamente" << endl;
	}
}

void CPila::Sacar() {
	if(Vacia() == 0) {
		cout << "Se sacó: " << Pila[Cima] << endl;
		Pila[Cima] = 0;
		Cima--;
	}
	else cout << "La pila está vacía" << endl;
}

void CPila::EleCima() {
	if(Vacia() == 1) cout << "La pila está vacía" << endl;
	else {
		cout << "El elemento tope es: " << Pila[Cima] << endl;
	}
}

void CPila::Imprimir() {
	if(Vacia() == true) cout << "La pila está vacía" << endl;
	else {
		for (int i = Cima; i >= 0; i--) {
		cout << "El elemento " << i+1 << " de la pila es: " << Pila[i] << endl;
		}
	}
}

CPila::~CPila() {
	for (int i = 0; i < MAX; i++) {
		Pila[i] = 0;
	}
	Cima = -1; 
}

int main(int argc, char **argv) {
	CPila Stack1;
	int dat, opc, numE;
	char continuar;
	bool estado;
	
	do {
		system("clear");
		menu();
		cin >> opc;
		//if(opc < 0 or opc > 6) cout << "Opción no válida" << endl;
		
		switch(opc) {
			case 0: //Agregar enteros hasta que se llene
				cout << "¿Cuántos elementos desea ingresar? ";
				cin >> numE;
				for (int i = 0; i < numE; i++) {
					dat = Stack1.LeerDato();
					Stack1.Agregar(dat);
				}
				break;
			case 1: //Agregar un nuevo número entero
				dat = Stack1.LeerDato();
				Stack1.Agregar(dat);
				break;
			case 2: //Desapilar el dato que se encuentra en la cima
				Stack1.Sacar();
				break;
			case 3: //Saber que dato se encuentra en la cima
				Stack1.EleCima();
				break;
			case 4: //Mostrar todos los enteros de la pila
				Stack1.Imprimir();
				break;
			case 5: //Verificar si está vacía
				estado = Stack1.Vacia();
				if(estado == true) cout << "La pila está vacía" << endl;
				else cout << "La pila tiene elementos" << endl;
				break;
			case 6: //Verificar si está llena
				estado = Stack1.Llena();
				if(estado == true) cout << "La pila está llena" << endl;
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
	cout << "1. Agregar dato" << endl;
	cout << "2. Desapilar último elemento" << endl;
	cout << "3. Ver elemento que esta en el tope" << endl;
	cout << "4. Imprimir elementos de la pila" << endl;
	cout << "5. Saber si está vacía" << endl;
	cout << "6. Saber si está llena" << endl;
	cout << "---> ";
}
