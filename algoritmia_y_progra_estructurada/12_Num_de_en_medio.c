#include <stdio.h>
#include <stdlib.h>

/* Objetivo: Mostrar el número de en "medio" dados tres números diferentes
 * Autor: David Betancourt Montellano
 * Fecha: 28-09-2016 */

int pedir_num();
int medio(int a, int b, int c);
void show (int x);

int main(int argc, char **argv)
{
	int n1 = 0, n2 = 0, n3 = 0, opc = 0;
		
		do {
			n1 = pedir_num();
			n2 = pedir_num();
			n3 = pedir_num();
			if (n1 == n2 || n1 == n3) {
				printf("Deben ser numeros diferentes\n");
			}
			else {
				if (n2 == n3) {
					printf("Deben ser numeros diferentes\n");
				}
				else {
					show(medio(n1, n2, n3));
				}
			}
		printf("Presione '0' o alguna letra para salir, u otro numero para continuar\n");
		scanf("%d",&opc);
		}while(opc != 0);
	
	return 0;
}
int pedir_num() {
	
	int num = 0;
	printf("Dame el numero: ");
	scanf("%i",&num);
	return num;
}
int medio (int a, int b, int c) {
	
	int medio = 0;
		if (a > b && a > c){
			if (b > c) {
				medio = b;
			}
			else {
				medio = c;
			}
		}
		else {
			if (b > a && b > c) {
				
				if (c > a) {
				medio = c;
			}
				else {
				medio = a;
			}
			
			}
			else {
				if (a > b) {
				medio = a;
			}
				else {
				medio = b;
			}
				
			}	
		}
	return medio;
}
void show (int x) {
	printf("El numero de 'el medio' es %i\n",x);
}
