#include <stdio.h>
#include <stdlib.h>

void intercambiar(int *px, int *py);

int main(int argc, char **argv)
{
	int x, y;
	
	x = 3;
	y = 23;
	printf("px = %d \py = %d\n",x,y);
	intercambiar(&x, &y);
	printf("px = %d \py = %d\n",x,y);
	
	return 0;
}
void intercambiar(int *px, int *py){
	int temp; 
	temp = *px; /* guarda el VALOR de la direccion x */
	*px = *py; 	/* pone y en x , es decir el 23*/
	*py = temp; /* pone x en y, es decir el 3 */
	}

