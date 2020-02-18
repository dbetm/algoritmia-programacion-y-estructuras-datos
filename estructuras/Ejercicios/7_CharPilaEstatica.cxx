#include <iostream>
#include <cstdlib>
//#include <cstdio>
#include <cctype>
#include <cstring>

/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 22/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Ejericio TAD Pila (estática) con carácteres
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/
void menu();

using namespace std;
#define MAX 10

class CPila {
	private:
		char Stack[MAX];
		int top;
	public:
		CPila();
		char Read();
		void Add(char);
		char Quit();
		char ITop();
		void Display();
		bool Empty();
		bool Full();
		~CPila();
} Stack2;

CPila::CPila() {
	for (int i = 0; i < MAX; i++) {
		Stack[i] = '\0';
	}
	top = -1;
}
char CPila::Read() {
	char ch;
	cout << "Letra a ingresar: ";
	cin >> ch;
	return ch;
}

void CPila::Add(char ch) {
	if(Full() == true) cout << "La pila está llena" << endl;
	else {
		top++;
		Stack[top] = ch;
		cout << "Se guardó correctamente" << endl;
	}
}

char CPila::Quit() {
	char c = '#';
	if(Empty() == true) {
		return c;
	}
	else {
		c = Stack[top];
		Stack[top] = '\0';
		top--;
		return c;
	}
}

char CPila::ITop() {
	char c = '#';
	if(Empty() == true) {
		return c;
	}
	else {
		c = Stack[top];
		return c;
	}
}

void CPila::Display() {
	for (int i = top; i >= 0; i--) {
		cout << i << " -->>> " << Stack[i] << endl;
	}
}

bool CPila::Empty() {
	if( top == -1) return true;
	else return false;
}

bool CPila::Full() {
	if( top == MAX - 1) return true;
	else return false;
}

CPila::~CPila() {
	for (int i = 0; i < MAX; i++) {
		Stack[i] = '\0';
	}
	top = -1;
}

int main(int argc, char **argv) {
	char ch;
	int opc, numE;
	char continuar;
	bool estado;
	
	do {
		system("clear");
		menu();
		cin >> opc;
		//if(opc < 0 or opc > 6) cout << "Opción no válida" << endl;
		
		switch(opc) {
			case 0: //Agregar enteros hasta que se llene
				cout << "¿Cuántas letras desea ingresar? ";
				cin >> numE;
				if(numE >= 0 and numE <= 10) {
					for (int i = 0; i < numE; i++) {
					ch = Stack2.Read();
					Stack2.Add(ch);
					}
				}
				else cout << "El número de elementos que desea excede la capacidad de la pila" << endl;
				
				break;
			case 1: //Agregar un nuevo número entero
				ch = Stack2.Read();
				Stack2.Add(ch);
				break;
			case 2: //Desapilar el dato que se encuentra en la cima
				ch = Stack2.Quit();
				if(ch == '#') cout << "La pila está vacía" << endl;
				else {
					cout << "Se sacó el carácter: " << ch << endl;
				}
				break;
			case 3: //Saber que dato se encuentra en la cima
				ch = Stack2.ITop();
				if(ch == '#') cout << "La pila está vacía" << endl;
				else {
					cout << "El elemento que está en la cima: "<< ch << endl;
				}
				break;
			case 4: //Mostrar todos los enteros de la pila
				Stack2.Display();
				break;
			case 5: //Verificar si está vacía
				estado = Stack2.Empty();
				if(estado == true) cout << "La pila está vacía" << endl;
				else cout << "La pila no está vacía" << endl;
				break;
			case 6: //Verificar si está llena
				estado = Stack2.Full();
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
	cout << "0. Agregar n letras" << endl;
	cout << "1. Agregar letra" << endl;
	cout << "2. Sacar última letra" << endl;
	cout << "3. Ver carácater tope" << endl;
	cout << "4. Imprimir elementos de la pila" << endl;
	cout << "5. Saber si está vacía" << endl;
	cout << "6. Saber si está llena" << endl;
	cout << "---> ";
}
