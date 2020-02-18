#include <stdio.h>
#include <stdlib.h>
/* Objetivo: Generar y mostrar en pantalla un "cuadrado mágico" dada una n impar. 
 * Autor: David Betancourt Montellano
 * Fecha: Noviembre del 2016 */

//Global variables
int box[17][17]; 

//Functions
int leer_n();
void inicializar(int n);
void llenado(int n);
void mostrar(int n);

int main(int argc, char **argv)
{
	int n = 0, opc = 0;
	char opt[1];
	
	do {
		n = leer_n();
		inicializar(n);
		llenado(n);
		mostrar(n);
		printf("Desea volver a intentarlo? \nPresiona '1' para indicar que si o cualquier otra tecla para salir.\n");
		scanf("%s", opt);
		opc = atoi(opt);
		if(opc != 0) {
			if(opc == 1) continue;
		}
		else break;
	} while(opc == 1);
	
	return 0;
}
int leer_n() {

	int n;
	char num[2];
	
	do {
		system("clear");
		//system("cls"); //for your Windows!
		printf("NOTA: DEBE SER MAYOR O IGUAL A 3, Y MENOR O IGUAL A 17.\n");
		printf("Ingresa un numero impar: ");
		scanf("%s",num);
		fflush(stdin);
		n = atoi(num);
		if(n != 0) {
			if(n > 17) n = 0;
			if(n % 2 == 0 || n < 3) n = 0;
			else break;
		}
		else n = 0;
	}while(n == 0);
	
	return n;
}
void inicializar(int n) {
	int i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			box[i][j] = 0;
		}
	}
}
void llenado(int n) {
	
	int max = 0, k = 0, i = 0, j = 0, dim = 0, aux1 = 0, aux2 = 0;
	
	max = (n*(n*n + 1)) / 2;
	printf("La constante del cuadro magico vale: %d\n", max);
	j = n / 2;
	dim = n*n;
	
	for(k = 0; k < dim; k++) {
		if(box[i][j] != 0) {
				i = aux1 + 1;
				j = aux2;
		}
		if(box[i][j] == 0) box[i][j] = k + 1;
		aux1 = i;
		aux2 = j;
		i--;
		j++;
		if(j > n-1) j = 0;
		if(i < 0) i = n - 1;
	}
}
void mostrar(int n) {
	int i, j; 
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(box[i][j] < 10) printf("   %d", box[i][j]);
			else if(box[i][j] >= 10 && box[i][j] < 100) printf("  %d", box[i][j]);
			else printf(" %d", box[i][j]);
		}
		printf("\n");
	}
}
