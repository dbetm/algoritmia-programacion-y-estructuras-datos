#include <stdio.h>
#include <stdlib.h>
char msj[20];

void pedir_datos(char men[25]);
void show(char men_[25]);

int main(int argc, char **argv)
{
	int age = 0;
	
	pedir_datos("Escriba su edad: \n");
	age = atoi(msj); //función para convertir la edad a tipo entero
	pedir_datos("Escriba su nombre: \n");
	if(age >= 18)show(" eres mayor de edad\n");
	else show(" eres menor de edad\n");
	
	return 0;
}

void pedir_datos(char men[25]){
	printf("%s",men);
	scanf("%s",msj);
}
void show(char men_[25]){
	printf("\n");
	printf("%s%s",msj,men_);
}




