#include <stdio.h>
#include <stdlib.h>

float factorial(float numero);

int main(int argc, char **argv)
{
	float n = 0;
	printf("Dame el numero para calcular su factorial\n");
	scanf("%f",&n);
	printf("El factorial es: %.0f\n",factorial(n));
	
	return 0;
}
float factorial(float numero){
	if (numero <= 1) return 1;
	else
		return numero*factorial(numero-1);
}


