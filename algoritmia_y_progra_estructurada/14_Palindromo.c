#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i = 0, j = 14;
	char msj[15] = "anitalavalatina";
	printf("%s\n",msj);
	//printf("Palabra: 'anitalavalatina'\n");

	for (i = 0; i < 15; i++) {	
		if( msj[i] == msj[j]){
			if(i == j) {
				printf("Es palindromo\n");
				break;
			}
		}
		else {
			printf("No es palindromo\n");
			break;
		}
		j--;
	}
	
	return 0;
}
