#include <stdio.h>
#include <stdlib.h>
int eve[9] = {4,8,9,2,0,1,3,8,11};
int i = 0, len = 0, j = 0, aux = 0, aux2 = 0;

void show(int x);
void ordena(int aux);

int main(int argc, char **argv)
{
	int x = 0;
	
	do {
		show(x);
		printf("\n");
		printf("Elija la forma de ordenamiento\n");
		printf("1. Forma ascendente\n");
		printf("2. Forma descendente\n");
		scanf("%d",&aux2);
		system("cls");
	}while(aux2 != 1 && aux2 !=2);
	
	ordena(aux2);
	printf("\n");
	x = 1;
	show(x);
	
	return 0;
}
void show(int x) {
	if(x == 0) printf("Elementos desordenados:\n");
	else printf("Elementos ordenados:\n");
	len=sizeof(eve)/sizeof(int);
	for(i = 0; i < len; i++){
		printf("%i ",eve[i]);
	} 
}
void ordena(int aux2) {
	
	len=sizeof(eve)/sizeof(int);
	
	for(j = 0; j < len; j++) {
		
		for(i = 0; i < len-1; i++){
			
			if (aux2 == 1) {
			
				if (eve[i] > eve[i+1]){
					aux = eve[i];
					eve[i] = eve[i+1];
					eve[i+1] = aux;
				}
			}
			else {
				if (eve[i] < eve[i+1]){
					aux = eve[i];
					eve[i] = eve[i+1];
					eve[i+1] = aux;
				}
			}
		}
	}
}
