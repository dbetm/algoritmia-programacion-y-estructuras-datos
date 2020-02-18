#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{ 
	int num, ok, ch;
	do{
      printf("Ingresa un entero: ");
      fflush(stdout);
      if ((ok = scanf("%d", &num)) == EOF)
      return EXIT_FAILURE;
		  
	  if ((ch = getchar()) != '\n'){
         ok = 0;
         while ((ch = getchar()) != EOF && ch != '\n');
      }
	}while (!ok);
   
   printf("num == %d\n", num);
   
	return 0;
}

