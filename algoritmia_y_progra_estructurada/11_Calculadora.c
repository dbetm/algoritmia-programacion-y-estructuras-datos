#include <stdio.h>
#include <stdlib.h>

float pedir_Numero();
float sumar(float a, float b);
float restar(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);
void message(float x);

int main(int argc, char **argv)
{
	int opc = 0, cont = 0;
	float n1 = 0, n2 = 0, out = 0;
	
	do {
	printf("Elige una opcion: \n");
	printf("1. Sumar\n");
	printf("2. Restar\n");
	printf("3. Multiplicar\n");
	printf("4. Dividir\n");
	printf("5. Salir\n");
	printf("----->  ");
	scanf("%i",&opc);
	
	if (opc >= 1 && opc <=5) {
		
		switch (opc) {
			case 1: 
				n1 = pedir_Numero();
				n2 = pedir_Numero();
				out = sumar(n1, n2);
				message(out);
				
				//message(sumar(pedir_Numero(),pedir_Numero()));  --forma anidada
				break;
			case 2: 
				n1 = pedir_Numero();
				n2 = pedir_Numero();
				out = restar(n1, n2);
				message(out);
				break;
			case 3: 
				n1 = pedir_Numero();
				n2 = pedir_Numero();
				out = multiplicar(n1, n2);
				message(out);
				break;
			case 4: 
				n1 = pedir_Numero();
				n2 = pedir_Numero();
				if (n2 == 0) {
					printf("No se puede dividir entre 0 ^_^ \n");
					printf("\n");
				}
				else {
					out = dividir(n1, n2);
					message(out); }
				break;
			case 5: 
				break;
		}
	}
	else {
		printf("Opcion no valida\n ");
		printf("\n");
		if (cont == 2){
			printf("!ULTIMA OPORTUNIDAD!\n");
			printf("\n");
		}
		if (cont == 3) {
			printf("Te lo dije ;)\n");
		}
		cont++;
	}
	}while(opc != 5 && cont != 4);
	
	return 0;
}

float pedir_Numero() {
	float a = 0;
	printf("Dame un numero: ");
	scanf("%f",&a);
	return a;
}
float sumar(float a, float b){
	float resultado = 0;
	resultado = a + b;
	return resultado;
}
float restar(float a, float b){
	float resultado = 0;
	resultado = a - b;
	return resultado;
}
float multiplicar(float a, float b){
	float resultado = 0;
	
	resultado = a * b;
	return resultado;
}
float dividir(float a, float b){
	float resultado = 0;
	
	resultado = a / b;
	return resultado;
}
void message(float x){
	printf("El resultado de la operacion es: %.2f \n",x);
	printf("\n");
}



