#include <iostream>
#include <cstdio>
#include <cstdlib>
/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 08/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia:
 * Grupo: 2CM1.
*/

using namespace std; //para evitar poner muchas veces std, al leer y mostrar

class DosNumeros { //TAD 2 números (especificación formal)
	private:
		int valor;
	public:
		DosNumeros(); //Constructor
		void Solicitar();
		int Leer();
		int Suma(int, int);
		int Resta(int, int);
		int Mult(int, int);
		int Div(int, int);
		void Mostrar(int);
		~DosNumeros(); //Destructor
};

//IMPLEMENTACIÓN
DosNumeros::DosNumeros() { //Llamar al constructor
	valor = 0;
}

void DosNumeros::Solicitar() {
	system("clear");
	cout<<"Dato: "<<endl; //con salto de línea cout<<"Dato: "<<endl; ---printf("Dato: \n");
}

int DosNumeros::Leer() {
	cin>>valor; //scanf("%d", &valor);
	return valor;
}

int DosNumeros::Suma(int a, int b) {
	int R;
	R = a + b;
	return R; //return a+b;
}

int DosNumeros::Resta(int a, int b) {
	return a - b; //return a+b;
}

int DosNumeros::Mult(int a, int b) {
	return a * b; //return a+b;
}

int DosNumeros::Div(int a, int b) {
	return a / b; //return a+b;
}

void DosNumeros::Mostrar(int resultado) {
	cout<<"El resultado es: "<<resultado<<endl;
}

DosNumeros::~DosNumeros() { //Llamar al destructor
	valor = 0;
}

//------>Main<-------
int main(int argc, char **argv) { //DosNumeros es nuestro tipo de dato

	DosNumeros Op;
	int a, b, resultado;
	int opc;

	cout<<"Elija una operación"<<endl;
	cout<<"1. Suma"<<endl;
	cout<<"2. Resta"<<endl;
	cout<<"3. Multiplicación"<<endl;
	cout<<"4. División"<<endl;
	do {
		cin>>opc;
		if(opc < 1 || opc > 4) printf("No válido\n");
	}while(opc < 1 || opc > 4);

	switch(opc) {
		case 1:
			cout<<"Suma"<<endl;
			Op.Solicitar();
			a = Op.Leer();
			Op.Solicitar();
			b = Op.Leer();
			resultado = Op.Suma(a, b);
			Op.Mostrar(resultado);
			break;
		case 2:
			cout<<"Resta"<<endl;
			Op.Solicitar();
			a = Op.Leer();
			Op.Solicitar();
			b = Op.Leer();
			resultado = Op.Resta(a, b);
			Op.Mostrar(resultado);
			break;
		case 3:
			cout<<"Multiplicación"<<endl;
			Op.Solicitar();
			a = Op.Leer();
			Op.Solicitar();
			b = Op.Leer();
			resultado = Op.Mult(a, b);
			Op.Mostrar(resultado);
			break;
		case 4:
			cout<<"División"<<endl;
			Op.Solicitar();
			a = Op.Leer();
			Op.Solicitar();
			b = Op.Leer();
			if(b == 0) printf("No es posible realizar la división entre 0\n");
			else {
				resultado = Op.Div(a, b);
				Op.Mostrar(resultado);
			}
			break;
	}	
	return 0;
}
