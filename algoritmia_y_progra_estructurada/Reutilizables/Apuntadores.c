#include <stdio.h>
#include <stdlib.h>

 //POINTERS

int main(int argc, char **argv) {
	
	int *ptr =  NULL;
	int a = 45;
	
	ptr = &a; //ahora ptr tiene la dirección de memoria de 'a'
	
	printf("la dirección de memoria de a es: %p\n", ptr);
	
	//el asterisco sirve para hacer referencia al contenido de la dirección al cual está apuntando
	printf("el valor de a es: %d\n", *ptr);
	
	//Cambia el contenido de la dirección de memoria a la cual está apuntando
	*ptr = 54; 
	
	printf("el valor de a es: %d\n", a);
	
	//ARITMÉTICA DE APUNTADORES
	
	int array[] = {1, 3, 5, 6}; //los elementos de un arreglo se almacenan de forma apilada, lo cual permite la aritmética de apuntadores
	int *ptrArray = array;
	//int *ptr = &array[0]; --> es equivalente a la expresión de arriba, pues el primer elemento de un arreglo es un identificador 
	//de su dirección de memoria, por eso al pasarlo como parámetro es posible trabajar y afectar el arreglo sin ser global
	printf("\n\nEl elemento 0 del arreglo es: %d\n", *ptrArray);
	
	ptrArray++; //solo se puede sumar y restar
	
	printf("El elemento 1 del arreglo es: %d\n", *ptrArray);
	
	ptrArray += 2;
	
	printf("El elemento 3 del arreglo es: %d\n", *ptrArray);
	
	
	return 0;
}

