#include <stdio.h>
#include <stdlib.h>

void imprime (char k[]);

int main(int argc, char **argv)
{
	char nombre[] = "Esto lee el mensaje al reves 'DAVID BETANOURT MONTELLANO'";
	printf("Esto lee el mensaje al reves 'DAVID BETANOURT MONTELLANO'\n");
	imprime(nombre);
	return 0;
	
}
void imprime (char k[]){
	int x; 
	for(x = strlen(k)-1; x >= 0; x--){
		printf("%c",k[x]);
	}
	printf("\n");
}

