#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int arreglo[3][3];
	int i = 0, j = 0, aux = 0, rx = 0, par = 0, impar = 0;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			rx++;
				if(rx % 2 == 0) par += rx;
				else {
					impar += rx;
				}
			arreglo[i][j] = rx;
		}
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(aux == 3){
				printf("\n");
				aux = 0;
			}
			printf("%i ",arreglo[i][j]);
			aux++;
		}
	}
	printf("\n");
	
	printf("La suma de los numeros pares es %i\n",par);
	printf("La suma de los impares es %i\n",impar);
	
	// alternativa
	/* for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%i ",arreglo[i][j]);
		}
		printf("\n");
	}
	*/
	
	
	return 0;
}

