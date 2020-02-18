#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int num1 = 0, num2 = 0;
	
	printf("Dame un numero ");
	scanf("%i",&num1);
	printf("Dame otro numero ");
	scanf("%i",&num2);
	
	if (num1 == num2) {
		printf("Los numeros son iguales ");
	}
	else {
		if (num1>num2) {
			printf("%i",num1);
			printf(" es mayor ");
		}
		else {
			printf("%i",num2);
			printf(" es mayor ");
		}
	}
	
	return 0;
}

