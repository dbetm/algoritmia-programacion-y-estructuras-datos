#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	/* Autor:    David Betancourt Montellano
       Objetivo: Número entero postivo, negativo o cero"
       Fecha:    13-septiembre-2016 */
       
       int num = 0;
     
       printf("Teclea el numero: ");
       scanf("%i",&num);
       
       if (num==0) {
		   printf("El numero es 0");
	   }
	   
	   else {
		   if (num > 0) {
				printf("Es positivo");
		   }
		   else {
				printf("Es negativo");
		   }	
			 
	   }
	
	return 0;
}

