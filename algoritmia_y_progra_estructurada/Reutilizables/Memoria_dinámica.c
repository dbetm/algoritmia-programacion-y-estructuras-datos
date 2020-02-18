#include <stdio.h>
#include <stdlib.h> //Importante incluir este archivo de librería, para el manejo de memoria dinámica
//Se recomieda usar la memoria dinámica cuando hay vectores, matrices...con dimensiones muy grandes >1000

int main(int argc, char **argv) {
	int *vector1; //para malloc
	int *vector2; //para calloc, inicializa con 0 a diferencia de malloc
	int n, m;
	
	printf("Dame n, y m: ");
	scanf("%d %d", &n, &m);
	
	vector1 = malloc(n * sizeof(int));
	vector2 = calloc(m, sizeof(int));
	
	//Hacer la siguiente verificación se ve com buenas prácticas de programación, pues estamos dando salida a posibles errores
	//durante la ejecución del programa...
	if(vector1 == NULL) printf("Error al intentar asignar memoria\n"); //Por ejemplo: en caso de que se obtenga un valor incorrecto de n
	if(vector2 == NULL) printf("Error al intentar asignar memoria\n");
	
	
	//Para liberar memoria (MALLOC) cuando ya no se necesita, ojo, si se quiere usar otra vez el puntero hay que asignar nuevamente
	//Así: vector1 = malloc(n * sizeof(int));
	free(vector1); 
	/*puede resultar sumamente peligroso si se intenta usar ya una vez liberada la memoria, 
	 *por lo que conviene inciarla otra vez, tampoco se debe liberar otra vez ya una vez que se liberó.
	 *para evitar posibles problemas hay que hacer: vector = NULL;
	*/
	
	//Para calloc
	cfree(vector2);
	/*
	 * Las reglas de C establecen que un puntero void se puede convertir automáticamente 
	 * a un puntero de cualquier otro tipo, por lo que no es necesario hacer una conversión (cast), 
	 * como en el siguiente ejemplo:
	*/
	vector1 = (int *)malloc(n * sizeof(int));
	//Otro ejemplo: string = (char *)malloc(n * sizeof(char));
	
	
	//Si queremos redimensionar un arreglo, entonces:
	vector1 = (int*)realloc(vector1, n * sizeof(int));
	return 0;
}

