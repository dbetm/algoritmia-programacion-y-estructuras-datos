#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int numcan = 0, cont = 0, cant = 0;
	float prom = 0, sum = 0;
	
	printf("Dame el numero de cantidades a ingresar: ");
	scanf("%i",&numcan);
	
		while(cont<numcan) {
			printf("Dame la cantidad: ");
			scanf("%i",&cant);
			sum+= cant;
			cont++;
		}
			prom = sum / numcan;
			printf("Su promedio es: ");
			printf("%.3f",prom);
			printf(" ");

	return 0;
	system("pause");
}

