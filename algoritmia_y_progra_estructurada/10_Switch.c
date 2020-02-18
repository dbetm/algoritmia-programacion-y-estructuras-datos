#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Mostrar_Menu();

int main(int argc, char **argv)
{
	int opcion = 0;
	opcion = Mostrar_Menu();
	
	switch(opcion) {
	
	case 1: 
		printf("Elegiste la opcion 1 ");
		break;
	case 2: 
		printf("Elegiste la opcion 2 ");
		break;
	case 3: 
		printf("Elegiste la opcion 3 ");
		break;
	case 4: 
		printf("Elegiste la opcion 4 ");
		break;
	case 5: 
		printf("Elegiste la opcion 5 ");
		break;
	default:
		break;		
	}	
	return 0;
}

int Mostrar_Menu()
{
	int opc = 0;
	
	printf("Selecciona una opcion: \n");
		printf("1. Opcion 1.\n");
		printf("2. Opcion 2.\n");
		printf("3. Opcion 3.\n");
		printf("4. Opcion 4.\n");
		printf("5. Opcion 5.\n");
	scanf("%i",&opc);
	
	return opc;
}
