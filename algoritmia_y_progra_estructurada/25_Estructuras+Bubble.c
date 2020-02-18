#include <stdio.h>
#include <stdlib.h>

//variables globales
char nom[30];
int i = 0;
float eve[3];

//estructuras
struct persona grupo[3];

struct fecha {
	int dia; 
	int mes;
	int anio;
	};
struct persona {
	char nomb[20];
	struct fecha fecha_nac;
	float prom;
	struct fecha fecha_i_IPN;
	};

void pedir_datos();
void mostrar_datos();

//burbuja
	void show();
	void burbuja();

int main(int argc, char **argv)
{
	pedir_datos();
	mostrar_datos();
	burbuja();
	show();
	return 0;
}
//Funciones
void pedir_datos(){
		for(i = 0;i<3;i++) {
			printf("Dame un nombre: ");
			scanf("%s",grupo[i].nomb);
			fflush(stdin);
			printf("Dame el dia de tu nacimiento: ");
			scanf("%i",&grupo[i].fecha_nac.dia);
			printf("Dame el mes de tu nacimiento: ");
			scanf("%i",&grupo[i].fecha_nac.mes);
			printf("Dame el anio de tu nacimiento: ");
			scanf("%i",&grupo[i].fecha_nac.anio);
			printf("Dame tu promedio: ");
			scanf("%f",&grupo[i].prom);
			eve[i] = grupo[i].prom;
 			printf("Dame el dia de ingreso al IPN: ");
			scanf("%i",&grupo[i].fecha_i_IPN.dia);
			printf("Dame el mes de ingreso al IPN: ");
			scanf("%i",&grupo[i].fecha_i_IPN.mes);
			printf("Dame el anio de ingreso al IPN: ");
			scanf("%i",&grupo[i].fecha_i_IPN.anio);
			printf("\n");
		}
	}
void mostrar_datos(){
	i = 0;
	system("CLS");
	for(i = 0; i < 3; i++){
		printf("\n");
		printf("Eres: %s \n",grupo[i].nomb);
		printf("Tu fecha de nacimiento es: %i/%i/%i \n",grupo[i].fecha_nac.dia, grupo[i].fecha_nac.mes, grupo[i].fecha_nac.anio);
		printf("Tu fecha de ingreso al Poli es: %i/%i/%i \n",grupo[i].fecha_i_IPN.dia, grupo[i].fecha_i_IPN.mes, grupo[i].fecha_i_IPN.anio);
		printf("Tu promedio es: %.2f \n",grupo[i].prom);
	}
}

void burbuja(){
	
	int len = 0, j = 0;
	float aux = 0;
	
	len=sizeof(eve)/sizeof(int);
	
	for(j = 0; j < len; j++){
		
		for(i = 0; i < len-1; i++){

				if (eve[i] < eve[i+1]){
					aux = eve[i];
					eve[i] = eve[i+1];
					eve[i+1] = aux;
				}
			}
		}
	}
	
void show() {
	
	int len = 0, j = 0;
	i = 0;
	len=sizeof(eve)/sizeof(int);
	printf("\nPromedios: \n \n");
	
	for(i = 0; i < len; i++){ 
		
		for(j = 0; j < len; j++){ //comparar el promedio en la posicion i con los promedios de cada individuo...
			                      //al ser iguales nos dice que dicho promedio le pertenece a tal persona y ponemos su nombre. 
			if(eve[i] == grupo[j].prom){
				printf("%s ,",grupo[j].nomb);
				printf("%.2f\n",eve[i]);
			} 
		} 
	}
	printf("\n");

}
