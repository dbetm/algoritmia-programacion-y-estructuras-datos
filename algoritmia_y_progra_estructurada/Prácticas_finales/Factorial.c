#include <stdio.h>
#include <stdlib.h>
/* Objetivo: Calcular el factorial de un número dado 
 * Autor: David Betancourt Montellano
 * Fecha: Noviembre del 2016 */

float pedir_n();
void calcular(float n);

int main(int argc, char **argv)
{
	float n = 0;
	
	do {
		n = pedir_n();
	} while( n < 0);
	
	if(n == 0 || n == 1) {
		printf("El factorial es: 1\n");
	}
	else {
		calcular(n);
	}
	
	return 0;
}
float pedir_n() {
	
	float n = 0;
	printf("Dame el numero: ");
	scanf("%f", &n);
	
	return n;
}
void calcular(float n) {
	float factorial = n, i = 1;
	
	while(i < n) {
		factorial = factorial * (n - i);
		i++;
	}
	
	printf("El factorial es: %.0f\n", factorial);
}
