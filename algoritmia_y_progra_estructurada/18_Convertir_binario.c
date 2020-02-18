#include <stdio.h>
#include <stdlib.h>

	// Objetivo: Conversor de binario
	// Autor:    David Betancourt Montellano
	// Fecha:    07/octubre/2016

int pide_num();
void llenar( int n);

int main(int argc, char **argv)
{
	llenar(pide_num());
	return 0;
}
int pide_num(){
	int n = 0;
	do {
		printf("Dame un numero positivo: ");
		scanf("%i",&n);
	}while(n<0);
	return n;
}
void llenar(int n){
	
	int arreglo[7];
	int res = 0, i = 0, a = 0;
	
	for(i = 0; i <= 7; i++){
		res = n % 2;
		arreglo[i] = res;
		n = n / 2;
	}
	for (i = 7; i >= 0; i-- ) {
			if (arreglo[i] == 0) a++;
			else break;
		}
		
	if(a == 8) a = 7;
	
	for (i = 7-a; i >= 0; i-- ) {
			printf("%i",arreglo[i]);
		}
	printf("\n");
}

