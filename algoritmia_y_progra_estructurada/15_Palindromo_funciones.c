#include <stdio.h>
#include <stdlib.h>
char msj[15];

void show(char msj[15]);
void pidepalabra();
void ciclo(char msj[15]);

int main(int argc, char **argv)
{
	pidepalabra();
	ciclo(msj);
	return 0;
}
void show(char msj[15]){
	printf("%s",msj);
}
void pidepalabra(){
	printf("Escribe tu mensaje sin espacios, y de 15 caracteres\n");
	scanf("%s",msj);
}
void ciclo(char msj[15]) {
	
	int i = 0, j = 14;
	
	for (i = 0; i < 15; i++) {	
		if( msj[i] == msj[j]){
			if(i == j) {
				show("Es palindromo\n");
				break;
			}
		}
		else {
			show("No es palindromo\n");
			break;
		}
		j--;
	}
}

