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
	
	apFile = fopen("ejemplo_de_archivo.txt", "a"); //'w'si no existe lo crea, si existe lo reemplaza, .dat es la extensión.
	// 'a' para no borrar lo que había, escribe al final del lo que ya había
	if(apFile == NULL) printf("No se puede abrir el archivo");
	else {
		do {
			printf("Dame el numero de cuenta: ");
			scanf("%d", &cuenta);
			printf("Dame el nombre: ");
			scanf("%s", nombre);
			fflush(stdin);
			printf("Ingresa el balance: ");
			scanf("%f", &balance);
			printf("Desesa continuar? ");
			scanf("%s", &opc);
			
			fprintf(apFile,"%d\n%s\n%.2f\n", cuenta, nombre, balance);
		} while(opc == 's');
		fclose(apFile);
	}
return 0;
}

