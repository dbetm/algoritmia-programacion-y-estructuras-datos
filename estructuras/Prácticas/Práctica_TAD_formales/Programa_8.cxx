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

class Edades {
	private:
		float *E;
		float edad, eMedia, eMax, eMin;
		int jub, men;
	public:
		Edades();
		int captura();
		float media(int);
		float max(int);
		float min(int);
		int jubilados(int);
		int menores(int);
		~Edades();
};

Edades::Edades() {
	E = NULL;
	edad = eMedia = eMax = eMin = 0;
	jub = men = 0;
}

int Edades::captura() {
	int i = 0;
	cout << "\tIngrese las edades" << endl;
	E = (float *)malloc(1 * sizeof(float));
	if(E != NULL) {
		do {
			cout << ">>> ";
			cin >> edad;
			if(edad >= 0) {
				E[i] = edad;
				i++;
				E = (float *)realloc(E, (i+1) * sizeof(float));
			}
			else break;
		} while(true);
	}
	else cout << "Error al intentar asignar memoria." << endl;
	return i;
}

float Edades::media(int len) {
	if(len > 0) {
		for(int i = 0; i < len; i++) {
			eMedia += E[i];
		}
		return (eMedia / len);
	}
	else return 0;
}

float Edades::max(int len) {
	eMax = E[0];
	
	if(len > 0) {
		for(int i = 0; i < len; i++) {
			if(E[i] > eMax) eMax = E[i];
		}
		return eMax;
	}
	else return 0;
}

float Edades::min(int len) {
	eMin = E[0];
	
	if(len > 0) {
		for(int i = 0; i < len; i++) {
			if(E[i] < eMin) eMin = E[i];
		}
		return eMin;
	}
	else return 0;
}

int Edades::jubilados(int len) {
	for(int i = 0; i < len; i++) {
		if(E[i] >= 60) jub++;
	}
	return jub;
}

int Edades::menores(int len) {
	for(int i = 0; i < len; i++) {
		if(E[i] < 18) men++;
	}
	return men;
}

Edades::~Edades() {
	if(E != NULL) free(E);
	edad = eMedia = eMax = eMin = 0;
	jub = men = 0;
}

int main(int argc, char **argv) {
	Edades Grupo;
	
	float media, max, min;
	int jubilados, menores;
	int cont;
	
	cont = Grupo.captura();
	
	media = Grupo.media(cont);
	cout << "La edad media es: " << media << " anios." << endl;
	
	max = Grupo.max(cont);
	cout << "La edad maxima es: " << max << " anios." << endl;
	
	min = Grupo.min(cont);
	cout << "La edad minima es: " << min << " anios." << endl;
	
	jubilados = Grupo.jubilados(cont);
	if(jubilados == 1) cout << "Hay 1 jubilado." << endl;
	else cout << "Hay " << jubilados << " jubilados." << endl;
	
	menores = Grupo.menores(cont);
	if( menores == 1) cout << "Hay 1 menor de edad." << endl;
	else cout << "Hay " << menores << " menores de edad." << endl;
	
	return 0;
}
