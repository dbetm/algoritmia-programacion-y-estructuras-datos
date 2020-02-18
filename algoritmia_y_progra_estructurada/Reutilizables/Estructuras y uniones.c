#include <stdio.h>
#include <stdlib.h>

//Estructuras y uniones

/*La diferencia está en que los elementos de una unión se almacenan en una
 * sola dirección de memoria, un tipo de dato a la vez */

struct alumno {
	int noLista;
	char nombre[30];
	int edad;
	float promedio;
};
//para no tener que escribir dentro del main 'struc':
//typedef struct alumno alumno;  lo que se hace es asignar un alias, por conveniencia el mismo nombre que el del tipo
//de estructura
/* o se puede simplificar así: 
 * typedef struct alumno {
	int noLista;
	char nombre[30];
	int edad;
	float promedio;
}; */

union alumno2 {
	int noLista;
	char nomb[30];
	int edad;
	float promedio;
}miguel;

int main(int argc, char **argv) {
	fflush(stdin);
	
	//ejemplo de una estructura
	struct alumno david;
	printf("Escriba el nombre del alumno: ");
	scanf("%[^\n]", david.nombre);
	fflush(stdout);
	//while(getchar() !='\n');
	
	david.edad = 19;
	david.promedio = 9.83;
	david.noLista = 5;
	
	printf("El nombre del alumno es: %s\n", david.nombre);
	
	//ejemplo de una unión
	
	//union alumno2 miguel;
	miguel.edad = 10;
	printf("\nLa edad del alumno2 es: %d\n", miguel.edad);
	
	return 0;
}

