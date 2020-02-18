#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	int i, num;
	char nombre[25],  area[25], perimetro[25];
	char opc;
	FILE *apFile;
	
	printf("Cuantas figuras desea introducir? ");
	scanf("%d",&num);
	apFile = fopen("Shapes.txt", "w"); //'w'si no existe lo crea, si existe lo reemplaza, .dat es la extensión.
	// 'a' para no borrar lo que había, escribe al final del lo que ya había
	if(apFile == NULL) printf("No se puede abrir el archivo");
	else {
		fprintf(apFile,"Nombre\t\tArea\t\tPerimetro\n");
	do {
		for(i = 0; i < num; i++) {
			if(i > 0) printf("\n");
			printf("Escribe el nombre de la figura: ");
			scanf("%s", nombre);
			fflush(stdin);
			printf("Area: ");
			scanf("%s", area);
			fflush(stdin);
			printf("Perimetro: ");
			scanf("%s", perimetro);
			fflush(stdin);
			
			fprintf(apFile,"%s\t%s\t\t%s\n",nombre, area,perimetro);
		} 
		printf("Desesa continuar? ");
		scanf("%s", &opc);
		fflush(stdin);
	} while(opc == 's');
		fclose(apFile);
	}
return 0;
}
