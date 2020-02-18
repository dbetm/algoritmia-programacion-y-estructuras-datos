#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
float pedir_catetos(char msj[20]);
float hip(float co, float ca);
float sen_cos(float hip, float a);
float tan_(float co, float ca);
void resultado(float x);

int main(int argc, char **argv)
{
	int opc = 0, cont = 0;
	float ca = 0, co = 0;
	
	printf("Bienvenid@. ");
	do {
		menu();
		scanf("%i",&opc);
		if (opc >= 1 && opc <=4){
			
			switch (opc) {
				
				case 1:
					printf("Has elegido calcular la razon seno ;)\n");
					co = pedir_catetos("el cateto opuesto:   ");
					ca = pedir_catetos("el cateto adyacente:  ");
					if(co <= 0 || ca <= 0) {
						printf("No pueden tener valores de 0 ni negativos. Deseas intentar otra vez?\n");
						system ("PAUSE");
						break;
					 }
					 resultado(sen_cos(hip(pow (co, 2), pow (ca, 2)),co));
					 cont = 0;
					break;
					
				case 2:
					printf("Has elegido calcular la razon coseno :)\n");
					co = pedir_catetos("el cateto opuesto:   ");
					ca = pedir_catetos("el cateto adyacente:  ");
					if(co <= 0 || ca <= 0) {
						printf("No pueden tener valores de 0 ni negativos. Deseas intentar otra vez?\n");
						system ("PAUSE");
						break;
					 }
					 resultado(sen_cos(hip(pow (co, 2), pow (ca, 2)),ca));
					 cont = 0;
					break;
					
				case 3: 
					printf("Has elegido calcular la razon tangente :D\n");
					co = pedir_catetos("el cateto opuesto:   ");
					ca = pedir_catetos("el cateto adyacente:  ");
					if(co <= 0 || ca <= 0) {
						printf("No pueden tener valores de 0 ni negativos. Deseas intentar otra vez?\n");
						system ("PAUSE");
						break;
					 }
					 resultado(tan_(co, ca));
					 cont = 0;
					break;	
			}
		}
		else {
			printf("No ha seleccionado una opcion correcta\n");
			if (cont == 2){
				printf("AVISO: ULTIMA OPORTUNIDAD!\n");
				printf("\n");
				} 
			if (cont == 3){
				printf("ADIOS\n");
				printf("\n");
				break;
			}
		cont++; 
		}
	}while(opc != 4);
	return 0;
}
void menu() {
	printf("Elija una opcion\n");
	printf("1. Calcular seno\n");
	printf("2. Calcular coseno\n");
	printf("3. Calcular tangente\n");
	printf("4. Salir\n");
}
float sen_cos(float hip, float a){
	float w = 0;
	w = a / hip;
	return w;
}
float tan_(float co, float ca){
	float t = 0;
	t = co / ca;
	return t;
}
float pedir_catetos(char msj[20]){
	float a = 0;
	printf("Dame ");
	printf("%s",msj);
	scanf("%f",&a);
	return a;
}
float hip(float co, float ca){	
	float h = co + ca;
	h = sqrt(h);
	return h;
}
void resultado(float x){
	printf("El resultado es ---> %.2f <---\n",x);
	system ("PAUSE");
}
