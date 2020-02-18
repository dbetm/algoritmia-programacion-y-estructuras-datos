#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int cont = 0, num = 0, res = 0;
	
	printf("Dame el numero:  ");
	scanf("%i",&num);
	cont = num -1;
	res = num;
	
	if (num>=0) {
		
	while(cont>=1) {
		res = res * cont;
		cont--;		
	}
	printf("El factorial es: %i",res);
	//printf("%i",res);
	printf(" ");
	
	}
	else {
		printf("El mundo se acabara si no usa numeros positivos ");
	}
	
	
	return 0;
}

