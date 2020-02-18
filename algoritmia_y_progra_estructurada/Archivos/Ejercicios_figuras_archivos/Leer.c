#include <stdio.h>
#include <stdlib.h>
//BOF------ARCHIVO-------\\EOF Begin of File ---> End of File
// Archivos de entrada(lectura - read),  actualización (update) y salida(escritura - write)
//Entrada y salida R/W
/*
 * 1 Byte = 8 bits = 1 carácter  
 * Kb kilobits
 * KB kilobytes 
 * Conjunto de carácteres,  campo (ejemplo: nombre, apellidos) como una variable
 * Conjunto de campos, se llama registro
 * Conjunto de registros se llama archivo
 */
int main(int argc, char **argv) {
	
	int cuenta;
	char nombre[5];
	float balance;
	char opc;
	FILE *apFile;
	
	apFile = fopen("ejemplo_de_archivo.txt", "r"); //'w'si no existe lo crea, si existe lo reemplaza, .dat es la extensión.
	// 'a' para no borrar lo que había, escribe al final del lo que ya había
	if(apFile == NULL) printf("No se puede abrir el archivo");
	else {
		printf("%")
		fclose(apFile);
	}
return 0;
}
