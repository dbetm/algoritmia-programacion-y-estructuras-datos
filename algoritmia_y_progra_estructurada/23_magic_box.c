#include <stdio.h>
#include <stdlib.h>
int box[17][17];
int leer_n();
void inicializar();
void llenado(int n);
void mostrar(int n);

int main(int argc, char **argv)
{
	int n = 0;
	n = leer_n();
	llenado(n);
	mostrar(n);
	
	return 0;
}
int leer_n() {
	int n;
	do {
		printf("Ingresa un numero impar: ");
		scanf("%d",&n);
		
		if(n%2 == 0 || n < 3) n = 0;
		else break;
	}while(n == 0);
	
	return n;
}
void llenado(int n) {
	
	int max = 0, k = 0, i = 0, j = 0, aux1 = 0; // aux2, aux3; // aux1, aux2;
	
	inicializar();
	max = (n*(n*n + 1)) / 2;
	//printf("la constante es %d", max);
	j = n % 2;
	aux1 = n*n;
	
	for(k = 0; k < aux1; k++) {
		if(box[i][j] != 0) {
			if(i >= 0 && j < n) {
				j--;
				i = i + 2;
			}
		}
		if(box[i][j] == 0) box[i][j] = k + 1;
		//printf("La celda %d , %d vale %d\n", i, j, box[i][j]);
		i--;
		j++;
		if(i < 0 && j > n-1) {
				i = i + 2;
				j--;
				continue;
			}
		if(j > n-1) j = 0;
		if(i < 0) i = n - 1;
	}
}
void inicializar() {
	int i, j;
	
	for(i = 0; i < 17; i++) {
		for(j = 0; j < 17; j++) {
			box[i][j] = 0;
		}
	}
}
void mostrar(int n) {
	int i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d  ", box[i][j]);
		}
		printf("\n");
	}
	
}

