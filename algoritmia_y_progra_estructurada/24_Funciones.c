#include <stdio.h>
#include <stdlib.h>

//void funcion_1(int a, int x);
//int pide_dato();
int pide_dato2(char msj[20]);

int main(int argc, char **argv)
{		
	int base = 0, altura = 0, res = 0;
	
	base = pide_dato2("la base ");
	altura = pide_dato2("la altura ");
	res = (base*altura)/2;
	printf("El area es: %i\n", res);
	
	/*int dato1 = 0;
	dato1 = pide_dato();
	printf("Recibi el valor = ");
	printf("%i\n",dato1); */
	
	/*int p = 9, a = 8;
	
	funcion_1(10,1);
	funcion_1(p, a);
	funcion_1(++p, --a); */
	
	return 0;
}
void funcion_1(int a, int x) {
	printf("Recibi los siguientes valores: \n");
	printf(" a = ");
	printf("%i\n",a);
	printf(" x = ");
	if (x == 1) printf("cierto\n");
	if (x != 1) printf("falso\n");
}
int pide_dato(){
	int x = 0;
	printf("Dame el numero \n");
	scanf("%i",&x);
	printf("El valor de x es: %i\n",x);
	system("PAUSE");
	return x;
}
int pide_dato2(char msj[20]) {
	int x = 0;
	printf("Dame ");
	printf("%s",msj);
	scanf("%i",&x);
	printf("El valor de %s es %x\n",msj,x);
	system("PAUSE");
	return x;
	
}
