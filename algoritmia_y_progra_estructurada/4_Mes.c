#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
	// Objetivo: Mostrar el nombre del mes
	// Autor:    David Betancourt Montellano
	// Fecha:    06/septiembre/2016
{
	int day  = 1,  month = 1, year = 1; 
	
	printf("El formato de fecha requerido es dd:mm:aaaa, se le solicitaran de izquierda a derecha");
	
	printf("Dame el dia: ");
	scanf("%i",&day);
	printf("Dame el mes ");
	scanf("%i",&month);
	printf("Dame el anio ");
	scanf("%i",&year);
	
	switch (month) {
		case 1:
			printf("Naciste en el mes de enero ");
			break;
		case 2:
			printf("Naciste en el mes de febrero ");
			break;
		case 3:
			printf("Naciste en el mes de marzo ");
			break;
		case 4:
			printf("Naciste en el mes de abril ");
			break;
		case 5:
			printf("Naciste en el mes de mayo" );
			break;
		case 6:
			printf("Naciste en el mes de junio ");
			break;
		case 7:
			printf("Naciste en el mes de julio ");
			break;
		case 8:
			printf("Naciste en el mes de agosto ");
			break;
		case 9:
			printf("Naciste en el mes de septiembre ");
			break;
		case 10:
			printf("Naciste en el mes de octubre ");
			break;
		case 11:
			printf("Naciste en el mes de noviembre ");
			break;
		case 12:
			printf("Naciste en el mes de diciembre ");
			break;
		default: 
			printf("No escribio correctamente ");
	}
		
	return 0;
}

