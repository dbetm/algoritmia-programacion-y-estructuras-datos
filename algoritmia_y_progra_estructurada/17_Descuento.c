#include <stdio.h>
#include <stdlib.h>

float pedir_precio();
float obtener_desc();

     
int main(int argc, char **argv)
{
	pedir_precio();
	obtener_desc();
	
	return 0;
}
float pedir_precio(){
	float precio = 0;
	printf("Dame el precio del producto: $");
	scanf("%f",&precio);
	return precio;
}
float obtener_desc(){
	int  cont = 0;
	float desc = 0, aux = 0;
	
	do{
		desc = rand();
		printf("%.2f\n",desc);
		if (desc <= 50) aux = desc;
		
		if(aux == 10) break;
		if(aux == 20) break;
		if(aux == 30) break;
		if(aux == 40) break;
		if(aux == 50) break;
	}while(cont == 0 );
	
	desc = aux;
	printf("Su descuento es de: %.0f por ciento \n",desc);
	return desc;
}
