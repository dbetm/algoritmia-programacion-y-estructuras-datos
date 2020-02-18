#include <stdio.h>
#include <stdlib.h>

char msj[20];
char gen;
int estado = 0, edad = 0;

void pedir_datos();
void menu();
void process();
void show(char men[25]);

int main(int argc, char **argv)
{
	pedir_datos();
	if (gen == 'h') process();
	else printf ("Adios!\n");
	
	return 0;
}
void pedir_datos() {
	
	printf("Escriba su nombre: ");
	scanf("%s",msj);
	printf("Escriba su edad: ");
	scanf("%i",&edad);
	
	do {
		printf("Elija su estado civil\n");
		menu();
		scanf("%i",&estado);
	}while(estado != 1 && estado != 2);
	
	do {
	printf("Elija su genero, h = hombre, m = mujer \n");
	scanf("%s",&gen);
	}while(gen != 'h' && gen != 'm');
}
void menu(){
	printf("1. Soltero\n");
	printf("2. Casado\n");
}
void process() {
	if (edad < 18 || estado == 2) show(" usted no se manda solo\n");
	else show(" felicitaciones, usted se manda solo\n");
	
}
void show(char men[25]){
	printf(msj);
	printf(men);
}

