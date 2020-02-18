#include <stdio.h>
#include <stdlib.h>

float factorial(float num);

int main(int argc, char **argv)
{
	float n = 0;
	printf("Dame un numero para calcular el factorial: ");
	scanf("%f",&n);
	if(n < 0) printf("No se admiten numeros negativos\n");
	else printf("El factorial es: %.0f\n", factorial(n));
	
	return 0;
}

float factorial(float num){
	if (num <= 1) return 1;
	else return num*(factorial(num-1));;
}
