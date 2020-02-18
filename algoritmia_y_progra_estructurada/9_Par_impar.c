#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int num = 0;
	
	printf("Escribe un numero: ");
	scanf("%i",&num);
	
	if (num == 0) {
		printf("Es cero");
	}
	else {
		num = num%2;
		
		if (num == 0){
			printf("Es par ");
		}
		else {
			printf("Es impar ");
		}
	}
	
	return 0;
}

