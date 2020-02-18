#include <stdio.h>
#include <stdlib.h>
int i = 0, cont = 0, cont1 = 0;

void sumar_par(int i);
void sumar_impar(int i);
void res(int a, int b);

int main(int argc, char **argv)
{	
	for (i = 1; i <= 100; i++) {
		if (i % 2 == 0) sumar_par(i);
		else sumar_impar(i);
	}
	res (cont, cont1);
	
	return 0;
}
void sumar_par(int i){
	cont += i;
}
void sumar_impar(int i){
	cont1 += i;
}
void res(int a, int b){
	printf("La suma de los pares es: %i\n",a);
	printf("La suma de los impares es: %i\n",b);
}


