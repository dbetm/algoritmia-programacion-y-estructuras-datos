#include <stdio.h>
#include <stdlib.h>

struct mi_dato {
	int cali1;
	char nombre[30];
	};

int main(int argc, char **argv)
{
	struct mi_dato hola;
	hola.cali1 = 1;
	hola.nombre = 'F';
	printf("%i\n",hola.cali1);
	printf("%s\n",hola.nombre);
	
	return 0;
}

