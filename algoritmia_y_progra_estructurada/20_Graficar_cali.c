#include <stdio.h>
#include <stdlib.h>
/*	Este programa pide 5 calificaciones y las grafica con
 * 	asteriscos
 */
char matrix[10][5];
int cali[5];  
int j =0, i= 0, aux = 1;

	void pedir_calif();
	void graficar(int x);
	void mostrar();

int main(int argc, char **argv)
{
	int aux2 = 0;
	do {
		aux2 = 0;
		pedir_calif();
		if(aux==1) mostrar();
		else aux2 = 1;
		printf("\n");
	}while(aux2 != 0);
	return 0;
}
void pedir_calif(){
	while (j<5){ 
		printf("Dame la calificacion: ");
		scanf("%i",&cali[j]);
		fflush(stdin);
		if (cali[j] < 0 || cali[j] > 10) {
			printf("Valor incorrecto, vuelva a intentarlo");
			aux = 0;
			break;
		}
		graficar(cali[j]);
		j++;
		aux = 1;
	}
	
}
void graficar(int x){
	for(i = 0;i<x;i++){
			matrix[i][j] = '*';
		}
	}
void mostrar(){
	for(i = 9; i >= 0; i--){
		for(j = 0; j < 5; j++){
			printf("%c ",matrix[i][j]);
		}
		printf("\n"); 
	}
}

