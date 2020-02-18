#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(int argc, char **argv)
	
	/* Autor:    David Betancourt Montellano
       Objetivo: Juego que "adivina" el número qué piensas"
       Fecha:    13-septiembre-2016 */
{
	int res = 0, opc = 0;
	
	do {
		printf("\nPiensa un numero");
		getch();
		printf("\nSumale 3");
		getch();
		printf("\nMultiplicalo por 2");
		getch();
		printf("\nRestale 8");
		getch();
		printf("\nDividelo entre 2");
		getch();
		printf("\nCuanto te quedo? ");
		scanf("%i",&res);
		
		printf("\nSu numero es: %i",res+=1);
		
		printf("\nDesea seguir jugando? (escriba 1 para indicar que si)");
		scanf("%i",&opc);
	}while(opc==1); //si fuera con char : (opc=='s')||(opc=='S')
	
	return 0;
}

