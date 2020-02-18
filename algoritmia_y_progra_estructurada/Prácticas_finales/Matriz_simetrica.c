#include <stdio.h>
#include <stdlib.h>
/* Objetivo: Programa para saber si una matriz es simétrica o no. 
 * Autor: David Betancourt Montellano
 * Fecha: Noviembre del 2016 */
 
//Arrays
int A[18][18], AT[18][18];
//Functions
int pedir_Datos();
int comparar(int dim);
void mensaje(int n);

int main(int argc, char **argv) {
	int dim = 0, n;
	
	dim = pedir_Datos();
	n = comparar(dim);
	mensaje(n);
	return 0;
}
int pedir_Datos() {
	int dim = 0, i, j;

	do {
		printf("Defina la dimension de la matriz cuadrada:  ");
		scanf("%d", &dim);
	} while(dim < 2 || dim > 18);
	printf("\nEscriba los valores de la matriz por fila separados por un espacio.\n");
	for(i = 0; i < dim; i++) {	
		for(j = 0; j < dim; j++) {	
			scanf("%d", &A[i][j]);
			AT[j][i] = A[i][j];
		}
	}
	 return dim;
}
int comparar(int dim) {
	int i, j, n = 1;
	
	for(i = 0; i < dim; i++) {	
		for(j = 0; j < dim; j++) {	
			if(A[i][j] != AT[i][j]) {
				n = 0;
				i = dim; //para abandonar ciclos
				j = dim;
			}
		}
	}
	return n;
}
void mensaje(int n) {
	if(n == 1) printf("Es simetrica\n");
	else printf("No es simetrica\n");
}

