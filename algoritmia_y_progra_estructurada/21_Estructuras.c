#include <stdio.h>
#include <stdlib.h>
struct fecha {
	int dia, mes, anio;
	};
struct persona {
	char nom[8];
	struct fecha nac;
	};
	
int main(int argc, char **argv)
{	
	int x = 0;
	struct persona grupo[5];
	for (x = 0; x < 5; x++) {
		printf("Dame el nombre: \n");
		scanf("%s",&grupo[x].nom);
		printf("Dame el dia: \n");
		scanf("%i",&grupo[x].nac.dia);
	}
	for (x = 0; x < 5; x++) {
		printf("Nombre: ");
		printf("%s\n",grupo[x].nom);
		printf("Dia: ");
		printf("%i\n",grupo[x].nac.dia);
	}
	
	
	return 0;
}

