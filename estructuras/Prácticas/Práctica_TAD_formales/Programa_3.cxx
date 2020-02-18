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

class Nums {
	private:
		int *A;
		int n, min, max;
	public:
		Nums();
		void leer();
		void ordenar(int);
		void mostrar();
		int menor();
		int mayor();
		~Nums();
};

Nums::Nums() {
	A = NULL;
	n = 0, min = 0, max = 0;
}

void Nums::leer() {
	cout << "Dame N: ";
	cin >> n;
	A = (int*)malloc(n*sizeof(int));
	if(A != NULL) {
		cout << "Ingrese los numeros separados por un espacio" << endl;
		for(int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
		}
	}
	else cout << "Error de memoria";
}

void Nums::ordenar(int opc) {
	int i, j, temp;
	for(j = 0; j < n; j++) {
		
		for(i = 0; i < n-1; i++){
			
			if (opc == 1) { //Ascendente
			
				if (A[i] > A[i+1]) {
					temp = A[i];
					A[i] = A[i+1];
					A[i+1] = temp;
				}
			}
			else { //Descendente
				if (A[i] < A[i+1]){
					temp = A[i];
					A[i] = A[i+1];
					A[i+1] = temp;
				}
			}
		}
	}
}

void Nums::mostrar() {
	for(int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	cout << endl;
}

int Nums::menor() {
	min = A[0];
	for(int i = 1; i < n; i++) {
		if(A[i] < min) min = A[i];
	}
	return min;
}

int Nums::mayor() {
	max = A[0];
	for(int i = 1; i < n; i++) {
		if(A[i] > max) max = A[i];
	}
	return max;
}

Nums::~Nums() {
	n = 0, min = 0, max = 0;
	if(A != NULL) free(A);
}

int main(int argc, char **argv) {
	Nums Op;
	int max, min, opc;
	
	do {
		system("cls");
		Op.leer();
		cout << "Forma ascencente: ";
		Op.ordenar(1);
		Op.mostrar();
		cout << "Forma descendente: ";
		Op.ordenar(0);
		Op.mostrar();

		max = Op.mayor();
		cout << "Mayor: " << max << endl;
		
		min = Op.menor();
		cout << "Menor: " << min << endl;
		
		cout << "Presione 1 para volver a intentar: ";
		cin >> opc;
	} while(opc == 1);
	
	return 0;
}
