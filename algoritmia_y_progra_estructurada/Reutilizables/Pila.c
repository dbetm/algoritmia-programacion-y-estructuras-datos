#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int dato;
	struct node* siguiente;
}node;

node *primero = NULL;

void insertar(int dato);
void desplegar();

int main(int argc, char **argv) {
	int i = 0, dato;
	unsigned int n;
	printf("¿Cuántos elementos desea ingresar? -->");
	scanf("%ud", &n);
	while(i < n) {
		printf("Dato %d: ", i+1);
		scanf("%d", &dato);
		insertar(dato);
		i++;
	}
	desplegar();
	return 0;
}

void insertar(int dato) {
	node *nuevo = (node *)malloc(sizeof(node));
	nuevo -> dato = dato;
	nuevo -> siguiente = primero;
	primero = nuevo;
}
void desplegar() {
	node *actual = (node *)malloc(sizeof(node));
	actual = primero;
	if(primero != NULL) {
		while(actual != NULL) {
			printf("%d\n", actual -> dato);
			actual = actual -> siguiente;
		}
	}
	else printf("\nLa pila se encuentra vacía\n");
}
