#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* Objetivo: Mostrar el desglose monetario de una cantidad dada por el usuario
 * Autor: David Betancourt Montellano
 * Fecha: Noviembre del 2016 */

//Global variables
float nominacion[12];

//Functions
float pedir_Cantidad();
void desglosar_Monto(float cantidad);
void mostrar_Desglose(int resultado, int i);

int main(int argc, char **argv) {
	float cantidad = 0;
	char opc;
	
	nominacion[0] = 1000.00 * 10;
	nominacion[1] = 500.00*10;
	nominacion[2] = 200.00*10;
	nominacion[3] = 100.00*10;
	nominacion[4] = 50.00*10;
	nominacion[5] = 20.00*10;
	nominacion[6] = 10.00*10;
	nominacion[7] = 5.00*10;
	nominacion[8] = 2.00*10;
	nominacion[9] = 1.00*10;
	nominacion[10] = 0.50*10;
	nominacion[11] = 0.10*10;
	
	do {
		//system("clear"); //for your linux <3
		system("cls"); //for your Windows
		cantidad = pedir_Cantidad();
		desglosar_Monto(cantidad);
		printf("Estimado usuario, ¿desea hacer más desgloses?\nPresione 'S' para indicar que sí\n");
		scanf("%s", &opc);
		fflush(stdin);
		opc = tolower(opc);
	} while(opc == 's');
	
	return 0;
}


float pedir_Cantidad() {
	float cantidad = 0;
	int limite = 1000 * 100000;
	char cantidad_1[9];
	
	do {
		system("clear");
		//system("cls");
		printf("Introduza la cantidad $");
		scanf("%s", cantidad_1);
		fflush(stdin);
		cantidad = atof(cantidad_1);
		if(cantidad == 0) continue;
		
	} while(cantidad <= 0 || cantidad > limite);
	
	return cantidad * 10;
}


void desglosar_Monto(float cantidad) {
	float residuo = cantidad; 
	int i;
	
	printf("Usted necesita: \n");
	
	for(i = 0; i < 12; i++) {
		mostrar_Desglose(residuo / nominacion[i], i);
		residuo = (int)residuo % (int)nominacion[i];
		if(residuo == 0) break;
	}
}


void mostrar_Desglose(int resultado, int i) {
	if(i < 6) {
		if(resultado != 0) {
			if(resultado > 1) {
				printf("%d billetes de $%.2f\n", resultado, nominacion[i] / 10);
			} else {
				printf("%d billete de $%.2f\n", resultado, nominacion[i] / 10);
			}
		}
	} else {
		if(resultado != 0) {
			if(resultado > 1) {
				printf("%d monedas de $%.2f\n", resultado, nominacion[i] / 10);
			} else {
				printf("%d moneda de $%.2f\n", resultado, nominacion[i] / 10);
			}
		}
	}
}
